#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "class.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
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

float hw2function::MSE(int width, int height, unsigned char* img1, unsigned char* img2)
{
	float MSE = 0;
	int size = height * width;
	for (int i = 0; i < size; i++)
	{
		MSE += pow(*(img1 + i) - *(img2 + i), 2);
	}
	MSE = MSE / size;
	printf("MSE = %f\n", MSE);
	return MSE;
}
float hw2function::PSNR(float mse, int max)
{
	float psnr = 10 * log10(max * max / mse);
	printf("PSNR = %f\n", psnr);
	return psnr;
}
void hw2function::executiontime(clock_t a, clock_t b)
{
	printf("\nExecution time:%d ms\n", b - a);
}
unsigned char* hw2function::RCzoom_in(unsigned char* img1, int width, int height, int ratio)
{
	int size = height * width * ratio * ratio;
	unsigned char* img_zoom = new unsigned char[size];
	for (int j = 0; j < height * ratio; j += ratio)
	{
		for (int i = 0; i < width * ratio; i += ratio)
		{
			for (int r1 = 0; r1 < ratio; r1++)
			{
				for (int r2 = 0; r2 < ratio; r2++)
				{
					*(img_zoom + height * ratio * (j + r1) + i + r2) = *(img1 + height * j / ratio + i / ratio);

				}
			}
		}
	}
	return img_zoom;
}
unsigned char* hw2function::RC_deletion(unsigned char* img1, int width, int height, int ratio)
{
	int size = height * width / ratio / ratio;
	unsigned char* img_shrink = new unsigned char[size];
	for (int j = 0; j < height; j += ratio)
	{
		for (int i = 0; i < width; i += ratio)
		{
			*(img_shrink + height / ratio * j / ratio + i / ratio) = *(img1 + height * j + i);
		}
	}
	return img_shrink;
}
unsigned char* hw2function::Nneighbor(unsigned char* img1, int width, int height, float ratio)
{
	float size = round(width * ratio) * round(height * ratio);
	unsigned char* img_nnzoom = new unsigned char[size];
	for (float j = 0; j < round(height * ratio); j++)
	{
		for (float i = 0; i < round(height * ratio); i++)
		{
			if (round(j / ratio) == height || round(i / ratio) == width)
			{
				*(img_nnzoom + int(round(height * ratio) * j) + int(i)) = *(img1 + height * int(j / ratio) + int(i / ratio));
			}
			else
			{
				*(img_nnzoom + int(round(height * ratio) * j) + int(i)) = *(img1 + height * int(round(j / ratio)) + int(round(i / ratio)));
			}

		}
	}
	return img_nnzoom;
}
unsigned char* hw2function::Bilinear(unsigned char* img1, int width, int height, float ratio)
{
	int size = round(width * ratio) * round(height * ratio);
	unsigned char* img_bilinear = new unsigned char[size];
	for (double j = 0; j < round(height * ratio); j++)
	{
		for (double i = 0; i < round(width * ratio); i++)
		{
			if (ceil(i / ratio) != height && ceil(j / ratio) != width)
			{
				unsigned char a = *(img1 + height * int(floor(j / ratio)) + int(floor(i / ratio)));
				unsigned char b = *(img1 + height * int(floor(j / ratio)) + int(ceil(i / ratio)));
				unsigned char c = *(img1 + height * int(ceil(j / ratio)) + int(floor(i / ratio)));
				unsigned char d = *(img1 + height * int(ceil(j / ratio)) + int(ceil(i / ratio)));

				unsigned char e = a * (1 - fmod(i, ratio) / ratio) + b * (fmod(i, ratio) / ratio);
				unsigned char f = c * (1 - fmod(i, ratio) / ratio) + d * (fmod(i, ratio) / ratio);
				unsigned char g = e * (1 - fmod(j, ratio) / ratio) + f * (fmod(j, ratio) / ratio);
				*(img_bilinear + int(round(height * ratio) * j) + int(i)) = g;
			}
			else if (ceil(i / ratio) == height || ceil(j / ratio) == width)
			{
				unsigned char a = *(img1 + height * int(floor(j / ratio)) + int(floor(i / ratio)));
				unsigned char b = *(img1 + height * int(floor(j / ratio)) + int(floor(i / ratio)));
				unsigned char c = *(img1 + height * int(floor(j / ratio)) + int(floor(i / ratio)));
				unsigned char d = *(img1 + height * int(floor(j / ratio)) + int(floor(i / ratio)));

				unsigned char e = a * (1 - fmod(i, ratio) / ratio) + b * (fmod(i, ratio) / ratio);
				unsigned char f = c * (1 - fmod(i, ratio) / ratio) + d * (fmod(i, ratio) / ratio);
				unsigned char g = e * (1 - fmod(j, ratio) / ratio) + f * (fmod(j, ratio) / ratio);
				*(img_bilinear + int(round(height * ratio) * j) + int(i)) = g;
			}
		}
	}
	return img_bilinear;
}
unsigned char* hw2function::Bicubic(unsigned char* img1, int width, int height, float ratio)
{
	int size = round(width * ratio) * round(height * ratio);
	unsigned char* img_bicubic = new unsigned char[size];
	for (double j = 0; j < round(height * ratio); j++)
	{
		for (double i = 0; i < round(width * ratio); i++)
		{
			double x_original = i / ratio;
			double y_original = j / ratio;
			int x1 = max(0,int(floor(x_original) - 1));
			int y1 = max(0,int(floor(y_original) - 1));

			double result = 0.0;
			for (int m = 0; m < 4; m++)
			{
				for (int n = 0; n < 4; n++)
				{
					int x = max(0, min(width - 1, x1 + n));
					int y = max(0, min(height - 1, y1 + m));
					double weight = BicubicWeight(x_original - x) * BicubicWeight(y_original - y);
					result += weight * img1[y * height + x];
				}
			}

			if (x_original >= width - 2 || y_original >= height - 2)
			{
				result = *(img1 + height * int(j / ratio) + int(i / ratio));
			}

			int index = int(round(height * ratio) * j + i);
			*(img_bicubic + index) = result;
		}
	}
	return img_bicubic;	
}
double hw2function::BicubicWeight(double x) 
{
	const double a = -0.5;
	double ax = fabs(x);
	if (ax <= 1.0)
	{
		return (a+2.0)*pow(ax,3) - (a + 3.0) * pow(ax, 2) + 1.0;
	}
	else if (ax < 2.0) 
	{
		return a * pow(ax, 3) - 5.0 * a * pow(ax, 2) + 8.0 * a * ax - 4.0 * a;
	}
	else 
	{
		return 0.0;
	}
}
unsigned char* hw2function::HW2_1Path_img(unsigned char* img1, int width, int height, int arr[])
{
	int size = width * height;
	int length = sizeof(arr) / sizeof(int);
	unsigned char* img_Path = new unsigned char[size];
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			for (int len = 0; len < length; len++)
			{
				if (*(img1 + (height * j) + i) == arr[len])
				{
					*(img1 + (height * j) + i) = 255;
				}
			}
			*(img_Path + (height * j) + i) = *(img1 + (height * j) + i);
		}
	}
	return img_Path;
}
unsigned char* hw2function::HW2_2Path_img(unsigned char* img1, int width, int height, int arr[])
{
	int size = width * height;
	int length = sizeof(arr) / sizeof(int);
	unsigned char* img_Path = new unsigned char[size];

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			for (int len = 0; len < length; len++)
			{
				if (*(img1 + (height * j) + i) == arr[len])
				{
					*(img1 + (height * j) + i) = 255;
				}
			}
			if (*(img1 + (height * j) + i) != 255)
			{
				*(img1 + (height * j) + i) = 0;
			}
			*(img_Path + (height * j) + i) = *(img1 + (height * j) + i);
		}
	}

	return img_Path;
}
unsigned char* hw2function::HW2_3Path_img(unsigned char* img1, int width, int height, int arr[])
{
	int size = width * height;
	unsigned char* img_Path = new unsigned char[size];

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			for (int len = 0; len < 3; len++)
			{
				if (*(img1 + (height * j) + i) == arr[len])
				{
					*(img1 + (height * j) + i) = 255;
				}
			}
			if (*(img1 + (height * j) + i) != 255)
			{
				*(img1 + (height * j) + i) = 0;
			}
			*(img_Path + (height * j) + i) = *(img1 + (height * j) + i);
		}
	}

	return img_Path;
}
unsigned char* hw2function::D4Path(unsigned char* img1, int width, int height)
{
	int now = 0;
	int	count = 0;
	int size = width * height;
	unsigned char* img_D4Path = new unsigned char[size];
	while (true)
	{
		if (now > 3)
		{
			if (*(img1 + now + height) == 255)
			{
				*(img1 + now + height) = 254;
				count += 1;
				now += 10;
			}
			else if (*(img1 + now + 1) == 255)
			{
				*(img1 + now + 1) = 254;
				count += 1;
				now += 1;
			}
			
			else if (*(img1 + now - 1) == 255)
			{
				*(img1 + now - 1) = 254;
				count += 1;
				now -= 1;
			}
			else if (*(img1 + now - height) == 255)
			{
				*(img1 + now - height) = 254;
				count += 1;
				now -= 10;
			}
		}
		else 
		{
			if (*(img1 + now + 1) == 255)
			{
				*(img1 + now + 1) = 254;
				count += 1;
				now += 1;
			}
			else if (*(img1 + now + height) == 255)
			{
				*(img1 + now + height) = 254;
				count += 1;
				now += 10;
			}
			else if (*(img1 + now - 1) == 255)
			{
				*(img1 + now - 1) = 254;
				count += 1;
				now -= 1;
			}
			else if (*(img1 + now - height) == 255)
			{
				*(img1 + now - height) = 254;
				count += 1;
				now -= 10;
			}
		}
		if (now == 99)
		{
			break;
		}
	}
	printf("\nD4Path = %d", count);
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			if (*(img1 + (height * j) + i) != 254)
			{
				* (img_D4Path + (height * j) + i) = 0;
			}
			else
			{
				*(img_D4Path + (height * j) + i) = 255;
			}
		}
	}
	*(img_D4Path) = 255;
	return img_D4Path;
}
unsigned char* hw2function::D8Path(unsigned char* img1, int width, int height)
{
	int now = 0;
	int	count = 0;
	int size = width * height;
	unsigned char* img_D8Path = new unsigned char[size];
	while (true)
	{
		if (*(img1 + now + height + 1) == 255)
		{	
			*(img1 + now + 1) = 0;
			*(img1 + now + height) = 0;
			*(img1 + now + height + 1) = 254;
			count += 1;
			now += 11;
		}
		else if (*(img1 + now + height) == 255)
		{
			*(img1 + now + height) = 254;
			count += 1;
			now += 10;
		}
		else if (*(img1 + now + height - 1) == 255)
		{
			*(img1 + now - 1) = 0;
			*(img1 + now + height) = 0;
			*(img1 + now + height - 1) = 254;
			count += 1;
			now += 9;
		}
		else if (*(img1 + now - height + 1) == 255)
		{
			*(img1 + now + 1) = 0;
			*(img1 + now - height) = 0;
			*(img1 + now - height + 1) = 254;
			count += 1;
			now -= 9;
		}
		else if (*(img1 + now - height - 1) == 255)
		{
			*(img1 + now - 1) = 0;
			*(img1 + now - height) = 0;
			*(img1 + now - height - 1) = 254;
			count += 1;
			now -= 11;
		}
		else if (*(img1 + now + 1) == 255)
		{
			*(img1 + now + 1) = 254;
			count += 1;
			now += 1;
		}

		else if (*(img1 + now - 1) == 255)
		{
			*(img1 + now - 1) = 254;
			count += 1;
			now -= 1;
		}
		else if (*(img1 + now - height) == 255)
		{
			*(img1 + now - height) = 254;
			count += 1;
			now -= 10;
		}
		if (now == 99)
		{
			break;
		}
	}
	printf("\nD8Path = %d\n", count);
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			if (*(img1 + (height * j) + i) != 254)
			{
				*(img_D8Path + (height * j) + i) = 0;
			}
			else
			{
				*(img_D8Path + (height * j) + i) = 255;
			}
		}
	}
	*(img_D8Path) = 255;
	return img_D8Path;
}
unsigned char* hw2function::DmPath(unsigned char* img1, int width, int height)
{
	int now = 0;
	int	count = 0;
	int size = width * height;
	unsigned char* img_D8Path = new unsigned char[size];
	while (true)
	{
		if (now > 44)
		{	
			if (*(img1 + now + 1) == 255)
			{
				*(img1 + now + 1) = 254;
				count += 1;
				now += 1;
			}
			else if (*(img1 + now + height) == 255)
			{
				*(img1 + now + height) = 254;
				count += 1;
				now += 10;
			}
			else if (*(img1 + now - 1) == 255)
			{
				*(img1 + now - 1) = 254;
				count += 1;
				now -= 1;
			}
			else if (*(img1 + now - height) == 255)
			{
				*(img1 + now - height) = 254;
				count += 1;
				now -= 10;
			}
			else if (*(img1 + now + height + 1) == 255)
			{
				*(img1 + now + 1) = 0;
				*(img1 + now + height) = 0;
				*(img1 + now + height + 1) = 254;
				count += 1;
				now += 11;
			}
			else if (*(img1 + now + height - 1) == 255)
			{
				*(img1 + now - 1) = 0;
				*(img1 + now + height) = 0;
				*(img1 + now + height - 1) = 254;
				count += 1;
				now += 9;
			}
			else if (*(img1 + now - height + 1) == 255)
			{
				*(img1 + now + 1) = 0;
				*(img1 + now - height) = 0;
				*(img1 + now - height + 1) = 254;
				count += 1;
				now -= 9;
			}
			else if (*(img1 + now - height - 1) == 255)
			{
				*(img1 + now - 1) = 0;
				*(img1 + now - height) = 0;
				*(img1 + now - height - 1) = 254;
				count += 1;
				now -= 11;
			}
		}
		else {
			if (*(img1 + now + height) == 255)
			{
				*(img1 + now + height) = 254;
				count += 1;
				now += 10;
			}
			else if (*(img1 + now + 1) == 255)
			{
				*(img1 + now + 1) = 254;
				count += 1;
				now += 1;
			}
			else if (*(img1 + now - 1) == 255)
			{
				*(img1 + now - 1) = 254;
				count += 1;
				now -= 1;
			}
			else if (*(img1 + now - height) == 255)
			{
				*(img1 + now - height) = 254;
				count += 1;
				now -= 10;
			}
			else if (*(img1 + now + height + 1) == 255)
			{
				*(img1 + now + 1) = 0;
				*(img1 + now + height) = 0;
				*(img1 + now + height + 1) = 254;
				count += 1;
				now += 11;
			}
			else if (*(img1 + now + height - 1) == 255)
			{
				*(img1 + now - 1) = 0;
				*(img1 + now + height) = 0;
				*(img1 + now + height - 1) = 254;
				count += 1;
				now += 9;
			}
			else if (*(img1 + now - height + 1) == 255)
			{
				*(img1 + now + 1) = 0;
				*(img1 + now - height) = 0;
				*(img1 + now - height + 1) = 254;
				count += 1;
				now -= 9;
			}
			else if (*(img1 + now - height - 1) == 255)
			{
				*(img1 + now - 1) = 0;
				*(img1 + now - height) = 0;
				*(img1 + now - height - 1) = 254;
				count += 1;
				now -= 11;
			}
		}
		if (now == 99)
		{
			break;
		}
	}
	printf("DmPath = %d\n", count);
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			if (*(img1 + (height * j) + i) != 254)
			{
				*(img_D8Path + (height * j) + i) = 0;
			}
			else
			{
				*(img_D8Path + (height * j) + i) = 255;
			}
		}
	}
	*(img_D8Path) = 255;
	return img_D8Path;
}
unsigned char* hw2function::quantize(unsigned char* img1, int width, int height, int bit)
{
	int size = width * height;
	unsigned char* img_shift = new unsigned char[size];
	int a = pow(2, bit) - 1;
	a = a << (8 - bit);
	int ratio = 255 / (pow(2, bit) - 1);
	for (int i = 0; i <= size; i++)
	{
		if ((*(img1 + i) & a) != 0)
		{
			*(img_shift + i) = ((*(img1 + i) & a) >> (8 - bit)) * ratio;
		}
		else
		{
			*(img_shift + i) = 0;
		}
	}

	return img_shift;
}
unsigned char* hw2function::HW4average(unsigned char* img1, int width, int height, int ratio)
{
	int size = height * width / ratio / ratio;
	int add = 0;
	unsigned char* img_HW4 = new unsigned char[size];
	
	for (int l = 0; l < height; l += ratio)
	{
		for (int k = 0; k < width; k += ratio)
		{
			for (int j = 0; j < ratio; j++)
			{
				for (int i = 0; i < ratio; i++)
				{
					add += *(img1 + (l + j) * height + k + i);
				}
			}
			add /= ratio * ratio;
			*(img_HW4 + l * height / ratio / ratio + k/ ratio) = add;
			add = 0;
		}
	}
	return img_HW4;
}
unsigned char* hw2function::HW4draw(unsigned char* img1)
{
	int size = 1024 * 1024;
	unsigned char* img = new unsigned char[size];
	int* a = new int [4096];
	int x, y, radius;
	for (int i = 0; i < 4096; i++)
	{
		if (*(img1 + i) < 58)
		{
			*(a + i) = 8;
		}
		else if (*(img1 + i) > 201)
		{
			*(a + i) = 1;
		}
		else
		{
			*(a + i) = 7 - ((*(img1 + i) - 58) / 24);
		}
	}
	for (int y = 0; y < 1024; y++)
	{
		for (int x = 0; x < 1024; x++)
		{
			unsigned char color = 0;
			int x_center = 7 + 16 * (x / 16);
			int y_center = 7 + 16 * (y / 16);
			int dx = x - x_center;
			int dy = y - y_center;
			int radius = a[64 * (y / 16) + (x / 16)];

			if (dx * dx + dy * dy <= radius * radius) 
			{
				*(img + 1024 * y + x) = 0;
			}
			else
			{
				*(img + 1024 * y + x) = 255;
			}
		}
	}
	return img;
}