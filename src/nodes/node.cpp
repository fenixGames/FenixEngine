#include <nodes/node.hpp>

BasicNode::BasicNode() : BasicNode(Point(0, 0), Size(0, 0))
{
}

BasicNode::BasicNode(const Point& startPoint, const Size& startSize)
{
	this->setPosition(startPoint);
	this->setSize(startSize);
	this->setGraphicResource(NULL);
	this->parent = NULL;
}


SDL_Texture *
BasicNode::getTexture()
{
	SDL_Texture * texture = NULL;

	if (graphicResource != NULL)
		texture = graphicResource->getTexture();
	return texture;
}

void
BasicNode::setGraphicResource(Graphic * resource) {
	graphicResource = resource;
}

void 
BasicNode::fillDimentions(SDL_Rect *rect) {
	BasicNode * root = this;

	rect->w = (int)this->size.width;
	rect->h = (int)this->size.height;

	rect->x = rect->y = 0;
	while (root != NULL) {
		rect->x += (int)root->position.x;
		rect->y += (int)root->position.y;
		root = root->parent;
	}
}

void
BasicNode::setPosition(const Point& point) {
	this->position = point;
}

void
BasicNode::setSize(const Size& size) {
	this->size = size;
}

void
BasicNode::addChild(BasicNode * child) {
	if (child != NULL)
		child->parent = this;
		this->children.push_back(child);
}

std::list<BasicNode*>* 
BasicNode::getChildren()
{
	return &this->children;
}

Node::Node(): BasicNode()
{
}

Node::Node(const Point& position, const Size& size) : BasicNode(position, size)
{
}

void
Node::act()
{
}
