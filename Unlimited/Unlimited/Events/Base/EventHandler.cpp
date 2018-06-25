#include "Common.h"
#include "EventHandler.h"

std::vector<Event*> EventHandler::m_EventQueue = std::vector<Event*>();
bool EventHandler::m_Locked = false;

EventHandler::EventHandler()
{
	if (!m_Locked)
	{
		m_Locked = true;
	}
	else
	{
		assert(false);
	}
}

EventHandler::~EventHandler()
{
}

void EventHandler::QueueEvent(Event* event)
{
	m_EventQueue.push_back(event);
}

void EventHandler::ProcessEvents()
{
	for (auto eventToProcess : m_EventQueue)
	{
		eventToProcess->Process();
	}

	m_EventQueue.clear();
}