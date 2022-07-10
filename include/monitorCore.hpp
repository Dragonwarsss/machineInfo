#include <thread>
#include "IMonitorModule.hpp"

#ifndef MONITORCORE_HPP_
#define MONITORCORE_HPP_

class MonitorCore : public IMonitorModule {
    public:
        MonitorCore();
        ~MonitorCore();
        int getCore() {_threads = std::thread::hardware_concurrency(); return _threads;};
        virtual std::string getModuleName() const {return _moduleName;};
        virtual void setModuleName(const std::string& moduleName) {_moduleName = moduleName;};
        virtual void refresh() {};
    private:
        int _threads;
};

#endif /* !MONITORCORE_HPP_ */
