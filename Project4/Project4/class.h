class rw
{
public:
	unsigned char* read_Raw_data(char* filename, int height, int width);
	void write_raw_data(char* filename, unsigned char* img, int height, int width);
};
class hw4
{
public:
	double* centroid(unsigned char* img, int height, int width, char* name);
	double central_moment(unsigned char* img, int height, int width, double* centroid, int p, int q, char* name);
	unsigned char* Boxed_filter3x3();
	unsigned char* Gaussian_blur_filter3x3();
	unsigned char* Boxed_filter5x5();
	unsigned char* Gaussian_blur_filter5x5();
	signed char* Perwitt_filter3x3_1();
	signed char* Perwitt_filter3x3_2();
	signed char* Sobel_filter_1();
	signed char* Sobel_filter_2();
	signed char* Sobel_filter_45();
	signed char* Sobel_filter_45_2();
	signed char* Laplacian_filter_4();
	signed char* Laplacian_filter_8();
	float* High_boost_filter_8_2();
	float* High_boost_filter_4_4();
	float* High_boost_filter3_2();
	float* Filter3_1_5x5();
	float* Laplacian_filter_5x5();
	unsigned char* filter3x3_move(unsigned char* img, int height, int width, const char* filter_name);
	unsigned char* filter5x5_move(unsigned char* img, int height, int width, const char* filter_name);
	unsigned char* robert_filter_1(unsigned char* img, int height, int width);
	unsigned char* robert_filter_2(unsigned char* img, int height, int width);
	unsigned char* img_combine(unsigned char* img1, unsigned char* img2, int height, int width);
	unsigned char* img_thresholding(unsigned char* img, int height, int width, unsigned char thresholding);
	unsigned char* OR_Gate(unsigned char* img1, unsigned char* img2, int height, int width);
	unsigned char* IMG_OR(unsigned char* img1, unsigned char* img2, int height, int width);
};