#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <stdio.h>

#include "../Socket/lib/SocketServer.h"
#include "../Socket/lib/SocketClient.h"

using namespace std;

std::vector<SocketClient*> clientsVector;
std::vector<std::vector<std::string> > clientsData;

std::string getUid(){
    std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::string uid="";
    int length = characters.size();
    for(int i=0 ; i<10 ; i++){
        uid += characters[rand() % length];
    }
    return uid;
}

void forward(string key, vector<string> messages, SocketClient *exception){
	std::string *_uid = (std::string*) exception->getTag();
	for(auto x : clientsVector){
		std::string *uid = (std::string*) x->getTag();
		if((*uid)!=(*_uid)){
			x->send(key, messages);
		}
	}
}

void onPlayer(SocketClient *socket, vector<string> messages){
	clientsData.push_back(messages);

    if(clientsVector.size()==2){
        clientsVector[0]->send("player", clientsData[1]);
        clientsVector[1]->send("player", clientsData[0]);
        clientsVector[0]->send("first", {"1"});
        clientsVector[1]->send("first", {"0"});
    }
}

void onPickCard(SocketClient *socket, vector<string> messages){
	forward("pick", messages, socket);
}

void onPlayCardDialog(SocketClient *socket, vector<string> messages){
	forward("playCardDialog", messages, socket);
}

void onAttackDialog(SocketClient *socket, vector<string> messages){
	forward("attackDialog", messages, socket);
}

void onDisconnect(SocketClient *socket){
	cout << "client disconnected !" << endl;
	forward("disconnect", {"Client disconnected"}, socket);
	std::string *_uid = (std::string*) socket->getTag();
	for(int i=0 ; i<clientsVector.size() ; i++){
		std::string *uid = (std::string*) clientsVector[i]->getTag();
		if((*uid)==(*_uid)){
			clientsVector.erase(clientsVector.begin() + i);
		}
	}
	delete socket;
}

void freeMemory(){
	for(auto x : clientsVector){
		delete (std::string*) x->getTag();
		delete x;
	}
}

int main(int argc , char *argv[]){
	srand(time(NULL));

	SocketServer server(8888);
	if(server.start()){
		cout << "server started. Listening on port 8888..." << endl;
		while (1) {
			int sock = server.accept();
			if(sock!=-1){
				cout << "client connected !" << endl;
				SocketClient *client = new SocketClient(sock);
                std::string *uid = new std::string(getUid());
				client->addListener("player", onPlayer);
				client->addListener("pick", onPickCard);
				client->addListener("playCardDialog", onPlayCardDialog);
				client->addListener("attackDialog", onAttackDialog);
				client->setDisconnectListener(onDisconnect);
				client->setTag(uid);
                client->send("uid", {*uid});
				clientsVector.push_back(client);
			}
		}
	}
	else{
		cout << "Could not create server" << endl;
	}

	freeMemory();
	return 0;
}
