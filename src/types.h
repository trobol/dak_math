// TYPE DECLARATIONS


typedef __m128 vec_generic;

struct vec2 {
	union
	{
		struct { float x, y; };
		vec_generic v;
	};

	FORCE_INLINE operator vec_generic() { return v; }
	vec2() : x{0}, y{0} {}
	vec2(float f) : x{f}, y{f} {}
	vec2(float x, float y) : x{x}, y{y} {}
	vec2(vec_generic v) : v{v} {}
	
};


struct vec3
{
	union {
		struct { float x, y, z; };
		vec_generic v;
	};

	FORCE_INLINE operator vec_generic() { return v; }

	FORCE_INLINE vec3() : x{0}, y{0}, z{0} {}
	FORCE_INLINE vec3(float x, float y, float z) : x{x}, y{y}, z{z} { };
	FORCE_INLINE vec3(vec_generic v) : v{v} {};
};

struct vec4 {
	union {
		struct { float x, y, z, w; };
		vec_generic v;
	};

	FORCE_INLINE operator vec_generic() { return v; }

	vec4() : x{0}, y{0}, z{0}, w{0} {}
	vec4(float f) : x{f}, y{f}, z{f}, w{f} {}
	vec4(vec_generic v) : v{v} {}
	vec4(float x, float y, float z, float w) : x{x}, y{y}, z{z}, w{w} {}

	vec4(vec3 xyz, float w) : vec4{xyz.x, xyz.y, xyz.z, w} {}
	vec4(float x, vec3 yzw) : vec4{x, yzw.x, yzw.y, yzw.z} {}
	vec4(vec2 xy, float z, float w) : vec4{xy.x, xy.y, z, w} {}
	vec4(vec2 xy, vec2 zw) : vec4{xy.x, xy.y, zw.x, zw.y} {}
	vec4(float x, vec2 yz, float w) : vec4{x, yz.x, yz.y, w} {}
	vec4(float x, float y, vec2 zw) : vec4{x, y, zw.x, zw.y} {}

};

