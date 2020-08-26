int open_listener_socket();

void bind_to_port(int socket, int port);

int say(int socket, char* s);

void handle_shutdown(int sig);