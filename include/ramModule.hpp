/*
** EPITECH PROJECT, 2020
** htop
** File description:
** ramModule
*/

#include "IMonitorModule.hpp"

#ifndef RAMMODULE_HPP_
#define RAMMODULE_HPP_

class RamModule : public IMonitorModule {
    public:
    RamModule();
    ~RamModule();
    void getMemoryInfo();
    std::string getMemory();
    std::string getMaxMemory();
    std::string getUsedMemory();
        virtual std::string getModuleName() const {return _moduleName;};
        virtual void setModuleName(const std::string& moduleName) {_moduleName = moduleName;};
        virtual void refresh() {};
    private:
        float _totalMemory;
        float _usedMemory;
};

#endif /* !RAMMODULE_HPP_ */
