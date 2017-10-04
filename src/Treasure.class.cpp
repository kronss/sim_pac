#include "Treasure.class.hpp"

Treasure::Treasure(int id) : _status(1)
{
	if (id == 1)
	{
		setID(0);
		setYX(2,1);	
	}
	else if (id == 2)
	{
		setID(0);
		setYX(2,5);
	}
	else if (id == 3)
	{
		setID(0);
		setYX(17,10);
	}
}

Treasure::~Treasure()
{

}

int  Treasure::getStatus()
{
	return _status;
}


void Treasure::resetStatus()
{
	_status = 0;
}

void Treasure::checkColision(Pacman &obj, Window &win)
{
	if (this->getY() == obj.getY())
		if (this->getX() == obj.getX())
			resetStatus();
	
	if (_status)
	{
		win.setIdByCord(*this);
	}
}
