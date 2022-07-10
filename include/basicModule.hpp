/*
** EPITECH PROJECT, 2020
** htop
** File description:
** basicModule
*/

#include <iostream>
#include <cstring>
#include "IMonitorModule.hpp"

#ifndef BASICMODULE_HPP_
#define BASICMODULE_HPP_

class BasicModule : public IMonitorModule{
    public:
        BasicModule();
        virtual ~BasicModule();
        std::string getHostname();
        std::string getUserName(char **env);
        virtual std::string getModuleName() const {return _moduleName;};
        virtual void setModuleName(const std::string& moduleName) {_moduleName = moduleName;};
        virtual void refresh() {};
    private:
        std::string _hostname;
        std::string _username;
};

#endif /* !BASICMODULE_HPP_ */
