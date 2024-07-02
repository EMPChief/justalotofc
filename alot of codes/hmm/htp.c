#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main()
{
	// Disable output buffering for debugging purposes
	setbuf(stdout, NULL);

	int server_fd, client_addr_len;
	struct sockaddr_in client_addr;

	// Create a TCP socket
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == -1)
	{
		printf("Socket creation failed: %s...\n", strerror(errno));
		return 1;
	}

	// Set SO_REUSEPORT to avoid 'Address already in use' errors
	int reuse = 1;
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) < 0)
	{
		printf("SO_REUSEPORT failed: %s \n", strerror(errno));
		return 1;
	}

	// Set up the server address structure
	struct sockaddr_in serv_addr = {
		.sin_family = AF_INET,
		.sin_port = htons(4221),
		.sin_addr = {htonl(INADDR_ANY)},
	};

	// Bind the socket to the specified port and address
	if (bind(server_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) != 0)
	{
		printf("Bind failed: %s \n", strerror(errno));
		return 1;
	}

	// Start listening for incoming connections
	int connection_backlog = 5;
	if (listen(server_fd, connection_backlog) != 0)
	{
		printf("Listen failed: %s \n", strerror(errno));
		return 1;
	}

	printf("Waiting for a client to connect...\n");

	client_addr_len = sizeof(client_addr);
	while (1)
	{
		// Accept a client connection
		int client_socket = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
		if (client_socket < 0)
		{
			printf("Accept failed: %s\n", strerror(errno));
			continue;
		}

		printf("Client connected\n");

		// Receive data from the client
		char buffer[BUFFER_SIZE];
		ssize_t bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
		if (bytes_received < 0)
		{
			printf("Error receiving data: %s\n", strerror(errno));
			close(client_socket);
			continue;
		}
		buffer[bytes_received] = '\0'; // Null-terminate the received data

		// Parse the request method, path, and HTTP version
		char *method = strtok(buffer, " ");
		char *path = strtok(NULL, " ");
		char *version = strtok(NULL, "\r\n");

		// Initialize a variable to hold the User-Agent value
		char user_agent[BUFFER_SIZE] = "";

		// Parse headers to find the User-Agent header
		char *header_line = strtok(NULL, "\r\n");
		while (header_line != NULL)
		{
			if (strncmp(header_line, "User-Agent:", 11) == 0)
			{
				// Extract the User-Agent value
				strncpy(user_agent, header_line + 12, BUFFER_SIZE - 1);
				user_agent[BUFFER_SIZE - 1] = '\0'; // Ensure null termination
			}
			header_line = strtok(NULL, "\r\n");
		}

		// Handle only GET requests
		if (method && path && version && strcmp(method, "GET") == 0)
		{
			// Check if the path is the /user-agent endpoint
			if (strcmp(path, "/user-agent") == 0)
			{
				char response[BUFFER_SIZE];
				int response_length = snprintf(response, sizeof(response),
											   "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: %ld\r\n\r\n%s",
											   strlen(user_agent), user_agent);
				// Send the response
				send(client_socket, response, response_length, 0);
			}
			else
			{
				// Handle other paths (existing /echo/{str} and default root handling)
				if (strncmp(path, "/echo/", 6) == 0)
				{
					char *echo_string = path + 6;
					char response[BUFFER_SIZE];
					int response_length = snprintf(response, sizeof(response),
												   "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: %ld\r\n\r\n%s",
												   strlen(echo_string), echo_string);
					send(client_socket, response, response_length, 0);
				}
				else if (strcmp(path, "/") == 0)
				{
					const char *response = "HTTP/1.1 200 OK\r\n\r\n";
					send(client_socket, response, strlen(response), 0);
				}
				else
				{
					const char *response = "HTTP/1.1 404 Not Found\r\n\r\n";
					send(client_socket, response, strlen(response), 0);
				}
			}
		}
		else
		{
			// Send 400 Bad Request for unsupported methods
			const char *response = "HTTP/1.1 400 Bad Request\r\n\r\n";
			send(client_socket, response, strlen(response), 0);
		}

		// Close the client connection
		close(client_socket);
	}

	// Close the server socket (unreachable code in this example)
	close(server_fd);
	return 0;
}
