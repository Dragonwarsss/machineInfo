#include <ostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include "IMonitorModule.hpp"

#ifndef CPUUSAGE_HPP_
#define CPUUSAGE_HPP_

struct core {
    int totalJiffies1;
    int totalJiffies2;
    int workJiffies1;
    int workJiffies2;
    int workOverPeriod;
    int totalOverPeriod;
    float percentage;
};

class CpuUsage : public IMonitorModule {
    public:
        CpuUsage() {_nbCore = 4;};
        CpuUsage(int nbcore);
        ~CpuUsage();
        void computeUsage();
        float *getCpuUsage();
        virtual std::string getModuleName() const {return _moduleName;};
        virtual void setModuleName(const std::string& moduleName) {_moduleName = moduleName;};
        virtual void refresh() override;
        int getNumberOfCores() const { return _nbCore; }
    private:
        int _nbCore;
        core _coreUsage[4];
        time_t _timestamp;
};

#endif /* !CPUUSAGE_HPP_ */
