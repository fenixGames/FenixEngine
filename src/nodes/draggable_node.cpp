#include <nodes/draggable_node.hpp>

DraggableNode::DraggableNode() :
	DraggableNode(Point(), Size()) {
}

DraggableNode::DraggableNode(const Point& position, const Size& size) :
	Node(position, size) {
	this->isDragged = false;
}

void
DraggableNode::drag() {
	this->isDragged = true;
}

void
DraggableNode::release() {
	this->isDragged = false;
}

bool 
DraggableNode::isNodeDragged() {
	return this->isDragged;
}
