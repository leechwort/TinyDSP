#include "tinydsp.h"
#include "minunit.h"

#define WINDOW_SIZE 32

float input_buffer[WINDOW_SIZE] = {
		0.0,
		1.9509032201612824,
		3.826834323650898,
		5.555702330196022,
		7.071067811865475,
		8.314696123025453,
		9.238795325112868,
		9.807852804032304,
		10.0,
		9.807852804032304,
		9.238795325112868,
		8.314696123025454,
		7.0710678118654755,
		5.555702330196022,
		3.826834323650899,
		1.9509032201612861,
		0.0,
		-1.9509032201612837,
		-3.8268343236508966,
		-5.55570233019602,
		-7.071067811865475,
		-8.314696123025453,
		-9.238795325112864,
		-9.807852804032303,
		-10.0,
		-9.807852804032304,
		-9.238795325112866,
		-8.314696123025454,
		-7.071067811865477,
		-5.555702330196022,
		-3.826834323650904,
		-1.9509032201612873
};
const float correct_results[WINDOW_SIZE] = {
		0.000000,
		0.000000,
		-0.000003,
		-160.00000,
		0.000000,
		0.000000,
		0.000001,
		-0.000001,
		0.000000,
		0.000000,
		-0.000002,
		0.000002,
		0.000000,
		0.000000,
		0.000000,
		0.000000,
		0.000000,
		-0.000000,
		0.000000,
		-0.000000,
		0.000000,
		-0.000000,
		0.000000,
		0.000006,
		0.000000,
		-0.000000,
		0.000000,
		0.000003,
		0.000000,
		-0.000000,
		0.000003,
		0.000008
};
float output_buffer[WINDOW_SIZE];

void test_setup(void) {
	/* Nothing */
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(sine_wave_fftr_check) {
#ifdef TEST_DEBUG
	for (int i = 0; i < WINDOW_SIZE; i++) {
		printf("%f: %f\r\n", output_buffer[i], correct_results[i]);

	}
#endif
	for (int i = 0; i < WINDOW_SIZE; i++) {
		mu_assert_double_eq(output_buffer[i], correct_results[i]);
	}
}

MU_TEST_SUITE(test_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(sine_wave_fftr_check);
}

int main(int argc, char *argv[]) {
	tdsp_rfft_cfg config;
	tdsp_rfft_init(&config, WINDOW_SIZE, false);
	tdsp_rfft_perform(&config, input_buffer, output_buffer);
	tdsp_rfft_cleanup(&config);

	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}
