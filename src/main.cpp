#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <ctime>
#include "my.h"
#include "os.hpp"
#include "timeModule.hpp"
#include "basicModule.hpp"
#include "cpuModule.hpp"
#include "cpuUsage.hpp"
#include "ramModule.hpp"

using namespace std;

string get_current_time() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_time), "%H:%M:%S");
    return ss.str();
}

void print_system_infos(char **env) {
    BasicModule base;
    Os os;
    CpuModule cpu;
    
    cout << BLUE << "=== SYSTEM INFORMATION ===" << WHITE << endl;
    cout << BLUE << base.getUserName(env) << "@" << base.getHostname() << WHITE << endl;
    cout << GREEN << "OS: " << WHITE << os.getOsName() << endl;
    cout << GREEN << "CPU: " << WHITE << cpu.getModelName() << endl;
    cout << endl;
}

void display_resources_usage(CpuUsage &cpuUsage, RamModule &ramModule, int iterations) {
    cout << BLUE << "=== RESOURCE MONITORING ===" << WHITE << endl;
    cout << "Monitoring for " << iterations << " seconds, refresh rate: 1 second" << endl << endl;
    
    cpuUsage.refresh();
    ramModule.refresh();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    for (int i = 0; i < iterations; i++) {
        cpuUsage.refresh();
        ramModule.refresh();
        
        cout << BLUE << "[" << get_current_time() << "]" << WHITE << endl;
        cout << GREEN << "RAM Usage: " << WHITE << ramModule.getUsedMemory() << " / " 
             << ramModule.getMaxMemory() << " GB" << endl;
        
        float *usage = cpuUsage.getCpuUsage();
        cout << GREEN << "CPU Usage: " << WHITE;
        for (int j = 0; j < cpuUsage.getNumberOfCores(); j++) {
            cout << "Core " << j << ": " << fixed << setprecision(1) << usage[j] << "% ";
        }
        cout << endl;
        cout << "------------------------------------------------" << endl;
        
        delete[] usage;
        
        if (i < iterations - 1)
            std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main(int ac, char **av, char **env) {
    (void)(ac);
    (void)(av);
    if (!env[0])
        return -1;
    
    int monitoringDuration = 10;
    if (ac > 1) {
        try {
            monitoringDuration = std::stoi(av[1]);
            if (monitoringDuration <= 0) {
                monitoringDuration = 10;
            }
        } catch (...) {}
    }
    
    print_system_infos(env);
    
    int nbCores = 4;
    CpuUsage cpuUsage(nbCores);
    cpuUsage.setModuleName("CPU Usage Monitor");
    
    RamModule ramModule;
    ramModule.setModuleName("RAM Usage Monitor");
    
    display_resources_usage(cpuUsage, ramModule, monitoringDuration);
    
    return 0;
}