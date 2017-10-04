#ifndef UNIT_CLASS_HPP
# define UNIT_CLASS_HPP

# include <iostream>
// # include "Window.class.hpp"

// #ifndef 
#define O 40


class Window;

class Unit
{
public:
	int _cord_y;
	int _cord_x;
	int _id;
	int _direction;


	Unit();
	~Unit();
	

	void setYX(int y, int x);
	int  getY();
	int  getX();
	void setID(int id);
	int  getID();



	int  moveUp(int map[][19]);
	int  moveDown(int map[][19]);
	int  moveLeft(int map[][19]);
	int  moveRight(int map[][19]);
};

#endif
