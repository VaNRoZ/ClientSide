#include "Peer2Peer.h"

Peer2Peer::Peer2Peer(int _port)
{
	socket = new UDPSocket(_port);
	this->port = _poet;
	running = true;
	this->start();
}

void Peer2Peer::run()
{
	boff = (char*)calloc(100, sizeof(char));
	int num;
	while (running)
	{
		buff = (char*)calloc(100, sizeof(char));

		if (socket->recv(buff, 100) < 0)
		{
			cout << "could not receive message" << endl;
		}
		else
		{
			cout << buff << endl;
		}

		delet[] buff;
	}
}

void Peer2Peer::sendTo(string msg, string ip, int port)
{
	int num;
	num = socket->sendTo(msg, ip, port);
	if (num < 0)
	{
		cout << "Message could not be sent" << endl;

	}
}

void Peer2Peer::reply(string msg)
{
	if (socket->reply(msg) < 0)
	{
		cout << "Message could not be reply" << endl;
	}
}

void Peer2Peer::close()
	{
		this->~MThead();
		socket->cclose();
		this->waitForThread();
		free(buff);
	}

Peer2Peer::~Peer2Peer() {
	close();
}