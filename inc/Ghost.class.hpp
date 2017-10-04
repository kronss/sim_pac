#ifndef GHOST_CLASS_HPP
# define GHOST_CLASS_HPP

# include "Unit.class.hpp"
# include "Pacman.class.hpp"

# include <string>
# include <ncurses.h>

#define O 40

# define	ABS(x)	((x < 0) ? -(x) : (x))

class Pacman;

	class Ghost : public Unit
	{

	public:
		int matrix[19][19];



		Ghost(std::string std, int map[][19]);
		~Ghost();
		
		// void	intitMatrixPriority(int map[][19]);
		
		void	makeStep(Window &win, Pacman &pacman, int map[][19], int &sleep);

	};


#endif
