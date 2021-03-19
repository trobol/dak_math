#include <cmath>
#include <nmmintrin.h> // for SSE4.2
#include <immintrin.h> // for AVX
#include <xmmintrin.h>

#if defined(__GNUC__)
#pragma GCC push_options
#pragma GCC optimize ("-O2")
// dak math function properties
#define DM_FUNC_PROP inline __attribute__((always_inline)) 

#elif defined(_MSC_VER)

#define DM_FUNC_PROP \
	_Pragma("optimize(\"g\", on)") \
	inline


#endif


#define VEC2_ZERO   vec2( 0, 0)
#define VEC2_ONE    vec2( 1, 1)
#define VEC2_LEFT   vec2(-1, 0)
#define VEC2_RIGHT  vec2( 1, 0)
#define VEC2_UP     vec2( 0, 1)
#define VEC2_DOWN   vec2( 0,-1)

#define VEC3_ZERO   vec3( 0, 0, 0)
#define VEC3_ONE    vec3( 1, 1, 1)
#define VEC3_LEFT   vec3(-1, 0, 0)
#define VEC3_RIGHT  vec3( 1, 0, 0)
#define VEC3_UP     vec3( 0, 1, 0)
#define VEC3_DOWN   vec3( 0,-1, 0)
#define VEC3_FRONT  vec3( 0, 0, 1)
#define VEC3_BACK   vec3( 0, 0,-1)

#define VEC4_IDENTITY vec4(0, 0, 0, 1)