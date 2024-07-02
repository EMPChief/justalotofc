#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
	// Disable output buffering
	setbuf(stdout, NULL);
	printf("Logs from your program will appear here!\n");

	int server_socket_fd, client_address_length;
	struct sockaddr_in client_address;

	// Create a TCP socket
	server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket_fd == -1)
	{
		printf("Socket creation failed: %s...\n", strerror(errno));
		return 1;
	}

	// Set SO_REUSEPORT to avoid 'Address already in use' errors
	int reuse = 1;
	if (setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) < 0)
	{
		printf("SO_REUSEPORT failed: %s \n", strerror(errno));
		return 1;
	}

	// Define server address
	struct sockaddr_in server_address = {
		.sin_family = AF_INET,
		.sin_port = htons(4221),
		.sin_addr = {htonl(INADDR_ANY)},
	};

	// Bind the socket to the specified port
	if (bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) != 0)
	{
		printf("Bind failed: %s \n", strerror(errno));
		return 1;
	}

	// Start listening for incoming connections
	int connection_backlog = 5;
	if (listen(server_socket_fd, connection_backlog) != 0)
	{
		printf("Listen failed: %s \n", strerror(errno));
		return 1;
	}

	printf("Waiting for a client to connect...\n");
	client_address_length = sizeof(client_address);

	while (1)
	{
		// Accept an incoming connection
		int client_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_address, &client_address_length);
		printf("Client connected\n");

		// Fork a new process to handle the client connection
		if (!fork())
		{
			// Child process does not need the server socket
			close(server_socket_fd);

			// Read the request from the client
			char request_buffer[BUFFER_SIZE];
			char request_buffer_copy[BUFFER_SIZE];
			int bytes_read = read(client_socket_fd, &request_buffer, sizeof(request_buffer));
			if (bytes_read == -1 || bytes_read < 0)
			{
				printf("Read failed: %s\n", strerror(errno));
				return 1;
			}
			strcpy(request_buffer_copy, request_buffer);

			// Prepare responses
			char *response_ok_200 = "HTTP/1.1 200 OK\r\n\r\n";
			char *response_not_found_404 = "HTTP/1.1 404 Not Found\r\n\r\n";

			// Parse the request line
			char *http_method = strtok(request_buffer, " ");
			char *request_path = strtok(NULL, " ");

			if (strcmp(http_method, "GET") == 0)
			{
				// Handle root request
				if (strcmp(request_path, "/") == 0)
				{
					write(client_socket_fd, (void *)response_ok_200, strlen(response_ok_200));
				}
				// Handle /user-agent endpoint
				else if (strstr(request_path, "/user-agent") != NULL)
				{
					char *header_line = strtok(request_buffer_copy, "\n");
					char *user_agent_value = NULL;

					while (header_line != NULL)
					{
						if (strncmp(header_line, "User-Agent:", 11) == 0)
						{
							user_agent_value = header_line + 12;
							break;
						}
						header_line = strtok(NULL, "\n");
					}

					if (user_agent_value)
					{
						int length = strlen(user_agent_value);
						char response_message_body[BUFFER_SIZE];
						snprintf(response_message_body, sizeof(response_message_body),
								 "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: %d\r\n\r\n%s",
								 length, user_agent_value);
						write(client_socket_fd, response_message_body, strlen(response_message_body));
					}
				}
				// Handle /echo endpoint
				else if (strncmp(request_path, "/echo/", 6) == 0)
				{
					char *echo_message = request_path + 6;
					int length_of_echo_message = strlen(echo_message);
					char response_message_body[BUFFER_SIZE];
					snprintf(response_message_body, sizeof(response_message_body),
							 "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: %d\r\n\r\n%s",
							 length_of_echo_message, echo_message);
					write(client_socket_fd, response_message_body, strlen(response_message_body));
				}
				// Handle /files endpoint
				else if (strncmp(request_path, "/files/", 7) == 0 && argc >= 3)
				{
					char *directory_path;
					if (strcmp(argv[1], "--directory") == 0 && strlen(argv[2]) >= 1)
					{
						directory_path = argv[2];
					}

					char file_path[BUFFER_SIZE];
					snprintf(file_path, sizeof(file_path), "%s/%s", directory_path, request_path + 7);

					FILE *file = fopen(file_path, "rb");
					if (file == NULL)
					{
						write(client_socket_fd, (void *)response_not_found_404, strlen(response_not_found_404));
					}
					else
					{
						// Get the file size
						fseek(file, 0, SEEK_END);
						long file_size = ftell(file);
						fseek(file, 0, SEEK_SET);

						// Read the file content
						char *file_contents = malloc(file_size);
						fread(file_contents, 1, file_size, file);
						fclose(file);

						// Prepare the response
						char response_message_body[BUFFER_SIZE];
						snprintf(response_message_body, sizeof(response_message_body),
								 "HTTP/1.1 200 OK\r\nContent-Type: application/octet-stream\r\nContent-Length: %ld\r\n\r\n",
								 file_size);
						write(client_socket_fd, response_message_body, strlen(response_message_body));
						write(client_socket_fd, file_contents, file_size);

						free(file_contents);
					}
				}
				// Handle unknown paths
				else
				{
					write(client_socket_fd, (void *)response_not_found_404, strlen(response_not_found_404));
				}
			}
			else
			{
				// If method is not GET, respond with 404 Not Found
				write(client_socket_fd, (void *)response_not_found_404, strlen(response_not_found_404));
			}

			// Close the client socket
			close(client_socket_fd);
			exit(0); // Child process exits
		}
		// Close the client socket in the parent process
		close(client_socket_fd);
	}

	// Close the server socket (this code is unreachable due to the infinite loop)
	close(server_socket_fd);
	return 0;
}
