/*
** EPITECH PROJECT, 2020
** htop
** File description:
** networkModule
*/

#include "networkModule.hpp"

NetworkModule::NetworkModule()
{
}

NetworkModule::~NetworkModule()
{
}

std::string NetworkModule::getLocalAddress()
{
    sf::IpAddress ip;
    sf::IpAddress tom;

    tom = ip.getLocalAddress();
    _localAddress = tom.toString();
    return _localAddress;
}

std::string NetworkModule::getPublicAddress()
{
    sf::IpAddress ip;
    sf::Time time = sf::seconds(5);
    sf::IpAddress tom;

    tom = ip.getPublicAddress(time);
    _publicAddress = tom.toString();
    return _publicAddress;
}