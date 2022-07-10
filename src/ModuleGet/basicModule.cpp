#include <fstream>
#include <boost/algorithm/string/replace.hpp>
#include "basicModule.hpp"

BasicModule::BasicModule()
{
}

BasicModule::~BasicModule()
{
}

std::string BasicModule::getHostname()
{
    std::string tmp;

    std::ifstream inputFile("/proc/sys/kernel/hostname", std::ifstream::in);
    std::getline(inputFile, tmp);
    inputFile.close();
    _hostname = boost::replace_all_copy(tmp, "\n", "");
    return _hostname;
}

std::string BasicModule::getUserName(char **env)
{
    int i = 0;

    for (; env[i]; i++) {
        if (!strncmp(env[i], "USER=", 5)) {
            std::string str = env[i];
            _username = boost::replace_all_copy(str, "USER=", "");
            return _username;
        }
    }
    return _username;
}