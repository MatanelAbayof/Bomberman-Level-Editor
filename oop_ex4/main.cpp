//------ for SFML library ------------------------------
#ifdef _DEBUG
#pragma comment ( lib , "sfml-main-d.lib" )
#pragma comment ( lib , "sfml-system-d.lib" )
#pragma comment ( lib , "sfml-window-d.lib" )
#pragma comment ( lib , "sfml-graphics-d.lib" )
#elif defined (NDEBUG)
#pragma comment ( lib , "sfml-main.lib" )
#pragma comment ( lib , "sfml-system.lib" )
#pragma comment ( lib , "sfml-window.lib" )
#pragma comment ( lib , "sfml-graphics.lib" )
#else
#error "Unrecognized configuration!"
#endif

//-------------- include section --------------
#include <iostream>
#include "EditController.h"

//-------------- using section ----------------
using std::cerr;
using std::endl;

//--------------- main ------------------------
int main()
{
	try {
		// start the editor
		EditController editController;
		editController.run();
	}
	catch (string errorMessage) {
		// Oh No! error...
		cerr << "Error: " << errorMessage << endl;
		system("pause");
	}
	return EXIT_SUCCESS;
}