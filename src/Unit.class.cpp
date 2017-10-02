#include "Unit.class.hpp"

Unit::Unit()
{
	// std::cout << "CTOR UNIT called" << std::endl;
}

Unit::~Unit()
{
	// std::cout << "CTOR UNIT called" << std::endl;
}

void	Unit::setYX(int y, int x)
{
	_cord_y = y;
	_cord_x = x;
}

int		Unit::getY()
{
	return _cord_y;
}

int		Unit::getX()
{
	return _cord_x;
}

int		Unit::getID()
{
	return _id;
}

void	Unit::setID(int id)
{
	_id = id;
}





int Unit::moveUp(int map[][19])
{
	if (getY() == 0 || map[getY() - 1][getX()] == -1)
		return 0;
	
	map[getY()][getX()] = 0;

	_cord_y -= 1;

	return (0);
}

int Unit::moveDown(int map[][19])
{
	if (getY() == 18 || map[getY() + 1][getX()] == -1)
		return 0;
	
	map[getY()][getX()] = 0;

	_cord_y += 1;

	return (0);
}

int Unit::moveLeft(int map[][19])
{
	if (getX() == 0 || map[getY()][getX() - 1] == -1)
		return 0;
	
	map[getY()][getX()] = 0;

	_cord_x -= 1;
	return (0);
}

int Unit::moveRight(int map[][19])
{
	if (getX() == 18 || map[getY()][getX() + 1] == -1)
		return 0;
	
	map[getY()][getX()] = 0;

	_cord_x += 1;
	return (0);
}














