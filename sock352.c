/*
 * sock352.c
 *
 * Created by mresch on 02/24/15
 * Copyright mresch (c) 2015. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <openssl/md5.h>
#include "sock352.h"

sock352_pkt_hdr_t *init_header(uint32_t client, in_port_t dest){
	sock352_pkt_hdr_t * connection;
	connection = (sock352_pkt_hdr_t *) malloc(sizeof(sock352_pkt_hdr_t));
	connection->version = SOCK352_VER_1;
	connection->flags = 0;
	connection->opt_ptr = 0;
	connection->protocol = 0;
	connection->header_len = sizeof(sock352_pkt_hdr_t);
	connection->checksum = 0;
	connection->source_port = client;
	connection->dest_port = dest;
	connection->sequence_no = 0;
	connection->ack_no = 0;
	connection->window = 0;
	connection->payload_len = 0;
	return connection;
}


/*	
 *	This function takes an UDP port to connect to, and initializes a socket for
 *	that port number
 *
 *	Input: int
 *	Output: int
 */
int sock352_init(int udp_port){
	if(udp_port == -1){
		return 0;
	}else if (udp_port != 0){
		return SOCK352_FAILURE;
	}else{
		conns = malloc(sizeof(sock352_global_t));
		conns->active_connections = (sock352_connection_t *) NULL;
		conns->sock352_base_fd = 0;
		conns->sock352_recv_port = SOCK352_DEFAULT_UDP_PORT;
		return SOCK352_SUCCESS;
	}
}

int sock352_init2(int remote_port, int local_port){

}
/*
 * This function takes three arguments, the domain, type, and protocol for
 * a socket. The output is either a number indicating success, or one
 * indicating failure. The new connection is also added to a global hashtable
 * of all active connections, which is held within a global data structure.
 *
 * Input: int, int, int
 * Output: int
 *
 *
 */

int sock352_socket(int domain, int type, int protocol){

	//Check to make sure the domains and types are correct
	if(domain != AF_CS352 || type != SOCK_STREAM)
		return SOCK352_FAILURE;
	//set up the socket with the given domain type and protocl
	int sock = socket(domain, type, protocol);
	//allocate memory for the connection
	sock352_connection_t * conn = malloc(sizeof(sock352_connection_t));
	//set up the connection
	memset(conn, 0, sizeof(sock352_connection_t));
	conn->state = CLOSED;
	conn->sock352_fd = sock;
	//add the connection to the active connections
	HASH_ADD_INT(conns->active_connections, sock352_fd, conn);
	//return the socket
	return sock;
}



int sock352_bind(int fd, sockaddr_sock352_t *addr, socklen_t len){

}

int sock352_connect(int fd, sockaddr_sock352_t *addr, socklen_t len){

}

int sock352_listen(int fd, int n){

}

int sock352_accept(int _fd, sockaddr_sock352_t *addr, int *len){

}

int sock352_close(int fd){

}

int sock352_read(int fd, void *buf, int count){

}

int sock352_write(int fd, void *buf, int count){

}
