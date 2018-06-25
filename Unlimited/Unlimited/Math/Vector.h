#ifndef VECTOR_H
#define VECTOR_H

#include <limits.h>
#include <math.h>

class Vector2
{
public:
	float x;
	float y;

	inline Vector2() { x = y = 0; }
	inline Vector2(float ax, float ay) { x = ax; y = ay; }
	inline Vector2(float value) { x = y = value; }
	inline ~Vector2() {}

	inline Vector2 operator+(const Vector2& rhs) { return Vector2(x + rhs.x, y + rhs.y); }
	inline Vector2 operator-(const Vector2& rhs) { return Vector2(x - rhs.x, y - rhs.y); }
	inline Vector2 operator*(const float& rhs) { return Vector2(x * rhs, y * rhs); }
	inline Vector2 operator/(const float& rhs) { return Vector2(x / rhs, y / rhs); }

	inline void operator+=(const Vector2& rhs) { x += rhs.x; y += rhs.y; }
	inline void operator-=(const Vector2& rhs) { x -= rhs.x; y -= rhs.y; }
	inline void operator*=(const float& rhs) { x *= rhs; y *= rhs; }
	inline void operator/=(const float& rhs) { x /= rhs; y /= rhs; }
	inline void operator=(const Vector2& rhs) { x = rhs.x; y = rhs.y; }

	//Returns a shorthanded forward direction of a Vector2 (1, 0)
	inline static Vector2 forward() { return Vector2(1, 0); }
	//Returns a shorthanded backward direction of a Vector2 (-1,0)
	inline static Vector2 back() { return Vector2(-1, 0); }
	//Returns a shorthanded upward direction of a Vector2 (0, 1)
	inline static Vector2 up() { return Vector2(0, 1); }
	//Returns a shorthanded downward direction of a Vector2 (0, -1)
	inline static Vector2 down() { return Vector2(0, -1); }
	//Returns a Vector2 with zeroed values
	inline static Vector2 zero() { return Vector2(0, 0); }
	//Returns a Vector2 with it's maximum values
	inline static Vector2 max() { return Vector2(static_cast<float>(INT_MAX), static_cast<float>(INT_MAX)); }
	//Returns a Vector2 with it's minimum values
	inline static Vector2 min() { return Vector2(static_cast<float>(INT_MIN), static_cast<float>(INT_MIN)); }

	//Returns the magnitude of this Vector2
	inline float magnitude() { return sqrtf(x * x + y * y); }
	//Returns the sqrd magnitude of this Vector2
	inline float sqrdMagnitude() { return x * x + y * y; }
	//Returns a normalized version of this Vector2
	inline Vector2 normalized() { float mag = magnitude(); return Vector2(x / mag, y / mag); }
	//Normalizes this Vector2
	inline void normalize() { float mag = magnitude(); x /= mag; y /= mag; }

	//Calculates the DOT product between two Vector2s
	inline static float dot(Vector2 vector1, Vector2 vector2) { return vector1.x * vector2.x + vector1.y * vector2.y; }
	//Calculates the distance between the two Vector2s
	inline static float distance(Vector2 vector1, Vector2 vector2)
	{
		return sqrtf(
			(vector1.x - vector2.x) * (vector1.x - vector2.x) +
			(vector1.y - vector2.y)  *(vector1.y - vector2.y));
	}
};

class Vector3
{
public:
	float x;
	float y;
	float z;

	inline Vector3() { x = y = z = 0; }
	inline Vector3(float ax, float ay, float az) { x = ax; y = ay; z = az; }
	inline Vector3(float value) { x = y = z = value; }
	inline ~Vector3() {}

	inline Vector3 operator+(const Vector3& rhs) { return Vector3(x + rhs.x, y + rhs.y, z + rhs.z); }
	inline Vector3 operator-(const Vector3& rhs) { return Vector3(x - rhs.x, y - rhs.y, z - rhs.z); }
	inline Vector3 operator*(const float& rhs) { return Vector3(x * rhs, y * rhs, z * rhs); }
	inline Vector3 operator/(const float& rhs) { return Vector3(x / rhs, y / rhs, z / rhs); }

