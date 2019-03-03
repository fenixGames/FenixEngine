#include <stdexcept>
#include <events/event_handler.hpp>
#include <exceptions.hpp>

EventHandler::EventHandler(SDL_EventType eventType)
{
	type = eventType;
}

SDL_EventType
EventHandler::getType() {
	return type;
}

bool
EventController::isEventHandlerAdded(SDL_EventType type) {
	std::list<EventHandler *>::iterator iteratorEvents;

	for (iteratorEvents = eventHandlers.begin(); iteratorEvents != eventHandlers.end(); iteratorEvents++) {
		if ((*iteratorEvents)->getType() == type)
			return true;
	}
	return false;
}

void
EventController::addEventHandler(EventHandler * eventHandler) {
	if (isEventHandlerAdded(eventHandler->getType())) {
		std::string msg("Event Handler already allocated: ");
		msg += eventHandler->getType();

		throw std::invalid_argument(msg);
	}
	eventHandlers.push_back(eventHandler);
}

void
EventController::handleEvents() {
	SDL_Event ev;
	std::list<EventHandler *>::iterator iteratorEvents;

	while (SDL_PollEvent(&ev)) {
		for (iteratorEvents = eventHandlers.begin(); iteratorEvents != eventHandlers.end(); iteratorEvents++) {
			if ((*iteratorEvents)->getType() == ev.type)
				(*iteratorEvents)->handle(&ev);
		}
	}
}

QuitHandler::QuitHandler():
	EventHandler(SDL_QUIT)
{
}

void
QuitHandler::handle(SDL_Event * ev)
{
	exit(0);
}
