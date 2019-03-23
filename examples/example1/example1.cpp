/** Creating a basic window using FenixEngine
 *
 * The goal is to create a very basic window using the FenixEngine
 * with a scene and waits for the user to close the window.
 */

#include <FenixEngine/FenixEngine.h>

#define WIN_WIDTH 640
#define WIN_HEIGHT 480

int
main(int argc, char **argv)
{
	Window win(WIN_WIDTH, WIN_HEIGHT, "Example1");
	Scene scene;
	EventController controller;

	scene.setRenderer(win.getRenderer());
	scene.evController = &controller;
	win.start();

	return 0;
}
