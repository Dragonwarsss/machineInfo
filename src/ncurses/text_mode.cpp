/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** text_mode
*/

#include "text_mode.hpp"

#define ENTER 10
#define ESC 27
#define LEFT_ARROW KEY_LEFT
#define RIGHT_ARROW KEY_RIGHT
#define UP_ARROW KEY_UP
#define DOWN_ARROW KEY_DOWN

textmode::textmode()
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    getmaxyx(stdscr, _height, _width);
    _monitorCoreModule = MonitorCore();
    _basicModule = BasicModule();
    _OS = Os();
    _timeModule = TimeModule();
    _cpuModule = CpuModule();
    _cpuUsage = CpuUsage(4);
    _ramModule = RamModule();
    _networkModule = NetworkModule();

    _cursorPos = 0;
    _MonitorCoreBool = true;
    _hostBool = true;
    _userBool = true;
    _OSBool = true;
    _kernelBool = true;
    _dateTimeBool = true;
    _cpuBool = true;
    _memoryBool = true;
    _networkBool = true;
}

void textmode::displayMonitorCore()
{
    mvprintw((_height / 10), _width / 20, "   Monitor Core:      ");
    if (_MonitorCoreBool) {
        mvprintw((_height / 10) - 1, (_width / 4) - 2, "+------------+");
        mvprintw((_height / 10) + 1, (_width / 4) - 2, "+------------+");
        mvprintw((_height / 10), (_width / 4) - 2, "|");
        mvprintw((_height / 10), (_width / 4) + 11, "|");
        mvprintw((_height / 10), _width / 4, ("Threads: " + _monitorCoreThreads).c_str());
    }
}

void textmode::displayHost()
{
    mvprintw((_height / 10) + 4, _width / 20, "   Hostname:          ");
    if (_hostBool) {
        mvprintw((_height / 10) + 3, (_width / 4) - 2, "+-----------------------+");
        mvprintw((_height / 10) + 5, (_width / 4) - 2, "+-----------------------+");
        mvprintw((_height / 10) + 4, (_width / 4) - 2, "|");
        mvprintw((_height / 10) + 4, (_width / 4) + 22, "|");
        mvprintw((_height / 10) + 4, _width / 4, _hostName.c_str());
    }
}

void textmode::displayUser()
{
    mvprintw((_height / 10) + 8, _width / 20, "   Username:          ");
    if (_userBool) {
        mvprintw((_height / 10) + 7, (_width / 4) - 2, "+-------------------+");
        mvprintw((_height / 10) + 9, (_width / 4) - 2, "+-------------------+");
        mvprintw((_height / 10) + 8, (_width / 4) - 2, "|");
        mvprintw((_height / 10) + 8, (_width / 4) + 18, "|");
        mvprintw((_height / 10) + 8, _width / 4, _userName.c_str());
    }
}

void textmode::displayOS()
{
    mvprintw((_height / 10) + 12, _width / 20, "   Operating system:  ");
    if (_OSBool) {
        mvprintw((_height / 10) + 11, (_width / 20) + 27, "+-------------------+");
        mvprintw((_height / 10) + 13, (_width / 20) + 27, "+-------------------+");
        mvprintw((_height / 10) + 12, (_width / 20) + 27, "|");
        mvprintw((_height / 10) + 12, (_width / 20) + 47, "|");
        mvprintw((_height / 10) + 12, _width / 4, _operatingSystem.c_str());
    }
}

void textmode::displayKernel()
{
    mvprintw((_height / 10) + 16, _width / 20, "   Kernel version     ");
    if (_kernelBool) {
        mvprintw((_height / 10) + 15, (_width / 4) - 2, "+------------------------------+");
        mvprintw((_height / 10) + 17, (_width / 4) - 2, "+------------------------------+");
        mvprintw((_height / 10) + 16, (_width / 4) - 2, "|");
        mvprintw((_height / 10) + 16, (_width / 4) + 29, "|");
        mvprintw((_height / 10) + 16, _width / 4, _kernel.c_str());
    }
}

void textmode::displayDate()
{
    mvprintw((_height / 10) + 20, _width / 20, "   Date and time:     ");
    if (_dateTimeBool) {
        mvprintw((_height / 10) + 19, (_width / 4) - 2, "+------------------------------+");
        mvprintw((_height / 10) + 21, (_width / 4) - 2, "+------------------------------+");
        mvprintw((_height / 10) + 20, (_width / 4) - 2, "|");
        mvprintw((_height / 10) + 20, _width / 4, (_date + " " + _time).c_str());
        mvprintw((_height / 10) + 20, (_width / 4) + 29, "|");
    }
}

