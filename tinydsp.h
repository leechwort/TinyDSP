typedef struct {
	kiss_fftr_cfg cfg;
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
