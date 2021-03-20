#include <ctime>
#include <cstdio>
#include <cstdlib>

#include "../dak_math.h"
#include "test.h"

/*

vec3 constructor_test() {
	vec3 c(1, 4, 5);
	return c;
}

bool equality_test() {
	return a == b;
}

float dot_test() {
	return dot(a, b);
}
vec3 mul_test() {
	return a * b;
}

vec3 cross_test() {
	return cross(a, b);
}

*/



float* float_data;
vec2* vec2_data;
vec3* vec3_data;
vec4* vec4_data;

TEST_START


	float_data = new float[ITERATIONS*4];
	for(volatile size_t i = 0; i < ITERATIONS; i++) {
		float_data[i] = rand() / RAND_MAX;
	}

	vec2_data = new vec2[ITERATIONS];
	vec3_data = new vec3[ITERATIONS];
	vec4_data = new vec4[ITERATIONS];


TEST_LOOP_START
	// constructors 
	DEFINE_TEST(VEC2_CONSTR_MEM_1F) {
		float* f = float_data + (test_index*4);
		vec2_data[test_index] = vec2(f[0]);
	}
	DEFINE_TEST(VEC2_CONSTR_MEM_2F) {
		float* f = float_data + (test_index*4);
		vec2_data[test_index] = vec2(f[0], f[1]);
	}

	DEFINE_TEST(VEC3_CONSTRU_MEM_1F) {
		float* f = float_data + (test_index*4);
		vec3_data[test_index] = vec3(f[0]);
	}
	DEFINE_TEST(VEC3_CONSTR_MEM_3F) {
		float* f = float_data + (test_index*4);
		vec3_data[test_index] = vec3(f[0], f[1], f[2]);
	}
	DEFINE_TEST(VEC3_CONSTR_MEM_1F_2F) {
		float* f = float_data + (test_index*4);
		vec3_data[test_index] = vec3(f[0], vec2_data[test_index]);
	}
	DEFINE_TEST(VEC3_CONSTR_MEM_2F_1F) {
		float* f = float_data + (test_index*4);
		vec3_data[test_index] = vec3(vec2_data[test_index], f[0]);
	}


	DEFINE_TEST(VEC4_CONSTRU_MEM_1F) {
		float* f = float_data + (test_index*4);
		vec4_data[test_index] = vec4(f[0]);
	}
	DEFINE_TEST(VEC4_CONSTR_MEM_4F) {
		float* f = float_data + (test_index*4);
		vec4_data[test_index] = vec4(f[0], f[1], f[2], f[3]);
	}
	DEFINE_TEST(VEC4_CONSTR_MEM_2F_2F) {	
		float* f = float_data + (test_index*4);
		vec4_data[test_index] = vec4(vec2_data[test_index], vec2_data[test_index]); //consider changing 
	}
	DEFINE_TEST(VEC4_CONSTR_MEM_2F_1F_1F) {	
		float* f = float_data + (test_index*4);
		vec4_data[test_index] = vec4(vec2_data[test_index], f[0], f[1]); 
	}
	DEFINE_TEST(VEC4_CONSTR_MEM_1F_2F_1F) {	
		float* f = float_data + (test_index*4);
		vec4_data[test_index] = vec4(f[0], vec2_data[test_index], f[1]); 
	}
	DEFINE_TEST(VEC4_CONSTR_MEM_1F_1F_2F) {	
		float* f = float_data + (test_index*4);
		vec4_data[test_index] = vec4(f[0], f[1], vec2_data[test_index]); 
	}
	DEFINE_TEST(VEC4_CONSTR_MEM_3F_1F) {
		float* f = float_data + (test_index*4);
		vec4_data[test_index] = vec4(vec3_data[test_index], f[0]);
	}
	DEFINE_TEST(VEC4_CONSTR_MEM_1F_3F) {
		float* f = float_data + (test_index*4);
		vec4_data[test_index] = vec4(f[0], vec3_data[test_index]);
	}
	
	//Vec 2 Opperations


	/*DEFINE_TEST(VEC2_MULT_VEC2) {
		float* f = float_data + (test_index*4);
		vec3_data[test_index] = vec3(vec2_data[test_index], f[0]);
	}*/
	


TEST_LOOP_END

	
	delete float_data;
	delete vec2_data;
	delete vec3_data;
	delete vec4_data;

TEST_END
