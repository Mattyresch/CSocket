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

int sock352_init(int udp_port){
	if(udp_port == -1){
		return 0;
	}else if(udp_port == 0){
		return SOCK352_DEFAULT_UDP_PORT;
	}else{
		if(udp_port < 0){
			return -1;
		}
		return udp_port;
	}
}

int sock352_init2(int remote_port, int local_port){

}

int sock352_socket(int domain, int type, int protocol){

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
