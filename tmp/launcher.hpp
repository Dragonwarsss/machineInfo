/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** true_launcher
*/

#ifndef TRUE_LAUNCHER_HPP_
#define TRUE_LAUNCHER_HPP_

#include <string.h>
#include <ncurses.h>
#include <signal.h>
#include "my.h"

class launcher {
public:
    launcher();
    ~launcher() {};
    bool start_launch();
    std::string getLaunchMode();
private:
    void display_launch();
    void display_text_box_graph();
    void modeSetter(int key);
    bool esc_key_pressed(int key);
    bool _textMode;
    bool _graphicMode;
    bool _exitMode;
    int _height;
    int _width;
    WINDOW *_text;
    WINDOW *_graph;
};

#endif /* !TRUE_LAUNCHER_HPP_ */