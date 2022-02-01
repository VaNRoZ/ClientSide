#include "Common.h"
#include "Peer2Peer.h"

typedef struct
{
public:
	string name;
	string ip;
	int port;
	void Client()
	{
		name.clear();
		ip.clear();
		port = 0;
	}
}Partner;

class Client : public MTherad
{
public:
	string client_name;
	string possword;
	string chatName;
	TCPSocket* server_sock;
	Peer2Peer* udp_sock;

	Partner session_partner;
	vector<Partner*> chatroom_partners;
	bool connctionStatus;//ture-if the connection to the server succeded, false-if not
	bool isInSession;
	bool isInChatroom;
	bool isRoomOwner;
	bool isLoggedIn; // if the client os logged in
	bool isCommectedToServer; //if connected to the server right now

	Client();
	void run(); //waiting for commands from server
	
	bool connectToServer(string ip, int port); //connect to server with tcp
	void sendMsgToServer(string msg);
	void login(string name, string pass);
	void signup(string name, string pass);
	void listAllUsers();
	void getUsers();//get all users names from file
	void gotAllUsers();
	void gotIncomingSession();
	void listAllChatrooms();
	void listChatroomUsers(string roomName);
	void chatroomWasClosed();
	void gotUsersList(); //connected users
	void gotChatroomsList();
	void disconnectFromServer();
	void openSession(string userName, string peerUsr); //udp
	void closeSession();
	void sendMsgToSession(string msg);
	void CreateChatRoom(string roomName);
	void gotChatroomUsersList();
	void gotChatroomUsersNames();
	void userHasJoinedChatroom();
	void userHasLeftChatroom();
	void gotIpAndPort();
	void loggedIn();
	bool ConnectionStatus();
	bool sessionStatus();
	bool chartoomStatus();
	void closeConnection();
	string getName();
	void close();
	~Client();
};