	inline void operator+=(const Vector3& rhs) { x += rhs.x; y += rhs.y; z += rhs.z; }
	inline void operator-=(const Vector3& rhs) { x -= rhs.x; y -= rhs.y; z += rhs.z; }
	inline void operator*=(const float& rhs) { x *= rhs; y *= rhs; z *= rhs; }
	inline void operator/=(const float& rhs) { x /= rhs; y /= rhs; z /= rhs; }
	inline void operator=(const Vector3& rhs) { x = rhs.x; y = rhs.y; z = rhs.z; }

	//Returns the shorthanded right direction of a Vector3 (1, 0, 0)
	inline static Vector3 right() { return Vector3(1, 0, 0); }
	//Returns the shorthanded left direction of a Vector3 (-1, 0, 0)
	inline static Vector3 left() { return Vector3(-1, 0, 0); }
	//Returns a shorthanded upward direction of a Vector3 (0, 1, 0)
	inline static Vector3 up() { return Vector3(0, 1, 0); }
	//Returns a shorthanded downward direction of a Vector3 (0, -1, 0)
	inline static Vector3 down() { return Vector3(0, -1, 0); }
	//Returns a shorthanded forward direction of a Vector3 (1, 0, 0)
	inline static Vector3 forward() { return Vector3(0, 0, 1); }
	//Returns a shorthanded backward direction of a Vector3 (-1, 0, 0)
	inline static Vector3 back() { return Vector3(0, 0, -1); }
	//Returns a zeroed Vector3
	inline static Vector3 zero() { return Vector3(0, 0, 0); }
	//Returns a Vector3 with maximized values
	inline static Vector3 max() { return Vector3(static_cast<float>(INT_MAX), static_cast<float>(INT_MAX), static_cast<float>(INT_MAX)); }
	//Returns a Vector3 with minimized values
	inline static Vector3 min() { return Vector3(static_cast<float>(INT_MIN), static_cast<float>(INT_MIN), static_cast<float>(INT_MIN)); }

	//Returns the magnitude of this Vector3
	inline float magnitude() { return sqrtf(x * x + y * y + z * z); }
	//Returns the sqrd magnitude of this Vector3
	inline float sqrdMagnitude() { return x * x + y * y + z * z; }
	//Returns the normalized value of this Vector3
	inline Vector3 normalized() { float mag = magnitude(); return Vector3(x / mag, y / mag, z / mag); }
	//Normalizes this Vector3
	inline void normalize() { float mag = magnitude(); x /= mag; y /= mag; z /= mag; }

	//Calculates the DOT product between two Vector3s
	inline static float dot(Vector3 vector1, Vector3 vector2) { return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z; }
	//Calculates the cross product between two Vector3s
	inline static Vector3 cross(Vector3 vector1, Vector3 vector2)
	{
		float x = vector1.y * vector2.z - vector1.z * vector2.y;
		float y = vector1.x * vector2.z - vector1.z * vector2.x;
		float z = vector1.y * vector2.x - vector1.x * vector2.y;
		return Vector3(x, y, z);
	}
	//Calculates the distance between two Vector3s
	inline static Vector3 distance(Vector3 vector1, Vector3 vector2)
	{
		return sqrtf(
			(vector1.x - vector2.x) * (vector1.x - vector2.x) +
			(vector1.y - vector2.y) * (vector1.y - vector2.y) +
			(vector1.z - vector2.z) * (vector1.z - vector2.z));
	}
};

class Vector4
{
public:
	float x;
	float y;
	float z;
	float w;

