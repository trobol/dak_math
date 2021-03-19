// TYPE DECLARATIONS


typedef __m128 vec_generic;

struct vec2 {
	union
	{
		struct { float x, y; };
		vec_generic v;
	};

	DM_FUNC_PROP operator vec_generic() { return v; }
	vec2();
	vec2(float f);
	vec2(float x, float y);
	vec2(vec_generic v);
};


struct vec3
{
	union {
		struct { float x, y, z; };
		vec_generic v;
	};

	DM_FUNC_PROP operator vec_generic() { return v; }

	vec3();
	vec3(float f);
	vec3(float x, float y, float z);
	vec3(float x, vec2 yz);
	vec3(vec2 xy, float z);
	vec3(vec_generic v);
};

struct vec4 {
	union {
		struct { float x, y, z, w; };
		vec_generic v;
	};

	DM_FUNC_PROP operator vec_generic() { return v; }

	vec4();
	vec4(float f);
	vec4(vec_generic v);
	vec4(float x, float y, float z, float w);

	vec4(vec3 xyz, float w);
	vec4(float x, vec3 yzw);
	vec4(vec2 xy, float z, float w);
	vec4(vec2 xy, vec2 zw);
	vec4(float x, vec2 yz, float w);
	vec4(float x, float y, vec2 zw);

};

#ifdef __SSE__

DM_FUNC_PROP vec2::vec2() : v{_mm_setzero_ps()} {}
DM_FUNC_PROP vec2::vec2(float f) : v{_mm_setr_ps(f, f, 0, 0)} {}
DM_FUNC_PROP vec2::vec2(float x, float y) : v{_mm_setr_ps(x, y, 0, 0)} {}
DM_FUNC_PROP vec2::vec2(vec_generic v) : v{v} {}

DM_FUNC_PROP vec3::vec3() : v{_mm_setzero_ps()} {}
DM_FUNC_PROP vec3::vec3(float f) : v{_mm_setr_ps(f, f, f, 0)} {}
DM_FUNC_PROP vec3::vec3(float x, float y, float z) : v{_mm_setr_ps(x, y, z, 0)} {};
DM_FUNC_PROP vec3::vec3(float x, vec2 yz) : x{x}, y{yz.x}, z{yz.y} {};
DM_FUNC_PROP vec3::vec3(vec2 xy, float z) : x{xy.x}, y{xy.y}, z{z} {};
DM_FUNC_PROP vec3::vec3(vec_generic v) : v{v} {};

DM_FUNC_PROP vec4::vec4() : v{_mm_setzero_ps()} {}
DM_FUNC_PROP vec4::vec4(float f) : v{_mm_set1_ps(f)} {}
DM_FUNC_PROP vec4::vec4(vec_generic v) : v{v} {}
DM_FUNC_PROP vec4::vec4(float x, float y, float z, float w) : v{_mm_setr_ps(x, y, z, w)} {}

DM_FUNC_PROP vec4::vec4(vec3 xyz, float w) : v{_mm_add_ps(xyz, _mm_setr_ps(0, 0, 0, w))} {}
DM_FUNC_PROP vec4::vec4(float x, vec3 yzw) : v{_mm_add_ps(_mm_shuffle_ps(yzw, yzw, 0b11000110), _mm_setr_ps(x, 0, 0, 0))} {}
DM_FUNC_PROP vec4::vec4(vec2 xy, float z, float w) : v{_mm_movelh_ps(xy.v, _mm_setr_ps(z, w, 0, 0))} {}
DM_FUNC_PROP vec4::vec4(vec2 xy, vec2 zw) : v{_mm_movelh_ps(xy, zw)} {}
DM_FUNC_PROP vec4::vec4(float x, vec2 yz, float w) : vec4{x, yz.x, yz.y, w} {}
DM_FUNC_PROP vec4::vec4(float x, float y, vec2 zw) : v{_mm_movelh_ps(_mm_setr_ps(x, y, 0, 0), zw.v)} {}
#else

DM_FUNC_PROP vec2::vec2() : x{0}, y{0} {}
DM_FUNC_PROP vec2::vec2(float f) : x{f}, y{f} {}
DM_FUNC_PROP vec2::vec2(float x, float y) : x{x}, y{y} {}
DM_FUNC_PROP vec2::vec2(vec_generic v) : v{v} {}

DM_FUNC_PROP vec3::vec3() : x{0}, y{0}, z{0} {}
DM_FUNC_PROP vec3::vec3(float f) : x{f}, y{f}, z{f} {}
DM_FUNC_PROP vec3::vec3(float x, float y, float z) : x{x}, y{y}, z{z} {};
DM_FUNC_PROP vec3::vec3(float x, vec2 yz) : x{x}, y{yz.x}, z{yz.y} {};
DM_FUNC_PROP vec3::vec3(vec2 xy, float z) : x{xy.x}, y{xy.y}, z{z} {};
DM_FUNC_PROP vec3::vec3(vec_generic v) : v{v} {};


DM_FUNC_PROP vec4::vec4() : x{0}, y{0}, z{0}, w{0} {}
DM_FUNC_PROP vec4::vec4(float f) : x{f}, y{f}, z{f}, w{f} {}
DM_FUNC_PROP vec4::vec4(vec_generic v) : v{v} {}
DM_FUNC_PROP vec4::vec4(float x, float y, float z, float w) : x{x}, y{y}, z{z}, w{w} {}

DM_FUNC_PROP vec4::vec4(vec3 xyz, float w) : vec4{xyz.x, xyz.y, xyz.z, w} {}
DM_FUNC_PROP vec4::vec4(float x, vec3 yzw) : vec4{x, yzw.x, yzw.y, yzw.z} {}
DM_FUNC_PROP vec4::vec4(vec2 xy, float z, float w) : vec4{xy.x, xy.y, z, w} {}
DM_FUNC_PROP vec4::vec4(vec2 xy, vec2 zw) : vec4{xy.x, xy.y, zw.x, zw.y} {}
DM_FUNC_PROP vec4::vec4(float x, vec2 yz, float w) : vec4{x, yz.x, yz.y, w} {}
DM_FUNC_PROP vec4::vec4(float x, float y, vec2 zw) : vec4{x, y, zw.x, zw.y} {}
#endif