
// VEC2
#ifdef __SSE__


// multiply, div, add, sub vec2
inline FORCE_INLINE vec2 operator*(vec2 a, vec2 b) { return _mm_mul_ps(a.v, b.v); }
inline FORCE_INLINE vec2 operator/(vec2 a, vec2 b) { return _mm_div_ps(a.v, b.v);}
inline FORCE_INLINE vec2 operator+(vec2 a, vec2 b) { return _mm_add_ps(a.v, b.v); }
inline FORCE_INLINE vec2 operator-(vec2 a, vec2 b) { return _mm_sub_ps(a.v, b.v); }

// operation on self and other vec2
inline FORCE_INLINE vec2 &operator*=(vec2& a, vec2 b) { a = a * b; return a; }
inline FORCE_INLINE vec2 &operator/=(vec2& a, vec2 b) { a = a * b; return a; }
inline FORCE_INLINE vec2 &operator+=(vec2& a, vec2 b) { a = a * b; return a; }
inline FORCE_INLINE vec2 &operator-=(vec2& a, vec2 b) { a = a * b; return a; }

// vector / float and vector * float 
inline FORCE_INLINE vec2 operator*(vec2 v, float f) { return vec2(v.x * f, v.y * f); }
inline FORCE_INLINE vec2 operator/(vec2 v, float f) { return vec2(v.x / f, v.y / f); }

// Float / vector and vector * float 
inline FORCE_INLINE vec2 operator*(float f, vec2 v) { return vec2(v.x * f, v.y * f); }
inline FORCE_INLINE vec2 operator/(float f, vec2 v) { return vec2(v.x / f, v.y / f); }

// Operation on self and other float
inline FORCE_INLINE vec2& operator*=(vec2& v, float f) { v = v * f; return v; }
inline FORCE_INLINE vec2& operator/=(vec2& v, float f) { v = v * f; return v; }

// check equalilty 
inline FORCE_INLINE bool operator==(vec2& a, vec2& b) { 
	__m128 vcmp = _mm_cmpeq_ps(a.v, b.v);
	return _mm_movemask_ps(vcmp);
}



// VEC3

inline FORCE_INLINE vec3::vec3() : x{0}, y{0}, z{0} {}
inline FORCE_INLINE vec3::vec3(float x, float y, float z) : x{x}, y{y}, z{z} { };
inline FORCE_INLINE vec3::vec3(__m128 v) : v{v} {};

inline FORCE_INLINE vec3 operator*(vec3 a, vec3 b) { return _mm_mul_ps(a.v, b.v); }
inline FORCE_INLINE vec3 operator/(vec3 a, vec3 b) { return vec3(a.x / b.x, a.y / b.y, a.z / b.z); }
inline FORCE_INLINE vec3 operator+(vec3 a, vec3 b) { return vec3(a.x + b.x, a.y + b.y, a.z + b.z); }
inline FORCE_INLINE vec3 operator-(vec3 a, vec3 b) { return vec3(a.x - b.x, a.y - b.y, a.z - b.z); }

inline FORCE_INLINE vec3 &operator*=(vec3& a, vec3 b) { a = a * b; return a; }
inline FORCE_INLINE vec3 &operator/=(vec3& a, vec3 b) { a = a * b; return a; }
inline FORCE_INLINE vec3 &operator+=(vec3& a, vec3 b) { a = a * b; return a; }
inline FORCE_INLINE vec3 &operator-=(vec3& a, vec3 b) { a = a * b; return a; }


inline FORCE_INLINE vec3 operator*(vec3 v, float f) { return vec3(v.x * f, v.y * f, v.z * f); }
inline FORCE_INLINE vec3 operator/(vec3 v, float f) { return vec3(v.x / f, v.y / f, v.z / f); }

inline FORCE_INLINE vec3 operator*(float f, vec3 v) { return vec3(v.x * f, v.y * f, v.z * f); }
inline FORCE_INLINE vec3 operator/(float f, vec3 v) { return vec3(v.x / f, v.y / f, v.z / f); }

inline FORCE_INLINE vec3& operator*=(vec3& v, float f) { v = v * f; return v; }
inline FORCE_INLINE vec3& operator/=(vec3& v, float f) { v = v * f; return v; }

inline FORCE_INLINE bool operator==(vec3 a, vec3 b) noexcept { 
	__m128 vcmp = _mm_cmpeq_ps(a.v, b.v);
	return _mm_movemask_ps(vcmp);
}


