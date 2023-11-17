#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "class.h"
using namespace std;
using namespace cv;

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

unsigned char* hw3::Binarlize(unsigned char* img1, int height, int width)
{
	int a = 128;
	int size = height * width;
	unsigned char* img_Binarize = new unsigned char[size];
	for (int i = 0; i < size; i++)
	{
		if ((*(img1 + i) & a) != 0)
		{
			*(img_Binarize + i) = (((*(img1 + i) & a) >> 7) * 255);
		}
		else
		{
			*(img_Binarize + i) = 0;
		}
	}
	return img_Binarize;
}
unsigned char* hw3::Replace(unsigned char* img1, unsigned char* img2, int height, int width, unsigned char bit)
{
	if (bit < 8)
	{
		int size = height * width;
		unsigned char mask = 1 << bit;
		unsigned char* img2mask = new unsigned char[size];
		unsigned char* img_Replace = new unsigned char[size];
		for (int i = 0; i < size; i++)
		{
			img2mask[i] = img2[i] & mask;
			img_Replace[i] = img2mask[i] + (~mask & img1[i]);
		}
		return img_Replace;
	}
	else
	{
		return 0;
	}
}
unsigned char* hw3::logtransform(unsigned char* img1, int height, int width)
{
	const double c = 255 / log(256);
	int size = height * width;
	unsigned char* img_logtransform = new unsigned char[size];
	for (int i = 0; i < size; i++)
	{
		img_logtransform[i] = c * log(img1[i] + 1);
	}
	return img_logtransform;
}
unsigned char* hw3::inverse_logtransform(unsigned char* img1, int height, int width)
{
	const double c = 255 / log(256);
	int size = height * width;
	unsigned char* img_inverse_logtransform = new unsigned char[size];
	for (int i = 0; i < size; i++)
	{
		img_inverse_logtransform[i] = (pow(exp(img1[i]), (1 / c))) - 1;
	}
	return img_inverse_logtransform;
}
unsigned char* hw3::power_lowtransform(unsigned char* img1, int height, int width, float gamma)
{
	const double c = 255 / pow(255, gamma);
	int size = height * width;
	unsigned char* img_power_lowtransform = new unsigned char[size];
	for (int i = 0; i < size; i++)
	{
		img_power_lowtransform[i] = c * pow(img1[i], gamma);
	}
	return img_power_lowtransform;
}
unsigned char* hw3::negative(unsigned char* img1, int height, int width)
{
	int size = height * width;
	unsigned char* img_negative = new unsigned char[size];
	for (int i = 0; i < size; i++)
	{
		img_negative[i] = 255 - img1[i];
	}
	return img_negative;
}
float* hw3::Histogram(unsigned char* img1, int height, int width)
{
	int size = height * width;
	float* list = new float[256]();
	for (int i = 0; i < size; i++)
	{
		list[img1[i]] += 1;
	}
	return list;
	delete[] list;
}
void hw3::Plot_histogram(float* list, char* filename)
{
	Mat Histogram(768, 768, CV_8UC1, cv::Scalar(255));
	line(Histogram, Point(100, 700), Point(650, 700), Scalar(0), 2); //x
	line(Histogram, Point(100, 700), Point(100, 100), Scalar(0), 2); // y
	putText(Histogram, "0", Point(100, 720), FONT_HERSHEY_COMPLEX, 0.7, Scalar(0), 1, 1, 0);
	putText(Histogram, "255", Point(610, 720), FONT_HERSHEY_COMPLEX, 0.7, Scalar(0), 1, 1, 0);
	putText(Histogram, "Number of pixels (*300)", Point(90, 90), FONT_HERSHEY_COMPLEX, 0.7, Scalar(0), 1, 1, 0);
	putText(Histogram, "Gray Level", Point(300, 720), FONT_HERSHEY_COMPLEX, 0.7, Scalar(0), 1, 1, 0);
	for (int i = 0; i < 256; i++)
	{
		int x = 105 + 2 * i;
		int length = 700 - (list[i] / 300);
		line(Histogram, Point(x, 700), Point(x, length), Scalar(0), 1);
	}
	imwrite(filename, Histogram);
	imshow("Histogram", Histogram);
	waitKey(0);
	destroyAllWindows();
}
unsigned char* hw3::Histogram_equalization(unsigned char* img1, float* list, int height, int width)
{
	int size = height * width;
	float CDF = 0;
	unsigned char* img_Histogram_equalization = new unsigned char[size];
	float* list_Histogram_equalization = new float[256]();
	for (int i = 0; i < 256; i++)
	{
		CDF += list[i] / size;
		list_Histogram_equalization[i] = CDF * 255;
	}
	for (int i = 0; i < size; i++)
	{
		img_Histogram_equalization[i] = list_Histogram_equalization[img1[i]];
	}
	return img_Histogram_equalization;
}
unsigned char* hw3::Histogram_matching(unsigned char* img1, float lowerBound, float upperBound, int height, int width)
{
	int size = height * width;
	float matchingvalue = 0;
	unsigned char* img_matching = new unsigned char[size];
	for (int i = 0; i < size; i++)
	{
		if (img1[i] < 50)
		{
			img_matching[i] = lowerBound + img1[i];
		}
		else
		{
			matchingvalue = img1[i] / 255;
			img_matching[i] = 123 + matchingvalue * (upperBound - lowerBound);
		}
	}
	return img_matching;
	delete[] img_matching;
}