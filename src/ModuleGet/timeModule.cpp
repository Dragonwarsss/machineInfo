/*
** EPITECH PROJECT, 2020
** htop
** File description:
** timeModule
*/

#include "timeModule.hpp"

TimeModule::TimeModule()
{
}

TimeModule::~TimeModule()
{
}

int fibonacci(int n)
{
    if (n < 3) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

std::string TimeModule::getDate()
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    end = std::chrono::system_clock::now();
 
    //int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
    //                         (end-start).count();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    return std::ctime(&end_time);
}

std::string TimeModule::getTime()
{
    return "";
}

std::string format_time(std::string str)
{
    int time = stoi(str);
    int day = time / 86400;
    std::ostringstream stringStream;

    if (day > 0) {
        time -= (day * 86400);
        day > 1 ? stringStream << day << " Days, " : stringStream << day << " Day, ";
    }
    int hours = time / 3600;
    if (hours)
        time -= (hours * 3600);
    stringStream << hours << ":";
    int minutes = time / 60;
    if (minutes)
        time -= (minutes * 60);
    stringStream << minutes << ":";
    int seconds = time;
    stringStream << seconds;
    return stringStream.str();
}

std::string TimeModule::uptime()
{
    std::ifstream inputFile("/proc/uptime", std::ifstream::in);
    std::string uptime_str;
    std::string tmp_str;
    std::vector<std::string> result;

    std::getline(inputFile, tmp_str);
    inputFile.close();
    boost::split(result, tmp_str, boost::is_any_of(" "));
    uptime_str = format_time(result[0]);
    return uptime_str;
}