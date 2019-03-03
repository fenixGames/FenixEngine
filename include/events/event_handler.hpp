/**
 * Definitions of event handling.
 *
 * This module defines the EventHandler class and
 * the Event class also.
 */

#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include <list>

#include <os.hpp>

/** API for SDL event handling.
 */
class EventHandler {
protected:
	SDL_EventType type; // <* Type of event to handle.
public:
	/** Creates an event handler for the event type given.
	 * \param type The type of SDL event to handle.
	 */
	EventHandler(SDL_EventType type);

	/** Retrieves the type of event associated to this handler.
	 * \param The SDL event type to handle by this object.
	 */
	SDL_EventType getType();

	/** The function to be performed when the event matches.
	 * \param ev The SDL event to handle.
	 */
	virtual void handle(SDL_Event *) = 0;
};

/** Event handler for quitting the game.
 */
class QuitHandler : public EventHandler {
public:
	/** Creates a event handler for the event SDL_QUIT
	 */
	QuitHandler();

	/** Quits the game by calling exit(0)
	 */
	virtual void handle(SDL_Event *);
};

/** Handles events by calling the handlers when the type matches.
 */
class EventController {
protected:
	std::list<EventHandler *> eventHandlers; // <* List of registered handlers.
public:
	/** Registers the given event when it was not registered.
	 * \param handler The handler to register in the controller.
	 *
	 * \throw std::invalid_argument On duplicated handlers for the same event type.
	 */
	void addEventHandler(EventHandler *);

	/** Checks if a event handler was already added for the SDL event type given.
	 * \param type The event type to check between the registered handlers.
	 */
	bool isEventHandlerAdded(SDL_EventType);

	/** Starts handling the pending SDL Events using the registered handlers.
	 */
	void handleEvents();
};
#endif
