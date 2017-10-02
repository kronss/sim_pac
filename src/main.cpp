#include "main.hpp"


int		main()
{
	Window win;
	Pacman pacman;
	Ghost  blinky("Blinky", win._matrix_priority);
	// blinky.intitMatrixPriority(win._matrix_priority);
	Ghost  pinky("Pinky", win._matrix_priority);
	// pinky.intitMatrixPriority(win._matrix_priority);

	win.setIdByCord(pacman);
	win.setIdByCord(blinky);
	win.setIdByCord(pinky);



	win.printMap();
	win.pauseEvent();





	for (;;)
	{
		win.keyEvent(pacman);
		win.printMap();
	}	














	return (0);
}