void textmode::displayCpu()
{
    mvprintw((_height / 10) + 24, _width / 20, "   CPU:            ");
    if (_cpuBool) {
        mvprintw((_height / 10) + 23, (_width / 4) - 2, "+-------------------------------------------------------+");
        mvprintw((_height / 10) + 25, (_width / 4) - 2, "+-------------------------------------------------------+");
        mvprintw((_height / 10) + 24, (_width / 4) - 2, "|");
        mvprintw((_height / 10) + 24, (_width / 4) + 54, "|");
        mvprintw((_height / 10) + 24, _width / 4, (_modelName + " " + _cpuFreq).c_str());
    }
}

void textmode::displayMemory()
{
    mvprintw((_height / 10) + 28, _width / 20, "   Memory:            ");
    if (_memoryBool) {
        mvprintw((_height / 10) + 27, (_width / 4) - 2, "+-------------------+");
        mvprintw((_height / 10) + 29, (_width / 4) - 2, "+-------------------+");
        mvprintw((_height / 10) + 28, (_width / 4) - 2, "|");
        mvprintw((_height / 10) + 28, (_width / 4) + 18, "|");
        mvprintw((_height / 10) + 28, (_width / 4) + 22, "[");
        mvprintw((_height / 10) + 28, (_width / 4) + 52, "]");
        for (int i = 0, k = 23; i <= (((std::stoi(_memory) * 100) / std::stoi(_memory_max))); i += 3, k++)
            mvprintw((_height / 10) + 28, (_width / 4) + k, "|");
        mvprintw((_height / 10) + 28, _width / 4, (_memory + "G / " + _memory_max + "G").c_str());
    }
}

void textmode::displayNetwork()
{
    mvprintw((_height / 10) + 32, _width / 20, "   Network:           ");
    if (_networkBool) {
        mvprintw((_height / 10) + 31, (_width / 4) - 2, "+----------------------------------------------+");
        mvprintw((_height / 10) + 33, (_width / 4) - 2, "+----------------------------------------------+");
        mvprintw((_height / 10) + 32, (_width / 4) - 2, "|");
        mvprintw((_height / 10) + 32, (_width / 4) + 45, "|");
        mvprintw((_height / 10) + 32, _width / 4, ("Local :" + _localAddress + " / Public " + _publicAddress).c_str());
    }
}

void textmode::displayCursor(int pos)
{
    mvprintw((_height / 10) + (pos * 4), _width / 40, "->");
}

void textmode::displayModList()
{
    displayMonitorCore();
    displayHost();
    displayUser();
    displayOS();
    displayKernel();
    displayDate();
    displayCpu();
    displayMemory();
    displayNetwork();
}

void textmode::getModules(char **env)
{
    _monitorCoreThreads = std::to_string(_monitorCoreModule.getCore()); // it is an int
    _hostName = _basicModule.getHostname();
    _userName = _basicModule.getUserName(env);
    _operatingSystem = _OS.getOsName();
    _kernel = _OS.getKernelVersion();
    _date = _timeModule.getDate();
    _upTime = _timeModule.uptime();
    _modelName = _cpuModule.getModelName();
    _cpuFreq = _cpuModule.getCpuFrequency();
    _maxCore = _cpuModule.getMaxCore();
    _memory = _ramModule.getUsedMemory();
    _memory_max = _ramModule.getMaxMemory();
    _localAddress = _networkModule.getLocalAddress();
    _publicAddress = _networkModule.getPublicAddress();
    // _macAddress = "SOME MAC ADRESS";
}

void textmode::display()
{
}

void textmode::manageHideMod()
{
    if (_cursorPos == 0)
        _MonitorCoreBool = !_MonitorCoreBool;
    if (_cursorPos == 1)
        _hostBool = !_hostBool;
    if (_cursorPos == 2)
        _userBool = !_userBool;
    if (_cursorPos == 3)
        _OSBool = !_OSBool;
    if (_cursorPos == 4)
        _kernelBool = !_kernelBool;
    if (_cursorPos == 5)
        _dateTimeBool = !_dateTimeBool;
    if (_cursorPos == 6)
        _cpuBool = !_cpuBool;
    if (_cursorPos == 7)
        _memoryBool = !_memoryBool;
    if (_cursorPos == 8)
        _networkBool = !_networkBool;
}

bool textmode::keyManagement()
{
    if ((_key = getch()) == ESC)
        return true;
    if (_key == DOWN_ARROW)
        if (_cursorPos < 8)
            _cursorPos++;
    if (_key == UP_ARROW)
        if (_cursorPos > 0)
            _cursorPos--;
    if (_key == ENTER)
        manageHideMod();
    return false;
}

void textmode::start_text_mode(char **env)
{
    clear();
    getModules(env);
    displayModList();
    while (1) {
        getModules(env);
        displayModList();
        displayCursor(_cursorPos);
        timeout(1);
        if (keyManagement())
            break;
        clear();
    }
    endwin();
}