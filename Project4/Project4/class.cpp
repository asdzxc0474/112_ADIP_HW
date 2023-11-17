#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "class.h"

using namespace std;

unsigned char* rw::read_Raw_data(char* filename, int height, int width)
{
	FILE* input_file;
	int size = height * width;
	unsigned char* input_img = new unsigned char[size];
	input_file = fopen(filename, "rb");
	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}

	fread(input_img, 1, size, input_file);
	fclose(input_file);
	return input_img;
	delete[] input_img;
}
void rw::write_raw_data(char* filename, unsigned char* img, int height, int width)
{
	FILE* output_file;
	int size = width * height;
	output_file = fopen(filename, "wb");
	fwrite(img, 1, size, output_file);
	fclose(output_file);
}

double* hw4::centroid(unsigned char* img, int height, int width,char* name)
{
	double M00 = 0;
	double M10 = 0;
	double M01 = 0;
	double *centroid = new double[2]{};
	for (int m = 0; m < height; m++)
	{
		for (int n = 0; n < width; n++)
		{
			M00 += pow(m, 0) * pow(n, 0) * img[m * height + n];
		}
	}
	for (int m = 0; m < height; m++)
	{
		for (int n = 0; n < width; n++)
		{
			M10 += pow(m, 1) * pow(n, 0) * img[m * height + n];
		}
	}
	for (int m = 0; m < height; m++)
	{
		for (int n = 0; n < width; n++)
		{
			M01 += pow(m, 0) * pow(n, 1) * img[m * height + n];
		}
	}
	double centroid_x = M10 / M00;
	double centroid_y = M01 / M00;
	centroid[0] = centroid_x;
	centroid[1] = centroid_y;
	printf("The centroid of %s is {%f,%f}\n", name, centroid_x, centroid_y);
	return centroid;
	delete[] centroid;
}
double hw4::central_moment(unsigned char* img, int height, int width, double* centroid, int p, int q, char* name)
{
	double u = 0;
	double x = 0;
	double y = 0;
	for (int m = 0; m < height; m++)
	{
		for (int n = 0; n < width; n++)
		{
			x = m - centroid[0];
			y = n - centroid[1];
			u += pow(x, p) * pow(y, q) * img[m * height + n];
		}
	}
	u = abs(u);
	printf("The central moments of %d (p = %d,q = %d) orders on %s is %f\n", p + q, p, q, name, u);
	return u;
}
unsigned char* hw4::Boxed_filter3x3()
{
	unsigned char* Box_filter3x3 = new unsigned char[9] { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	return Box_filter3x3;
}
unsigned char* hw4::Gaussian_blur_filter3x3()
{
	unsigned char* Gaussian_filter3x3 = new unsigned char[9]{ 1, 2, 1, 2, 4, 2, 1, 2, 1 };
	return Gaussian_filter3x3;
}
unsigned char* hw4::Boxed_filter5x5()
{
	unsigned char* Box_filter5x5 = new unsigned char[25]{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	return Box_filter5x5;
}
unsigned char* hw4::Gaussian_blur_filter5x5()
{
	unsigned char* Gaussian_filter5x5 = new unsigned char[25]{ 1, 2, 4, 2, 1, 2, 4, 8, 4, 2, 4, 8, 16, 8, 4, 2, 4, 8, 4, 2, 1, 2, 4, 2, 1 };
	return Gaussian_filter5x5;
}
signed char* hw4::Perwitt_filter3x3_1()
{
	signed char* Perwitt_filter = new signed char[9]{ 1, 1, 1, 0, 0, 0, -1, -1, -1};
	return Perwitt_filter;
}
signed char* hw4::Perwitt_filter3x3_2()
{
	signed char* Perwitt_filter = new signed char[9]{ 1, 0, -1, 1, 0, -1, 1, 0, -1 };
	return Perwitt_filter;
}
signed char* hw4::Sobel_filter_1() 
{
	signed char* Sobel_filter = new signed char[9]{ 1, 2, 1, 0, 0, 0, -1, -2, -1 };
	return Sobel_filter;
}
signed char* hw4::Sobel_filter_2()
{
	signed char* Sobel_filter = new signed char[9]{ 1, 0, -1, 2, 0, -2, 1, 0, -1};
	return Sobel_filter;
}
signed char* hw4::Sobel_filter_45()
{
	signed char* Sobel_filter_45 = new signed char[9]{\
		0, 1, 2, \
		-1, 0, 1, \
		-2, -1, 0};
	return Sobel_filter_45;
}
signed char* hw4::Sobel_filter_45_2()
{
	signed char* Sobel_filter_45_2 = new signed char[9]{\
		-2, -1, 0,\
		-1, 0, 1,\
		0, 1, 2 };
	return Sobel_filter_45_2;
}
signed char* hw4::Laplacian_filter_4()
{
	signed char* Laplacian_filter_4 = new signed char[9]{ 0, -1, 0, -1, 4, -1, 0, -1, 0};
	return Laplacian_filter_4;
}
signed char* hw4::Laplacian_filter_8()
{
	signed char* Laplacian_filter_8 = new signed char[9]{ -1, -1, -1, -1, 8, -1, -1, -1, -1};
	return Laplacian_filter_8;
}
float* hw4::High_boost_filter_8_2()
{
	float* High_boost_filter_8_2 = new float[9]\
	{
		-1, -1, -1,\
		-1, 9.2, -1,\
		-1, -1, -1 \
	};
	return High_boost_filter_8_2;
}
float* hw4::High_boost_filter_4_4()
{
	float* High_boost_filter_4_4 = new float[9]\
	{
		0, -1, 0,\
		-1, 5.2, -1,\
		0, -1, 0\
	};
	return High_boost_filter_4_4;
}
float* hw4::High_boost_filter3_2() 
{
	float* High_boost_filter3_2 = new float[9]\
	{
		-1, -1, -1, \
		-1, 9, -1, \
		-1, -1, -1\
	};
	return High_boost_filter3_2;
}
float* hw4::Laplacian_filter_5x5()
{
	float* Laplacian_filter_5x5 = new float[25]{ \
		-1, -1, -1, -1, -1, \
		-1, -2, -2, -2, -1, \
		-1, -2, 32, -2, -1,\
		-1, -2, -2, -2, -1, \
		-1, -1, -1, -1, -1, \
	};
	return Laplacian_filter_5x5;
}
float* hw4::Filter3_1_5x5()
{
	float* Filter3_1_5x5 = new float[25]{ \
		1, 1, 1, 1, 1, \
		1, 2, 2, 2, 1, \
		1, 2, -30, 2, 1,\
		1, 2, 2, 2, 1, \
		1, 1, 1, 1, 1, \
	};
	return Filter3_1_5x5;
}
unsigned char* hw4::filter3x3_move(unsigned char* img, int height, int width, const char* filter_name)
{
	int add = 0;
	int dst_size = height * width;
	unsigned char* out_img = new unsigned char[dst_size];
	const char* Box_filter = "Box_filter";
	const char* Gaussian_filter = "Gaussian_filter";
	const char* Perwitt_filter = "Perwitt_filter";
	const char* Perwitt_filter90 = "Perwitt_filter90";
	const char* Sobel_filter = "Sobel_filter";
	const char* Sobel_filter90 = "Sobel_filter90";
	const char* Sobel_filter45 = "Sobel_filter45";
	const char* Sobel_filter45_2 = "Sobel_filter_45";
	const char* Laplacian_filter_4n = "Laplacian_filter_4";
	const char* Laplacian_filter_8n = "Laplacian_filter_8";
	const char* High_boost_filter_4 = "High_boost_filter_4";
	const char* High_boost_filter_8 = "High_boost_filter_8";

	int padded_height = height + 2;
	int padded_width = width + 2;
	int padded_size = padded_height * padded_width;
	unsigned char* img_padding = new unsigned char[padded_size];

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			img_padding[(i + 1) * padded_width + j + 1] = img[i * width + j];
		}
	}
	for (int j = 1; j <= width; j++)
	{
		img_padding[j] = img[j - 1];
	}
	for (int j = 1; j <= width; j++)
	{
		img_padding[padded_size - padded_width + j] = img[(height - 1) * width + (j - 1)];
	}
	for (int i = 0; i < padded_height; i++)
	{
		img_padding[i * padded_width] = img_padding[i * padded_width + 1];
		img_padding[(i + 1) * padded_width - 1] = img_padding[(i + 1) * padded_width - 2];
	}
	if (strcmp(filter_name, Gaussian_filter) == 0)
		{
			unsigned char* filter = Gaussian_blur_filter3x3();
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					add = filter[0] * img_padding[(i) * padded_width + (j)] \
						+ filter[1] * img_padding[(i) * padded_width + (j + 1)] \
						+ filter[2] * img_padding[(i) * padded_width + (j + 2)] \
						+ filter[3] * img_padding[(i + 1) * padded_width + (j)] \
						+ filter[4] * img_padding[(i + 1) * padded_width + (j + 1)] \
						+ filter[5] * img_padding[(i + 1) * padded_width + (j + 2)] \
						+ filter[6] * img_padding[(i + 2) * padded_width + (j)] \
						+ filter[7] * img_padding[(i + 2) * padded_width + (j + 1)] \
						+ filter[8] * img_padding[(i + 2) * padded_width + (j + 2)];
					out_img[i * width + j] = (unsigned char)(add / 16);
				}
			}
		}
	else if (strcmp(filter_name, Box_filter) == 0)
	{
		unsigned char* filter = Boxed_filter3x3();
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				add = filter[0] * img_padding[(i)* padded_width + (j)] \
					+ filter[1] * img_padding[(i)* padded_width + (j + 1)] \
					+ filter[2] * img_padding[(i)* padded_width + (j + 2)] \
					+ filter[3] * img_padding[(i + 1) * padded_width + (j)] \
					+ filter[4] * img_padding[(i + 1) * padded_width + (j + 1)] \
					+ filter[5] * img_padding[(i + 1) * padded_width + (j + 2)] \
					+ filter[6] * img_padding[(i + 2) * padded_width + (j)] \
					+ filter[7] * img_padding[(i + 2) * padded_width + (j + 1)] \
					+ filter[8] * img_padding[(i + 2) * padded_width + (j + 2)];
				out_img[i * width + j] = (unsigned char)(add / 9);
			}
		}
	}
	else if (strcmp(filter_name, Perwitt_filter) == 0)
	{
		signed char* filter = Perwitt_filter3x3_1();
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				add = filter[0] * img_padding[(i)* padded_width + (j)] \
					+ filter[1] * img_padding[(i)* padded_width + (j + 1)] \
					+ filter[2] * img_padding[(i)* padded_width + (j + 2)] \
					+ filter[3] * img_padding[(i + 1) * padded_width + (j)] \
					+ filter[4] * img_padding[(i + 1) * padded_width + (j + 1)] \
					+ filter[5] * img_padding[(i + 1) * padded_width + (j + 2)] \
					+ filter[6] * img_padding[(i + 2) * padded_width + (j)] \
					+ filter[7] * img_padding[(i + 2) * padded_width + (j + 1)] \
					+ filter[8] * img_padding[(i + 2) * padded_width + (j + 2)];
				if (add < 0)
				{
					out_img[i * width + j] = 0;
				}
					else
				{
					out_img[i * width + j] = (unsigned char)(add);
				}
			}
		}
	}
	else if (strcmp(filter_name, Perwitt_filter90) == 0)
	{
		signed char* filter = Sobel_filter_1();
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				add = filter[0] * img_padding[(i)* padded_width + (j)] \
					+ filter[1] * img_padding[(i)* padded_width + (j + 1)] \
					+ filter[2] * img_padding[(i)* padded_width + (j + 2)] \
					+ filter[3] * img_padding[(i + 1) * padded_width + (j)] \
					+ filter[4] * img_padding[(i + 1) * padded_width + (j + 1)] \
					+ filter[5] * img_padding[(i + 1) * padded_width + (j + 2)] \
					+ filter[6] * img_padding[(i + 2) * padded_width + (j)] \
					+ filter[7] * img_padding[(i + 2) * padded_width + (j + 1)] \
					+ filter[8] * img_padding[(i + 2) * padded_width + (j + 2)];

				if (add < 0)
				{
					out_img[i * width + j] = 0;
				}
				else
				{
					out_img[i * width + j] = (unsigned char)(add);
				}
			}
		}
	}
	else if (strcmp(filter_name, Sobel_filter) == 0)
	{
		signed char* filter = Sobel_filter_1();
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				add = filter[0] * img_padding[(i)* padded_width + (j)] \
					+ filter[1] * img_padding[(i)* padded_width + (j + 1)] \
					+ filter[2] * img_padding[(i)* padded_width + (j + 2)] \
					+ filter[3] * img_padding[(i + 1) * padded_width + (j)] \
					+ filter[4] * img_padding[(i + 1) * padded_width + (j + 1)] \
					+ filter[5] * img_padding[(i + 1) * padded_width + (j + 2)] \
					+ filter[6] * img_padding[(i + 2) * padded_width + (j)] \
					+ filter[7] * img_padding[(i + 2) * padded_width + (j + 1)] \
					+ filter[8] * img_padding[(i + 2) * padded_width + (j + 2)];

				if (add < 0)
				{
					out_img[i * width + j] = 0;
				}
				else
				{
					out_img[i * width + j] = (unsigned char)(add);
				}
			}
		}
	}
	else if (strcmp(filter_name, Sobel_filter90) == 0)
	{
		signed char* filter = Sobel_filter_2();
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				add = filter[0] * img_padding[(i)* padded_width + (j)] \
					+ filter[1] * img_padding[(i)* padded_width + (j + 1)] \
					+ filter[2] * img_padding[(i)* padded_width + (j + 2)] \
					+ filter[3] * img_padding[(i + 1) * padded_width + (j)] \
					+ filter[4] * img_padding[(i + 1) * padded_width + (j + 1)] \
					+ filter[5] * img_padding[(i + 1) * padded_width + (j + 2)] \
					+ filter[6] * img_padding[(i + 2) * padded_width + (j)] \
					+ filter[7] * img_padding[(i + 2) * padded_width + (j + 1)] \
					+ filter[8] * img_padding[(i + 2) * padded_width + (j + 2)];

				if (add < 0)
				{
					out_img[i * width + j] = 0;
				}
				else
				{
					out_img[i * width + j] = (unsigned char)(add);
				}
			}
		}
	}
	else if (strcmp(filter_name, Sobel_filter45) == 0)
	{
	signed char* filter = Sobel_filter_45();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			add = filter[0] * img_padding[(i)*padded_width + (j)] \
				+ filter[1] * img_padding[(i)*padded_width + (j + 1)] \
				+ filter[2] * img_padding[(i)*padded_width + (j + 2)] \
				+ filter[3] * img_padding[(i + 1) * padded_width + (j)] \
				+ filter[4] * img_padding[(i + 1) * padded_width + (j + 1)] \
				+ filter[5] * img_padding[(i + 1) * padded_width + (j + 2)] \
				+ filter[6] * img_padding[(i + 2) * padded_width + (j)] \
				+ filter[7] * img_padding[(i + 2) * padded_width + (j + 1)] \
				+ filter[8] * img_padding[(i + 2) * padded_width + (j + 2)];

			if (add < 0)
			{
				out_img[i * width + j] = 0;
			}
			else
			{
				out_img[i * width + j] = (unsigned char)(add);
			}
		}
	}
	}
	else if (strcmp(filter_name, Sobel_filter45_2) == 0)
	{
	signed char* filter = Sobel_filter_45_2();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			add = filter[0] * img_padding[(i)*padded_width + (j)] \
				+ filter[1] * img_padding[(i)*padded_width + (j + 1)] \
				+ filter[2] * img_padding[(i)*padded_width + (j + 2)] \
				+ filter[3] * img_padding[(i + 1) * padded_width + (j)] \
				+ filter[4] * img_padding[(i + 1) * padded_width + (j + 1)] \
				+ filter[5] * img_padding[(i + 1) * padded_width + (j + 2)] \
				+ filter[6] * img_padding[(i + 2) * padded_width + (j)] \
				+ filter[7] * img_padding[(i + 2) * padded_width + (j + 1)] \
				+ filter[8] * img_padding[(i + 2) * padded_width + (j + 2)];

			if (add < 0)
			{
				out_img[i * width + j] = 0;
			}
			else
			{
				out_img[i * width + j] = (unsigned char)(add);
			}
		}
	}
	}
	else if (strcmp(filter_name, Laplacian_filter_4n) == 0)
	{
		signed char* filter = Laplacian_filter_4();
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				add = filter[0] * img_padding[(i)*padded_width + (j)] \
					+ filter[1] * img_padding[(i)*padded_width + (j + 1)] \
					+ filter[2] * img_padding[(i)*padded_width + (j + 2)] \
					+ filter[3] * img_padding[(i + 1) * padded_width + (j)] \
					+ filter[4] * img_padding[(i + 1) * padded_width + (j + 1)] \
					+ filter[5] * img_padding[(i + 1) * padded_width + (j + 2)] \
					+ filter[6] * img_padding[(i + 2) * padded_width + (j)] \
					+ filter[7] * img_padding[(i + 2) * padded_width + (j + 1)] \
					+ filter[8] * img_padding[(i + 2) * padded_width + (j + 2)];

				if (add < 0)
				{
					out_img[i * width + j] = 0;
				}
				else
				{
					out_img[i * width + j] = (unsigned char)(add);
				}
			}
		}
	}
	else if (strcmp(filter_name, Laplacian_filter_8n) == 0)
	{
	signed char* filter = Laplacian_filter_8();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			add = filter[0] * img_padding[(i)*padded_width + (j)] \
				+ filter[1] * img_padding[(i)*padded_width + (j + 1)] \
				+ filter[2] * img_padding[(i)*padded_width + (j + 2)] \
				+ filter[3] * img_padding[(i + 1) * padded_width + (j)] \
				+ filter[4] * img_padding[(i + 1) * padded_width + (j + 1)] \
				+ filter[5] * img_padding[(i + 1) * padded_width + (j + 2)] \
				+ filter[6] * img_padding[(i + 2) * padded_width + (j)] \
				+ filter[7] * img_padding[(i + 2) * padded_width + (j + 1)] \
				+ filter[8] * img_padding[(i + 2) * padded_width + (j + 2)];

			if (add < 0)
			{
				out_img[i * width + j] = 0;
			}
			else
			{
				out_img[i * width + j] = (unsigned char)(add);
			}
		}
	}
	}
	else if (strcmp(filter_name, High_boost_filter_4) == 0)
	{
	float* filter = High_boost_filter_4_4();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			add = filter[0] * img_padding[(i)*padded_width + (j)] \
				+ filter[1] * img_padding[(i)*padded_width + (j + 1)] \
				+ filter[2] * img_padding[(i)*padded_width + (j + 2)] \
				+ filter[3] * img_padding[(i + 1) * padded_width + (j)] \
				+ filter[4] * img_padding[(i + 1) * padded_width + (j + 1)] \
				+ filter[5] * img_padding[(i + 1) * padded_width + (j + 2)] \
				+ filter[6] * img_padding[(i + 2) * padded_width + (j)] \
				+ filter[7] * img_padding[(i + 2) * padded_width + (j + 1)] \
				+ filter[8] * img_padding[(i + 2) * padded_width + (j + 2)];

			if (add < 0)
			{
				out_img[i * width + j] = 0;
			}
			else
			{
				out_img[i * width + j] = (unsigned char)(add);
			}
		}
	}
	}
	else if (strcmp(filter_name, High_boost_filter_8) == 0)
	{
	float* filter = High_boost_filter_8_2();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			add = filter[0] * img_padding[(i)*padded_width + (j)] \
				+ filter[1] * img_padding[(i)*padded_width + (j + 1)] \
				+ filter[2] * img_padding[(i)*padded_width + (j + 2)] \
				+ filter[3] * img_padding[(i + 1) * padded_width + (j)] \
				+ filter[4] * img_padding[(i + 1) * padded_width + (j + 1)] \
				+ filter[5] * img_padding[(i + 1) * padded_width + (j + 2)] \
				+ filter[6] * img_padding[(i + 2) * padded_width + (j)] \
				+ filter[7] * img_padding[(i + 2) * padded_width + (j + 1)] \
				+ filter[8] * img_padding[(i + 2) * padded_width + (j + 2)];

			if (add < 0)
			{
				out_img[i * width + j] = 0;
			}
			else
			{
				out_img[i * width + j] = (unsigned char)(add);
			}
		}
	}
	}
	return out_img;
	delete[] out_img;
}
unsigned char* hw4::filter5x5_move(unsigned char* img, int height, int width, const char* filter_name)
{
	int add = 0;
	int padded_height = height + 4;
	int padded_width = width + 4;
	int dst_size = height * width;
	int padded_size = padded_height * padded_width;
	unsigned char* out_img = new unsigned char[dst_size];
	unsigned char* img_padding = new unsigned char[padded_size];
	const char* Box_filter = "Box_filter";
	const char* Gaussian_filter = "Gaussian_filter";
	const char* filter_3_1 = "Filter3_1";
	const char* Laplacian_filter = "Laplacian_filter";

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			img_padding[(i + 2) * padded_width + j + 2] = img[i * width + j];
		}
	}
	for (int j = 1; j <= width; j++)
	{
		img_padding[j] = img[j - 2];
		img_padding[padded_width + j] = img[j - 2];
	}
	for (int j = 0; j <= width; j++)
	{
		img_padding[padded_size - 2 * padded_width + j + 2] = img[(height - 1) * width + j];
		img_padding[padded_size - padded_width + j + 2] = img[(height - 1) * width + j];
	}
	for (int i = 0; i < padded_height; i++)
	{
		img_padding[i * padded_width] = img_padding[i * padded_width + 2];
		img_padding[i * padded_width + 1] = img_padding[i * padded_width + 2];
		img_padding[(i + 1) * padded_width - 1] = img_padding[(i + 1) * padded_width - 3];
		img_padding[(i + 2) * padded_width - 2] = img_padding[(i + 2) * padded_width - 3];
	}
	if (strcmp(filter_name, Gaussian_filter) == 0)
	{
		unsigned char* filter = Gaussian_blur_filter5x5();
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				add = filter[0] * img_padding[(i)*padded_width + (j)] \
					+ filter[1] * img_padding[(i)*padded_width + (j + 1)] \
					+ filter[2] * img_padding[(i)*padded_width + (j + 2)] \
					+ filter[3] * img_padding[(i) *padded_width + (j + 3)] \
					+ filter[4] * img_padding[(i) *padded_width + (j + 4)] \
					+ filter[5] * img_padding[(i + 1) * padded_width + (j)] \
					+ filter[6] * img_padding[(i + 1) * padded_width + (j + 1)] \
					+ filter[7] * img_padding[(i + 1) * padded_width + (j + 2)] \
					+ filter[8] * img_padding[(i + 1) * padded_width + (j + 3)] \
					+ filter[9] * img_padding[(i + 1) * padded_width + (j + 4)] \
					+ filter[10] * img_padding[(i + 2) * padded_width + (j)] \
					+ filter[11] * img_padding[(i + 2) * padded_width + (j + 1)] \
					+ filter[12] * img_padding[(i + 2) * padded_width + (j + 2)] \
					+ filter[13] * img_padding[(i + 2) * padded_width + (j + 3)] \
					+ filter[14] * img_padding[(i + 2) * padded_width + (j + 4)] \
					+ filter[15] * img_padding[(i + 3) * padded_width + (j)] \
					+ filter[16] * img_padding[(i + 3) * padded_width + (j + 1)] \
					+ filter[17] * img_padding[(i + 3) * padded_width + (j + 2)] \
					+ filter[18] * img_padding[(i + 3) * padded_width + (j + 3)] \
					+ filter[19] * img_padding[(i + 3) * padded_width + (j + 4)] \
					+ filter[20] * img_padding[(i + 4) * padded_width + (j)] \
					+ filter[21] * img_padding[(i + 4) * padded_width + (j + 1)] \
					+ filter[22] * img_padding[(i + 4) * padded_width + (j + 2)] \
					+ filter[23] * img_padding[(i + 4) * padded_width + (j + 3)] \
					+ filter[24] * img_padding[(i + 4) * padded_width + (j + 4)];
				out_img[i * width + j] = (unsigned char)(add / 100);
			}
		}
	}
	else if (strcmp(filter_name, Box_filter) == 0)
	{
		unsigned char* filter = Boxed_filter5x5();
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				add = filter[0] * img_padding[(i)*padded_width + (j)] \
					+ filter[1] * img_padding[(i)*padded_width + (j + 1)] \
					+ filter[2] * img_padding[(i)*padded_width + (j + 2)] \
					+ filter[3] * img_padding[(i)*padded_width + (j + 3)] \
					+ filter[4] * img_padding[(i)*padded_width + (j + 4)] \
					+ filter[5] * img_padding[(i + 1) * padded_width + (j)] \
					+ filter[6] * img_padding[(i + 1) * padded_width + (j + 1)] \
					+ filter[7] * img_padding[(i + 1) * padded_width + (j + 2)] \
					+ filter[8] * img_padding[(i + 1) * padded_width + (j + 3)] \
					+ filter[9] * img_padding[(i + 1) * padded_width + (j + 4)] \
					+ filter[10] * img_padding[(i + 2) * padded_width + (j)] \
					+ filter[11] * img_padding[(i + 2) * padded_width + (j + 1)] \
					+ filter[12] * img_padding[(i + 2) * padded_width + (j + 2)] \
					+ filter[13] * img_padding[(i + 2) * padded_width + (j + 3)] \
					+ filter[14] * img_padding[(i + 2) * padded_width + (j + 4)] \
					+ filter[15] * img_padding[(i + 3) * padded_width + (j)] \
					+ filter[16] * img_padding[(i + 3) * padded_width + (j + 1)] \
					+ filter[17] * img_padding[(i + 3) * padded_width + (j + 2)] \
					+ filter[18] * img_padding[(i + 3) * padded_width + (j + 3)] \
					+ filter[19] * img_padding[(i + 3) * padded_width + (j + 4)] \
					+ filter[20] * img_padding[(i + 4) * padded_width + (j)] \
					+ filter[21] * img_padding[(i + 4) * padded_width + (j + 1)] \
					+ filter[22] * img_padding[(i + 4) * padded_width + (j + 2)] \
					+ filter[23] * img_padding[(i + 4) * padded_width + (j + 3)] \
					+ filter[24] * img_padding[(i + 4) * padded_width + (j + 4)];
				out_img[i * width + j] = (unsigned char)(add / 25);
			}
		}
	}
	else if (strcmp(filter_name, filter_3_1) == 0)
	{
		float* filter = Filter3_1_5x5();
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				add = filter[0] * img_padding[(i)*padded_width + (j)] \
					+ filter[1] * img_padding[(i)*padded_width + (j + 1)] \
					+ filter[2] * img_padding[(i)*padded_width + (j + 2)] \
					+ filter[3] * img_padding[(i)*padded_width + (j + 3)] \
					+ filter[4] * img_padding[(i)*padded_width + (j + 4)] \
					+ filter[5] * img_padding[(i + 1) * padded_width + (j)] \
					+ filter[6] * img_padding[(i + 1) * padded_width + (j + 1)] \
					+ filter[7] * img_padding[(i + 1) * padded_width + (j + 2)] \
					+ filter[8] * img_padding[(i + 1) * padded_width + (j + 3)] \
					+ filter[9] * img_padding[(i + 1) * padded_width + (j + 4)] \
					+ filter[10] * img_padding[(i + 2) * padded_width + (j)] \
					+ filter[11] * img_padding[(i + 2) * padded_width + (j + 1)] \
					+ filter[12] * img_padding[(i + 2) * padded_width + (j + 2)] \
					+ filter[13] * img_padding[(i + 2) * padded_width + (j + 3)] \
					+ filter[14] * img_padding[(i + 2) * padded_width + (j + 4)] \
					+ filter[15] * img_padding[(i + 3) * padded_width + (j)] \
					+ filter[16] * img_padding[(i + 3) * padded_width + (j + 1)] \
					+ filter[17] * img_padding[(i + 3) * padded_width + (j + 2)] \
					+ filter[18] * img_padding[(i + 3) * padded_width + (j + 3)] \
					+ filter[19] * img_padding[(i + 3) * padded_width + (j + 4)] \
					+ filter[20] * img_padding[(i + 4) * padded_width + (j)] \
					+ filter[21] * img_padding[(i + 4) * padded_width + (j + 1)] \
					+ filter[22] * img_padding[(i + 4) * padded_width + (j + 2)] \
					+ filter[23] * img_padding[(i + 4) * padded_width + (j + 3)] \
					+ filter[24] * img_padding[(i + 4) * padded_width + (j + 4)];
				out_img[i * width + j] = (unsigned char)(add);
			}
		}
	}
	else if (strcmp(filter_name, Laplacian_filter) == 0)
	{
	float* filter = Laplacian_filter_5x5();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			add = filter[0] * img_padding[(i)*padded_width + (j)] \
				+ filter[1] * img_padding[(i)*padded_width + (j + 1)] \
				+ filter[2] * img_padding[(i)*padded_width + (j + 2)] \
				+ filter[3] * img_padding[(i)*padded_width + (j + 3)] \
				+ filter[4] * img_padding[(i)*padded_width + (j + 4)] \
				+ filter[5] * img_padding[(i + 1) * padded_width + (j)] \
				+ filter[6] * img_padding[(i + 1) * padded_width + (j + 1)] \
				+ filter[7] * img_padding[(i + 1) * padded_width + (j + 2)] \
				+ filter[8] * img_padding[(i + 1) * padded_width + (j + 3)] \
				+ filter[9] * img_padding[(i + 1) * padded_width + (j + 4)] \
				+ filter[10] * img_padding[(i + 2) * padded_width + (j)] \
				+ filter[11] * img_padding[(i + 2) * padded_width + (j + 1)] \
				+ filter[12] * img_padding[(i + 2) * padded_width + (j + 2)] \
				+ filter[13] * img_padding[(i + 2) * padded_width + (j + 3)] \
				+ filter[14] * img_padding[(i + 2) * padded_width + (j + 4)] \
				+ filter[15] * img_padding[(i + 3) * padded_width + (j)] \
				+ filter[16] * img_padding[(i + 3) * padded_width + (j + 1)] \
				+ filter[17] * img_padding[(i + 3) * padded_width + (j + 2)] \
				+ filter[18] * img_padding[(i + 3) * padded_width + (j + 3)] \
				+ filter[19] * img_padding[(i + 3) * padded_width + (j + 4)] \
				+ filter[20] * img_padding[(i + 4) * padded_width + (j)] \
				+ filter[21] * img_padding[(i + 4) * padded_width + (j + 1)] \
				+ filter[22] * img_padding[(i + 4) * padded_width + (j + 2)] \
				+ filter[23] * img_padding[(i + 4) * padded_width + (j + 3)] \
				+ filter[24] * img_padding[(i + 4) * padded_width + (j + 4)];
			
			if (add < 0)
			{
				out_img[i * width + j] = 0;
			}
			else
			{
				out_img[i * width + j] = (unsigned char)(add);
			}
		}

	}
	}
	return out_img;
	delete[] out_img;
}
unsigned char* hw4::robert_filter_1(unsigned char* img, int height, int width)
{
	int add = 0;
	int size = height * width ;
	int padding_size = (height + 1) * (width + 1);
	unsigned char* out_img = new unsigned char[size];
	unsigned char* img_padding = new unsigned char[padding_size];
	signed char* robert_filter_1 = new signed char[4]{ -1, 0, 0, 1 };
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			img_padding[i * (width + 1) + j] = img[i * width + j];
		}
	}
	for (int i = 0; i < height; i++)
	{
		img_padding[(i + 1) * (width + 1) - 1] = img_padding[(i + 1) * (width + 1) - 2];
	}
	for (int i = 0; i <= width; i++)
	{
		img_padding[padding_size - (width + 1) + i] = img_padding[padding_size - 2 * (width + 1) + i];
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			add = robert_filter_1[0] * img_padding[i * (width + 1) + j] +\
				robert_filter_1[1] * img_padding[i * (width + 1) + (j + 1)] +\
				robert_filter_1[2] * img_padding[(i + 1) * (width + 1) + j] +\
				robert_filter_1[3] * img_padding[(i + 1) * (width + 1) + (j + 1)];			
			
			if (add < 0)
			{
				out_img[i * width + j] = 0;
			}
			else
			{
				out_img[i * width + j] = (unsigned char)(add);
			}
		}
	}
	return out_img;
	delete[] out_img;
}
unsigned char* hw4::robert_filter_2(unsigned char* img, int height, int width)
{
	int add = 0;
	int size = height * width;
	int padding_size = (height + 1) * (width + 1);
	unsigned char* out_img = new unsigned char[size];
	unsigned char* img_padding = new unsigned char[padding_size];
	signed char* robert_filter_1 = new signed char[4]{ 0, -1, 1 , 0 };
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			img_padding[i * (width + 1) + j] = img[i * width + j];
		}
	}
	for (int i = 0; i < height; i++)
	{
		img_padding[(i + 1) * (width + 1) - 1] = img_padding[(i + 1) * (width + 1) - 2];
	}
	for (int i = 0; i <= width; i++)
	{
		img_padding[padding_size - (width + 1) + i] = img_padding[padding_size - 2 * (width + 1) + i];
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			add = robert_filter_1[0] * img_padding[i * (width + 1) + j] + \
				robert_filter_1[1] * img_padding[i * (width + 1) + (j + 1)] + \
				robert_filter_1[2] * img_padding[(i + 1) * (width + 1) + j] + \
				robert_filter_1[3] * img_padding[(i + 1) * (width + 1) + (j + 1)];

			if (add < 0)
			{
				out_img[i * width + j] = 0;
			}
			else
			{
				out_img[i * width + j] = (unsigned char)(add);
			}
		}
	}
	return out_img;
	delete[] out_img;
}
unsigned char* hw4::img_combine(unsigned char* img1, unsigned char* img2, int height, int width)
{
	int size = height * width;
	unsigned char* img_combine = new unsigned char[size];
	for (int i = 0; i < size; i++)
	{
		int a = img1[i] + img2[i];
		if (a < 255)
		{
			img_combine[i] = a;
		}
		else
		{
			img_combine[i] = 255;
		}
	}
	return img_combine;
}
unsigned char* hw4::img_thresholding(unsigned char* img, int height, int width, unsigned char thresholding)
{
	int size = height * width;
	unsigned char* img_thresholding = new unsigned char[size];
	for (int i = 0; i < size; i++)
	{
		if (img[i] < thresholding)
		{
			img_thresholding[i] = 0;
		}
		else
		{
			img_thresholding[i] = 255;
		}
	}
	return img_thresholding;
}
unsigned char* hw4::OR_Gate(unsigned char* img, unsigned char* maskimg, int height, int width)
{
	int add = 0;
	int size = height * width;
	unsigned char* filter0 = Gaussian_blur_filter3x3();
	float* filter1 = High_boost_filter3_2();
	unsigned char* img_OR = new unsigned char[size];
	int padded_height = height + 2;
	int padded_width = width + 2;
	int padded_size = padded_height * padded_width;
	unsigned char* img_padding = new unsigned char[padded_size];
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			img_padding[(i + 1) * padded_width + j + 1] = img[i * width + j];
		}
	}
	for (int j = 1; j <= width; j++)
	{
		img_padding[j] = img[j - 1];
	}
	for (int j = 1; j <= width; j++)
	{
		img_padding[padded_size - padded_width + j] = img[(height - 1) * width + (j - 1)];
	}
	for (int i = 0; i < padded_height; i++)
	{
		img_padding[i * padded_width] = img_padding[i * padded_width + 1];
		img_padding[(i + 1) * padded_width - 1] = img_padding[(i + 1) * padded_width - 2];
	}
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (maskimg[i * width + j] == 0)
			{
				add = filter0[0] * img_padding[(i)*padded_width + (j)] \
					+ filter0[1] * img_padding[(i)*padded_width + (j + 1)] \
					+ filter0[2] * img_padding[(i)*padded_width + (j + 2)] \
					+ filter0[3] * img_padding[(i + 1) * padded_width + (j)] \
					+ filter0[4] * img_padding[(i + 1) * padded_width + (j + 1)] \
					+ filter0[5] * img_padding[(i + 1) * padded_width + (j + 2)] \
					+ filter0[6] * img_padding[(i + 2) * padded_width + (j)] \
					+ filter0[7] * img_padding[(i + 2) * padded_width + (j + 1)] \
					+ filter0[8] * img_padding[(i + 2) * padded_width + (j + 2)];
				img_OR[i * width + j] = (unsigned char)(add / 16);
			}
			else
			{
				add = filter1[0] * img_padding[(i)*padded_width + (j)] \
					+ filter1[1] * img_padding[(i)*padded_width + (j + 1)] \
					+ filter1[2] * img_padding[(i)*padded_width + (j + 2)] \
					+ filter1[3] * img_padding[(i + 1) * padded_width + (j)] \
					+ filter1[4] * img_padding[(i + 1) * padded_width + (j + 1)] \
					+ filter1[5] * img_padding[(i + 1) * padded_width + (j + 2)] \
					+ filter1[6] * img_padding[(i + 2) * padded_width + (j)] \
					+ filter1[7] * img_padding[(i + 2) * padded_width + (j + 1)] \
					+ filter1[8] * img_padding[(i + 2) * padded_width + (j + 2)];

				if (add < 0)
				{
					img_OR[i * width + j] = 0;
				}
				else if (add > 255)
				{
					img_OR[i * width + j] = 255;
				}
				else
				{
					img_OR[i * width + j] = (unsigned char)(add);
				}
			}
		}
	}
	return img_OR;
}
unsigned char* hw4::IMG_OR(unsigned char* img1, unsigned char* img2, int height, int width)
{
	int size = height * width;
	unsigned char* img_OR = new unsigned char[size];
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			img_OR[i * width + j] = img1[i * width + j] || img2[i * width + j];
		}
	}
	return img_OR;
}