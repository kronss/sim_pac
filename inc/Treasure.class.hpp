#ifndef TREASURE_CLASS_HPP
# define TREASURE_CLASS_HPP

# include "Unit.class.hpp"
# include "Pacman.class.hpp"
# include "Window.class.hpp"

// # include <string>
// # include <ncurses.h>

// #define O 40

// # define	ABS(x)	((x < 0) ? -(x) : (x))

	class Treasure : public Unit
	{
		int _status;
	public:
		
		Treasure(int i);
		~Treasure();

		int 	getStatus();
		void	resetStatus();

		void	checkColision(Pacman &obj, Window &win);

	};


#endif
