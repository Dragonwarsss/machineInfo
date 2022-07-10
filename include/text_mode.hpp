/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** text_mode
*/

#ifndef TEXT_MODE_HPP_
#define TEXT_MODE_HPP_

#include "os.hpp"
#include "timeModule.hpp"
#include "basicModule.hpp"
#include "cpuModule.hpp"
#include "cpuUsage.hpp"
#include "ramModule.hpp"
#include "networkModule.hpp"
#include "IMonitorDisplay.hpp"
#include "monitorCore.hpp"
#include <ncurses.h>

class textmode : public IMonitorDisplay {
public:
    textmode();
    virtual ~textmode() {};
    void display();
    std::string getModuleName() const { return nullptr; };
    void setModuleName(const std::string &moduleName) { (void)(moduleName); };
    void refresh() {};
    void start_text_mode(char **env);
protected:
private:
    void displayModList();
    void displayCursor(int pos);
    void displayMonitorCore();
    void displayHost();
    void displayUser();
    void displayOS();
    void displayKernel();
    void displayDate();
    void displayMemory();
    void displayCpu();
    void displayNetwork();
    void getModules(char **env);
    void manageHideMod();
    bool keyManagement();
    int _height;
    int _width;
    int _key;
    int _cursorPos;
    BasicModule _basicModule;
    Os _OS;
    TimeModule _timeModule;
    CpuModule _cpuModule;
    CpuUsage _cpuUsage;
    RamModule _ramModule;
    NetworkModule _networkModule;
    MonitorCore _monitorCoreModule;

    bool _MonitorCoreBool;
    bool _hostBool;
    bool _userBool;
    bool _OSBool;
    bool _kernelBool;
    bool _dateTimeBool;
    bool _cpuBool;
    bool _memoryBool;
    bool _networkBool;

    std::string _monitorCoreThreads;
    std::string _hostName;
    std::string _userName;
    std::string _operatingSystem;
    std::string _kernel;
    std::string _date;
    std::string _upTime;
    std::string _modelName;
    std::string _maxCore;
    std::string _cpuFreq;
    std::string _memory;
    std::string _memory_max;
    std::string _localAddress;
    std::string _publicAddress;
    std::string _macAddress;
};

#endif /* !TEXT_MODE_HPP_ */