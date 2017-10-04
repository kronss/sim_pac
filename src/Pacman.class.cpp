#include "Pacman.class.hpp"

Pacman::Pacman()
{

	setID(1);
	setYX(5,5);
}

Pacman::~Pacman()
{
	;
}

int	Pacman::checkColision(Ghost &obj)
{
	if (this->getY() == obj.getY())
		if (this->getX() == obj.getX())
		{
			mvprintw(15, 50, "YOU LOSE!!!!!!!!!!");
			return (1);
		}
		return (0);
}

int Pacman::checkExitCord()
{
	if (!(getY() == 18 && getX() == 18))
	{
		return (0);
	}
	mvprintw(15, 50, "YOU WIN!!!!!!!!!!!");	
	return 1;
}
