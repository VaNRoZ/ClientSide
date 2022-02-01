#ifndef COMMON_H_
#define COMMON_H_

#include <WinSock2.h>
#include "Protocol.h"
#include <iostream>
#include <sys/types.h>
//#include <netinet/in.h> // winsock2.h
#include <inttypes.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <algorithm>
#include "MThread.h"
#include "MultipleTCPSocketsListener.h"
#include "TCPSocket.h"
#include "UDPSocket.h"

static int readCommand(TCPSocket* socktoread) {
	int messagekength = 0, recived = 0;
	recived = socktoread->recv((char*)&messagelength, 4);
	if (!recived == 4)
		return 0;
	return ntohl((uint32_t)messagelength);
}

static void writeCommand(TCPSocket* socktowrite, int command){
	int meglen = htonl((uint32_t)command); // unsigned integer 32-bit type
	socktoweite->send((char*)&msglen, 4);
}

static void writeMsg(TCPSocket* socktowrite, string msg) {
	//send msg lengh
	int msglen = htonl((uint32_t)msg.length());
	socktowrite->send((char*)&msglen, 4);
	//send msg
	socktowrite->send(msg.c_str(), msg.lengh());
}

static string readMsg(TCPSocket* socktoread) {
	char rcvmsg[300];
	bzero(rcvmsg, 300);
	int recived = 0, meddagelengh = 0, len = 0;
	recived = socktoread->recv((char*)&messagelength, 4);
	if (!recived > 0)
		return string("0");
	len = ntonl((uint32_t)messagelength);
	socktoread->recv(recvmsg, len);
	return string(rcvmsg);
}

#endif /*COMMON_H_*/