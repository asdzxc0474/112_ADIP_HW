class rw
{
public:
	unsigned char* read_Raw_data(char* filename, int height, int width);
	void write_raw_data(char* filename, unsigned char* img, int height, int width);
};

class hw3
{
public:
	unsigned char* Binarlize(unsigned char* img1, int height, int width);
	unsigned char* Replace(unsigned char* img1, unsigned char* img2, int height, int width, unsigned char bit);
	unsigned char* logtransform(unsigned char* img1, int height, int width);
	unsigned char* inverse_logtransform(unsigned char* img1, int height, int width);
	unsigned char* power_lowtransform(unsigned char* img1, int height, int width, float gamma);
	unsigned char* negative(unsigned char* img1, int height, int width);
	float* Histogram(unsigned char* img1, int height, int width);
	void Plot_histogram(float* list, char* filename);
	unsigned char* Histogram_equalization(unsigned char* img1, float* list, int height, int width);
	unsigned char* Histogram_matching(unsigned char* img1, float lowerBound, float upperBound, int height, int width);
};