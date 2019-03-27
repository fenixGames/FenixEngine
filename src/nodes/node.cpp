#include <node.h>
#include <typeinfo>


BasicNode::BasicNode() : BasicNode(Vector(0, 0))
{
}

BasicNode::BasicNode(const Vector& startPoint)
{
	Transform * transform = new Transform();
	this->parent = NULL;

	transform->position = startPoint;
	transform->scale = Vector(1, 1);
	this->addGameComponent(transform);
}


SDL_Texture *
BasicNode::getTexture()
{
	SDL_Texture * texture = NULL;
	//Graphic * graphicResource = getComponentOfType<Graphic>();
	Graphic * graphicResource = getGraphicComponent();

	if (graphicResource != NULL)
		texture = graphicResource->getTexture();
	return texture;
}

void
BasicNode::setGraphicResource(Graphic * resource) {
	this->addGameComponent(resource);
}

void 
BasicNode::fillDimentions(SDL_Rect *rect) {
	BasicNode * root = this;
	Size size;
	//Graphic * graphicResource = getComponentOfType<Graphic>();
	Graphic * graphicResource = getGraphicComponent();

	if (graphicResource != NULL)
		size = graphicResource->getSize();

	rect->w = (int)size.width;
	rect->h = (int)size.height;

	rect->x = rect->y = 0;
	while (root != NULL) {
		//const Vector& position = root->getComponentOfType<Transform>()->position;
		const Vector& position = root->getTransformComponent()->position;
		rect->x += (int)position.x;
		rect->y += (int)position.y;
		root = root->parent;
	}
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

template<class Type>
Type *
BasicNode::getComponentOfType()
{
	return NULL;
}

Graphic *
BasicNode::getGraphicComponent()
{
	std::list<GameComponent *>::iterator iterator;
	const std::type_info& classType = typeid(Graphic *);

	for (iterator = this->components.begin();
		iterator != this->components.end(); iterator++)
	{
		const std::type_info& type = (*iterator)->getType();
		if (type == classType)
			return (Graphic *)*iterator;
	}
	return NULL;
}

Transform *
BasicNode::getTransformComponent()
{
	std::list<GameComponent *>::iterator iterator;

	for (iterator = this->components.begin();
		iterator != this->components.end(); iterator++)
	{
		const std::type_info& type = (*iterator)->getType();
		if (type == typeid(Transform *))
			return (Transform *)*iterator;
	}
	return NULL;
}


void
BasicNode::addGameComponent(GameComponent * component)
{
	this->components.push_back(component);
}

/********************* Node ********************************/
Node::Node(): BasicNode()
{
}

Node::Node(const Vector& position) : BasicNode(position)
{
}

void
Node::act()
{
}
