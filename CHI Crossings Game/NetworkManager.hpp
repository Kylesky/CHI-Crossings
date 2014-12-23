#pragma once

#include <map>
#include <SFML\Network.hpp>

class NetworkManager{
private:
	unsigned short ID, port;
	sf::UdpSocket socket;
	std::map<sf::IpAddress, unsigned short> playerIDs;
	std::map<unsigned short, sf::IpAddress> IPs;
	std::map<unsigned short, unsigned short> ports;
public:
	NetworkManager();
	~NetworkManager();
	
	void initialize();
	bool bindSocket(int port = -1);

	unsigned short getID();
	unsigned short getPort();

	bool receive(sf::Packet& packet, int& player, unsigned short& port);
	bool send(sf::Packet& packet, int player);
};