	inline Vector4() { x = y = z = w = 0; }
	inline Vector4(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
	inline Vector4(float value) { x = y = z = w = value; }
	inline ~Vector4() {}

	inline Vector4 operator+(const Vector4& rhs) { return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w); }
	inline Vector4 operator-(const Vector4& rhs) { return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w); }
	inline Vector4 operator*(const float& rhs) { return Vector4(x * rhs, y * rhs, z * rhs, w * rhs); }
	inline Vector4 operator/(const float& rhs) { return Vector4(x / rhs, y / rhs, z / rhs, w / rhs); }

	inline void operator+=(const Vector4& rhs) { x += rhs.x; y += rhs.y; z += rhs.z; w += rhs.w; }
	inline void operator-=(const Vector4& rhs) { x -= rhs.x; y -= rhs.y; z += rhs.z; w -= rhs.w; }
	inline void operator*=(const float& rhs) { x *= rhs; y *= rhs; z *= rhs; w *= rhs; }
	inline void operator/=(const float& rhs) { x /= rhs; y /= rhs; z /= rhs; w /= rhs; }
	inline void operator=(const Vector4& rhs) { x = rhs.x; y = rhs.y; z = rhs.z; w = rhs.w; }

	//Returns a shorthanded right direction of a Vector4 (1, 0, 0, 0)
	inline static Vector4 right() { return Vector4(1, 0, 0, 0); }
	//Returns a shorthanded left direction of a Vector4 (-1, 0, 0, 0)
	inline static Vector4 left() { return Vector4(-1, 0, 0, 0); }
	//Returns a shorthanded upward direction of a Vector4 (0, 1, 0, 0)
	inline static Vector4 up() { return Vector4(0, 1, 0, 0); }
	//Returns a shorthanded downward direction of a Vector4 (0, -1, 0, 0)
	inline static Vector4 down() { return Vector4(0, -1, 0, 0); }
	//Returns a shorthanded forward direction of a Vector4 (0, 0, 1, 0)
	inline static Vector4 forward() { return Vector4(0, 0, 1, 0); }
	//Returns a shorthanded backward direction of a Vector4 (0, 0, -1, 0)
	inline static Vector4 back() { return Vector4(0, 0, -1, 0); }
	//Returns a zeroed Vector4
	inline static Vector4 zero() { return Vector4(0, 0, 0, 0); }
	//Returns a Vector4 at its maximum values
	inline static Vector4 max() { return Vector4(static_cast<float>(INT_MAX), static_cast<float>(INT_MAX), static_cast<float>(INT_MAX), static_cast<float>(INT_MAX)); }
	//Returns a Vector4 at its minimum values
	inline static Vector4 min() { return Vector4(static_cast<float>(INT_MIN), static_cast<float>(INT_MIN), static_cast<float>(INT_MIN), static_cast<float>(INT_MIN)); }

	//Returns the magnitude of this Vector4
	inline float magnitude() { return sqrtf(x * x + y * y + z * z + w * w); }
	//Returns the sqrd magnitude of this Vector4
	inline float sqrdmagnitude() { return x * x + y * y + z * z + w * w; }
	//Returns a normalized version of this Vector4
	inline Vector4 normalized() { float mag = magnitude(); return Vector4(x / mag, y / mag, z / mag, w / mag); }
	//Normalizes this Vector4
	inline void normalize() { float mag = magnitude(); x /= mag; y /= mag; z /= mag; w /= mag; }

	//Calculates the DOT product between the two Vector4s
	inline static float dot(Vector4 vector1, Vector4 vector2) { return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z + vector1.w * vector2.w; }
	//Calculates the distance between the two Vector4s
	inline static Vector4 distance(Vector4 vector1, Vector4 vector2)
	{
		return sqrtf(
			(vector1.x - vector2.x) * (vector1.x - vector2.x) +
			(vector1.y - vector2.y) * (vector1.y - vector2.y) +
			(vector1.z - vector2.z) * (vector1.z - vector2.z) +
			(vector1.w - vector2.w) * (vector1.w - vector2.w));
	}
};

class iVector2
{
public:
	int x;
	int y;

	inline iVector2() { x = y = 0; }
	inline iVector2(int ax, int ay) { x = ax; y = ay; }
	inline iVector2(int value) { x = y = value; }
	inline ~iVector2() {}

	inline iVector2 operator+(const iVector2& rhs) { return iVector2(x + rhs.x, y + rhs.y); }
	inline iVector2 operator-(const iVector2& rhs) { return iVector2(x - rhs.x, y - rhs.y); }
	inline iVector2 operator*(const int& rhs) { return iVector2(x * rhs, y * rhs); }
	inline iVector2 operator/(const int& rhs) { return iVector2(x / rhs, y / rhs); }

	inline void operator+=(const iVector2& rhs) { x += rhs.x; y += rhs.y; }
	inline void operator-=(const iVector2& rhs) { x -= rhs.x; y -= rhs.y; }
	inline void operator*=(const int& rhs) { x *= rhs; y *= rhs; }
	inline void operator/=(const int& rhs) { x /= rhs; y /= rhs; }
	inline void operator=(const iVector2& rhs) { x = rhs.x; y = rhs.y; }

