/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** hTop
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "cpuModule.hpp"

#ifndef HTOP_HPP_
#define HTOP_HPP_

typedef struct
{
    sf::Sprite *sprite;
    sf::Texture *texture;
    sf::Vector2f pos;
    sf::IntRect rect;
} data_t;

typedef struct {
    sf::RectangleShape rectangle;
    sf::Font arial;
    sf::Text coreinfo;
} font_t;

typedef struct
{
    sf::RenderWindow *body;
    font_t *fontinfo;
    sf::Sprite bg;
} sprite_t;



class hTop
{
public:
    hTop();
    void core_disp(char**, sf::RenderWindow*, font_t*, CpuModule);
    void CPU_usage(sf::RenderWindow *window, CpuModule*, font_t*);
    void os_info(sf::RenderWindow*, font_t*);
    ~hTop();
};

int graphicalhTop(char **env);
font_t *createHUnames();
sf::RectangleShape *progress_bar(float posx, float posy, float size);

#endif /* !HTOP_HPP_ */
