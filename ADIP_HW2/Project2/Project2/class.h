class rw
{
public:
	unsigned char* read_Raw_data(char* filename, int height, int width);
	void write_raw_data(char* filename, unsigned char* img, int height, int width);
};
class hw2function
{
public:
	float MSE(int width, int height, unsigned char* img1, unsigned char* img2);
	float PSNR(float mse, int max);
	void executiontime(clock_t a, clock_t b);
	unsigned char* RCzoom_in(unsigned char* img1, int width, int height, int ratio);
	unsigned char* RC_deletion(unsigned char* img1, int width, int height, int ratio);
	unsigned char* Nneighbor(unsigned char* img1, int width, int height, float ratio);
	unsigned char* Bilinear(unsigned char* img1, int width, int height, float ratio);
	unsigned char* Bicubic(unsigned char* img1, int width, int height, float ratio);
	double BicubicWeight(double x);
	unsigned char* HW2_1Path_img(unsigned char* img1, int width, int height, int arr[]);
	unsigned char* HW2_2Path_img(unsigned char* img1, int width, int height, int arr[]);
	unsigned char* HW2_3Path_img(unsigned char* img1, int width, int height, int arr[]);
	unsigned char* D4Path(unsigned char* img1, int width, int height);
	unsigned char* D8Path(unsigned char* img1, int width, int height);
	unsigned char* DmPath(unsigned char* img1, int width, int height);
	unsigned char* quantize(unsigned char* img1, int width, int height, int bit);
	unsigned char* HW4average(unsigned char* img1, int width, int height, int ratio);
	unsigned char* HW4draw(unsigned char* img1);
};