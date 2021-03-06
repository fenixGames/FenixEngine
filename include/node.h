/**
 * Nodes are everything that forms part of a scene.
 * It can be a light, a character, a npc or a camera.
 */

#ifndef NODE_HPP
#define NODE_HPP

#include <mutex>
#include <list>

#ifndef FENIX_ENGINE_H
#include <geometry.h>
#include <graphic.h>
#include <os.h>
#include <game_component.h>
#endif

/** Representation of a game object.
 */
class BasicNode {
protected:
	std::list<GameComponent *> components; // <* List of game components.

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

	/**Creates an object in the position `position`.
	 * \param position The position of the new object.
	 */
	BasicNode(const Vector& position);

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

	/** Adds a game component to the object.
	 * \param component The game component to attach.
	 */
	void addGameComponent(GameComponent * component);

	/** Gets the component of the type given.
	 * \return The component specified.
	 */
	template <class Type>
	Type * getComponentOfType();

	Graphic * getGraphicComponent();

	Transform * getTransformComponent();

	/** A virtual function to allow the node to perform actions on itself after printing.
	 */
	virtual void act() = 0;
};

/** A game object that does not act.
 */
class Node: public BasicNode {
public:
	/** Creates an object of size 0 x 0 in the position (0, 0)
	 */
	Node();

	/**Creates an object of the size `size` in the position `position`.
	 * \param position The position of the new object.
	 * \param size The size of the object to create.
	 */
	Node(const Vector& position);

	/** Action of the Node.
	 * Do nothing.
	 */
	virtual void act();
};

#endif
