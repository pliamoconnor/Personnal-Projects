#ifndef EVENT_H
#define EVENT_H

class EventArgs;

class Event
{
public:
	Event(EventArgs* args);
	virtual ~Event();

	virtual void Process() = 0;

private:
	EventArgs* m_EventArguments;
};

#endif
