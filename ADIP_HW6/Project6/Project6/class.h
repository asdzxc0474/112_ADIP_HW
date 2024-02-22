class rw
{
public:
	unsigned char* read_Raw_data(char* filename, int height, int width);
	void write_raw_data(char* filename, unsigned char* img, int height, int width);
};

class hw6
{
public:
	float local_mean(unsigned char* img, int width, int x, int y, int filter_size);
	float local_var(unsigned char* img, int width, int x, int y, int filter_size, float local_mean);
	float Noise_variance(unsigned char* img, int height, int width, int pad_width, int filter_size);
	unsigned char trimmed_mean(unsigned char* pad_img, int pad_height, int pad_width, int x, int y, int filter_size, int d);
	unsigned char* IID_DFT(unsigned char* img, int height, int width, double* real, double* imagine);
	unsigned char* IID_IDFT(double* real, double* imagine, int height, int width);
	unsigned char* padding3x3(unsigned char* img, int height, int width);
	unsigned char* padding5x5(unsigned char* img, int height, int width);
	unsigned char* padding7x7(unsigned char* img, int height, int width);
	unsigned char* padding9x9(unsigned char* img, int height, int width);
	unsigned char* adaptive_local_noise_filter_run(unsigned char* img, int height, int width, int filter_size);
	unsigned char* alpha_trimmed_mean_filter_run(unsigned char* img, int height, int width, int filter_size, int d);
	void Motion_blur_IID_DFT(int height, int width, double a, double b, int t, long double* blur_real, long double* blur_imagine);
	unsigned char* Inverse_Filter(double* real, double* imagine, long double* blur_real, long double* blur_imagine, int height, int width,bool with_R, int radius);
	float MSE(unsigned char* img, unsigned char* img2, int height, int width);
	void bubble_sort(unsigned char* arr, int filter_size);
	double* orgin_shift(double* real, int height, int width);
	void show__DFTimg(long double* real, long double* imagine, int height, int width);
	unsigned char* Weiner_Filter(double* real, double* imagine, long double* blur_real, long double* blur_imagine, int height, int width, double K);
	void Pxy_to_Puv(int height, int width, double* real, double* imagine);
	unsigned char* Constrained_Least_Squares_Filtering(double* real, double* imagine, long double* blur_real, long double* blur_imagine, int height, int width, double gamma);
	unsigned char* contour_detect(unsigned char* img, int height, int width);
	unsigned char* warping_relationship(unsigned char* distorted_img, int height, int width);
	void bubble_sort2(long double* arr, int filter_size);
	void show__DFTimg2(double* real, double* imagine, int height, int width);
};