#ifndef WINDOW_CLASS_HPP
# define WINDOW_CLASS_HPP 


#include <ncurses.h>
#include <iostream>
#include <unistd.h>

#include "Unit.class.hpp"

#include "Pacman.class.hpp"



#define O 40



#define MSLEEP(msec) usleep(msec * 1000000.0)
#define SPACE 32
#define ESC 27

const int g_size = 19;

// class Unit;

class Window
{
	int _pause;
	int _game;
public:
	int _map[g_size][g_size];
	int _matrix_priority[g_size][g_size];

	Window();
	~Window();
	void	print_horizontal_line(int y, int x, int y_limit);
	void	print_vertical_line(int y, int x, int y_limit);
	void	initMap();
	void	printMap();
	void	setIdByCord(Unit &obj);
	int 	isGame();
	void	keyEvent(Pacman &obj);
	void 	pauseEvent();
	void	periodEvent();
	int 	**getMap();
};



#endif
