// STATIC FUNCTIONS


// this is complicated but we really wanna make sure
// that the numbers are not leaving the SIMD (xmm0) registers
// https://gist.github.com/rikusalminen/3040241
#ifdef __SSE3__
inline FORCE_INLINE float dot(vec_generic a, vec_generic b) {
	vec_generic p = _mm_mul_ps(a, b);gvfdf
	// 1, 0, 3, 2
	vec_generic s0 = _mm_shuffle_ps(p, p, 0b01001110);
	s0 = _mm_add_ps(p, s0);
	// 2, 2, 0, 0
	vec_generic s1 = _mm_shuffle_ps(s0, s0, 0b10100000);
	s1 = _mm_add_ps(s0, s1);
	return _mm_cvtss_f32(s1);
}
#elif __SSE__
inline FORCE_INLINE float dot(vec_generic a, vec_generic b) {
	vec_generic p = _mm_mul_ps(a, b);
	// 1, 0, 3, 2
	vec_generic s0 = _mm_shuffle_ps(p, p, 0b01001110);
	s0 = _mm_add_ps(p, s0);
	// 2, 2, 0, 0
	vec_generic s1 = _mm_shuffle_ps(s0, s0, 0b10100000);
	s1 = _mm_add_ps(s0, s1);
	return _mm_cvtss_f32(s1);
}
#else
// TODO: no sse support
#endif

#ifdef __SSE__

inline FORCE_INLINE float lengthSqr(vec_generic v) { return dot(v, v); }
inline FORCE_INLINE float length(vec_generic v) { return sqrt(lengthSqr(v)); }

inline FORCE_INLINE float distanceSqr(vec_generic a, vec_generic b) { return lengthSqr(_mm_sub_ps(a, b)); }
inline FORCE_INLINE float distance(vec_generic a, vec_generic b) { return length(_mm_sub_ps(a, b)); }

inline FORCE_INLINE vec2 normalize(vec2 v) { return v / length(v); }
inline FORCE_INLINE vec3 normalize(vec3 v) { return v / length(v); }
inline FORCE_INLINE vec4 normalize(vec4 v) { return v / length(v); }

inline FORCE_INLINE vec3 cross(vec3 a, vec3 b) { return vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }

#else

inline FORCE_INLINE float lengthSqr(vec2 v) { return v.x * v.x + v.y * v.y; }
inline FORCE_INLINE float lengthSqr(vec3 v) { return v.x * v.x + v.y * v.y + v.z * v.z; }
inline FORCE_INLINE float lengthSqr(vec4 v) { return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w; }

inline FORCE_INLINE float length(vec2 v) { return sqrt(v.x * v.x + v.y * v.y); }
inline FORCE_INLINE float length(vec3 v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }
inline FORCE_INLINE float length(vec4 v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w); }


inline FORCE_INLINE float distance(vec2 a, vec2 b) { return length(a - b); }
inline FORCE_INLINE float distance(vec3 a, vec3 b) { return length(a - b); }
inline FORCE_INLINE float distance(vec4 a, vec4 b) { return length(a - b); }

inline FORCE_INLINE float distanceSqr(vec2 a, vec2 b) { return lengthSqr(a - b); }
inline FORCE_INLINE float distanceSqr(vec3 a, vec3 b) { return lengthSqr(a - b); }
inline FORCE_INLINE float distanceSqr(vec4 a, vec4 b) { return lengthSqr(a - b); }

inline FORCE_INLINE vec2 normalize(vec2 v) { return v / length(v); }
inline FORCE_INLINE vec3 normalize(vec3 v) { return v / length(v); }
inline FORCE_INLINE vec4 normalize(vec4 v) { return v / length(v); }

inline FORCE_INLINE float dot(vec2 a, vec2 b) { return a.x * b.x + a.y * b.y; }
inline FORCE_INLINE float dot(vec3 a, vec3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
inline FORCE_INLINE float dot(vec4 a, vec4 b) { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.z; }



inline FORCE_INLINE vec3 cross(vec3 a, vec3 b) { return vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }

#endif


#ifdef __GNUC_
#pragma GCC pop_options
#endif