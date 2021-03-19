// STATIC FUNCTIONS


// this is complicated but we really wanna make sure
// that the numbers are not leaving the SIMD (xmm0) registers
// https://gist.github.com/rikusalminen/3040241
#ifdef __SSE3__
DM_FUNC_PROP float dot(vec_generic a, vec_generic b) {
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
DM_FUNC_PROP float dot(vec_generic a, vec_generic b) {
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


DM_FUNC_PROP float lengthSqr(vec_generic v) { return dot(v, v); }
DM_FUNC_PROP float length(vec_generic v) { return sqrt(lengthSqr(v)); }

DM_FUNC_PROP float distanceSqr(vec_generic a, vec_generic b) { return lengthSqr(_mm_sub_ps(a, b)); }
DM_FUNC_PROP float distance(vec_generic a, vec_generic b) { return length(_mm_sub_ps(a, b)); }

DM_FUNC_PROP vec2 normalize(vec2 v) { return v / length(v); }
DM_FUNC_PROP vec3 normalize(vec3 v) { return v / length(v); }
DM_FUNC_PROP vec4 normalize(vec4 v) { return v / length(v); }

DM_FUNC_PROP vec3 cross(vec3 a, vec3 b) {

	const char yzxw = 0b01100011;
	const char zxyw = 0b10000111;
	vec3 c = _mm_shuffle_ps(a, a, yzxw);
	vec3 d = _mm_shuffle_ps(b, b, zxyw);
	vec3 cd = c*d;
	
	vec3 e = _mm_shuffle_ps(a, a, zxyw);
	vec3 f = _mm_shuffle_ps(b, b, yzxw);
	
	vec3 ef = e*f;
	return ef - cd;
}

#else

DM_FUNC_PROP float lengthSqr(vec2 v) { return v.x * v.x + v.y * v.y; }
DM_FUNC_PROP float lengthSqr(vec3 v) { return v.x * v.x + v.y * v.y + v.z * v.z; }
DM_FUNC_PROP float lengthSqr(vec4 v) { return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w; }

DM_FUNC_PROP float length(vec2 v) { return sqrt(v.x * v.x + v.y * v.y); }
DM_FUNC_PROP float length(vec3 v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }
DM_FUNC_PROP float length(vec4 v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w); }


DM_FUNC_PROP float distance(vec2 a, vec2 b) { return length(a - b); }
DM_FUNC_PROP float distance(vec3 a, vec3 b) { return length(a - b); }
DM_FUNC_PROP float distance(vec4 a, vec4 b) { return length(a - b); }

DM_FUNC_PROP float distanceSqr(vec2 a, vec2 b) { return lengthSqr(a - b); }
DM_FUNC_PROP float distanceSqr(vec3 a, vec3 b) { return lengthSqr(a - b); }
DM_FUNC_PROP float distanceSqr(vec4 a, vec4 b) { return lengthSqr(a - b); }

DM_FUNC_PROP vec2 normalize(vec2 v) { return v / length(v); }
DM_FUNC_PROP vec3 normalize(vec3 v) { return v / length(v); }
DM_FUNC_PROP vec4 normalize(vec4 v) { return v / length(v); }

DM_FUNC_PROP float dot(vec2 a, vec2 b) { return a.x * b.x + a.y * b.y; }
DM_FUNC_PROP float dot(vec3 a, vec3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
DM_FUNC_PROP float dot(vec4 a, vec4 b) { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.z; }



DM_FUNC_PROP vec3 cross(vec3 a, vec3 b) { return vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }

#endif


#ifdef __GNUC_
#pragma GCC pop_options
#endif