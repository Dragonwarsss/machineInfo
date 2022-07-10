#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

#include "IMonitorModule.hpp"
#include <vector>

class IMonitorDisplay : public IMonitorModule {
	public:
        virtual ~IMonitorDisplay() {};
        virtual void display() = 0;
	protected:
		std::string _os;
		std::string _time;
		std::string _username;
		std::string _hostname;
		std::string _cpuModelName;
		std::string _cpuFreq;
		std::string _cpuMaxCore;
		float *_cpuUsage;
};

#endif /* !IMONITORDISPLAY_HPP_ */
