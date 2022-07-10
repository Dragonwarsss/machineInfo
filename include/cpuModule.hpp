#include <ostream>
#include <fstream>
#include <cstring>
#include <boost/algorithm/string/replace.hpp>
#include "IMonitorModule.hpp"
#include "cpuUsage.hpp"

#ifndef CPUMODULE_HPP_
#define CPUMODULE_HPP_

class CpuModule : public IMonitorModule {
    public:
        CpuModule();
        ~CpuModule();
        std::string getModelName();
        std::string getCpuFrequency();
        std::string getMaxCore();
        float *getCpuUsage();
        void reload();
        virtual std::string getModuleName() const {return _moduleName;};
        virtual void setModuleName(const std::string& moduleName) {_moduleName = moduleName;};
        virtual void refresh() {};
    private:
        CpuUsage _cpu_use;
        std::string _modelName;
        std::string _cpuFrequency;
        std::string _maxCore;
};

#endif /* !CPUMODULE_HPP_ */
