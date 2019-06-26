#ifndef TINYDSP_H
#define TINYDSP_H

#include <stdbool.h>

/* Choose FFT engine USE_KISSFFT - generic USE_ARMDSP - ARM-specific */
#define USE_KISSFFT
//#define USE_ARMDSP

#if defined(USE_KISSFFT)
#include "kiss_fft.h"
#include "kiss_fftr.h"
#elif defined(USE_ARMDSP)
#include "arm_math.h"
#include "arm_const_structs.h"
#endif

typedef struct {

#if defined(USE_KISSFFT)
	kiss_fftr_cfg cfg;
#elif defined(USE_ARMDSP)
	arm_rfft_fast_instance_f32 S;
	arm_status status;
#endif
	bool is_ifft;
	int fftsize;
	float *input_data;
	float *output_data;
} tdsp_rfft_cfg;

typedef enum
{
    TDSP_OK,
    TDSP_FAIL
} tdsp_result;

tdsp_result tdsp_rfft_init(tdsp_rfft_cfg *cfg, unsigned int fftsize, bool is_ifft);
tdsp_result tdsp_rfft_perform(tdsp_rfft_cfg *cfg, float *input_data, float *output_data);
tdsp_result tdsp_rfft_cleanup(tdsp_rfft_cfg *cfg);

#endif /* TINYDSP_H */
