#include <iostream>
#include <sys/utsname.h>
#include "IMonitorModule.hpp"

#ifndef OS_HPP_
#define OS_HPP_

class Os : public IMonitorModule {
    public:
        Os();
        virtual ~Os();
        std::string getOsName();
        std::string getKernelVersion();
        virtual std::string getModuleName() const {return _moduleName;};
        virtual void setModuleName(const std::string& moduleName) {_moduleName = moduleName;};
        virtual void refresh() {};
    private:
        void getOsNamePrivate(void);
        std::string _osName;
        std::string _kernelVersion;
};

#endif /* !OS_HPP_ */