	inline bool operator!=(const iVector2& rhs) { return x != rhs.x && y != rhs.y; }
	inline bool operator==(const iVector2& rhs) { return x == rhs.x && y == rhs.y; }

	//Returns a shorthanded forward direction of a iVector2 (1, 0)
	inline static iVector2 forward() { return iVector2(1, 0); }
	//Returns a shorthanded backward direction of a iVector2 (-1,0)
	inline static iVector2 back() { return iVector2(-1, 0); }
	//Returns a shorthanded upward direction of a iVector2 (0, 1)
	inline static iVector2 up() { return iVector2(0, 1); }
	//Returns a shorthanded downward direction of a iVector2 (0, -1)
	inline static iVector2 down() { return iVector2(0, -1); }
	//Returns a iVector2 with zeroed values
	inline static iVector2 zero() { return iVector2(0, 0); }
	//Returns a iVector2 with it's maximum values
	inline static iVector2 max() { return iVector2(INT_MAX, INT_MAX); }
	//Returns a iVector2 with it's minimum values
	inline static iVector2 min() { return iVector2(INT_MIN, INT_MIN); }
};

class iVector3
{
public:
	int x;
	int y;
	int z;

	inline iVector3() { x = y = z = 0; }
	inline iVector3(int ax, int ay, int az) { x = ax; y = ay; z = ay; }
	inline iVector3(int value) { x = y = z = value; }
	inline ~iVector3() {}

	inline iVector3 operator+(const iVector3& rhs) { return iVector3(x + rhs.x, y + rhs.y, z + rhs.z); }
	inline iVector3 operator-(const iVector3& rhs) { return iVector3(x - rhs.x, y - rhs.y, z - rhs.z); }
	inline iVector3 operator*(const int& rhs) { return iVector3(x * rhs, y * rhs, z * rhs); }
	inline iVector3 operator/(const int& rhs) { return iVector3(x / rhs, y / rhs, z / rhs); }

	inline void operator+=(const iVector3& rhs) { x += rhs.x; y += rhs.y; z += rhs.z; }
	inline void operator-=(const iVector3& rhs) { x -= rhs.x; y -= rhs.y; z += rhs.z; }
	inline void operator*=(const int& rhs) { x *= rhs; y *= rhs; z *= rhs; }
	inline void operator/=(const int& rhs) { x /= rhs; y /= rhs; z /= rhs; }
	inline void operator=(const iVector3& rhs) { x = rhs.x; y = rhs.y; z = rhs.z; }

	inline bool operator!=(const iVector3& rhs) { return x != rhs.x && y != rhs.y && z != rhs.z; }
	inline bool operator==(const iVector3& rhs) { return x == rhs.x && y == rhs.y && z == rhs.z; }

	//Returns the shorthanded right direction of a Vector3 (1, 0, 0)
	inline static iVector3 right() { return iVector3(1, 0, 0); }
	//Returns the shorthanded left direction of a Vector3 (-1, 0, 0)
	inline static iVector3 left() { return iVector3(-1, 0, 0); }
	//Returns a shorthanded upward direction of a Vector3 (0, 1, 0)
	inline static iVector3 up() { return iVector3(0, 1, 0); }
	//Returns a shorthanded downward direction of a Vector3 (0, -1, 0)
	inline static iVector3 down() { return iVector3(0, -1, 0); }
	//Returns a shorthanded forward direction of a Vector3 (1, 0, 0)
	inline static iVector3 forward() { return iVector3(0, 0, 1); }
	//Returns a shorthanded backward direction of a Vector3 (-1, 0, 0)
	inline static iVector3 back() { return iVector3(0, 0, -1); }
	//Returns an iVector3 with zeroed values
	inline static iVector3 zero() { return iVector3(0, 0, 0); }
	//Returns an iVector3 with maximized values
	inline static iVector3 max() { return iVector3(INT_MAX, INT_MAX, INT_MAX); }
	//Returns an iVector3 with minimized values
	inline static iVector3 min() { return iVector3(INT_MIN, INT_MIN, INT_MIN); }
};


#define vec2 Vector2
#define vec3 Vector3
#define vec4 Vector4
#define ivec2 iVector2
#define ivec3 iVector3

#endif