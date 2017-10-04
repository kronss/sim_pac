#include "main.hpp"


int		main()
{
	Window win;
	Pacman pacman;
	Ghost  blinky("Blinky", win._matrix_priority);
	Ghost  pinky("Pinky", win._matrix_priority);
	Treasure treasure1(1);
	Treasure treasure2(2);
	Treasure treasure3(3);


	win.setIdByCord(pacman);
	win.setIdByCord(blinky);
	win.setIdByCord(pinky);


	win.setIdByCord(treasure1);
	win.setIdByCord(treasure2);
	win.setIdByCord(treasure3);

	win.printMap();

	int delayBlinky = 5;		
	int delayPinky = -500;

	while ( !pacman.checkColision(blinky)
			&& !pacman.checkColision(pinky) 
			&& !pacman.checkExitCord() )
	{

		win.keyEvent(pacman);

		treasure1.checkColision(pacman, win);
		treasure2.checkColision(pacman, win);
		treasure3.checkColision(pacman, win);

		blinky.makeStep(win, pacman, win._map, delayBlinky);
		win.setIdByCord(blinky);

		pinky.makeStep(win, pacman, win._map, delayPinky);
		win.setIdByCord(pinky);

		win.printMap();
	}	
	return (0);
}
