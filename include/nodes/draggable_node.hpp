#ifndef DRAGGABLE_NODE_HPP
#define DRAGGABLE_NODE_HPP
#include <nodes/node.hpp>

/** An object that can be dragged with the mouse and dropped somewhere else.
 */
class DraggableNode : public Node {
protected:
	bool isDragged; //<* Set whenever the node had been dragged with the mouse.
public:
	/** Sets a draggable object of size 0 x 0 on the point (0, 0)
	 */
	DraggableNode();

	/** Creates a draggable object of size `size` on the position `position`.
	 * \param position The point where the node should appear first.
	 * \param size The size of the object.
	 */
	DraggableNode(const Point&, const Size&);

	/** Sets the object to have been dragged.
	 */
	void drag();

	/** Sets the object to have been released from a previous dragged.
	 */
	void release();

	/** Checks if the Node has been dragged yet.
	 * \return If the node has been dragged.
	 */
	bool isNodeDragged();

};

#endif // !DRAGGABLE_NODE_HPP
