/*
** EPITECH PROJECT, 2020
** htop
** File description:
** cpuModule
*/

#include "cpuModule.hpp"

CpuModule::CpuModule()
{
}

CpuModule::~CpuModule()
{
}

std::string CpuModule::getModelName()
{
    std::ifstream inputFile("/proc/cpuinfo", std::ifstream::in);
    std::string tmp_str;
    const char *tmp;

    for (int i = 0; std::getline(inputFile, tmp_str); i++) {
        tmp = tmp_str.c_str();
        if (!strncmp(tmp, "model name", 10)) {
            _modelName = boost::replace_all_copy(tmp_str, "model name\t: ", "");
            inputFile.close();
            return _modelName;
        }
    }
    return _modelName;
}

std::string CpuModule::getCpuFrequency()
{
    std::ifstream inputFile("/proc/cpuinfo", std::ifstream::in);
    std::string tmp_str;
    const char *tmp;

    for (int i = 0; std::getline(inputFile, tmp_str); i++) {
        tmp = tmp_str.c_str();
        if (!strncmp(tmp, "cpu MHz", 7)) {
            _cpuFrequency = boost::replace_all_copy(tmp_str, "cpu MHz\t\t: ", "");
            inputFile.close();
            return _cpuFrequency + " MHz";
        }
    }
    inputFile.close();
    return _cpuFrequency + " MHz";
}

std::string CpuModule::getMaxCore()
{
    std::ifstream inputFile("/proc/cpuinfo", std::ifstream::in);
    std::string tmp_str;
    const char *tmp;
    int maxCore = 0;

    for (int i = 0; std::getline(inputFile, tmp_str); i++) {
        tmp = tmp_str.c_str();
        if (!strncmp(tmp, "processor", 9)) {
            _maxCore = boost::replace_all_copy(tmp_str, "processor\t: ", "");
            maxCore = std::stoi(_maxCore);
        }
    }
    inputFile.close();
    maxCore += 1;
    _maxCore = std::to_string(maxCore);
    return _maxCore;
}


float *CpuModule::getCpuUsage()
{
    return _cpu_use.getCpuUsage();
}

void CpuModule::reload()
{
    _cpu_use.computeUsage();
}