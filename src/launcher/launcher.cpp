/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** launcher
*/

#include "launcher.hpp"

#define str "Please select a mode"
#define text "Text mode"
#define graph "Graphical mode"
#define ENTER 10
#define ESC 27
#define LEFT_ARROW KEY_LEFT
#define RIGHT_ARROW KEY_RIGHT

launcher::launcher()
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    _textMode = false;
    _graphicMode = false;
    _exitMode = false;
}

void launcher::display_launch()
{
    clear();
    mvprintw((_height/2 - _height/3), (_width/2) - (strlen(str) / 2), str);
    mvprintw(_height/2, (_width/3) - (strlen(text) / 2), text);
    mvprintw(_height/2, (_width/4) + (_width/2) - (strlen(graph)), graph);
}

void launcher::display_text_box_graph()
{
    if (_textMode) {
        mvprintw((_height/2) + 1, (_width/3) - (strlen(text)/2) - 2,"+-----------+");
        mvprintw((_height/2) - 1, (_width/3) - (strlen(text)/2) - 2,"+-----------+");
        mvprintw((_height/2), (_width/3) - (strlen(text)/2) - 2, "|");
        mvprintw((_height/2), (_width/3) - (strlen(text)/2) + 10, "|");
    }
    if (_graphicMode) {
        mvprintw((_height/2) + 1, (_width/2) + (strlen(graph) + (strlen(graph) / 2)) - 1, "+----------------+");
        mvprintw((_height/2) - 1, (_width/2) + (strlen(graph) + (strlen(graph) /2)) - 1,"+----------------+");
        mvprintw((_height/2), (_width/2) + (strlen(graph)) + 6, "|");
        mvprintw((_height/2), (_width/2) + strlen(graph) + 23, "|");
    }
}

void launcher::modeSetter(int key)
{
    if (key == LEFT_ARROW) {
        _textMode = true;
        _graphicMode = false;
    }
    if (key == RIGHT_ARROW) {
        _textMode = false;
        _graphicMode = true;
    }
}

bool launcher::esc_key_pressed(int key)
{
    if (key == ESC) {
        _exitMode = true;
        return true;
    }
    return false;
}

bool launcher::start_launch()
{
    getmaxyx(stdscr, _height, _width);
    display_launch();
    refresh();
    int key;
	while ((key = getch()) != ENTER || (!_textMode && !_graphicMode)) {
        display_launch();
        modeSetter(key);
        display_text_box_graph();
        if (esc_key_pressed(key))
            break;
    }
    endwin();
    return true;
}

std::string launcher::getLaunchMode()
{
    if (_textMode && !_exitMode)
        return "textMode";
    if (_graphicMode && !_exitMode)
        return "graphicMode";
    return "exit";
}