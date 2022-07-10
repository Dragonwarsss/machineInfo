/*
** EPITECH PROJECT, 2020
** htop
** File description:
** networkModule
*/

#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <net/if.h>
#include <unistd.h>
#include <SFML/Network.hpp>
#include "IMonitorModule.hpp"

#ifndef NETWORKMODULE_HPP_
#define NETWORKMODULE_HPP_

class NetworkModule : public IMonitorModule {
    public:
        NetworkModule();
        virtual ~NetworkModule();
        std::string getLocalAddress();
        std::string getPublicAddress();
        //std::string getMacAddress();
        virtual std::string getModuleName() const {return _moduleName;};
        virtual void setModuleName(const std::string& moduleName) {_moduleName = moduleName;};
        virtual void refresh() {};
    private:
        std::string _localAddress;
        std::string _publicAddress;
};

#endif /* !NETWORKMODULE_HPP_ */