// VEC4
inline FORCE_INLINE vec4 operator*(vec4 a, vec4 b) { return vec4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }
inline FORCE_INLINE vec4 operator/(vec4 a, vec4 b) { return vec4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); }
inline FORCE_INLINE vec4 operator+(vec4 a, vec4 b) { return vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
inline FORCE_INLINE vec4 operator-(vec4 a, vec4 b) { return vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }

inline FORCE_INLINE vec4 &operator*=(vec4& a, vec4 b) { a = a * b; return a; }
inline FORCE_INLINE vec4 &operator/=(vec4& a, vec4 b) { a = a * b; return a; }
inline FORCE_INLINE vec4 &operator+=(vec4& a, vec4 b) { a = a * b; return a; }
inline FORCE_INLINE vec4 &operator-=(vec4& a, vec4 b) { a = a * b; return a; }


inline vec4 operator*(vec4 v, float f) { return vec4(v.x * f, v.y * f, v.z * f, v.w * f); }
inline vec4 operator/(vec4 v, float f) { return vec4(v.x / f, v.y / f, v.z / f, v.w / f); }

inline vec4 operator*(float f, vec4 v) { return v * f; }
inline vec4 operator/(float f, vec4 v) { return vec4(f / v.x, f / v.y, f / v.z, f / v.w); }

inline vec4& operator*=(vec4& v, float f) { v = v * f; return v; }
inline vec4& operator/=(vec4& v, float f) { v = v * f; return v; }

#else

inline vec2 operator*(vec2 a, vec2 b) { return vec2(a.x * b.x, a.y * b.y); }
inline vec2 operator/(vec2 a, vec2 b) { return vec2(a.x / b.x, a.y / b.y); }
inline vec2 operator+(vec2 a, vec2 b) { return vec2(a.x + b.x, a.y + b.y); }
inline vec2 operator-(vec2 a, vec2 b) { return vec2(a.x - b.x, a.y - b.y); }

inline vec2 &operator*=(vec2& a, vec2 b) { a = a * b; return a; }
inline vec2 &operator/=(vec2& a, vec2 b) { a = a * b; return a; }
inline vec2 &operator+=(vec2& a, vec2 b) { a = a * b; return a; }
inline vec2 &operator-=(vec2& a, vec2 b) { a = a * b; return a; }


inline vec2 operator*(vec2 v, float f) { return vec2(v.x * f, v.y * f); }
inline vec2 operator/(vec2 v, float f) { return vec2(v.x / f, v.y / f); }

inline vec2 operator*(float f, vec2 v) { return vec2(v.x * f, v.y * f); }
inline vec2 operator/(float f, vec2 v) { return vec2(v.x / f, v.y / f); }


inline vec2& operator*=(vec2& v, float f) { v = v * f; return v; }
inline vec2& operator/=(vec2& v, float f) { v = v * f; return v; }

inline FORCE_INLINE bool operator==(vec2 a, vec2 b) { return a.x == b.x && a.y == b.y; }


// VEC3
inline vec3 operator*(vec3 a, vec3 b) { return vec3(a.x * b.x, a.y * b.y, a.z * b.z); }
inline vec3 operator/(vec3 a, vec3 b) { return vec3(a.x / b.x, a.y / b.y, a.z / b.z); }
inline vec3 operator+(vec3 a, vec3 b) { return vec3(a.x + b.x, a.y + b.y, a.z + b.z); }
inline vec3 operator-(vec3 a, vec3 b) { return vec3(a.x - b.x, a.y - b.y, a.z - b.z); }

inline vec3 &operator*=(vec3& a, vec3 b) { a = a * b; return a; }
inline vec3 &operator/=(vec3& a, vec3 b) { a = a * b; return a; }
inline vec3 &operator+=(vec3& a, vec3 b) { a = a * b; return a; }
inline vec3 &operator-=(vec3& a, vec3 b) { a = a * b; return a; }


inline vec3 operator*(vec3 v, float f) { return vec3(v.x * f, v.y * f, v.z * f); }
inline vec3 operator/(vec3 v, float f) { return vec3(v.x / f, v.y / f, v.z / f); }

inline vec3 operator*(float f, vec3 v) { return vec3(v.x * f, v.y * f, v.z * f); }
inline vec3 operator/(float f, vec3 v) { return vec3(v.x / f, v.y / f, v.z / f); }

inline vec3& operator*=(vec3& v, float f) { v = v * f; return v; }
inline vec3& operator/=(vec3& v, float f) { v = v * f; return v; }


// VEC4
inline vec4 operator*(vec4 a, vec4 b) { return vec4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }
inline vec4 operator/(vec4 a, vec4 b) { return vec4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); }
inline vec4 operator+(vec4 a, vec4 b) { return vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
inline vec4 operator-(vec4 a, vec4 b) { return vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }

inline vec4 &operator*=(vec4& a, vec4 b) { a = a * b; return a; }
inline vec4 &operator/=(vec4& a, vec4 b) { a = a * b; return a; }
inline vec4 &operator+=(vec4& a, vec4 b) { a = a * b; return a; }
inline vec4 &operator-=(vec4& a, vec4 b) { a = a * b; return a; }


inline vec4 operator*(vec4 v, float f) { return vec4(v.x * f, v.y * f, v.z * f, v.w * f); }
inline vec4 operator/(vec4 v, float f) { return vec4(v.x / f, v.y / f, v.z / f, v.w / f); }

inline vec4 operator*(float f, vec4 v) { return v * f; }
inline vec4 operator/(float f, vec4 v) { return vec4(f / v.x, f / v.y, f / v.z, f / v.w); }

inline vec4& operator*=(vec4& v, float f) { v = v * f; return v; }
inline vec4& operator/=(vec4& v, float f) { v = v * f; return v; }

#endif