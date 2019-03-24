/** Creating a basic window using FenixEngine
 *
 * The goal is to create a very basic window using the FenixEngine
 * with a scene, present an image and waits for the user to close the window.
 */

#include <FenixEngine/FenixEngine.h>

#define WIN_WIDTH 640
#define WIN_HEIGHT 480
#define EXAMPLE_SPRITE_PATH "resources/hello-world.png"


int
main(int argc, char **argv)
{
	Window win(WIN_WIDTH, WIN_HEIGHT, "Example2");
	Scene scene;
	EventController controller;
	Viewport viewport(Vector(0, 0), Size(WIN_WIDTH, WIN_HEIGHT), win.getRenderer());
	Sprite sprite(EXAMPLE_SPRITE_PATH, Color(0xFFFFFF), win.getRenderer());
	Node node(Vector(0, 0));

	node.setGraphicResource(&sprite);
	controller.addEventHandler(new QuitHandler());
	scene.setRenderer(win.getRenderer());
	scene.evController = &controller;
	scene.addViewport(&viewport);
	viewport.nodes.push_back(&node);
	win.sceneList.push_back(&scene);
	win.start();

	return 0;
}
