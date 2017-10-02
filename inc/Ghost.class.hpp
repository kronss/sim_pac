#ifndef GHOST_CLASS_HPP
# define GHOST_CLASS_HPP

# include "Unit.class.hpp"
# include <string>


class Pacman;

	class Ghost : public Unit
	{

	public:
		int matrix[19][19];
		Ghost(std::string std, int map[][19]);
		~Ghost();
		
		// void	intitMatrixPriority(int map[][19]);
		
		void	makeStep(Pacman &pacman, int map[][19]);

	};


#endif
