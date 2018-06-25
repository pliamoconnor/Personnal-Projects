#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

class Time
{
public:
	Time();
	~Time();

	//Returns the time elapsed since the program started running
	static float TimeElapsed();
	//Returns the delta time which is the time since the last update
	static float DeltaTime();
	//Returns fixed delta time which is used for physics steps
	static float FixedDeltaTime();

	//Tells the game engine that a new frame has begun.
	void NewFrame();

private:
	static float m_DeltaTime;
	static float m_FixedDeltaTime;
	static float m_TimeElapsed;

	static float m_PreviousTime;
	
	static bool m_Locked;
};
#endif
