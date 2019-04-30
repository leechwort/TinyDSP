#include "tinydsp.h"
#include "kiss_fft.h"
#include "kiss_fftr.h"

#include "kiss_fftr.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "kiss_fft.h"
#include <complex.h>
#include <stdbool.h>

tdsp_result tdsp_rfft_init(tdsp_rfft_cfg *cfg, unsigned int fftsize, bool is_ifft)
{
	int inverse_fft = 0;
	if (is_ifft)
		inverse_fft = 1;
	cfg->cfg = kiss_fftr_alloc(fftsize, is_ifft, NULL, NULL);
	return TDSP_OK;
}

tdsp_result tdsp_rfft_perform(tdsp_rfft_cfg *cfg, float *input_data, float *output_data)
{
	kiss_fftr(cfg->cfg, (const kiss_fft_scalar* )&input_buffer[0], (kiss_fft_cpx *)&output_buffer[0]);
	return TDSP_OK;
}
tdsp_result tdsp_rfft_cleanup(tdsp_rfft_cfg *cfg)
{
	free(cfg->cfg);
	return TDSP_OK;
}
