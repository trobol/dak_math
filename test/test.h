#include <ctime>
#include <cstdio>
#include <cstdlib>

#define ITERATIONS 100000000

#define TEST_REPEAT 10

#define MAX_TEST_COUNT 200

typedef clock_t times_t[TEST_REPEAT];

const char* tests_names[MAX_TEST_COUNT];
times_t tests_times[MAX_TEST_COUNT];

void test_register(const char* name, size_t test_index) {
	if ( test_index >= MAX_TEST_COUNT ) {
		printf("TOO MANY TESTS ADDED\n");
		exit(1);
	}

	if (tests_names[test_index] != nullptr) return;

	tests_names[test_index] = name;
	
}



void test_end(size_t test_index, size_t iteration, clock_t time_start) {
	clock_t time_end = clock();
	clock_t time_total = time_end - time_start;
	tests_times[test_index][iteration] = time_total;
}

#define TEST_START \
int main() { \
printf("initializing\n"); \
clock_t test_init_start = clock(); \
size_t test_index; 


#define TEST_LOOP_START \
clock_t test_init_end = clock(); \
clock_t test_init_total = test_init_end - test_init_start; \
printf("initialized in %f\n", (double)test_init_total / CLOCKS_PER_SEC); \
printf("running tests"); \
for (size_t test_iteration = 0; test_iteration < TEST_REPEAT; test_iteration++) { \
test_index = 0; \
const size_t runs_per_test = ITERATIONS; \
clock_t tests_time_start = clock();

#define TEST_LOOP_END \
clock_t tests_time_end = clock(); \
clock_t tests_time_total = tests_time_end - tests_time_start; \
printf("finished %i tests in %fs\n", test_index, (double)tests_time_total / CLOCKS_PER_SEC); \
}

#define TEST_END \
print_test_results(test_index); \
}

#define DEFINE_TEST(name) \
test_register(#name, test_index++); \
clock_t test_start_##name = clock(); \
for (size_t i = 0; i < ITERATIONS || (test_end( test_index, test_iteration, test_start_##name ), false); i++)



void print_test_results(size_t test_count) {
	for (size_t i = 0; i < test_count; i++) {
		clock_t average = 0;
		clock_t max = 0;
		clock_t min = 1000000000;
		for (size_t j = 0; j < TEST_REPEAT; j++) {
			clock_t c = tests_times[i][j];
			average += c;
			max = c > max ? c : max;
			min = c < min ? c : min;
		}

		average /= TEST_REPEAT;
		printf("%s avg: %fs min: %fs max: %fs\n", tests_names[i], (double)average / CLOCKS_PER_SEC, (double)min / CLOCKS_PER_SEC, (double)max / CLOCKS_PER_SEC);
	}
}