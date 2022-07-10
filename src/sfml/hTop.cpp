/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2018
** File description:
** hTop
*/

#include <iostream>
#include "hTop.hpp"
#include "cpuModule.hpp"
#include "ramModule.hpp"
#include "timeModule.hpp"
#include "networkModule.hpp"
#include "../../include/basicModule.hpp"

hTop::hTop()
{
}

hTop::~hTop()
{
}

sf::RenderWindow *init_window()
{
    sf::RenderWindow *window = new sf::RenderWindow();
    window->create(sf::VideoMode(1920, 1080), "My window");
    window->setPosition(sf::Vector2i(10, 50));
    window->setSize(sf::Vector2u(640, 480));
    window->setTitle("hTop");
    window->clear(sf::Color::Black);
    window->setFramerateLimit(30);
    window->display();
    return window;
}

sf::Sprite create_sprite(const std::string &path, float x, float y)
{
    sf::Sprite sprite;
    sf::Texture *texture = new sf::Texture();

    texture->loadFromFile(path);
    sprite.setPosition(x, y);
    sprite.setTexture(*texture);
    return (sprite);
}

sprite_t init_values()
{
    sprite_t objet;
    objet.bg = create_sprite("src/sfml/bg.jpg", 0, 0);
    objet.fontinfo = createHUnames();
    return objet;
}

void display_ram(sf::RenderWindow *window, font_t *fontinfo, RamModule ram)
{
    fontinfo->coreinfo.setString("Memory usage: " + ram.getUsedMemory() + "G / " + ram.getMaxMemory() + "G");
    fontinfo->coreinfo.setPosition(10, 165);
    window->draw(fontinfo->coreinfo);
}

void display_date(sf::RenderWindow *window, font_t *fontinfo, TimeModule time)
{
    fontinfo->coreinfo.setString(time.getDate());
    fontinfo->coreinfo.setPosition(10, 190);
    window->draw(fontinfo->coreinfo);
    fontinfo->coreinfo.setString("Uptime: " + time.uptime());
    fontinfo->coreinfo.setPosition(250, 190);
    window->draw(fontinfo->coreinfo);
}

void display_network(sf::RenderWindow *window, font_t *fontinfo, NetworkModule net)
{
    std::string str = "Network: Local " + net.getLocalAddress() + " / Public " + net.getPublicAddress();
    fontinfo->coreinfo.setString(str);
    fontinfo->coreinfo.setPosition(10, 215);
    window->draw(fontinfo->coreinfo);
}

int graphicalhTop(char **env)
{
    sf::RenderWindow *window = init_window();
    sprite_t objet = init_values();
    hTop top;
    CpuModule CPUinfo;
    RamModule ram;
    TimeModule time;
    NetworkModule net;

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        CPUinfo.reload();
        window->draw(objet.bg);
        top.core_disp(env, window, objet.fontinfo, CPUinfo);
        display_ram(window, objet.fontinfo, ram);
        display_date(window, objet.fontinfo, time);
        display_network(window, objet.fontinfo, net);
        window->display();
        window->clear(sf::Color::White);
    }
    return 0;
}
