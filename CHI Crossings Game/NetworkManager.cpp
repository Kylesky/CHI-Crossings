#include "NetworkManager.hpp"

NetworkManager::NetworkManager(){
}

NetworkManager::~NetworkManager(){
}

void NetworkManager::initialize(){
	socket.setBlocking(false);
	bindSocket();
}

bool NetworkManager::bindSocket(int port){
	if(port == -1){
		if(socket.bind(sf::Socket::AnyPort) == sf::Socket::Done){
			this->port = socket.getLocalPort();
			return true;
		}else{
			this->port = -1;
			return false;
		}
	}else{
		this->port = port;
		return socket.bind(port) == sf::Socket::Done;
	}
}

unsigned short NetworkManager::getID(){
	return ID;
}

unsigned short NetworkManager::getPort(){
	return port;
}

bool NetworkManager::receive(sf::Packet& packet, int& player, unsigned short& port){
	sf::IpAddress address;
	if(socket.receive(packet, address, port) == sf::Socket::NotReady){
		return false;
	}else{
		player = playerIDs[address];
		return true;
	}
}

bool NetworkManager::send(sf::Packet& packet, int player){
	return socket.send(packet, IPs[player], ports[player]) == sf::Socket::Done;
}