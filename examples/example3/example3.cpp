/** Creating a basic window using FenixEngine
 *
 * The goal is to create a very basic window using the FenixEngine
 * with a scene, and two viewports, one with an image and the other
 * with a yellow filled rectangle. Then it waits for the user to close
 * the window.
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
	Viewport mainViewport(Vector(0, 0), Size(WIN_WIDTH, WIN_HEIGHT), win.getRenderer());
	Viewport secondaryViewport(
		Vector(WIN_WIDTH - 100.0, WIN_HEIGHT - 100.0),
		Size(100, 100), win.getRenderer());
	Sprite sprite(EXAMPLE_SPRITE_PATH, Color(0xFFFFFF), win.getRenderer());
	Node node(Vector(0, 0));
	FilledRect rect(
		Color(0xFFFF00),
		Size(100, 100),
		0xFFFFFF, 
		win.getRenderer()
	);
	Node rectNode(Vector(WIN_WIDTH - 100.0, WIN_HEIGHT - 100.0));

	node.addGameComponent(&sprite);
	rectNode.addGameComponent((GameComponent *)&rect);

	controller.addEventHandler(new QuitHandler());

	scene.setRenderer(win.getRenderer());
	scene.evController = &controller;
	scene.addViewport(&mainViewport);
	scene.addViewport(&secondaryViewport);

	mainViewport.nodes.push_back(&node);
	secondaryViewport.nodes.push_back(&rectNode);
	win.sceneList.push_back(&scene);
	win.start();

	return 0;
}
