#include "Ghost.class.hpp"

Ghost::Ghost(std::string str, int map[][19])
{
	if (str == "Blinky")
	{
		setID(2);
		setYX(13,10);
	}
	if (str == "Pinky")
	{
		setID(3);
		setYX(15,11);
	}




	for (int j = 0; j < 19; ++j)
	{
		for (int i = 0; i < 19; ++i)
		{
			matrix[j][i] = map[j][i];
		}
	}





}


Ghost::~Ghost()
{
	;
}














void	Ghost::makeStep(Pacman &pacman, int map[][19])
{
	priority[pacman.getY()][pacman.getX()] = 0;


	for (register int j = 0; j < count; ++j)
	{
		for (register int i = 0; i < count; ++i)
		{
			if (map[j][i] != )
			{
				tmp = ABS(j - y) + ABS(i - x);
				block->priority[j][i] = ft_min(tmp, block->priority[j][i]);
			}
		}
	}
}
