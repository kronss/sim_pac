#ifndef PACMAN_CLASS_HPP
# define PACMAN_CLASS_HPP

# include "Unit.class.hpp"
# include "Ghost.class.hpp"
# include <ncurses.h>


	class Ghost;

	class Pacman : public Unit
	{
	public:
		Pacman();
		~Pacman();
		

		int	checkColision(Ghost &obj);
		int checkExitCord();


	};


#endif
