/** Describes components of a game object.
 * This is a generic class that has to be extended.
 */

#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

#include <list>
#include <typeinfo>

#define DEFINE_GET_TYPE(Class)		\
const std::type_info&				\
Class::getType() const {			\
	return typeid(*this);			\
}

#define GET_TYPE_DEFINITION() \
	virtual const std::type_info& getType() const

class GameComponent {
public:
	GET_TYPE_DEFINITION() = 0;
};

#endif // !GAME_COMPONENT_H
