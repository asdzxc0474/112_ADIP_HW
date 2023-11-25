class rw
{
public:
	unsigned char* read_Raw_data(char* filename, int height, int width);
	void write_raw_data(char* filename, unsigned char* img, int height, int width);
	cv::Mat Opencv_read_raw_data(char* filename, int height, int width);
};
class hw5
{
public:
	unsigned char* DFT(unsigned char* img, int height, int width, double* real, double* imagine);
	unsigned char* IDFT(unsigned char* img, int height, int width, double* real, double* imagine);
	unsigned char* DCT(unsigned char* img, int height, int width, double* outarr);
	unsigned char* IDCT(double* outarr, int height, int width);
	float MSE(unsigned char* img1, unsigned char* img2, int width, int height);
	float PSNR(float mse, int max);
	void show_Mat_img(cv::Mat img, char* filename);
	float Get_Mat_MSE(cv::Mat img, cv::Mat img2);
	cv::Mat Opencv_DFT(cv::Mat img);
	cv::Mat Opencv_DFT_withoutshift(cv::Mat img);
	cv::Mat Opencv_DFT_COMPLEX_OUTPUT(cv::Mat img);// Complex output
	cv::Mat complex_origin_shift(cv::Mat img);
	cv::Mat Opencv_IDFT(cv::Mat img);// Complex input
	cv::Mat Opencv_show_Complex_Mat(cv::Mat img);
	cv::Mat Gaussian_LPF(cv::Mat img, double D0, bool shift, char* writename); // Complex input
	cv::Mat Gaussian_HPF(cv::Mat img, double D0, bool shift, char* writename);// Complex input
	cv::Mat Butterworth_LPF(cv::Mat img, double D0, double n, bool shift, char* writename);
	cv::Mat Butterworth_HPF(cv::Mat img, double D0, double n, bool shift, char* writename);
	cv::Mat Ideal_LPF(cv::Mat img, double D0, bool shift, char* writename);
	cv::Mat Ideal_HPF(cv::Mat img, double D0, bool shift, char* writename);
	unsigned char* Sobel_DFT(float* img, int height, int width, double* real, double* imagine);
	void Sobel_DFT_mul(double* real, double* imagine, double* s_real, double* s_imagine, double* o_real, double* o_imagine, int height, int width);
};