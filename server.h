#ifndef SERVER_H
# define SERVER_H

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# define MAX_CLIENTS 10

typedef struct s_client
{
	int	pid;
	int	is_connected;
}	t_client;

typedef struct s_server
{
	int			pid;
	int			client_count;
	t_client	clients[MAX_CLIENTS];
}	t_server;

void    init_server(t_server *server);
void    handle_client(t_server *server, int pid);
void    send_message(t_server *server, char *message);
void    receive_message(t_server *server, int pid, char *message);
void    disconnect_client(t_server *server, int pid);
void    print_clients(t_server *server);

#endif
