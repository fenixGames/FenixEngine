#include <draggable_node.h>

DraggableNode::DraggableNode() :
	DraggableNode(Vector()) {
}

DraggableNode::DraggableNode(const Vector& position) :
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
