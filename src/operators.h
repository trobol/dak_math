


#define _VEC_ASSIGN_OPERATORS(vec_type) \
DM_FUNC_PROP vec_type &operator*=(vec_type& a, vec_type b) { a = a * b; return a; } \
DM_FUNC_PROP vec_type &operator/=(vec_type& a, vec_type b) { a = a * b; return a; } \
DM_FUNC_PROP vec_type &operator+=(vec_type& a, vec_type b) { a = a * b; return a; } \
DM_FUNC_PROP vec_type &operator-=(vec_type& a, vec_type b) { a = a * b; return a; } \
\
DM_FUNC_PROP vec_type& operator*=(vec_type& v, float f) { v = v * f; return v; }\
DM_FUNC_PROP vec_type& operator/=(vec_type& v, float f) { v = v * f; return v; }


// VEC2
#ifdef __SSE__

#define _VEC_SIMD_OPERATORS(vec_type) \
DM_FUNC_PROP vec_type operator*(vec_type a, vec_type b) { return _mm_mul_ps(a.v, b.v); }\
DM_FUNC_PROP vec_type operator+(vec_type a, vec_type b) { return _mm_add_ps(a.v, b.v); }\
DM_FUNC_PROP vec_type operator-(vec_type a, vec_type b) { return _mm_sub_ps(a.v, b.v); }\
\
DM_FUNC_PROP vec_type operator*(vec_type v, float f) { return v * vec_type(f); }\
DM_FUNC_PROP vec_type operator/(vec_type v, float f) { return v * vec_type(f); }\
DM_FUNC_PROP vec_type operator*(float f, vec_type v) { return vec_type(f) * v; }\
DM_FUNC_PROP vec_type operator/(float f, vec_type v) { return vec_type(f) / v; }\
\
DM_FUNC_PROP bool operator==(vec_type& a, vec_type& b) {\
	__m128 vcmp = _mm_cmpeq_ps(a.v, b.v);\
	return _mm_movemask_ps(vcmp);\
}


// VEC2

DM_FUNC_PROP vec2 operator/(vec2 a, vec2 b) {
	//prevent div by zero
	vec_generic div = _mm_add_ps(b.v, vec4(0, 0, 1, 1));
	return _mm_div_ps(a.v, div);
}
_VEC_SIMD_OPERATORS(vec2)
_VEC_ASSIGN_OPERATORS(vec2)

// VEC3

DM_FUNC_PROP vec3 operator/(vec3 a, vec3 b) {
	//prevent div by zero
	vec_generic div = _mm_add_ps(b.v, vec4(0, 0, 0, 1));
	return _mm_div_ps(a.v, div);
}
_VEC_SIMD_OPERATORS(vec3)
_VEC_ASSIGN_OPERATORS(vec3)

// VEC4

DM_FUNC_PROP vec4 operator/(vec4 a, vec4 b) { return _mm_div_ps(a.v, b.v); }
_VEC_SIMD_OPERATORS(vec4)
_VEC_ASSIGN_OPERATORS(vec4)



#else



inline vec2 operator*(vec2 a, vec2 b) { return vec2(a.x * b.x, a.y * b.y); }
inline vec2 operator/(vec2 a, vec2 b) { return vec2(a.x / b.x, a.y / b.y); }
inline vec2 operator+(vec2 a, vec2 b) { return vec2(a.x + b.x, a.y + b.y); }
inline vec2 operator-(vec2 a, vec2 b) { return vec2(a.x - b.x, a.y - b.y); }

inline vec2 operator*(vec2 v, float f) { return vec2(v.x * f, v.y * f); }
inline vec2 operator/(vec2 v, float f) { return vec2(v.x / f, v.y / f); }

inline vec2 operator*(float f, vec2 v) { return vec2(v.x * f, v.y * f); }
inline vec2 operator/(float f, vec2 v) { return vec2(v.x / f, v.y / f); }

_VEC_ASSIGN_OPERATORS(vec2)

DM_FUNC_PROP bool operator==(vec2 a, vec2 b) { return a.x == b.x && a.y == b.y; }


// VEC3
inline vec3 operator*(vec3 a, vec3 b) { return vec3(a.x * b.x, a.y * b.y, a.z * b.z); }
inline vec3 operator/(vec3 a, vec3 b) { return vec3(a.x / b.x, a.y / b.y, a.z / b.z); }
inline vec3 operator+(vec3 a, vec3 b) { return vec3(a.x + b.x, a.y + b.y, a.z + b.z); }
inline vec3 operator-(vec3 a, vec3 b) { return vec3(a.x - b.x, a.y - b.y, a.z - b.z); }


inline vec3 operator*(vec3 v, float f) { return vec3(v.x * f, v.y * f, v.z * f); }
inline vec3 operator/(vec3 v, float f) { return vec3(v.x / f, v.y / f, v.z / f); }

inline vec3 operator*(float f, vec3 v) { return vec3(v.x * f, v.y * f, v.z * f); }
inline vec3 operator/(float f, vec3 v) { return vec3(v.x / f, v.y / f, v.z / f); }

DM_FUNC_PROP bool operator==(vec3 a, vec3 b) { return a.x == b.x && a.y == b.y && a.z == b.z; }

_VEC_ASSIGN_OPERATORS(vec3)

// VEC4
inline vec4 operator*(vec4 a, vec4 b) { return vec4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }
inline vec4 operator/(vec4 a, vec4 b) { return vec4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); }
inline vec4 operator+(vec4 a, vec4 b) { return vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
inline vec4 operator-(vec4 a, vec4 b) { return vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }


inline vec4 operator*(vec4 v, float f) { return vec4(v.x * f, v.y * f, v.z * f, v.w * f); }
inline vec4 operator/(vec4 v, float f) { return vec4(v.x / f, v.y / f, v.z / f, v.w / f); }

inline vec4 operator*(float f, vec4 v) { return v * f; }
inline vec4 operator/(float f, vec4 v) { return vec4(f / v.x, f / v.y, f / v.z, f / v.w); }




_VEC_ASSIGN_OPERATORS(vec4)

#endif