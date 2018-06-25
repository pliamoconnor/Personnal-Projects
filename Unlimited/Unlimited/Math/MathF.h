#ifndef MATHF_H
#define MATHF_H



class MathF
{

//Methods
public:
	//Rounds the float to the next highest round number
	static float RoundUp(float value);
	//Rounds the float to the next lowest round number
	static float RoundDown(float value);
	
	//


//Members
public:
	const float epsilon = 0.00001f;
	const float bigEpsilon = 0.1f;

};

#endif