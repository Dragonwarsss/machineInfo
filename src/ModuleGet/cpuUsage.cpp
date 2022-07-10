#include "cpuUsage.hpp"

CpuUsage::CpuUsage(int nbCore)
{
    _nbCore = nbCore;

    for (int i = 0; i != nbCore; i++) {
        _coreUsage[i].totalJiffies1 = 0;
        _coreUsage[i].totalJiffies2 = 0;
        _coreUsage[i].percentage = 0;
    }
    _timestamp = std::time(nullptr);
}

CpuUsage::~CpuUsage()
{
}

int compute_sum(std::string str, int n)
{
    int i = 0;
    std::string arr[11];
    std::stringstream ssin(str);
    int total = 0;

    while (ssin.good() && i < 11){
        ssin >> arr[i];
        ++i;
    }
    for (i = 1; i != n; i++) {
        total += stoi(arr[i]);
    }
    if (n == 3)
        total += stoi(arr[i]);
    return total;
}

float *CpuUsage::getCpuUsage()
{
    float *arr = new float[_nbCore];

    for (int i = 0; i != _nbCore; i++)
        arr[i] = _coreUsage[i].percentage;
    return arr;
}

void CpuUsage::computeUsage()
{
    std::ifstream inputFile("/proc/stat", std::ifstream::in);
    std::string tmp_str;
    time_t curr = std::time(nullptr);

    if (curr == _timestamp)
        return;
    _timestamp = curr;
    std::getline(inputFile, tmp_str); //skip total usage proc
    for (int i = 0; i != _nbCore; i++) {
        std::getline(inputFile, tmp_str);
        if (_coreUsage[i].totalJiffies1 == 0) {
            _coreUsage[i].totalJiffies1 = compute_sum(tmp_str, 11);
            _coreUsage[i].workJiffies1 = compute_sum(tmp_str, 3);
        }
        if (_coreUsage[i].totalJiffies2 == 0) {
            _coreUsage[i].totalJiffies2 = _coreUsage[i].totalJiffies1;
            _coreUsage[i].workJiffies2 = _coreUsage[i].workJiffies1;
        }
        else {
            _coreUsage[i].totalJiffies2 = _coreUsage[i].totalJiffies1;
            _coreUsage[i].workJiffies2 = _coreUsage[i].workJiffies1;
            _coreUsage[i].totalJiffies1 = compute_sum(tmp_str, 11);
            _coreUsage[i].workJiffies1 = compute_sum(tmp_str, 3);
            _coreUsage[i].workOverPeriod = _coreUsage[i].workJiffies1 - _coreUsage[i].workJiffies2;
            _coreUsage[i].totalOverPeriod = _coreUsage[i].totalJiffies1 - _coreUsage[i].totalJiffies2;
            _coreUsage[i].percentage = (float)_coreUsage[i].workOverPeriod / (float)_coreUsage[i].totalOverPeriod * 100;
        }
    }
    inputFile.close();
}