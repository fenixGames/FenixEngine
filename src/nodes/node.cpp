#include <node.h>

BasicNode::BasicNode() : BasicNode(Point(0, 0))
{
}

BasicNode::BasicNode(const Point& startPoint)
{
	this->setPosition(startPoint);
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
	Size size;

	if (this->graphicResource != NULL)
		size = this->graphicResource->getSize();

	rect->w = (int)size.width;
	rect->h = (int)size.height;

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

Node::Node(const Point& position) : BasicNode(position)
{
}

void
Node::act()
{
}
