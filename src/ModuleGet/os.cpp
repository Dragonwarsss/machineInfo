/*
** EPITECH PROJECT, 2020
** htop
** File description:
** os
*/

#include <fstream>
#include "os.hpp"

Os::Os()
{
    getOsNamePrivate();
}

Os::~Os()
{
}

std::string Os::getOsName()
{
    return _osName;
}

void Os::getOsNamePrivate()
{
    std::ifstream inputFile("/etc/system-release", std::ifstream::in);
    std::string osName = "";

    std::getline(inputFile, osName);
    inputFile.close();
    _osName = osName;
}

std::string Os::getKernelVersion()
{
    struct utsname uts;
    uname(&uts);
    _kernelVersion = uts.release;
    return _kernelVersion;
}