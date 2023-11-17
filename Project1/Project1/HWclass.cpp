#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include"HWclass.h"
#define	height	256
#define	width	256
using namespace cv;
typedef unsigned char  BYTE;

void HW::HW1_2a() {
	char  input_img[] = "lena256.raw";                 // Input  raw image name
	char output_img[] = "lena256out.raw";
	FILE* input_file;
	FILE* output_file;
	int size = width * height;
	int i, j;
	BYTE B[256][256];
	BYTE* ptr;

	unsigned char* img_lena = new unsigned char[size];
	input_file = fopen(input_img, "rb");

	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}

	ptr = (BYTE*)malloc(width * height * sizeof(BYTE));

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (ptr > 0)
			{
				fread(ptr, 1, 1, input_file);
				B[i][j] = *ptr;
				ptr++;

			}
		}
	}
	printf("1.2a (1) answer: The intensity values of the pixel at the coordinate of the 42rd raw & 145th column is %d", B[42][145]);
	printf("\n\n1.2a (2)-1 answer: The intensity values of the 42019 pixel stored in lena256.raw is %d", B[42019 / 256][42019 % 256]);
	printf("\n1.2a (2)-2 answer:The pixel at the coordinate in the image is (%d,%d)\n\n", 42019 / 256, 42019 % 256);
	fclose(input_file);

	if ((output_file = fopen(output_img, "wb")) == NULL)
	{
		printf("can not create the raw_image : %s\n", output_img);

		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			fwrite(&B[i][j], 1, 1, output_file);
		}
	}

	fclose(output_file);

}
void HW::HW1_2b() {
	//-----------------------1. Initial variable-----------------------//
	char  input_img[] = "lena256.raw";                 // Input  raw image name
	char output_img[] = "lena256out.raw";              // Output raw image name
	FILE* input_file;
	FILE* output_file;
	int size = width * height;
	unsigned char* img_lena = new unsigned char[size]; // array for image data

	//-----------------------2. Read File-----------------------//
	// using fopen as example, fstream works too
	input_file = fopen(input_img, "rb");

	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}

	fread(img_lena, 1, size, input_file);

	//-----------------------3. Save Image as raw format-----------------------//
	output_file = fopen(output_img, "wb");
	fwrite(img_lena, 1, size, output_file);

	//-----------------------4. Release memory-----------------------//
	delete[] img_lena;
	fclose(input_file);
	fclose(output_file);

}
void HW::HW1_2c() {
	//-----------------------1. Initial variable-----------------------//
	char  input_img[] = "lena256.raw";                 // Input  raw image name
	char output_img[] = "(1_2c)lena256out.raw";              // Output raw image name
	FILE* input_file;
	FILE* output_file;
	int size = width * height;
	int i, j, m, n;
	BYTE B[height][width];
	BYTE C[height][width];
	BYTE* ptr;

	unsigned char* img_lena = new unsigned char[size];
	input_file = fopen(input_img, "rb");

	if (input_file == NULL)
	{
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}

	ptr = (BYTE*)malloc(width * height * sizeof(BYTE));
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (ptr > 0)
			{
				fread(ptr, 1, 1, input_file);
				B[i][j] = *ptr;
				ptr++;
			}
		}
	}

	//new 左上角
	for (i = 0; i < height / 2; i++)
	{
		for (j = 0; j < width / 2 - i; j++)
		{
			C[i][j] = B[height - i - 1][width - j - 1];
		}
	}
	//new 左上中間
	for (i = height / 2; i > 0; i--)
	{
		for (j = height / 2 - i; j < width / 2; j++)
		{
			C[i][j] = B[i][j];
		}
	}
	//new 右上角
	for (i = 0; i < height / 2; i++)
	{
		for (j = width / 2 + i; j < width; j++)
		{
			C[i][j] = B[height - j][i];
		}
	}
	//new 右上中間
	for (i = 0; i < height / 2; i++)
	{
		for (j = width / 2; j < width / 2 + i; j++)
		{
			C[i][j] = B[height - i][width - j];
		}
	}
	//左下角
	for (i = height / 2; i < height; i++)
	{
		for (j = 0; j < i - width / 2; j++)
		{
			C[i][j] = B[i][j];
		}
	}
	//左下中間
	for (i = height / 2; i < height; i++)
	{
		for (j = i - width / 2; j < width / 2; j++)
		{
			C[i][j] = B[height - i][width - j];
		}
	}
	//右下中間
	for (i = height / 2; i < height; i++)
	{
		for (j = width / 2; j < 1.5 * width - i; j++)
		{
			C[i][j] = B[i][j];
		}
	}
	//右下角
	for (i = height / 2; i < height; i++)
	{
		for (j = 1.5 * width - i; j < width; j++)
		{
			C[i][j] = B[height - j][i];
		}
	}


	if ((output_file = fopen(output_img, "wb")) == NULL)
	{
		printf("can not create the raw_image : %s\n", output_img);

		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			fwrite(&C[i][j], 1, 1, output_file);
		}
	}
	fclose(output_file);
}
void HW::HW1_2d() {
	char  input_img[] = "lena256.raw";                 // Input  raw image name
	char output_img[] = "(1_2d)lena256out.raw";              // Output raw image name
	FILE* input_file;
	FILE* output_file;
	int size = width * height;
	int i, j, m, n, min, z;
	int list[64], list2[1024];
	BYTE B[height][width];
	BYTE C[height][width];
	BYTE* ptr;

	unsigned char* img_lena = new unsigned char[size];
	input_file = fopen(input_img, "rb");

	if (input_file == NULL)
	{
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}

	ptr = (BYTE*)malloc(width * height * sizeof(BYTE));

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (ptr > 0)
			{
				fread(ptr, 1, 1, input_file);
				B[i][j] = *ptr;
				ptr++;
			}
		}
	}
	for (n = 0; n < 32; n++)
	{
		for (m = 0; m < 32; m++)
		{
			z = 0;

			for (i = 8 * m; i < 8 * m + 8; i++)
			{
				for (j = 8 * n; j < 8 * n + 8; j++)
				{
					list[z] = B[i][j];
					z++;
				}
			}
			min = list[0];

			for (z = 1; z < 64; z++)
			{
				if (list[z] < min)
				{
					min = list[z];
				}
			}

			for (i = 8 * m; i < 8 * m + 8; i++)
			{
				for (j = 8 * n; j < 8 * n + 8; j++)
				{
					C[i][j] = min;
					z++;
				}
			}

		}
	}

	if ((output_file = fopen(output_img, "wb")) == NULL)
	{
		printf("can not create the raw_image : %s\n", output_img);

		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}

	for (n = 0; n < height; n++)
	{
		for (m = 0; m < width; m++)
		{
			fwrite(&C[n][m], 1, 1, output_file);
		}
	}
	fclose(output_file);
}
void HW::HW1_3a() {

	char  input_img[] = "lena256.raw";                 // Input  raw image name
	char output_img[] = "(1_3a)lena256out.raw";              // Output raw image name
	FILE* input_file;
	FILE* output_file;
	int size = width * height;
	int i, j;
	BYTE B[height][width];
	BYTE* ptr;

	unsigned char* img_lena = new unsigned char[size];
	input_file = fopen(input_img, "rb");

	if (input_file == NULL)
	{
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}

	ptr = (BYTE*)malloc(width * height * sizeof(BYTE));
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (ptr > 0)
			{
				fread(ptr, 1, 1, input_file);
				B[i][j] = *ptr;
				ptr++;
			}
		}
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (B[i][j] > 185)
			{
				B[i][j] = 255;
			}
			else
			{
				B[i][j] = B[i][j] + 70	;
			}
		}
	}

	if ((output_file = fopen(output_img, "wb")) == NULL)
	{
		printf("can not create the raw_image : %s\n", output_img);

		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			fwrite(&B[i][j], 1, 1, output_file);
		}
	}
	fclose(output_file);
}
void HW::HW1_3b() {
	char  input_img[] = "lena256.raw";                 // Input  raw image name
	char output_img[] = "(1_3b)lena256out.raw";              // Output raw image name
	FILE* input_file;
	FILE* output_file;
	int size = width * height;
	int i, j, x;
	BYTE B[height][width];
	BYTE* ptr;

	unsigned char* img_lena = new unsigned char[size];
	input_file = fopen(input_img, "rb");
	srand(time(NULL));
	if (input_file == NULL)
	{
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}

	ptr = (BYTE*)malloc(width * height * sizeof(BYTE));
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (ptr > 0)
			{
				fread(ptr, 1, 1, input_file);
				B[i][j] = *ptr;
				ptr++;
			}
		}
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			x = rand()%120-60;

			if (B[i][j] + x > 255)
			{
				B[i][j] = 255;
			}
			else if (B[i][j] + x < 0)
			{
				B[i][j] = 0;
			}
			else 
			{
				B[i][j] = B[i][j] + x;
			}
		}
	}

	if ((output_file = fopen(output_img, "wb")) == NULL)
	{
		printf("can not create the raw_image : %s\n", output_img);

		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			fwrite(&B[i][j], 1, 1, output_file);
		}
	}
	fclose(output_file);
}
int HW::HW2_b() { 
	Mat image(512, 512, CV_8UC1, cv::Scalar(255));  

	ellipse(image, Point(256, 256), Size(200, 200), 0, 174, 367, Scalar(100), -1, LINE_AA);
	ellipse(image, Point(256, 300), Size(195, 121), 180, 6, 174, Scalar(255), -1, LINE_AA);
	circle(image, Point(256, 256), 200, Scalar(0), 3); //頭
	ellipse(image, Point(256, 300), Size(198, 125), 180, 6, 65, Scalar(0), 2, LINE_AA);
	ellipse(image, Point(256, 300), Size(198, 120), 180, 115, 174, Scalar(0), 2, LINE_AA);

	ellipse(image, Point(215, 180), Size(40, 52), 0, 0, 360, Scalar(255), -1, LINE_AA);
	ellipse(image, Point(298, 180), Size(40, 52), 0, 0, 360, Scalar(255), -1, LINE_AA);
	ellipse(image, Point(215, 180),Size(40, 52), 0, 0,360, Scalar(0),2, LINE_AA);
	ellipse(image, Point(298, 180), Size(40, 52), 0, 0, 360, Scalar(0), 2, LINE_AA);
	ellipse(image, Point(225, 185), Size(9, 15), 0, 0, 360, Scalar(0), 5, LINE_AA);
	ellipse(image, Point(287, 185), Size(9, 15), 0, 0, 360, Scalar(0), 5, LINE_AA);

	circle(image, Point(256, 235), 20, Scalar(0), 3);
	circle(image, Point(256, 235), 18, Scalar(100), -1);
	circle(image, Point(250, 230), 5, Scalar(255), -1);

	line(image, Point(256, 256), Point(256, 385), Scalar(0), 2);
	ellipse(image, Point(256, 295), Size(120, 90), 180,360, 180, Scalar(0), 2, LINE_AA);

	line(image, Point(180, 280), Point(55, 242), Scalar(0), 2);
	line(image, Point(180, 300), Point(56, 285), Scalar(0), 2);
	line(image, Point(180, 320), Point(82, 360), Scalar(0), 2);	
	
	line(image, Point(332, 280), Point(455, 242), Scalar(0), 2);
	line(image, Point(332, 300), Point(452, 285), Scalar(0), 2);
	line(image, Point(332, 320), Point(423, 360), Scalar(0), 2);

	putText(image, "112318084", Point(168, 490), FONT_HERSHEY_COMPLEX, 1,Scalar(0), 2, 1, 0);
	imwrite("doraemon.png", image);
	imshow("Doraemon", image);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
