#include "Common.h"
#include "Time.h"

#include <time.h>

float Time::m_DeltaTime = 0.0f;
float Time::m_FixedDeltaTime = 0.0f;
float Time::m_PreviousTime = 0.0f;
float Time::m_TimeElapsed = 1.0f/30.0f;
bool Time::m_Locked = false;

Time::Time()
{
	if (!m_Locked)
	{
		m_Locked = !m_Locked;
	}
	else
	{
		assert(false);
	}
}

Time::~Time()
{
}

void Time::NewFrame()
{
	m_PreviousTime = m_TimeElapsed;
	m_TimeElapsed = static_cast<float>(clock()) / CLOCKS_PER_SEC;
	m_DeltaTime = m_TimeElapsed - m_PreviousTime;
}

float Time::DeltaTime()
{
	return m_DeltaTime;
}

float Time::FixedDeltaTime()
{
	return m_FixedDeltaTime;
}

float Time::TimeElapsed()
{
	return m_TimeElapsed;
}
