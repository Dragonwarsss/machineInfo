/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** modules
*/

#include "../../include/basicModule.hpp"
#include <sstream>
#include <fstream>
#include <iomanip>
#include "hTop.hpp"
#include "os.hpp"

font_t *createHUnames()
{
    sf::RectangleShape _rectangle(sf::Vector2f(350.f, 22.f));
    font_t *fontinfo = new font_t();

    fontinfo->rectangle.setFillColor(sf::Color(80, 80, 80));
    fontinfo->rectangle.setPosition(8, 11);
    fontinfo->arial.loadFromFile("src/sfml/arial.ttf");
    fontinfo->coreinfo.setFont(fontinfo->arial);
    fontinfo->coreinfo.setFillColor(sf::Color::White);
    fontinfo->coreinfo.setCharacterSize(18);
    fontinfo->coreinfo.setPosition(10, 10);
    return fontinfo;
}

void hTop::os_info(sf::RenderWindow *window, font_t *info)
{
    Os *osinfo = new Os();
    std::string to_disp = "operating system: " + osinfo->getOsName() + " kernel: "
                            + osinfo->getKernelVersion();

    info->coreinfo.setPosition(10, 10);
    info->coreinfo.setString(to_disp);
    info->coreinfo.setPosition(10, 40);
    window->draw(info->coreinfo);
}

void hTop::core_disp(char **env, sf::RenderWindow *window, font_t *infos, CpuModule CPUinfo)
{
    BasicModule envinfo;
    std::string to_disp = "HostName: " + envinfo.getHostname() + " username: "
                            + envinfo.getUserName(env);

    infos->coreinfo.setPosition(10, 10);
    infos->coreinfo.setString(to_disp);
    window->draw(infos->coreinfo);
    infos->coreinfo.setPosition(380, 10);
    to_disp = "CPU: " + CPUinfo.getModelName() + " frequency: "
    + CPUinfo.getCpuFrequency() + " max core: " + CPUinfo.getMaxCore();
    infos->coreinfo.setString(to_disp);
    window->draw(infos->coreinfo);
    CPU_usage(window, &CPUinfo, infos);
    os_info(window, infos);
}

sf::RectangleShape *progress_bar(float posx, float posy, float size)
{
    sf::RectangleShape *progbar = new sf::RectangleShape();

    progbar->setPosition(posx, posy);
    progbar->setFillColor(sf::Color::Green);
    progbar->setSize(sf::Vector2f(size, 22.f));
    return progbar;
}

void hTop::CPU_usage(sf::RenderWindow *window, CpuModule *CPUinfo, font_t *fontinfo)
{
    float *CPUcore;
    std::ostringstream stream0;
    std::ostringstream stream1;
    std::ostringstream stream2;
    std::ostringstream stream3;
    sf::RectangleShape *info_bar = new sf::RectangleShape;

    CPUcore = CPUinfo->getCpuUsage();
    stream0 << std::setprecision(4) << CPUcore[0];
    fontinfo->coreinfo.setString("cpu0: " + stream0.str() + "%");
    fontinfo->coreinfo.setPosition(10, 80);
    window->draw(fontinfo->coreinfo);
    info_bar = progress_bar(200, 80, (CPUcore[0] * 10));
    window->draw(*info_bar);
    stream1 << std::setprecision(4) << CPUcore[1];
    fontinfo->coreinfo.setString("cpu1: " + stream1.str() + "%");
    fontinfo->coreinfo.setPosition(10, 100);
    window->draw(fontinfo->coreinfo);
    info_bar = progress_bar(200, 100, (CPUcore[1] * 10));
    window->draw(*info_bar);
    stream2 << std::setprecision(4) << CPUcore[2];
    fontinfo->coreinfo.setString("cpu2: " + stream2.str() + "%");
    fontinfo->coreinfo.setPosition(10, 120);
    window->draw(fontinfo->coreinfo);
    info_bar = progress_bar(200, 120, (CPUcore[2] * 10));
    window->draw(*info_bar);
    stream3 << std::setprecision(4) << CPUcore[3];
    fontinfo->coreinfo.setString("cpu3: " + stream3.str() + "%");
    fontinfo->coreinfo.setPosition(10, 140);
    window->draw(fontinfo->coreinfo);
    info_bar = progress_bar(200, 140, (CPUcore[3] * 10));
    window->draw(*info_bar);
}