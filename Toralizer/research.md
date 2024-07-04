## SOCKS4 RFC

The [SOCKS4 RFC](https://tools.ietf.org/html/rfc1928) defines the SOCKS4 protocol, a standard for routing network packets between a client and a server through a proxy server.

### SOCKS4 Protocol

The SOCKS4 protocol is a simple, client-server protocol that permits a client to tunnel connection requests to a SOCKS server, and for the server to forward the request to the desired destination. The SOCKS server acts as an intermediary for the client's request, without any knowledge of the request's content.

### Client-Server Protocol

The client-server protocol and the roles of the client and server are described in [section 4](https://tools.ietf.org/html/rfc1928#section-4) of the RFC. The client sends a request to the server in the following format:

| Field     | Length  | Description          |
|-----------|---------|----------------------|
| `VN`      | 1 byte  | SOCKS version number |
| `CD`      | 1 byte  | SOCKS command code   |
| `DSTPORT` | 2 bytes | Destination port     |
| `DSTIP`   | 4 bytes | Destination IP       |
| `USERID`  | variable| User ID              |
| `NULL`    | 1 byte  | Null byte            |

# of bytes:
| Field     | Length  |
|-----------|---------|
| `VN`      | 1       |
| `CD`      | 1       |
| `DSTPORT` | 2       |
| `DSTIP`   | 4       |
| `USERID`  | variable|
| `NULL`    | 1       |

