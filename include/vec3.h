#ifndef _DAK_VECTOR_LIB_VEC3
#define _DAK_VECTOR_LIB_VEC3

struct vec3
{
	float x, y, z;
	vec3(float x, float y, float z) : x{x}, y{y}, z{z} {};

	static vec3 one, left, right, up, down, forwards, back;
};

float doc(const vec3 &a, const vec3 &b);
vec3 cross(const vec3 &a, const vec3 &b);

vec3 &operator*=(const vec3 &v0, const vec3 &v1);
vec3 &operator/=(const vec3 &v0, const vec3 &v1);
vec3 &operator+=(const vec3 &v0, const vec3 &v1);
vec3 &operator-=(const vec3 &v0, const vec3 &v1);

vec3 operator*(const vec3 &v0, const vec3 &v1);
vec3 operator/(const vec3 &v0, const vec3 &v1);
vec3 operator+(const vec3 &v0, const vec3 &v1);
vec3 operator-(const vec3 &v0, const vec3 &v1);

#endif