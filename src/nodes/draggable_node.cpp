#include <draggable_node.h>

DraggableNode::DraggableNode() :
	DraggableNode(Point()) {
}

DraggableNode::DraggableNode(const Point& position) :
	Node(position) {
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
