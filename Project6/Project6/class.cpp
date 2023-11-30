#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <math.h>
#include<omp.h>
#include <algorithm>
#include <vector>
#include "class.h"

#define M_PI 3.1415926585897
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

void hw6::bubble_sort(unsigned char* arr, int filter_size)
{
	int N = filter_size * filter_size;
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j < N - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void hw6::bubble_sort2(long double* arr, int filter_size)
{
	int N = filter_size * filter_size;
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j < N - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
float hw6::local_var(unsigned char* img, int width, int x, int y, int filter_size, float local_mean)
{
	float mean = 0;
	float mean2 = 0;
	for (int i = x ; i < x  + filter_size; i++)
	{
		for (int j = y ; j < y  + filter_size; j++)
		{
			float img_src = static_cast<float>(img[i * width + j]);
			mean += img_src;
			mean2 += (img_src * img_src);
		}
	}
	mean = mean / (filter_size * filter_size);
	mean2 = mean2 / (filter_size * filter_size);
	float l_var = mean2 - mean * mean;
	return l_var;
}
float hw6::local_mean(unsigned char* img, int width, int x, int y, int filter_size)
{
	float add = 0;
	for (int i = x ; i < x  + filter_size; i++)
	{
		for (int j = y ; j < y  + filter_size; j++)
		{
			float img_src = static_cast<float>(img[i * width + j]);
			add += img_src;
		}		
	}
	float local_mean = add / (filter_size * filter_size);
	return local_mean;
}
float  hw6::Noise_variance(unsigned char* img, int height, int width, int pad_width, int filter_size)
{	
	float Noise_var = 0;
	float mean = 0;
	float mean2 = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{		
			mean = 0;
			mean2 = 0;
			for (int m = i; m < i + filter_size; m++)
			{
				for (int n = j; n < j + filter_size; n++)
				{
					float img_src = static_cast<float>(img[m * pad_width + n]);
					mean += img_src;
					mean2 += (img_src * img_src);
				}
			}
			mean /= (filter_size * filter_size);
			mean2 /= (filter_size * filter_size);
			Noise_var += (mean2 - mean * mean);
		}
	}
	Noise_var = Noise_var / (height * width);
	return Noise_var;
}
unsigned char hw6::trimmed_mean(unsigned char* pad_img, int pad_height, int pad_width, int x, int y, int filter_size, int d)
{
	int add = 0;
	int size = filter_size * filter_size;
	unsigned char* arr = new unsigned char[size];
	for (int i = x; i < x + filter_size; i++)
	{
		for (int j = y; j < y + filter_size; j++)
		{
			arr[(i - x) * filter_size + (j - y)] = (pad_img[i * pad_width + j]);
		}
	}
	bubble_sort(arr, filter_size);
	for (int i = d; i < size - d; i++)
	{
		add += arr[i];
	}
	add = static_cast<unsigned char>(add / (filter_size * filter_size - 2*d));
	return add;
}
unsigned char* hw6::padding3x3(unsigned char* img, int height, int width)
{
	int padded_height = height + 2;
	int padded_width = width + 2;
	int padded_size = padded_height * padded_width;
	unsigned char* img_padding = new unsigned char[padded_size] {0};

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
	return img_padding;
}
unsigned char* hw6::padding5x5(unsigned char* img, int height, int width)
{
	int padded_height = height + 4;
	int padded_width = width + 4;
	int padded_size = padded_height * padded_width;
	unsigned char* img_padding = new unsigned char[padded_size] {0};
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			img_padding[(i + 2) * padded_width + j + 2] = img[i * width + j];
		}
	}
	for (int j = 2; j <= width; j++)
	{
		img_padding[j] = img[j - 2];
		img_padding[padded_width + j] = img[width + j - 2];
	}
	for (int j = 0; j <= width; j++)
	{
		img_padding[padded_size - 2 * padded_width + j + 2] = img[(height - 1) * width + j];
		img_padding[padded_size - padded_width + j + 2] = img[(height - 2) * width + j];
	}
	for (int i = 0; i < padded_height; i++)
	{
		img_padding[i * padded_width] = img_padding[i * padded_width + 3];
		img_padding[i * padded_width + 1] = img_padding[i * padded_width + 2];
		img_padding[(i + 1) * padded_width - 1] = img_padding[(i + 1) * padded_width - 4];
		img_padding[(i + 1) * padded_width - 2] = img_padding[(i + 1) * padded_width - 3];
	}
	return img_padding;
}
unsigned char* hw6::padding7x7(unsigned char* img, int height, int width)
{
	int padded_height = height + 6;
	int padded_width = width + 6;
	int padded_size = padded_height * padded_width;
	unsigned char* img_padding = new unsigned char[padded_size] {0};
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			img_padding[(i + 3) * padded_width + j + 3] = img[i * width + j];
		}
	}
	for (int j = 3; j <= width; j++)
	{
		img_padding[j] = img[j - 3];
		img_padding[padded_width + j] = img[width + j - 3];
		img_padding[2*padded_width + j] = img[2*width + j - 3];
	}
	for (int j = 0; j <= width; j++)
	{
		img_padding[padded_size - 3*padded_width + j + 3] = img[(height - 1) * width + j];
		img_padding[padded_size - 2 * padded_width + j + 3] = img[(height - 2) * width + j];
		img_padding[padded_size - padded_width + j + 3] = img[(height - 3) * width + j];
	}
	for (int i = 0; i < padded_height; i++)
	{
		img_padding[i * padded_width] = img_padding[i * padded_width + 5];
		img_padding[i * padded_width + 1] = img_padding[i * padded_width + 4];
		img_padding[i * padded_width + 2] = img_padding[i * padded_width + 3];
		img_padding[(i + 1) * padded_width - 1] = img_padding[(i + 1) * padded_width - 6];
		img_padding[(i + 1) * padded_width - 2] = img_padding[(i + 1) * padded_width - 5];
		img_padding[(i + 1) * padded_width - 3] = img_padding[(i + 1) * padded_width - 4];
	}
	return img_padding;
}
unsigned char* hw6::padding9x9(unsigned char* img, int height, int width)
{
	int padded_height = height + 8;
	int padded_width = width + 8;
	int padded_size = padded_height * padded_width;
	unsigned char* img_padding = new unsigned char[padded_size] {0};
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			img_padding[(i + 4) * padded_width + j + 4] = img[i * width + j];
		}
	}
	for (int j = 4; j <= width; j++)
	{
		img_padding[j] = img[j - 4];
		img_padding[padded_width + j] = img[width + j - 4];
		img_padding[2 * padded_width + j] = img[2 * width + j - 4];
		img_padding[3 * padded_width + j] = img[3 * width + j - 4];
	}
	for (int j = 0; j <= width; j++)
	{
		img_padding[padded_size - 4 * padded_width + j + 3] = img[(height - 1) * width + j];
		img_padding[padded_size - 3 * padded_width + j + 3] = img[(height - 2) * width + j];
		img_padding[padded_size - 2 * padded_width + j + 3] = img[(height - 3) * width + j];
		img_padding[padded_size - padded_width + j + 3] = img[(height - 4) * width + j];
	}
	for (int i = 0; i < padded_height; i++)
	{
		img_padding[i * padded_width] = img_padding[i * padded_width + 7];
		img_padding[i * padded_width + 1] = img_padding[i * padded_width + 6];
		img_padding[i * padded_width + 2] = img_padding[i * padded_width + 5];
		img_padding[i * padded_width + 3] = img_padding[i * padded_width + 4];
		img_padding[(i + 1) * padded_width - 1] = img_padding[(i + 1) * padded_width - 8];
		img_padding[(i + 1) * padded_width - 2] = img_padding[(i + 1) * padded_width - 7];
		img_padding[(i + 1) * padded_width - 3] = img_padding[(i + 1) * padded_width - 6];
		img_padding[(i + 1) * padded_width - 4] = img_padding[(i + 1) * padded_width - 5];
	}
	return img_padding;
}
float hw6::MSE(unsigned char* img, unsigned char* img2, int height, int width)
{
	float MSE = 0;
	int size = height * width;
	for (int i = 0; i < size; i++)
	{
		MSE += pow(*(img + i) - *(img2 + i), 2);
	}
	MSE = MSE / size;
	return MSE;
}
unsigned char* hw6::adaptive_local_noise_filter_run(unsigned char* img, int height, int width, int filter_size)
{
	float mean = 0;
	float l_var = 0;
	float n_var = 0;
	int size = height * width;
	int padd_h = (height + filter_size - 1);
	int padd_w = (width + filter_size - 1);
	unsigned char* img_out = new unsigned char[size];
	unsigned char* img_padding = new unsigned char[padd_h * padd_w];
	switch (filter_size)
	{
	case 3:
		img_padding = padding3x3(img, height, width);
		break;
	case 5:
		img_padding = padding5x5(img, height, width);
		break;
	case 7:
		img_padding = padding7x7(img, height, width);
		break;
	case 9:
		img_padding = padding9x9(img, height, width);
		break;
	default:
		return 0;
		break;
	}
	n_var = Noise_variance(img_padding, height, width, padd_w, filter_size);
	for (int x = 0; x < height; x ++)
	{
		for (int y = 0; y < width; y ++)
		{
			float img_src = static_cast<float>(img[x * width + y]);
			mean = local_mean(img_padding, padd_w, x, y, filter_size);
			l_var = max(local_var(img_padding, padd_w, x, y, filter_size, mean), n_var);
			float d = (n_var / l_var) * (img_src - mean);
			img_out[x * width + y] = static_cast<float>(round(img_src - d));
		}
	}
	return img_out;
}
unsigned char* hw6::alpha_trimmed_mean_filter_run(unsigned char* img, int height, int width, int filter_size, int d)
{
	int size = height * width;
	int padd_h = (height + filter_size - 1);
	int padd_w = (width + filter_size - 1);
	int trim_d = 0;
	unsigned char* img_out = new unsigned char[size];
	unsigned char* img_padding = new unsigned char[padd_h * padd_w];
	switch (filter_size)
	{
	case 3:
		img_padding = padding3x3(img, height, width);
		break;
	case 5:
		img_padding = padding5x5(img, height, width);
		break;
	case 7:
		img_padding = padding7x7(img, height, width);
		break;
	case 9:
		img_padding = padding9x9(img, height, width);
		break;
	default:
		return 0;
		break;
	}
	switch (filter_size)
	{
	case 3:
		trim_d = min(2, d);
		break;
	case 5:
		trim_d = min(3, d);
		break;
	case 7:
		trim_d = min(4, d);
		break;
	case 9:
		trim_d = min(5, d);
		break;
	default:
		return 0;
		break;
	}
	printf("filter_size = %d set d = %d\n", filter_size, trim_d);
	for (int x = 0; x < height; x++)
	{
		for (int y = 0; y < width; y++)
		{
			float img_src = static_cast<float>(img[x * width + y]);
			unsigned char mean = trimmed_mean(img_padding, padd_h, padd_w, x, y, filter_size, trim_d);
			img_out[x * width + y] = mean;
		}
	}
	return img_out;
}
double* hw6::orgin_shift(double* real, int height, int width)
{
	int size = height * width;
	double* out = new double[size];
	for (int i = 0; i <= height / 2; i++)
	{
		for (int j = 0; j <= width / 2; j++)
		{
			out[i * width + j] = real[(i + height / 2) * width + (j + width / 2)];
		}
	}
	for (int i = 0; i <= height / 2; i++)
	{
		for (int j = width / 2 ; j <= width; j++)
		{
			out[i * width + j] = real[(i + height / 2) * width + (j - width / 2)];
		}
	}
	for (int i = height / 2; i <= height; i++)
	{
		for (int j = 0; j <= width / 2; j++)
		{
			out[i * width + j] = real[(i - height / 2) * width + (j + width / 2)];
		}
	}
	for (int i = height / 2; i <= height; i++)
	{
		for (int j = width / 2; j <= width; j++)
		{
			out[i * width + j] = real[(i - height / 2) * width + (j - width / 2)];
		}
	}
	return out;
}
unsigned char* hw6::IID_DFT(unsigned char* img, int height, int width, double* real, double* imagine)
{
	int size = height * width;
	double* sum_imagin = new double[size];
	double* sum_real = new double[size];
	double* temp_imagin = new double[size];
	double* temp_real = new double[size];
	double* temp_imagin2 = new double[size];
	double* temp_real2 = new double[size];
	unsigned char* img_DFT = new unsigned char[size];
	unsigned char* img_DFT2 = new unsigned char[size];
	const double c = 255 / log(256);
#pragma omp parallel for
	for (int u = 0; u < width; u++)
	{
		for (int y = 0; y < height; y++)
		{
			temp_imagin[y * width + u] = 0.0;
			temp_real[y * width + u] = 0.0;
			for (int v = 0; v < height; v++)
			{
				double img_src = img[v * width + u] * pow(-1, u + v);
				double factor = (2.0 * M_PI * y * v) / (double)height;
				double cos_factor = cos(factor);
				double sin_factor = sin(factor);
				temp_real[y * width + u] += img_src * cos_factor;
				temp_imagin[y * width + u] -= img_src * sin_factor;
			}

		}
	}
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			sum_real[y * width  + x] = 0.0;
			sum_imagin[y * width + x] = 0.0;
			for (int u = 0; u < width; u++)
			{
				double factor = (2.0 * M_PI * u * x) / (double)height;
				double cos_factor = cos(factor);
				double sin_factor = sin(factor);
				sum_real[y * width + x] += ((temp_real[y * width + u] * cos_factor) - (temp_imagin[y * width + u] * sin_factor));
				sum_imagin[y * width + x] += ((temp_real[y * width + u] * sin_factor) + (temp_imagin[y * width + u] * cos_factor));
			}
			temp_real2[y * width + x] = sum_real[y * width + x] / size;
			temp_imagin2[y * width + x] = sum_imagin[y * width + x] / size;
			double sum = sqrt(sum_real[y * width + x] * sum_real[y * width + x] + sum_imagin[y * width + x] * sum_imagin[y * width + x]) / size;
			img_DFT[y * width + x] = static_cast<unsigned char>(c * log(c * log(sum + 1) + 1));
		}
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			real[y * width + x] = temp_real2[(height - y - 1) * width + x];
			imagine[y * width + x] = temp_imagin2[(height - y - 1) * width + x];
			img_DFT2[y * width + x] = img_DFT[(height - y - 1) * width + x];
		}
	}
	return img_DFT2;
}
unsigned char* hw6::IID_IDFT(double* real, double* imagine, int height, int width)
{
	int size = height * width;
	double* sum_imagin = new double[size];
	double* sum_real = new double[size];
	double* temp_imagin = new double[size];
	double* temp_real = new double[size];
	unsigned char* img_IDFT = new unsigned char[size];
	unsigned char* img_IDFT2 = new unsigned char[size];
#pragma omp parallel for
	for (int u = 0; u < height; u++)
	{
		for (int y = 0; y < width; y++)
		{
			temp_imagin[u * width + y] = 0.0;
			temp_real[u * width + y] = 0.0;
			for (int v = 0; v < width; v++)
			{
				double factor = (2.0 * M_PI * v * y) / (double)width;
				double cos_factor = cos(factor);
				double sin_factor = sin(factor);
				temp_real[u * width + y] += real[u * width + v] * cos_factor - imagine[u * width + v] * sin_factor;
				temp_imagin[u * width + y] += real[u * width + v] * sin_factor + imagine[u * width + v] * cos_factor;
			}

		}
	}
	for (int u = 0; u < height; u++)
	{
		for (int v = 0; v < width; v++)
		{
			sum_real[u * width + v] = 0.0;
			sum_imagin[u * width + v] = 0.0;
			for (int x = 0; x < height; x++)
			{
				double factor = (2.0 * M_PI * u * x) / (double)height;
				double cos_factor = cos(factor);
				double sin_factor = sin(factor);
				sum_real[u * width + v] += (temp_real[x * width + v] * cos_factor) - (temp_imagin[x * width + v] * sin_factor);
				sum_imagin[u * width + v] -= (temp_real[x * width + v] * sin_factor) + (temp_imagin[x * width + v] * cos_factor);
			}
			img_IDFT[u * width + v] = static_cast<unsigned char>(sqrt(sum_real[u * width + v] * sum_real[u * width + v] + sum_imagin[u * width + v] * sum_imagin[u * width + v]));
		}
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			img_IDFT2[y * width + x] = img_IDFT[(height - y - 1) * width + width - x - 1];
		}
	}
	return img_IDFT2;
}
void hw6::Motion_blur_IID_DFT(int height, int width, double a, double b, int t, long double* blur_real, long double* blur_imagine)
{
	int size = height * width;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			double factor = M_PI * (i * a + j * b);
			double temp = (t / factor) * sin(factor);
			blur_real[i * width + j] = temp * cos(factor);
			blur_imagine[i * width + j] = temp * -1 * sin(factor);
		}
	}
}
unsigned char* hw6::Inverse_Filter(double* real, double* imagine, long double* blur_real, long double* blur_imagine, int height, int width, bool with_R, int radius)
{
	int size = height * width;
	double* real_coff = new double[size];
	double* imagine_coff = new double[size];
	unsigned char* img_IDFT = new unsigned char[size] {0};

	long double a, b, c, d;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{	
			a = real[i * width + j];
			b = imagine[i * width + j];
			c = blur_real[i * width + j];
			d = blur_imagine[i * width + j];
			double denominator = c * c + d * d ;
			if(sqrt(denominator)>0.022)
			{
				real_coff[i * width + j] = (a * c + b * d) / denominator;
				imagine_coff[i * width + j] = (b * c - a * d) / denominator;
			}
			else
			{
				real_coff[i * width + j] = a;
				imagine_coff[i * width + j] = b;
			}
			if (with_R)
			{
				int dist = sqrt((i - height / 2.0) * (i - height / 2.0) + (j - width / 2.0) * (j - width / 2.0));
				if (dist > radius)
				{
					real_coff[i * width + j] = 0.0;
					imagine_coff[i * width + j] = 0.0;
				}
			}
		}
	}
	show__DFTimg(blur_real, blur_imagine, 256, 256);
	img_IDFT = IID_IDFT(real_coff, imagine_coff, height, width);
	return img_IDFT;
}
void hw6::show__DFTimg(long double* real, long double* imagine, int height, int width)
{
	rw rw;
	char test[] = "test.raw";
	int size = height * width;
	const double c = 255 / log(256);
	unsigned char* img_out = new unsigned char[size];
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			double out = real[i * width + j] * real[i * width + j] + imagine[i * width + j] * imagine[i * width + j];
			img_out[i * width + j] = c*log(c*log(out+1)+1)*32;
		}
	}
	rw.write_raw_data(test, img_out, height, width);
}
void hw6::show__DFTimg2(double* real, double* imagine, int height, int width)
{
	rw rw;
	char test[] = "test.raw";
	int size = height * width;
	const double c = 255 / log(256);
	unsigned char* img_out = new unsigned char[size];
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			double out = real[i * width + j] * real[i * width + j] + imagine[i * width + j] * imagine[i * width + j];
			img_out[i * width + j] = c * log(c * log(out + 1) + 1);
		}
	}
	rw.write_raw_data(test, img_out, height, width);
}
unsigned char* hw6::Weiner_Filter(double* real, double* imagine, long double* blur_real, long double* blur_imagine, int height, int width, double K)
{
	int size = height * width;
	unsigned char* img_IDFT = new unsigned char[size] {0};
	double* real_coff = new double[size];
	double* imagine_coff = new double[size];
	long double a, b, c, d;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			a = real[i * width + j];
			b = imagine[i * width + j];
			c = blur_real[i * width + j];
			d = blur_imagine[i * width + j];
			double denominator = c * c + d * d;
			if (sqrt(denominator+ K) > 0.1)
			{
				real_coff[i * width + j] = (a * c + b * d) / (denominator + K);
				imagine_coff[i * width + j] = (b * c - a * d) / (denominator + K);
			}
			else
			{
				real_coff[i * width + j] = a;
				imagine_coff[i * width + j] = b;
			}
		}
	}
	show__DFTimg2(real_coff, imagine_coff, height, width);
	img_IDFT = IID_IDFT(real_coff, imagine_coff, height, width);
	return img_IDFT;
}
void hw6::Pxy_to_Puv(int height, int width, double* real, double* imagine)
{
	int size = height * width;
	signed char* img = new signed char[size];
	double* sum_imagin = new double[size];
	double* sum_real = new double[size];
	double* temp_imagin = new double[size];
	double* temp_real = new double[size];
	signed char* Pxy = new signed char[9]{ 0, -1, 0, -1, 4, -1, 0, -1, 0 };
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			img[i * width + j] = 0;
		}
	}
	for (int i = height / 2 - 1; i < height / 2 + 2; i++)
	{
		for (int j = width / 2 - 1; j < width / 2 + 2; j++)
		{
			img[i * width + j] = Pxy[(i + 1 - height / 2) * 3 + (j + 1 - width / 2)];
		}
	}
	for (int u = 0; u < height; u++)
	{
		for (int y = 0; y < width; y++)
		{
			temp_imagin[u * width + y] = 0.0;
			temp_real[u * width + y] = 0.0;
			for (int v = 0; v < width; v++)
			{
				double img_src = img[u * width + v] * pow(-1, u + v);
				double factor = (2.0 * M_PI * v * y) / (double)width;
				double cos_factor = cos(factor);
				double sin_factor = sin(factor);
				temp_real[u * width + y] += img_src * cos_factor;
				temp_imagin[u * width + y] -= img_src * sin_factor;
			}
		}
	}
	for (int x = 0; x < height; x++)
	{
		for (int y = 0; y < width; y++)
		{
			sum_real[x * width + y] = 0.0;
			sum_imagin[x * width + y] = 0.0;
			for (int u = 0; u < height; u++)
			{
				double factor = (2.0 * M_PI * u * x) / (double)height;
				double cos_factor = cos(factor);
				double sin_factor = sin(factor);
				sum_real[x * width + y] += ((temp_real[u * width + y] * cos_factor) - (temp_imagin[u * width + y] * sin_factor));
				sum_imagin[x * width + y] += ((temp_real[u * width + y] * sin_factor) + (temp_imagin[u * width + y] * cos_factor));
			}
			real[x * width + y] = sum_real[x * width + y] / size;
			imagine[x * width + y] = sum_imagin[x * width + y] / size;
		}
	}
}
unsigned char* hw6::Constrained_Least_Squares_Filtering(double* real, double* imagine, long double* blur_real, long double* blur_imagine, int height, int width, double gamma)
{

	double* P_real = new double[256 * 256]{0};
	double* P_imagine = new double[256 * 256]{0};
	Pxy_to_Puv(256, 256, P_real, P_imagine);
	int size = height * width;
	unsigned char* img_IDFT = new unsigned char[size] {0};
	double* real_coff = new double[size];
	double* imagine_coff = new double[size];
	long double a, b, c, d, e, f;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			a = real[i * width + j];
			b = imagine[i * width + j];
			c = blur_real[i * width + j];
			d = blur_imagine[i * width + j];
			e = P_real[i * width + j];
			f = P_imagine[i * width + j];
			double denominator = c * c + d * d + gamma * (e * e + f * f);
			if (sqrt(c * c + d * d ) > 0.12)
			{
				real_coff[i * width + j] = (a * c + b * d) / denominator;
				imagine_coff[i * width + j] = (b * c - a * d) / (denominator);
			}
			else
			{
				real_coff[i * width + j] = a;
				imagine_coff[i * width + j] = b;
			}
		}
	}
	img_IDFT = IID_IDFT(real_coff, imagine_coff, height, width);
	return img_IDFT;
}
unsigned char* hw6::contour_detect(unsigned char* img, int height, int width)
{
	char output3[] = "chessboard_edge.raw";
	rw rw;
	int size = height * width;
	unsigned char* img_out = new unsigned char[size] {0};
	unsigned char* img_padding = padding3x3(img, 256, 256);
	double add1, add2;
	signed char* filter = new signed char[9]{ 0, 1, 2, -1, 0, 1, -2, -1, 0 };
	signed char* filter2 = new signed char[9]{ 2, 1, 0, 1, 0, -1, 0, -1, -2 };
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			add1 = filter[0] * img_padding[(i) * (width + 2) + (j)] \
				+ filter[1] * img_padding[(i) * (width + 2) + (j + 1)] \
				+ filter[2] * img_padding[(i) * (width + 2) + (j + 2)] \
				+ filter[3] * img_padding[(i + 1) * (width + 2) + (j)] \
				+ filter[4] * img_padding[(i + 1) * (width + 2) + (j + 1)] \
				+ filter[5] * img_padding[(i + 1) * (width + 2) + (j + 2)] \
				+ filter[6] * img_padding[(i + 2) * (width + 2) + (j)] \
				+ filter[7] * img_padding[(i + 2) * (width + 2) + (j + 1)] \
				+ filter[8] * img_padding[(i + 2) * (width + 2) + (j + 2)];
			add2 = filter2[0] * img_padding[(i) * (width + 2) + (j)] \
				+ filter2[1] * img_padding[(i) * (width + 2) + (j + 1)] \
				+ filter2[2] * img_padding[(i) * (width + 2) + (j + 2)] \
				+ filter2[3] * img_padding[(i + 1) * (width + 2) + (j)] \
				+ filter2[4] * img_padding[(i + 1) * (width + 2) + (j + 1)] \
				+ filter2[5] * img_padding[(i + 1) * (width + 2) + (j + 2)] \
				+ filter2[6] * img_padding[(i + 2) * (width + 2) + (j)] \
				+ filter2[7] * img_padding[(i + 2) * (width + 2) + (j + 1)] \
				+ filter2[8] * img_padding[(i + 2) * (width + 2) + (j + 2)];
			if (add1 < 0)
			{
				img_out[i * width + j] = 0;
			}
			else
			{
				img_out[i * width + j] = (unsigned char)(sqrt(add1 * add1 + add2 * add2));
			}
		}
	}
	return img_out;
}
unsigned char* hw6::warping_relationship(unsigned char* distorted_img, int height, int width)
{
	int size = height * width;
	int x, y;
	unsigned char* img_out = new unsigned char[size] {0};
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			x = 4.11764706e-1 * j - 5.88235294e-01 * i  + 7.84313725e-04 * i * j + 1.50000000e+02;
			y = 2.03921569e-01 * j + 4.11764706e-01 * i + 1.50711265e-03 * i * j;
			img_out[i * width + j] = distorted_img[y * width + x];
		}
	}
	return img_out;
}