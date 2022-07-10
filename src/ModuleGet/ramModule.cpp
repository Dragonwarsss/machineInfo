/*
** EPITECH PROJECT, 2020
** htop
** File description:
** ramModule
*/

#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <iomanip>
#include "ramModule.hpp"

RamModule::RamModule()
{
}

RamModule::~RamModule()
{
}

float float_memory(float memory)
{
    std::ostringstream stream;
    std::string result;

    stream << std::setprecision(3) << memory * 0.00000095367432;
    result = stream.str();
    return stof(result);
}

std::string RamModule::getMaxMemory()
{
    this->getMemory();
    std::ostringstream stream;
    stream << _totalMemory;
    return stream.str();
}

std::string RamModule::getUsedMemory()
{
    this->getMemory();
    std::ostringstream stream;
    stream << _usedMemory;
    return stream.str();
}

float mem_line_to_float(std::string str)
{
    std::string tmp = boost::replace_all_copy(str, " ", "");
    std::vector<std::string> result;

    tmp = boost::replace_all_copy(tmp, "kB", "");
    boost::split(result, tmp, boost::is_any_of(":"));
    return stof(result[1]);
}
void RamModule::getMemoryInfo()
{
    std::ifstream inputFile("/proc/meminfo", std::ifstream::in);
    std::string tmp_str;
    std::string tmp_str_used;
    std::string precision;
    std::string nstr;

    std::getline(inputFile, tmp_str); // total memory
    for (int i = 0; i != 5; i++)
        std::getline(inputFile, tmp_str_used); // skip
    std::getline(inputFile, tmp_str_used); // memory available
    inputFile.close();
//
    _totalMemory = float_memory(mem_line_to_float(tmp_str));
    _usedMemory = float_memory(mem_line_to_float(tmp_str_used));
}

std::string RamModule::getMemory()
{
    std::ostringstream stringStream;
    this->getMemoryInfo();

    stringStream << _usedMemory << " / " << _totalMemory;
    return stringStream.str();
}