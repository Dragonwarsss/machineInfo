/*
** EPITECH PROJECT, 2020
** htop
** File description:
** IMonitorModule
*/

#include <iostream>


#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

class IMonitorModule {
public:
    virtual ~IMonitorModule() {};

public:
    virtual std::string getModuleName() const = 0;
    virtual void setModuleName(const std::string& moduleName) = 0;
    virtual void refresh() = 0;

protected:
    std::string _moduleName;
};

#endif