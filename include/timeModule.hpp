#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <ostream>
#include <fstream>
#include <iomanip>
#include "IMonitorModule.hpp"

#ifndef TIMEMODULE_HPP_
#define TIMEMODULE_HPP_

class TimeModule : public IMonitorModule {
    public:
        TimeModule();
        virtual ~TimeModule();
        std::string getDate();
        std::string getTime();
        std::string uptime();
        virtual std::string getModuleName() const {return _moduleName;};
        virtual void setModuleName(const std::string& moduleName) {_moduleName = moduleName;};
        virtual void refresh() {};
};

#endif /* !TIMEMODULE_HPP_ */
