#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

class Event;

class EventHandler
{
public:
	EventHandler();
	~EventHandler();
	
	//This method will process all queued events.
	void ProcessEvents();
	static void QueueEvent(Event* event);

private:
	static std::vector<Event*> m_EventQueue;
	static bool m_Locked;
};

#endif
