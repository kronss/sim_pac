#include "Window.class.hpp"

Window::Window() : _pause(1), _game(1)
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
	mvprintw(19, 39, "<--- exit there");

	attron(COLOR_PAIR(1));
	mvprintw(22, 2, "01 - pacman");
	attron(COLOR_PAIR(2));
	mvprintw(23, 2, "02 - ghost1");
	attron(COLOR_PAIR(3));
	mvprintw(24, 2, "03 - ghost2, waiting for a few seconds");
	attroff(COLOR_PAIR(3));
	mvprintw(25, 2, "00 - treasure, give You no point)");

	mvprintw(27, 12, "'w' - step up");
	mvprintw(28, 12, "'s' - step down");
	mvprintw(29, 12, "'a' - step left");
	mvprintw(30, 12, "'d' - step right");

	mvprintw(32, 12, "'SPACE' - PAUSE");	

	this->initMap();
}


Window::~Window()
{
	nodelay(stdscr, FALSE);
	getch();
	endwin();
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
		{O ,-1,-1,-1,-1,-1,-1,-1,O ,O ,O ,-1,-1,-1,-1,-1,-1,-1,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,-1,O ,O ,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,-1,O ,O ,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,-1,O ,O ,-1,-1,-1,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,-1,O ,O ,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,-1,O ,O ,O ,O ,O ,O ,O ,O ,O ,O },
		{O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,O ,-1,-1,-1},
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
	//TODO rebuild matrix
}


int		Window::isGame()
{
	return _game;
}


void	Window::printMap()
{
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
			
		}
		else if (key == 's')
		{
			obj.moveDown(_map);
		}	
		else if (key == 'a')
		{
			obj.moveLeft(_map);
		}
		else if (key == 'd')
		{
			obj.moveRight(_map);
		}	
		else if (key == SPACE)
			_pause ^= 1;

		setIdByCord(obj);
		periodEvent();
}



void		Window::pauseEvent()
{
	int key;

	while (_pause == 1)
	{
		nodelay(stdscr, FALSE);
		key = getch();
		// mvprintw(g_size + 7, 0, "%d\n", key);
		if (key == SPACE)
		{
			_pause ^= 1;		
		}
	}
	periodEvent();
}

void		Window::periodEvent()
{
	double	period;

	nodelay(stdscr, TRUE);
	period = (1.0 / 50.0);
	MSLEEP(period);
}

int **Window::getMap()
{
	return (int **)_map;
}
