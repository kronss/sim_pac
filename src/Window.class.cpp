#include "Window.class.hpp"

Window::Window() : _game(1), _pause(1)
{
	initscr();
	curs_set(0);
	noecho();
	refresh();


//create color pair
	start_color();
	init_pair(32, COLOR_WHITE, COLOR_BLACK);
	init_pair(33, 16, 16);
	init_pair(34, 241, 241);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, 242, COLOR_BLACK);
	init_pair(9, COLOR_BLACK, COLOR_GREEN);
	init_pair(10, COLOR_BLACK, COLOR_BLUE);
	init_pair(11, COLOR_BLACK, COLOR_RED);
	init_pair(12, COLOR_BLACK, COLOR_CYAN);
	init_pair(13, 240, 240);


//print border line
	print_horizontal_line(0, 0, 40);
	print_horizontal_line(20, 0, 40);
	print_vertical_line(0, 0, 20);
	print_vertical_line(0, 39, 20);
	this->initMap();

	// std::cout << "CTOR" << std::endl;
}


Window::~Window()
{
	getch();
	endwin();

	std::cout << "DTOR" << std::endl;

}


void	Window::print_horizontal_line(int y, int x, int x_limit)
{
	attron(COLOR_PAIR(34));
	while (x < x_limit)
	{
		mvprintw(y, x, "*");
		++x;
	}
	attroff(COLOR_PAIR(34));
}
void	Window::print_vertical_line(int y, int x, int y_limit)
{	
	attron(COLOR_PAIR(34));
	while (y < y_limit)
	{
		mvprintw(y, x, "*");
		++y;
	}
	attroff(COLOR_PAIR(34));

}


void	Window::initMap()
{
	int tmp[g_size][g_size] = {
		{O ,O ,O ,O ,O ,O ,O ,O ,-1,O ,O ,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,-1,O ,-1,-1,-1,-1,-1,-1,-1,-1,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,-1,O ,-1,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,-1,O ,-1,O ,-1,-1,-1,-1,-1,-1,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,-1,O ,-1,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,-1,O ,O ,O ,O ,O }
	};

	for (int j = 0; j < g_size; ++j)
	{
		for (int i = 0; i < g_size; ++i)
		{
			_map[j][i] = tmp[j][i];
		}
	}

		/* init matrix priority */
	for (int j = 0; j < g_size; ++j)
	{
		for (int i = 0; i < g_size; ++i)
		{
			if (tmp[j][i] == -1)
				_matrix_priority[j][i] = -1;
			else
				_matrix_priority[j][i] = 0;
		}
	}
}


int		Window::isGame()
{
	return _game;
}


void	Window::printMap()
{
	mvprintw(g_size + 5, 0, "dick\n");
	for (int j = 0, y = 1; j < g_size; ++j, ++y)
	{
		for (int i = 0, x = 1; i < g_size; ++i, x+=2)
		{
			int color = _map[j][i];
			if (color == 1)
				attron(A_BOLD);
			{
				attron(COLOR_PAIR(color));

				mvprintw(y, x, "%2.2hhd", color);

				attroff(COLOR_PAIR(color));
			}
			if (color == 1)
				attroff(A_BOLD);
		}
	}
}

void	Window::setIdByCord(Unit &obj)
{
	_map[obj.getY()][obj.getX()] = obj.getID(); 

}


void		Window::keyEvent(Pacman &obj)
{
	int key;

		key = getch();
		if (key == ERR)
		{
			return (pauseEvent());
		}
		else if (key == 'w')
		{
			obj.moveUp(_map);
			setIdByCord(obj);
		}
		else if (key == 's')
		{
			obj.moveDown(_map);
			setIdByCord(obj);
		}	
		else if (key == 'a')
		{
			obj.moveLeft(_map);
			setIdByCord(obj);
		}
		else if (key == 'd')
		{
			obj.moveRight(_map);
			setIdByCord(obj);
		}	
		else if (key == SPACE)
			_pause ^= 1;

		mvprintw(g_size + 7, 0, "%d\n", key);

		// else if (key == ESC)
		// 	return ;

		periodEvent();
}



void		Window::pauseEvent()
{
	int key;

	while (_pause == 1)
	{
									mvprintw(g_size + 10, 0, "pause == %d\n", _pause); //
		nodelay(stdscr, FALSE);
		key = getch();
		mvprintw(g_size + 7, 0, "%d\n", key);
		if (key == SPACE)
		{
			_pause ^= 1;		
		}
		// else if (key == 's')
		// 	break ;
		// else if (key == 'q')
		// 	viz->hz -= 10;
		// else if (key == 'w')
		// 	viz->hz -= 1;
		// else if (key == 'e')
		// 	viz->hz += 1;
		// else if (key == 'r')
		// 	viz->hz += 10;
		// else if (key == ESC)
		// 	return ;
		// ((int)viz->hz < 5) ? viz->hz = 5 : 0;
		// ((int)viz->hz > 1000) ? viz->hz = 1000 : 0;
	}
	periodEvent();
}

void		Window::periodEvent()
{
	double	period;

	nodelay(stdscr, TRUE);
									mvprintw(g_size + 10, 0, "pause == %d\n", _pause); //
	period = (1 / 50);
	MSLEEP(period);
}

int **Window::getMap()
{
	return (int **)_map;
}
