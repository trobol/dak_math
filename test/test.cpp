
#include "../dak_math.h"
vec3 a = vec3(1, 1, 1), b(5, 3, 2);
/*

TEST_CASE( "equality", "[vec3]" ) {
	REQUIRE( vec3(0, 0, 0) == vec3(0, 0, 0) );
	REQUIRE( vec3(0, 3, 1) == vec3(0, 3, 1) );
	REQUIRE( vec3(5,-3, 1) == vec3(5,-3, 0) );

	BENCHMARK("equality") {
		return vec3(1, 1, 1) === vec3(1, 1, 1);
	};
}

*/

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

int main() {

	volatile vec3 c = constructor_test();

	volatile float f = dot_test();

	return equality_test();
}

