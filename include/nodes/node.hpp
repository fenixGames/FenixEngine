/**
 * Nodes are everything that forms part of a scene.
 * It can be a light, a character, a npc or a camera.
 */

#ifndef NODE_HPP
#define NODE_HPP

#include <mutex>
#include <list>

#include <physics/geometry.hpp>
#include <graphics/graphic.hpp>
#include <os.hpp>

/** Representation of a game object.
 */
class BasicNode {
protected:
	Graphic * graphicResource; // <* The graphical resource associated.
	Point position; // <* Position of the object on the world.
	Size size; // <* Size of the object.

	/* A node uses relative coordinates, 
	   so we need to keep track of the ancestory to
	   calculate the absolute coordinates.
	 */
	BasicNode * parent; // <* Parent node.
	std::list<BasicNode *> children; // <* List of depending nodes.
public:

	/** Creates an object of size 0 x 0 in the position (0, 0)
	 */
	BasicNode();

	/**Creates an object of the size `size` in the position `position`.
	 * \param position The position of the new object.
	 * \param size The size of the object to create.
	 */
	BasicNode(const Point& position, const Size& size);

	/** Sets the position of the object to a new place.
	 * \param position The new position of the node.
	 */
	void setPosition(const Point& position);

	/** Resizes the object.
	 * \param size The new size of the object.
	 */
	void setSize(const Size& size);

	/** Retrieves the texture from the graphical resource associated to the node.
	 * \return The Texture belonging to the attached graphical resource.
	 */
	SDL_Texture * getTexture();

	/** Sets the graphical resource of the node.
	 * \param resource The graphical resource to attach to the node.
	 */
	void setGraphicResource(Graphic *resource);

	/** Retrieves the position and size and stores them in rect.
	 * \param rect The rectangle to fill with the node information.
	 */
	void fillDimentions(SDL_Rect *rect);

	/** Appends a child to the node.
	 * \param child The child to append to the node.
	 */
	void addChild(BasicNode * node);

	/** Retrieves the list of children of the node.
	 * \return The list of children of the node.
	 */
	std::list<BasicNode *> * getChildren();

	/** A virtual function to allow the node to perform actions on itself after printing.
	 */
	virtual void act() = 0;
};

class Node: public BasicNode {
public:
	Node();
	Node(const Point& position, const Size& size);
	virtual void act();
};

#endif
