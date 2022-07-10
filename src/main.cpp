/*
** EPITECH PROJECT, 2020
** Some Project
** File description:
** main
*/

#include <ostream>
#include "my.h"
#include "launcher.hpp"
#include "os.hpp"
#include "timeModule.hpp"
#include "basicModule.hpp"
#include "cpuModule.hpp"
#include "cpuUsage.hpp"
#include "hTop.hpp"
#include "text_mode.hpp"

using namespace std;

void print_infos(char **env)
{
    BasicModule base;
    Os os;
    CpuModule cpu;
    RamModule ram;

    cout << BLUE;
    cout << base.getUserName(env) << "@" << base.getHostname() << endl;
    cout << WHITE;
    cout << GREEN + string("OS: ") + WHITE << os.getOsName() << endl;
    cout << GREEN << "CPU: " << WHITE << cpu.getModelName() << endl;
}

int main(int ac, char **av, char **env)
{
    (void)(ac);
    (void)(av);
    if (!env[0])
        return -1;

    //try to get all comps here before

    print_infos(env);
    return 0;
}