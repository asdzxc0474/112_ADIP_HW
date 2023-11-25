#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <iostream>
#include<time.h> 
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <math.h>
#include<omp.h>
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
Mat rw::Opencv_read_raw_data(char* filename, int height, int width)
{
	FILE* fp = NULL;
	fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	unsigned char* data = (unsigned char*)malloc(width * height * sizeof(unsigned char));
	fread(data, sizeof(unsigned char), width * height, fp);
	fclose(fp);
	Mat img;
	int bufLen = width * height;
	img.create(height, width, CV_8UC1);
	memcpy(img.data, data, bufLen * sizeof(unsigned char));
	free(data);
	return img;		
}

unsigned char* hw5::DFT(unsigned char* img, int height, int width, double* real, double* imagine)
{
	clock_t start, end;	
	start = clock();
	int size = height * width;
	unsigned char* img_DFT = new unsigned char[size];
	double two_pi = 2 * M_PI;
	const double c = 255 / log(256);
#pragma omp parallel for
	for (int u = 0; u < height; u++)
	{
		for (int v = 0; v < width; v++)
		{
			double sum = 0;
			double sum_imagin = 0;
			double sum_real = 0;

			for (int x = 0; x < height; x++)
			{
				for (int y = 0; y < width; y++)
				{
					double imr_src = static_cast<double> (img[x * width + y]) * pow(-1, x + y);
					double i = two_pi * ((double)x * u / (double)height + (double)y * v / (double)width);
					sum_real += imr_src * cos(i);
					sum_imagin += imr_src * -sin(i);
				}
			}
			real[u * width + v] = sum_real / size;
			imagine[u * width + v] = sum_imagin / size;
			sum = sqrt(sum_real * sum_real + sum_imagin * sum_imagin) / size;
			img_DFT[u * width + v] = static_cast<unsigned char>(c * log(c * log(sum + 1) + 1));
		}
	}
	end = clock();
	printf("DFT execution time: %d min %d sec\n", (end - start) / 60000, ((end - start) / 1000) % 60);
	return img_DFT;
}
unsigned char* hw5::IDFT(unsigned char* img_DFT, int height, int width, double* real, double* imagine)
{
	clock_t start, end;
	start = clock();
	int size = height * width;
	unsigned char* img_IDFT = new unsigned char[size];
	double two_pi = 2 * M_PI;
	const double c = 255 / log(256);
#pragma omp parallel for
	for (int x = 0; x < height; x++)
	{
		for (int y = 0; y < width; y++)
		{
			double sum_real = 0;
			double sum_imagin = 0;

			for (int u = 0; u < height; u++)
			{
				for (int v = 0; v < width; v++)
				{
					double angle = two_pi * ((double)u * x / (double)height + (double)v * y / (double)width);
					double R = real[u * width + v];
					double Im = imagine[u * width + v];
					sum_real += R * cos(angle) - Im * sin(angle);
					sum_imagin += Im * cos(angle) + R * sin(angle);
				}
			}
			double result = sqrt(sum_real * sum_real + sum_imagin * sum_imagin);
			img_IDFT[x * width + y] = static_cast<unsigned char>(result);
		}
	}
	end = clock();
	printf("IDFT execution time: %d min %d sec\n", (end - start) / 60000, ((end - start) / 1000) % 60);
	return img_IDFT;
}
unsigned char* hw5::DCT(unsigned char* img, int height, int width, double* outarr)
{
	clock_t start, end;
	start = clock();
	int size = height * width;
	unsigned char* img_DCT = new unsigned char[size];
	const double pi = M_PI;
	const double h2 = 2 * (double)height;
	const double w2 = 2 * (double)width;
	double result;
#pragma omp parallel for
	for (int u = 0; u < height; u++)
	{
		for (int v = 0; v < width; v++)
		{
			double sum = 0;
			for (int x = 0; x < height; x++)
			{
				for (int y = 0; y < width; y++)
				{
					double src = static_cast<double>(img[x * width + y]);
					double c = cos((2 * (double)x + 1) * u * pi / h2) * cos((2 * (double)y + 1) * v * pi / w2);
					sum += src * c;
				}
			}
			if (u == 0)
			{
				if (v == 0)
				{
					result = (sqrt(1/ (double)height) * sqrt(1 / (double)width) * sum);
				}
				else
				{
					result = (sqrt(1 / (double)height) * sqrt(2 / (double)width) * sum);
				}
			}
			else
			{
				if (v == 0)
				{
					result = (sqrt(2 / (double)height) * sqrt(1 / (double)width) * sum);
				}
				else
				{
					result = (sqrt(2 / (double)height) * sqrt(2 / (double)width) * sum);
				}
			}
			outarr[u * width + v] = result;
			result = abs(round(result));
			img_DCT[u * width + v] = static_cast<unsigned char>(result);
		}
	}
	end = clock();
	printf("DCT execution time: %d min %d sec\n", (end - start) / 60000, ((end - start) / 1000) % 60);
	return img_DCT;
}
unsigned char* hw5::IDCT(double* outarr, int height, int width)
{
	clock_t start, end;
	start = clock();
	int size = height * width;
	unsigned char* img_IDCT = new unsigned char[size];
	const double pi = M_PI;
	const double c = 255 / log(256);
	const double h2 = 2 * (double)height;
	const double w2 = 2 * (double)width;
	double cx, cy;
#pragma omp parallel for
	for (int x = 0; x < height; x++)
	{
		for (int y = 0; y < width; y++)
		{
			double result = 0;
			for (int u = 0; u < height; u++)
			{
				for (int v = 0; v < width; v++)
				{
					double src = static_cast<double>(outarr[u * width + v]);
					double c = cos((2 * (double)x + 1) * u * pi / h2) * cos((2 * (double)y + 1) * v * pi / w2);
					if (u == 0)
					{
						if (v == 0)
						{
							cx = sqrt(1 / (double)height);
							cy = sqrt(1 / (double)width);
						}
						else
						{
							cx = sqrt(1 / (double)height);
							cy = sqrt(2 / (double)width);
						}
					}
					else
					{
						if (v == 0)
						{
							cx = sqrt(2 / (double)height);
							cy = sqrt(1 / (double)width);
						}
						else
						{
							cx = sqrt(2 / (double)height);
							cy = sqrt(2 / (double)width);
						}
					}
					result += cx * cy * src * c;
				}
			}
			img_IDCT[x * width + y] = static_cast<unsigned char>(result);
		}
	}
	end = clock();
	printf("IDCT execution time: %d min %d sec\n", (end - start) / 60000, ((end - start) / 1000) % 60);
	return img_IDCT;
}
float hw5::MSE(unsigned char* img1, unsigned char* img2, int width, int height)
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
float hw5::PSNR(float mse, int max)
{
	float psnr = 10 * log10(max * max / mse);
	printf("PSNR = %f\n", psnr);
	return psnr;
}
Mat hw5::Opencv_DFT(cv::Mat img)
{
	clock_t start, end;
	start = clock();
	Mat padded;                            //expand input image to optimal size
	int m = getOptimalDFTSize(img.rows);
	int n = getOptimalDFTSize(img.cols); // on the border add zero values
	copyMakeBorder(img, padded, 0, m - img.rows, 0, n - img.cols, BORDER_CONSTANT, Scalar::all(0));
	Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
	Mat complexI;
	merge(planes, 2, complexI);         // Add to the expanded another plane with zeros
	dft(complexI, complexI);            // this way the result may fit in the source matrix
	// compute the magnitude and switch to logarithmic scale
	// => log(1 + sqrt(Re(DFT(I))^2 + Im(DFT(I))^2))
	split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
	magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude
	Mat magI = planes[0];
	magI += Scalar::all(1);                    // switch to logarithmic scale
	log(magI, magI);
	// crop the spectrum, if it has an odd number of rows or columns
	magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));
	// rearrange the quadrants of Fourier image  so that the origin is at the image center
	int cx = magI.cols / 2;
	int cy = magI.rows / 2;
	Mat q0(magI, Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
	Mat q1(magI, Rect(cx, 0, cx, cy));  // Top-Right
	Mat q2(magI, Rect(0, cy, cx, cy));  // Bottom-Left
	Mat q3(magI, Rect(cx, cy, cx, cy)); // Bottom-Right
	Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);
	q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
	q2.copyTo(q1);
	tmp.copyTo(q2);
	normalize(magI, magI, 0, 1, NORM_MINMAX);
	end = clock();
	printf("Opencv DFT execution time: %d ms\n", (end - start));
	return magI;
}
Mat hw5::Opencv_DFT_withoutshift(Mat img)
{
	Mat padded;                            //expand input image to optimal size
	int m = getOptimalDFTSize(img.rows);
	int n = getOptimalDFTSize(img.cols); // on the border add zero values
	copyMakeBorder(img, padded, 0, m - img.rows, 0, n - img.cols, BORDER_CONSTANT, Scalar::all(0));
	Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
	Mat complexI;
	merge(planes, 2, complexI);
	dft(complexI, complexI, DFT_COMPLEX_OUTPUT);
	complexI = complex_origin_shift(complexI);
	return complexI;
}
Mat hw5::Opencv_DFT_COMPLEX_OUTPUT(Mat img)
{
	Mat padded;                            //expand input image to optimal size
	int m = getOptimalDFTSize(img.rows);
	int n = getOptimalDFTSize(img.cols); // on the border add zero values
	copyMakeBorder(img, padded, 0, m - img.rows, 0, n - img.cols, BORDER_CONSTANT, Scalar::all(0));
	Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
	Mat complexI;
	merge(planes, 2, complexI);
	dft(complexI, complexI, DFT_COMPLEX_OUTPUT);
	return complexI;
}
Mat hw5::Opencv_IDFT(cv::Mat img)	// only input from Mat hw5::Opencv_DFT_COMPLEX_OUTPUT(Mat img)
{
	clock_t start, end;
	start = clock();
	Mat ifft;
	idft(img, ifft, DFT_REAL_OUTPUT);
	normalize(ifft, ifft, 0, 1, NORM_MINMAX);
	end = clock();
	printf("Opencv IDFT execution time: %d ms\n", (end - start));
	return ifft;
}
float hw5::Get_Mat_MSE(Mat img, Mat img2)
{
	cv::Mat M1 = img.clone();
	cv::Mat M2 = img2.clone();
	cv::Mat Diff;
	M1.convertTo(M1, CV_32F);
	M2.convertTo(M2, CV_32F);
	Diff.convertTo(Diff, CV_32F);
	cv::absdiff(M1, M2, Diff); 

	Diff = Diff.mul(Diff);
	cv::Scalar S = cv::sum(Diff);

	double sse;
	if (Diff.channels() == 3)
	{
		sse = S.val[0] + S.val[1] + S.val[2];
	}
	else
	{
		sse = S.val[0];
	}
	int nTotalElement = M2.channels() * M2.total();
	double mse = (sse / (double)nTotalElement);
	printf("MSE = %f\n", mse);
	return mse;
}
void hw5::show_Mat_img(Mat img, char* filename)
{
	imshow(filename, img);
	waitKey(0);
	destroyAllWindows();
}
Mat hw5::Gaussian_LPF(Mat img, double D0, bool shift, char* writename)
{
	Mat img_in = img.clone();
	Mat img_DFT;
	char buffer[32];
	sprintf(buffer, "%f", D0);
	if (shift)
	{
		img_DFT = Opencv_DFT_COMPLEX_OUTPUT(img_in);
	}
	else if (!shift)
	{
		img_DFT = Opencv_DFT_withoutshift(img_in);
	}
	img_DFT.convertTo(img_DFT, CV_64F);
	Mat filter(Size(img_DFT.cols, img_DFT.rows), CV_64F, Scalar::all(0));
	int half_x = filter.cols / 2;
	int half_y = filter.rows / 2;
	for (int u = 0; u < filter.rows; u++)
	{
		for (int v = 0; v < filter.cols; v++)
		{
			double distance = sqrt((u - half_y) * (u - half_y) + (v - half_x) * (v - half_x));
			filter.at<double>(u, v) = exp(-distance * distance / (2 * D0 * D0));
		}
	}
	if (shift)
	{
		imwrite(writename, filter * 255);
	}
	Mat dftImage1_vector(filter.size(), CV_64F, img_DFT.data);
	dftImage1_vector = dftImage1_vector.mul(filter);
	Mat IMG_IDFT = Opencv_IDFT(img_DFT);
	return IMG_IDFT;
}
Mat hw5::Gaussian_HPF(Mat img, double D0, bool shift, char* writename)
{
	Mat img_in = img.clone();
	Mat img_DFT;
	char buffer[32];
	sprintf(buffer, "%f", D0);
	if (shift)
	{
		img_DFT = Opencv_DFT_COMPLEX_OUTPUT(img_in);
	}
	else if (!shift)
	{
		img_DFT = Opencv_DFT_withoutshift(img_in);
	}
	img_DFT.convertTo(img_DFT, CV_64F);
	Mat filter(Size(img_DFT.cols, img_DFT.rows), CV_64F, Scalar::all(0));
	int half_x = filter.cols / 2;
	int half_y = filter.rows / 2;
	for (int u = 0; u < filter.rows; u++)
	{
		for (int v = 0; v < filter.cols; v++)
		{
			double distance = (sqrt((u - half_y) * (u - half_y) + (v - half_x) * (v - half_x)));
			filter.at<double>(u, v) = 1-(exp(-distance * distance / (2 * D0 * D0)));
		}
	}
	if (shift)
	{
		imwrite(writename, filter * 255);
	}
	Mat dftImage1_vector(filter.size(), CV_64F, img_DFT.data);
	dftImage1_vector = dftImage1_vector.mul(filter);
	Mat IMG_IDFT = Opencv_IDFT(img_DFT);
	return IMG_IDFT;
}
Mat hw5::Butterworth_LPF(cv::Mat img, double D0, double n, bool shift, char* writename)
{
	Mat img_in = img.clone();
	Mat img_DFT;
	char buffer[32];
	sprintf(buffer, "%f", D0);
	if (shift)
	{
		img_DFT = Opencv_DFT_COMPLEX_OUTPUT(img_in);
	}
	else if (!shift)
	{
		img_DFT = Opencv_DFT_withoutshift(img_in);
	}
	img_DFT.convertTo(img_DFT, CV_64F);
	Mat filter(Size(img_DFT.cols, img_DFT.rows), CV_64F, Scalar::all(0));
	int half_x = filter.cols / 2;
	int half_y = filter.rows / 2;
	for (int u = 0; u < filter.rows; u++)
	{
		for (int v = 0; v < filter.cols; v++)
		{
			double distance = sqrt((u - half_y) * (u - half_y) + (v - half_x) * (v - half_x));
			filter.at<double>(u, v) = (1 / (1 + pow(distance / D0, 2*n)));
		}
	}
	if (shift)
	{
		imwrite(writename, filter * 255);
	}
	Mat dftImage1_vector(filter.size(), CV_64F, img_DFT.data);
	dftImage1_vector = dftImage1_vector.mul(filter);
	Mat IMG_IDFT = Opencv_IDFT(img_DFT);
	return IMG_IDFT;
}
Mat hw5::Butterworth_HPF(cv::Mat img, double D0, double n, bool shift, char* writename)
{
	Mat img_in = img.clone();
	Mat img_DFT;
	char buffer[32];
	sprintf(buffer, "%f", D0);
	if (shift)
	{
		img_DFT = Opencv_DFT_COMPLEX_OUTPUT(img_in);
	}
	else if (!shift)
	{
		img_DFT = Opencv_DFT_withoutshift(img_in);
	}
	img_DFT.convertTo(img_DFT, CV_64F);
	Mat filter(Size(img_DFT.cols, img_DFT.rows), CV_64F, Scalar::all(0));
	int half_x = filter.cols / 2;
	int half_y = filter.rows / 2;
	for (int u = 0; u < filter.rows; u++)
	{
		for (int v = 0; v < filter.cols; v++)
		{
			double distance = sqrt((u - half_y) * (u - half_y) + (v - half_x) * (v - half_x));
			filter.at<double>(u, v) = 1-(1 / (1 + pow(distance / D0, 2 * n)));
		}
	}
	if (shift)
	{
		imwrite(writename, filter * 255);
	}
	Mat dftImage1_vector(filter.size(), CV_64F, img_DFT.data);
	dftImage1_vector = dftImage1_vector.mul(filter);
	Mat IMG_IDFT = Opencv_IDFT(img_DFT);
	return IMG_IDFT;
}
Mat hw5::Ideal_LPF(Mat img, double D0, bool shift, char* writename)
{
	Mat img_in = img.clone();
	Mat img_DFT;
	char buffer[32];
	sprintf(buffer, "%f", D0);
	if (shift)
	{
		img_DFT = Opencv_DFT_COMPLEX_OUTPUT(img_in);
	}
	else if (!shift)
	{
		img_DFT = Opencv_DFT_withoutshift(img_in);
	}
	img_DFT.convertTo(img_DFT, CV_64F);
	Mat filter(Size(img_DFT.cols, img_DFT.rows), CV_64F, Scalar::all(0));
	int half_x = filter.cols / 2;
	int half_y = filter.rows / 2;
	for (int u = 0; u < filter.rows; u++)
	{
		for (int v = 0; v < filter.cols; v++)
		{
			double distance = sqrt((u - half_y) * (u - half_y) + (v - half_x) * (v - half_x));
			if (distance > D0)
			{
				filter.at<double>(u, v) = 0;
			}
			else
			{
				filter.at<double>(u, v) = 1;
			}
		}
	}
	if (shift)
	{
		imwrite(writename, filter * 255);
	}
	Mat dftImage1_vector(filter.size(), CV_64F, img_DFT.data);
	dftImage1_vector = dftImage1_vector.mul(filter);
	Mat IMG_IDFT = Opencv_IDFT(img_DFT);
	return IMG_IDFT;
}
Mat hw5::Ideal_HPF(Mat img, double D0, bool shift, char* writename)
{
	Mat img_in = img.clone();
	Mat img_DFT;
	char buffer[32];
	sprintf(buffer, "%f", D0);
	if (shift)
	{
		img_DFT = Opencv_DFT_COMPLEX_OUTPUT(img_in);
	}
	else if (!shift)
	{
		img_DFT = Opencv_DFT_withoutshift(img_in);
	}
	img_DFT.convertTo(img_DFT, CV_64F);
	Mat filter(Size(img_DFT.cols, img_DFT.rows), CV_64F, Scalar::all(0));
	int half_x = filter.cols / 2;
	int half_y = filter.rows / 2;
	for (int u = 0; u < filter.rows; u++)
	{
		for (int v = 0; v < filter.cols; v++)
		{
			double distance = sqrt((u - half_y) * (u - half_y) + (v - half_x) * (v - half_x));
			if (distance > D0)
			{
				filter.at<double>(u, v) = 1;
			}
			else
			{
				filter.at<double>(u, v) = 0;
			}
		}
	}
	//show_Mat_img(filter, buffer);
	if (shift)
	{
		imwrite(writename, filter * 255);
	}
	Mat dftImage1_vector(filter.size(), CV_64F, img_DFT.data);
	dftImage1_vector = dftImage1_vector.mul(filter);
	Mat IMG_IDFT = Opencv_IDFT(img_DFT);
	return IMG_IDFT;
}
Mat hw5::complex_origin_shift(Mat img) 
{
	int row = img.rows / 2;
	int col = img.cols / 2;
	Mat q1(img, Rect(0, 0, col, row));
	Mat q2(img, Rect(col, 0, col, row));
	Mat q3(img, Rect(0, row, col, row));
	Mat q4(img, Rect(col, row, col, row));
	Mat tmp;
	q1.copyTo(tmp);
	q4.copyTo(q1);
	tmp.copyTo(q4);

	q3.copyTo(tmp);
	q2.copyTo(q3);
	tmp.copyTo(q2);
	return img;
}
unsigned char* hw5::Sobel_DFT(float* img, int height, int width, double* real, double* imagine)
{
	int size = height * width;
	unsigned char* img_DFT = new unsigned char[632 * 474];
	double two_pi = 2 * M_PI;
	const double c = 255 / log(256);
#pragma omp parallel for
	for (int u = 0; u < 632; u++)
	{
		for (int v = 0; v < 474; v++)
		{
			double sum = 0;
			double sum_imagin = 0;
			double sum_real = 0;

			for (int x = 0; x < height; x++)
			{
				for (int y = 0; y < width; y++)
				{
					double imr_src = static_cast<double> (img[x * width + y]) * pow(-1, x + y);
					double i = two_pi * ((double)x * u / (double)height + (double)y * v / (double)width);
					sum_real += imr_src * cos(i);
					sum_imagin += imr_src * -sin(i);
				}
			}
			real[u * 474 + v] = sum_real / size;
			imagine[u * 474 + v] = sum_imagin / size;
			sum = sqrt(sum_real * sum_real + sum_imagin * sum_imagin) / size;
			img_DFT[u * 474 + v] = static_cast<unsigned char>(c * log(c * log(sum + 1) + 1));
		}
	}
	return img_DFT;
}
void hw5::Sobel_DFT_mul(double* real, double* imagine, double* s_real, double* s_imagine, double* o_real, double* o_imagine, int height, int width)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			o_real[i * width + j] = real[i * width + j] * s_real[i * width + j] - imagine[i * width + j] * s_imagine[i * width + j];
			o_imagine[i * width + j] = imagine[i * width + j] * s_real[i * width + j] + real[i * width + j] * s_imagine[i * width + j];
		}
	}
}