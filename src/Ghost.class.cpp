#include "Ghost.class.hpp"

Ghost::Ghost(std::string str, int tmp[][19])
{
	if (str == "Blinky")
	{
		setID(2);
		setYX(13,10);
	}
	else if (str == "Pinky")
	{
		setID(3);
		setYX(15,11);
	}
	for (int j = 0; j < 19; ++j)
	{
		for (int i = 0; i < 19; ++i)
		{
			matrix[j][i] = tmp[j][i];
		}
	}
}


Ghost::~Ghost()
{
	;
}

void	Ghost::makeStep(Pacman &pacman, int map[][19])
{
//reset matrix

	for (register int j = 0; j < 19; ++j)
	{
		for (register int i = 0; i < 19; ++i)
		{
			if (matrix[j][i] == -1)
				continue ;
			matrix[j][i] = O;
		}
	}
	int y = pacman.getY();
	int x = pacman.getX();
	int tmp;

	matrix[y][x] = 0; // set main target

//build matrix
	for (register int j = 0; j < 19; ++j)
	{
		for (register int i = 0, ii =0; i < 19; ++i, ii +=4)
		{
			if (matrix[j][i] == -1)
				continue ;
			tmp = ABS(j - y) + ABS(i - x);
			if (tmp < matrix[j][i])
				matrix[j][i] = tmp;


mvprintw(j + 1 , ii + 50, "[%2.2d]", matrix[j][i]); //debug


		}
	}
}
