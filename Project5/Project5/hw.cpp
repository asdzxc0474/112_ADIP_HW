#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include "class.h"
#include "hw.h"
using namespace std;
using namespace cv;

void hw::HW1_1()
{
	rw rw;
	hw5 hw5;
	char lena[] = "lena_256.raw";
	char baboon[] = "baboon_256.raw";
	char lenaDFT[] = "(1_1)lenaDFT_256.raw";
	char baboonDFT[] = "(1_1)baboonDFT_256.raw";
	double* real = new double[256 * 256];
	double* imagine = new double[256 * 256];
	unsigned char* lena256 = rw.read_Raw_data(lena, 256, 256);
	unsigned char* baboon256 = rw.read_Raw_data(baboon, 256, 256);
	unsigned char* lena256_DFT = hw5.DFT(lena256, 256, 256, real, imagine);
	unsigned char* baboon256_DFT = hw5.DFT(baboon256, 256, 256, real, imagine);
	rw.write_raw_data(lenaDFT, lena256_DFT, 256, 256);
	rw.write_raw_data(baboonDFT, baboon256_DFT, 256, 256);
	delete[] real, imagine;
}
void hw::HW1_2()
{
	rw rw;
	hw5 hw5;
	char lena[] = "lena_256.raw";
	char baboon[] = "baboon_256.raw";
	char lenaIDFT[] = "(1_2)lena_IDFT_256.raw";
	char baboonIDFT[] = "(1_2)baboon_IDFT_256.raw";
	double* real = new double[256 * 256];
	double* imagine = new double[256 * 256];
	unsigned char* lena256 = rw.read_Raw_data(lena, 256, 256);
	unsigned char* baboon256 = rw.read_Raw_data(baboon, 256, 256);
	unsigned char* lena256_DFT = hw5.DFT(lena256, 256, 256, real, imagine);
	unsigned char* lena256_IDFT = hw5.IDFT(lena256_DFT, 256, 256, real, imagine);
	printf("=======================================================\nMSE, PSNR between lena_256 and lena256_IDFT\n");
	float MSE_lena = hw5.MSE(lena256_IDFT, lena256, 256, 256);
	float PSNR_lena = hw5.PSNR(MSE_lena, 256);
	printf("=======================================================\n");
	unsigned char* baboon256_DFT = hw5.DFT(baboon256, 256, 256, real, imagine);
	unsigned char* baboon256_IDFT = hw5.IDFT(baboon256_DFT, 256, 256, real, imagine);
	printf("=======================================================\nMSE, PSNR between baboon_256 and baboon256_IDFT\n");
	float MSE_baboon = hw5.MSE(baboon256_IDFT, baboon256, 256, 256);
	float PSNR_baboon = hw5.PSNR(MSE_baboon, 256);
	printf("=======================================================\n");
	rw.write_raw_data(lenaIDFT, lena256_IDFT, 256, 256);
	rw.write_raw_data(baboonIDFT, baboon256_IDFT, 256, 256);
	delete[] real, imagine;
}
void hw::HW1_3()
{
	rw rw;
	hw5 hw5;
	char lena[] = "lena_256.raw";
	char lena_DFT[] = "(1_1)lenaDFT_256.raw";
	char lena_DFT_opencv[] = "(1_3)lena256_DFT_with_opencv";
	char baboon[] = "baboon_256.raw";
	char baboon_DFT[] = "(1_1)baboonDFT_256.raw";
	char baboon_DFT_opencv[] = "(1_3)baboon256_DFT_with_opencv";

	Mat lena256_mat = rw.Opencv_read_raw_data(lena, 256, 256);
	Mat lena256_DFT_mat = rw.Opencv_read_raw_data(lena_DFT, 256, 256);
	Mat lena256_DFT_opencv = hw5.Opencv_DFT(lena256_mat);
	hw5.show_Mat_img(lena256_DFT_opencv, lena_DFT_opencv);
	imwrite("(1_3)lena256_DFT_opencv.png", lena256_DFT_opencv * 255); // *255 to inverse normalize
	printf("=======================================================\nMSE, PSNR between (1_1)lenaDFT_256.raw and lena256_DFT_with_opencv\n");
	float MSE_lena = hw5.Get_Mat_MSE(lena256_DFT_mat, lena256_DFT_opencv);
	float PSNR_lena = hw5.PSNR(MSE_lena, 256);
	printf("=======================================================\n");

	Mat baboon256_mat = rw.Opencv_read_raw_data(baboon, 256, 256);
	Mat baboon256_DFT_mat = rw.Opencv_read_raw_data(baboon_DFT, 256, 256);
	Mat baboon256_DFT_opencv = hw5.Opencv_DFT(baboon256_mat);
	hw5.show_Mat_img(baboon256_DFT_opencv, baboon_DFT_opencv);
	imwrite("(1_3)baboon256_DFT_opencv.png", baboon256_DFT_opencv * 255); // *255 to inverse normalize
	printf("=======================================================\nMSE, PSNR between (1_1)baboonDFT_256.raw and baboon256_DFT_with_opencv\n");
	float MSE_baboon = hw5.Get_Mat_MSE(baboon256_DFT_mat, baboon256_DFT_opencv);
	float PSNR_baboon = hw5.PSNR(MSE_baboon, 256);
	printf("=======================================================\n");
}
void hw::HW1_4()
{
	rw rw;
	hw5 hw5;
	char lena[] = "lena_256.raw";
	char lenaIDFT[] = "(1_2)lena_IDFT_256.raw";
	char lena_IDFT_opencv[] = "(1_4)lena256_IDFT_with_opencv";
	char baboon[] = "baboon_256.raw";
	char baboon_IDFT[] = "(1_2)baboon_IDFT_256.raw";
	char baboon_IDFT_opencv[] = "(1_4)baboon256_IDFT_with_opencv";

	Mat lena256_mat = rw.Opencv_read_raw_data(lena, 256, 256);
	Mat lena256_IDFT_mat = rw.Opencv_read_raw_data(lenaIDFT, 256, 256);
	Mat lena256_DFT_COMPLEX = hw5.Opencv_DFT_COMPLEX_OUTPUT(lena256_mat);
	Mat lena256_IDFT_opencv = hw5.Opencv_IDFT(lena256_DFT_COMPLEX);
	hw5.show_Mat_img(lena256_IDFT_opencv, lena_IDFT_opencv);
	imwrite("(1_4)lena256_IDFT_opencv.png", lena256_IDFT_opencv * 255);
	printf("=======================================================\nMSE, PSNR between (1_2)lena_IDFT_256.raw and lena256_IDFT_with_opencv\n");
	float MSE_lena = hw5.Get_Mat_MSE(lena256_IDFT_mat, lena256_IDFT_opencv * 255);
	float PSNR_lena = hw5.PSNR(MSE_lena, 256);
	printf("=======================================================\n");

	Mat baboon_mat = rw.Opencv_read_raw_data(baboon, 256, 256);
	Mat baboon256_IDFT_mat = rw.Opencv_read_raw_data(baboon_IDFT, 256, 256);
	Mat baboon256_DFT_COMPLEX = hw5.Opencv_DFT_COMPLEX_OUTPUT(baboon_mat);
	Mat baboon256_IDFT_opencv = hw5.Opencv_IDFT(baboon256_DFT_COMPLEX);
	hw5.show_Mat_img(baboon256_IDFT_opencv, baboon_IDFT_opencv);
	imwrite("(1_4)baboon256_IDFT_opencv.png", baboon256_IDFT_opencv * 255);	
	printf("=======================================================\nMSE, PSNR between (1_2)baboon_IDFT_256.raw and baboon256_IDFT_opencv\n");
	float MSE_baboon = hw5.Get_Mat_MSE(baboon256_IDFT_mat, baboon256_IDFT_opencv * 255);
	float PSNR_baboon = hw5.PSNR(MSE_baboon, 256);
	printf("=======================================================\n");
}
void hw::HW1_5()
{
	rw rw;
	hw5 hw5;
	char lena[] = "lena_256.raw";
	char baboon[] = "baboon_256.raw";
	char lenaDCT[] = "(1_5)lenaDCT_256.raw";
	char baboonDcT[] = "(1_5)baboonDCT_256.raw";
	double* outarr = new double[256 * 256];
	unsigned char* lena256 = rw.read_Raw_data(lena, 256, 256);
	unsigned char* baboon256 = rw.read_Raw_data(baboon, 256, 256);
	unsigned char* lena256_DCT = hw5.DCT(lena256, 256, 256, outarr);
	unsigned char* baboon256_DCT = hw5.DCT(baboon256, 256, 256, outarr);
	rw.write_raw_data(lenaDCT, lena256_DCT, 256, 256);
	rw.write_raw_data(baboonDcT, baboon256_DCT, 256, 256);
	delete[] outarr;
}
void hw::HW1_6()
{
	rw rw;
	hw5 hw5;
	char lena[] = "lena_256.raw";
	char baboon[] = "baboon_256.raw";
	char lenaIDCT[] = "(1_6)lenaIDCT_256.raw";
	char baboonIDCT[] = "(1_6)baboonIDCT_256.raw";
	double* outarr = new double[256 * 256];
	unsigned char* lena256 = rw.read_Raw_data(lena, 256, 256);
	unsigned char* baboon256 = rw.read_Raw_data(baboon, 256, 256);
	unsigned char* lena256_DCT = hw5.DCT(lena256, 256, 256, outarr);
	unsigned char* lena256_IDCT = hw5.IDCT(outarr, 256, 256);
	printf("=======================================================\nMSE, PSNR between lena_256 and lena256_IDCT\n");
	float MSE_lena = hw5.MSE(lena256_IDCT, lena256, 256, 256);
	float PSNR_lena = hw5.PSNR(MSE_lena, 256);
	printf("=======================================================\n");
	unsigned char* baboon256_DCT = hw5.DCT(baboon256, 256, 256, outarr);
	unsigned char* baboon256_IDCT = hw5.IDCT(outarr, 256, 256);	
	printf("=======================================================\nMSE, PSNR between baboon_256 and baboon256_IDCT\n");
	float MSE_baboon = hw5.MSE(baboon256_IDCT, baboon256, 256, 256);
	float PSNR_baboon = hw5.PSNR(MSE_baboon, 256);
	printf("=======================================================\n");
	rw.write_raw_data(lenaIDCT, lena256_IDCT, 256, 256);
	rw.write_raw_data(baboonIDCT, baboon256_IDCT, 256, 256);
	delete[] outarr;
}
void hw::HW2_1()
{
	rw rw;
	hw5 hw5;
	char baboon[] = "baboon_256.raw";
	Mat baboon_mat = rw.Opencv_read_raw_data(baboon, 256, 256);

	char GLPF10[] = "baboon_GLPF10";
	char GLPF20[] = "baboon_GLPF20";
	char GLPF40[] = "baboon_GLPF40";
	char GLPF100[] = "baboon_GLPF100";
	char GHPF10[] = "baboon_GHPF10";
	char GHPF20[] = "baboon_GHPF20";
	char GHPF40[] = "baboon_GHPF40";
	char GHPF100[] = "baboon_GHPF100";
	char cvLPF10[] = "(2_1)GLPF_10_magntude_spectrum.png";
	char cvLPF20[] = "(2_1)GLPF_20_magntude_spectrum.png";
	char cvLPF40[] = "(2_1)GLPF_40_magntude_spectrum.png";
	char cvLPF100[] = "(2_1)GLPF_100_magntude_spectrum.png";
	char cvHPF10[] = "(2_1)GHPF_10_magntude_spectrum.png";
	char cvHPF20[] = "(2_1)GHPF_20_magntude_spectrum.png";
	char cvHPF40[] = "(2_1)GHPF_40_magntude_spectrum.png";
	char cvHPF100[] = "(2_1)GHPF_100_magntude_spectrum.png";

	Mat Gaussian_LPF_10 = hw5.Gaussian_LPF(baboon_mat, 10.0, true, cvLPF10);
	Mat Gaussian_LPF_20 = hw5.Gaussian_LPF(baboon_mat, 20.0, true, cvLPF20);
	Mat Gaussian_LPF_40 = hw5.Gaussian_LPF(baboon_mat, 40.0, true, cvLPF40);
	Mat Gaussian_LPF_100 = hw5.Gaussian_LPF(baboon_mat, 100.0, true, cvLPF100);
	Mat Gaussian_LPF_10_noshift = hw5.Gaussian_LPF(baboon_mat, 10.0, false, cvLPF10);
	Mat Gaussian_LPF_20_noshift = hw5.Gaussian_LPF(baboon_mat, 20.0, false, cvLPF20);
	Mat Gaussian_LPF_40_noshift = hw5.Gaussian_LPF(baboon_mat, 40.0, false, cvLPF40);
	Mat Gaussian_LPF_100_noshift = hw5.Gaussian_LPF(baboon_mat, 100.0, false, cvLPF100);

	Mat Gaussian_HPF_10 = hw5.Gaussian_HPF(baboon_mat, 10.0, true, cvHPF10);
	Mat Gaussian_HPF_20 = hw5.Gaussian_HPF(baboon_mat, 20.0, true, cvHPF20);
	Mat Gaussian_HPF_40 = hw5.Gaussian_HPF(baboon_mat, 40.0, true, cvHPF40);
	Mat Gaussian_HPF_100 = hw5.Gaussian_HPF(baboon_mat, 100.0, true, cvHPF100);
	Mat Gaussian_HPF_10_noshift = hw5.Gaussian_HPF(baboon_mat, 10.0, false, cvHPF10);
	Mat Gaussian_HPF_20_noshift = hw5.Gaussian_HPF(baboon_mat, 20.0, false, cvHPF20);
	Mat Gaussian_HPF_40_noshift = hw5.Gaussian_HPF(baboon_mat, 40.0, false, cvHPF40);
	Mat Gaussian_HPF_100_noshift = hw5.Gaussian_HPF(baboon_mat, 100.0, false, cvHPF100);

	imwrite("(2_1)IDFT_GLPF_10.png", Gaussian_LPF_10* 255);
	imwrite("(2_1)IDFT_GLPF_20.png", Gaussian_LPF_20 * 255);
	imwrite("(2_1)IDFT_GLPF_40.png", Gaussian_LPF_40 * 255);
	imwrite("(2_1)IDFT_GLPF_100.png", Gaussian_LPF_100 * 255);
	imwrite("(2_1)IDFT_GLPF_10_noshift.png", Gaussian_LPF_10_noshift * 255);
	imwrite("(2_1)IDFT_GLPF_20_noshift.png", Gaussian_LPF_20_noshift * 255);
	imwrite("(2_1)IDFT_GLPF_40_noshift.png", Gaussian_LPF_40_noshift * 255);
	imwrite("(2_1)IDFT_GLPF_100_noshift.png", Gaussian_LPF_100_noshift * 255);
	imwrite("(2_1)IDFT_GHPF_10.png", Gaussian_HPF_10 * 255);
	imwrite("(2_1)IDFT_GHPF_20.png", Gaussian_HPF_20 * 255);
	imwrite("(2_1)IDFT_GHPF_40.png", Gaussian_HPF_40 * 255);
	imwrite("(2_1)IDFT_GHPF_100.png", Gaussian_HPF_100 * 255);
	imwrite("(2_1)IDFT_GHPF_10_noshift.png", Gaussian_HPF_10_noshift * 255);
	imwrite("(2_1)IDFT_GHPF_20_noshift.png", Gaussian_HPF_20_noshift * 255);
	imwrite("(2_1)IDFT_GHPF_40_noshift.png", Gaussian_HPF_40_noshift * 255);
	imwrite("(2_1)IDFT_GHPF_100_noshift.png", Gaussian_HPF_100_noshift * 255);
}
void hw::HW2_2()
{
	rw rw;
	hw5 hw5;
	char baboon[] = "baboon_256.raw";
	Mat baboon_mat = rw.Opencv_read_raw_data(baboon, 256, 256);


	char cvLPF10_1[] = "(2_2)BLPF_10_1_magntude_spectrum.png";
	char cvLPF10_2[] = "(2_2)BLPF_10_2_magntude_spectrum.png";
	char cvLPF10_3[] = "(2_2)BLPF_10_3_magntude_spectrum.png";
	char cvLPF10_4[] = "(2_2)BLPF_10_4_magntude_spectrum.png";
	char cvLPF20_1[] = "(2_2)BLPF_20_1_magntude_spectrum.png";
	char cvLPF20_2[] = "(2_2)BLPF_20_2_magntude_spectrum.png";
	char cvLPF20_3[] = "(2_2)BLPF_20_3_magntude_spectrum.png";
	char cvLPF20_4[] = "(2_2)BLPF_20_4_magntude_spectrum.png";
	char cvLPF40_1[] = "(2_2)BLPF_40_1_magntude_spectrum.png";
	char cvLPF40_2[] = "(2_2)BLPF_40_2_magntude_spectrum.png";
	char cvLPF40_3[] = "(2_2)BLPF_40_3_magntude_spectrum.png";
	char cvLPF40_4[] = "(2_2)BLPF_40_4_magntude_spectrum.png";
	char cvLPF100_1[] = "(2_2)BLPF_100_1_magntude_spectrum.png";
	char cvLPF100_2[] = "(2_2)BLPF_100_2_magntude_spectrum.png";
	char cvLPF100_3[] = "(2_2)BLPF_100_3_magntude_spectrum.png";
	char cvLPF100_4[] = "(2_2)BLPF_100_4_magntude_spectrum.png";

	char cvHPF10_1[] = "(2_2)BHPF_10_1_magntude_spectrum.png";
	char cvHPF10_2[] = "(2_2)BHPF_10_2_magntude_spectrum.png";
	char cvHPF10_3[] = "(2_2)BHPF_10_3_magntude_spectrum.png";
	char cvHPF10_4[] = "(2_2)BHPF_10_4_magntude_spectrum.png";
	char cvHPF20_1[] = "(2_2)BHPF_20_1_magntude_spectrum.png";
	char cvHPF20_2[] = "(2_2)BHPF_20_2_magntude_spectrum.png";
	char cvHPF20_3[] = "(2_2)BHPF_20_3_magntude_spectrum.png";
	char cvHPF20_4[] = "(2_2)BHPF_20_4_magntude_spectrum.png";
	char cvHPF40_1[] = "(2_2)BHPF_40_1_magntude_spectrum.png";
	char cvHPF40_2[] = "(2_2)BHPF_40_2_magntude_spectrum.png";
	char cvHPF40_3[] = "(2_2)BHPF_40_3_magntude_spectrum.png";
	char cvHPF40_4[] = "(2_2)BHPF_40_4_magntude_spectrum.png";
	char cvHPF100_1[] = "(2_2)BHPF_100_1_magntude_spectrum.png";
	char cvHPF100_2[] = "(2_2)BHPF_100_2_magntude_spectrum.png";
	char cvHPF100_3[] = "(2_2)BHPF_100_3_magntude_spectrum.png";
	char cvHPF100_4[] = "(2_2)BHPF_100_4_magntude_spectrum.png";

	Mat BLPF_10_1 = hw5.Butterworth_LPF(baboon_mat, 10.0, 1, true, cvLPF10_1);
	Mat BLPF_10_2 = hw5.Butterworth_LPF(baboon_mat, 10.0, 2, true, cvLPF10_2);
	Mat BLPF_10_3 = hw5.Butterworth_LPF(baboon_mat, 10.0, 3, true, cvLPF10_3);
	Mat BLPF_10_4 = hw5.Butterworth_LPF(baboon_mat, 10.0, 4, true, cvLPF10_4);
	Mat BLPF_10_1_noshift = hw5.Butterworth_LPF(baboon_mat, 10.0, 1, false, cvLPF10_1);
	Mat BLPF_10_2_noshift = hw5.Butterworth_LPF(baboon_mat, 10.0, 2, false, cvLPF10_2);
	Mat BLPF_10_3_noshift = hw5.Butterworth_LPF(baboon_mat, 10.0, 3, false, cvLPF10_3);
	Mat BLPF_10_4_noshift = hw5.Butterworth_LPF(baboon_mat, 10.0, 4, false, cvLPF10_4);

	Mat BHPF_10_1 = hw5.Butterworth_HPF(baboon_mat, 10.0, 1, true, cvHPF10_1);
	Mat BHPF_10_2 = hw5.Butterworth_HPF(baboon_mat, 10.0, 2, true, cvHPF10_2);
	Mat BHPF_10_3 = hw5.Butterworth_HPF(baboon_mat, 10.0, 3, true, cvHPF10_3);
	Mat BHPF_10_4 = hw5.Butterworth_HPF(baboon_mat, 10.0, 4, true, cvHPF10_4);
	Mat BHPF_10_1_noshift = hw5.Butterworth_HPF(baboon_mat, 10.0, 1, false, cvHPF10_1);
	Mat BHPF_10_2_noshift = hw5.Butterworth_HPF(baboon_mat, 10.0, 2, false, cvHPF10_2);
	Mat BHPF_10_3_noshift = hw5.Butterworth_HPF(baboon_mat, 10.0, 3, false, cvHPF10_3);
	Mat BHPF_10_4_noshift = hw5.Butterworth_HPF(baboon_mat, 10.0, 4, false, cvHPF10_4);

	Mat BLPF_20_1 = hw5.Butterworth_LPF(baboon_mat, 20.0, 1, true, cvLPF20_1);
	Mat BLPF_20_2 = hw5.Butterworth_LPF(baboon_mat, 20.0, 2, true, cvLPF20_2);
	Mat BLPF_20_3 = hw5.Butterworth_LPF(baboon_mat, 20.0, 3, true, cvLPF20_3);
	Mat BLPF_20_4 = hw5.Butterworth_LPF(baboon_mat, 20.0, 4, true, cvLPF20_4);
	Mat BLPF_20_1_noshift = hw5.Butterworth_LPF(baboon_mat, 20.0, 1, false, cvLPF20_1);
	Mat BLPF_20_2_noshift = hw5.Butterworth_LPF(baboon_mat, 20.0, 2, false, cvLPF20_2);
	Mat BLPF_20_3_noshift = hw5.Butterworth_LPF(baboon_mat, 20.0, 3, false, cvLPF20_3);
	Mat BLPF_20_4_noshift = hw5.Butterworth_LPF(baboon_mat, 20.0, 4, false, cvLPF20_4);

	Mat BHPF_20_1 = hw5.Butterworth_HPF(baboon_mat, 20.0, 1, true, cvHPF20_1);
	Mat BHPF_20_2 = hw5.Butterworth_HPF(baboon_mat, 20.0, 2, true, cvHPF20_2);
	Mat BHPF_20_3 = hw5.Butterworth_HPF(baboon_mat, 20.0, 3, true, cvHPF20_3);
	Mat BHPF_20_4 = hw5.Butterworth_HPF(baboon_mat, 20.0, 4, true, cvHPF20_4);
	Mat BHPF_20_1_noshift = hw5.Butterworth_HPF(baboon_mat, 20.0, 1, false, cvHPF20_1);
	Mat BHPF_20_2_noshift = hw5.Butterworth_HPF(baboon_mat, 20.0, 2, false, cvHPF20_2);
	Mat BHPF_20_3_noshift = hw5.Butterworth_HPF(baboon_mat, 20.0, 3, false, cvHPF20_3);
	Mat BHPF_20_4_noshift = hw5.Butterworth_HPF(baboon_mat, 20.0, 4, false, cvHPF20_4);

	Mat BLPF_40_1 = hw5.Butterworth_LPF(baboon_mat, 40.0, 1, true, cvLPF40_1);
	Mat BLPF_40_2 = hw5.Butterworth_LPF(baboon_mat, 40.0, 2, true, cvLPF40_2);
	Mat BLPF_40_3 = hw5.Butterworth_LPF(baboon_mat, 40.0, 3, true, cvLPF40_3);
	Mat BLPF_40_4 = hw5.Butterworth_LPF(baboon_mat, 40.0, 4, true, cvLPF40_4);
	Mat BLPF_40_1_noshift = hw5.Butterworth_LPF(baboon_mat, 40.0, 1, false, cvLPF40_1);
	Mat BLPF_40_2_noshift = hw5.Butterworth_LPF(baboon_mat, 40.0, 2, false, cvLPF40_2);
	Mat BLPF_40_3_noshift = hw5.Butterworth_LPF(baboon_mat, 40.0, 3, false, cvLPF40_3);
	Mat BLPF_40_4_noshift = hw5.Butterworth_LPF(baboon_mat, 40.0, 4, false, cvLPF40_4);

	Mat BHPF_40_1 = hw5.Butterworth_HPF(baboon_mat, 40.0, 1, true, cvHPF40_1);
	Mat BHPF_40_2 = hw5.Butterworth_HPF(baboon_mat, 40.0, 2, true, cvHPF40_2);
	Mat BHPF_40_3 = hw5.Butterworth_HPF(baboon_mat, 40.0, 3, true, cvHPF40_3);
	Mat BHPF_40_4 = hw5.Butterworth_HPF(baboon_mat, 40.0, 4, true, cvHPF40_4);
	Mat BHPF_40_1_noshift = hw5.Butterworth_HPF(baboon_mat, 40.0, 1, false, cvHPF40_1);
	Mat BHPF_40_2_noshift = hw5.Butterworth_HPF(baboon_mat, 40.0, 2, false, cvHPF40_2);
	Mat BHPF_40_3_noshift = hw5.Butterworth_HPF(baboon_mat, 40.0, 3, false, cvHPF40_3);
	Mat BHPF_40_4_noshift = hw5.Butterworth_HPF(baboon_mat, 40.0, 4, false, cvHPF40_4);

	Mat BLPF_100_1 = hw5.Butterworth_LPF(baboon_mat, 100.0, 1, true, cvLPF100_1);
	Mat BLPF_100_2 = hw5.Butterworth_LPF(baboon_mat, 100.0, 2, true, cvLPF100_2);
	Mat BLPF_100_3 = hw5.Butterworth_LPF(baboon_mat, 100.0, 3, true, cvLPF100_3);
	Mat BLPF_100_4 = hw5.Butterworth_LPF(baboon_mat, 100.0, 4, true, cvLPF100_4);
	Mat BLPF_100_1_noshift = hw5.Butterworth_LPF(baboon_mat, 100.0, 1, false, cvLPF100_1);
	Mat BLPF_100_2_noshift = hw5.Butterworth_LPF(baboon_mat, 100.0, 2, false, cvLPF100_2);
	Mat BLPF_100_3_noshift = hw5.Butterworth_LPF(baboon_mat, 100.0, 3, false, cvLPF100_3);
	Mat BLPF_100_4_noshift = hw5.Butterworth_LPF(baboon_mat, 100.0, 4, false, cvLPF100_4);

	Mat BHPF_100_1 = hw5.Butterworth_HPF(baboon_mat, 100.0, 1, true, cvHPF100_1);
	Mat BHPF_100_2 = hw5.Butterworth_HPF(baboon_mat, 100.0, 2, true, cvHPF100_2);
	Mat BHPF_100_3 = hw5.Butterworth_HPF(baboon_mat, 100.0, 3, true, cvHPF100_3);
	Mat BHPF_100_4 = hw5.Butterworth_HPF(baboon_mat, 100.0, 4, true, cvHPF100_4);
	Mat BHPF_100_1_noshift = hw5.Butterworth_HPF(baboon_mat, 100.0, 1, false, cvHPF100_1);
	Mat BHPF_100_2_noshift = hw5.Butterworth_HPF(baboon_mat, 100.0, 2, false, cvHPF100_2);
	Mat BHPF_100_3_noshift = hw5.Butterworth_HPF(baboon_mat, 100.0, 3, false, cvHPF100_3);
	Mat BHPF_100_4_noshift = hw5.Butterworth_HPF(baboon_mat, 100.0, 4, false, cvHPF100_4);

	imwrite("(2_2)IDFT_BLPF_10_1.png", BLPF_10_1 * 255);
	imwrite("(2_2)IDFT_BLPF_10_2.png", BLPF_10_2 * 255);
	imwrite("(2_2)IDFT_BLPF_10_3.png", BLPF_10_3 * 255);
	imwrite("(2_2)IDFT_BLPF_10_4.png", BLPF_10_4 * 255);
	imwrite("(2_2)IDFT_BLPF_10_1_noshift.png", BLPF_10_1_noshift * 255);
	imwrite("(2_2)IDFT_BLPF_10_2_noshift.png", BLPF_10_2_noshift * 255);
	imwrite("(2_2)IDFT_BLPF_10_3_noshift.png", BLPF_10_3_noshift * 255);
	imwrite("(2_2)IDFT_BLPF_10_4_noshift.png", BLPF_10_4_noshift * 255);
	imwrite("(2_2)IDFT_BLPF_20_1.png", BLPF_20_1 * 255);
	imwrite("(2_2)IDFT_BLPF_20_2.png", BLPF_20_2 * 255);
	imwrite("(2_2)IDFT_BLPF_20_3.png", BLPF_20_3 * 255);
	imwrite("(2_2)IDFT_BLPF_20_4.png", BLPF_20_4 * 255);
	imwrite("(2_2)IDFT_BLPF_20_1_noshift.png", BLPF_20_1_noshift * 255);
	imwrite("(2_2)IDFT_BLPF_20_2_noshift.png", BLPF_20_2_noshift * 255);
	imwrite("(2_2)IDFT_BLPF_20_3_noshift.png", BLPF_20_3_noshift * 255);
	imwrite("(2_2)IDFT_BLPF_20_4_noshift.png", BLPF_20_4_noshift * 255);
	imwrite("(2_2)IDFT_BLPF_40_1.png", BLPF_40_1 * 255);
	imwrite("(2_2)IDFT_BLPF_40_2.png", BLPF_40_2 * 255);
	imwrite("(2_2)IDFT_BLPF_40_3.png", BLPF_40_3 * 255);
	imwrite("(2_2)IDFT_BLPF_40_4.png", BLPF_40_4 * 255);
	imwrite("(2_2)IDFT_BLPF_40_1_noshift.png", BLPF_40_1_noshift * 255);
	imwrite("(2_2)IDFT_BLPF_40_2_noshift.png", BLPF_40_2_noshift * 255);
	imwrite("(2_2)IDFT_BLPF_40_3_noshift.png", BLPF_40_3_noshift * 255);
	imwrite("(2_2)IDFT_BLPF_40_4_noshift.png", BLPF_40_4_noshift * 255);
	imwrite("(2_2)IDFT_BLPF_100_1.png", BLPF_100_1 * 255);
	imwrite("(2_2)IDFT_BLPF_100_2.png", BLPF_100_2 * 255);
	imwrite("(2_2)IDFT_BLPF_100_3.png", BLPF_100_3 * 255);
	imwrite("(2_2)IDFT_BLPF_100_4.png", BLPF_100_4 * 255);
	imwrite("(2_2)IDFT_BLPF_100_1_noshift.png", BLPF_100_1_noshift * 255);
	imwrite("(2_2)IDFT_BLPF_100_2_noshift.png", BLPF_100_2_noshift * 255);
	imwrite("(2_2)IDFT_BLPF_100_3_noshift.png", BLPF_100_3_noshift * 255);
	imwrite("(2_2)IDFT_BLPF_100_4_noshift.png", BLPF_100_4_noshift * 255);

	imwrite("(2_2)IDFT_BHPF_10_1.png", BHPF_10_1 * 255);
	imwrite("(2_2)IDFT_BHPF_10_2.png", BHPF_10_2 * 255);
	imwrite("(2_2)IDFT_BHPF_10_3.png", BHPF_10_3 * 255);
	imwrite("(2_2)IDFT_BHPF_10_4.png", BHPF_10_4 * 255);
	imwrite("(2_2)IDFT_BHPF_10_1_noshift.png", BHPF_10_1_noshift * 255);
	imwrite("(2_2)IDFT_BHPF_10_2_noshift.png", BHPF_10_2_noshift * 255);
	imwrite("(2_2)IDFT_BHPF_10_3_noshift.png", BHPF_10_3_noshift * 255);
	imwrite("(2_2)IDFT_BHPF_10_4_noshift.png", BHPF_10_4_noshift * 255);
	imwrite("(2_2)IDFT_BHPF_20_1.png", BHPF_20_1 * 255);
	imwrite("(2_2)IDFT_BHPF_20_2.png", BHPF_20_2 * 255);
	imwrite("(2_2)IDFT_BHPF_20_3.png", BHPF_20_3 * 255);
	imwrite("(2_2)IDFT_BHPF_20_4.png", BHPF_20_4 * 255);
	imwrite("(2_2)IDFT_BHPF_20_1_noshift.png", BHPF_20_1_noshift * 255);
	imwrite("(2_2)IDFT_BHPF_20_2_noshift.png", BHPF_20_2_noshift * 255);
	imwrite("(2_2)IDFT_BHPF_20_3_noshift.png", BHPF_20_3_noshift * 255);
	imwrite("(2_2)IDFT_BHPF_20_4_noshift.png", BHPF_20_4_noshift * 255);
	imwrite("(2_2)IDFT_BHPF_40_1.png", BHPF_40_1 * 255);
	imwrite("(2_2)IDFT_BHPF_40_2.png", BHPF_40_2 * 255);
	imwrite("(2_2)IDFT_BHPF_40_3.png", BHPF_40_3 * 255);
	imwrite("(2_2)IDFT_BHPF_40_4.png", BHPF_40_4 * 255);
	imwrite("(2_2)IDFT_BHPF_40_1_noshift.png", BHPF_40_1_noshift * 255);
	imwrite("(2_2)IDFT_BHPF_40_2_noshift.png", BHPF_40_2_noshift * 255);
	imwrite("(2_2)IDFT_BHPF_40_3_noshift.png", BHPF_40_3_noshift * 255);
	imwrite("(2_2)IDFT_BHPF_40_4_noshift.png", BHPF_40_4_noshift * 255);
	imwrite("(2_2)IDFT_BHPF_100_1.png", BHPF_100_1 * 255);
	imwrite("(2_2)IDFT_BHPF_100_2.png", BHPF_100_2 * 255);
	imwrite("(2_2)IDFT_BHPF_100_3.png", BHPF_100_3 * 255);
	imwrite("(2_2)IDFT_BHPF_100_4.png", BHPF_100_4 * 255);
	imwrite("(2_2)IDFT_BHPF_100_1_noshift.png", BHPF_100_1_noshift * 255);
	imwrite("(2_2)IDFT_BHPF_100_2_noshift.png", BHPF_100_2_noshift * 255);
	imwrite("(2_2)IDFT_BHPF_100_3_noshift.png", BHPF_100_3_noshift * 255);
	imwrite("(2_2)IDFT_BHPF_100_4_noshift.png", BHPF_100_4_noshift * 255);
}
void hw::HW2_3()
{
	rw rw;
	hw5 hw5;
	char baboon[] = "baboon_256.raw";
	Mat baboon_mat = rw.Opencv_read_raw_data(baboon, 256, 256);

	char cvILPF10[] = "(2_3)ILPF_10_magntude_spectrum.png";
	char cvILPF20[] = "(2_3)ILPF_20_magntude_spectrum.png";
	char cvILPF40[] = "(2_3)ILPF_40_magntude_spectrum.png";
	char cvILPF100[] = "(2_3)ILPF_100_magntude_spectrum.png";
	char cvIHPF10[] = "(2_3)IHPF_10_magntude_spectrum.png";
	char cvIHPF20[] = "(2_3)IHPF_20_magntude_spectrum.png";
	char cvIHPF40[] = "(2_3)IHPF_40_magntude_spectrum.png";
	char cvIHPF100[] = "(2_3)IHPF_100_magntude_spectrum.png";

	Mat ILPF_10 = hw5.Ideal_LPF(baboon_mat, 10.0, true, cvILPF10);
	Mat ILPF_20 = hw5.Ideal_LPF(baboon_mat, 20.0, true, cvILPF20);
	Mat ILPF_40 = hw5.Ideal_LPF(baboon_mat, 40.0, true, cvILPF40);
	Mat ILPF_100 = hw5.Ideal_LPF(baboon_mat, 100.0, true, cvILPF100);
	Mat ILPF_10_without_shift = hw5.Ideal_LPF(baboon_mat, 10.0, false, cvILPF10);
	Mat ILPF_20_without_shift = hw5.Ideal_LPF(baboon_mat, 20.0, false, cvILPF20);
	Mat ILPF_40_without_shift = hw5.Ideal_LPF(baboon_mat, 40.0, false, cvILPF40);
	Mat ILPF_100_without_shift = hw5.Ideal_LPF(baboon_mat, 100.0, false, cvILPF100);

	Mat IHPF_10 = hw5.Ideal_HPF(baboon_mat, 10.0, true, cvIHPF10);
	Mat IHPF_20 = hw5.Ideal_HPF(baboon_mat, 20.0, true, cvIHPF20);
	Mat IHPF_40 = hw5.Ideal_HPF(baboon_mat, 40.0, true, cvIHPF40);
	Mat IHPF_100 = hw5.Ideal_HPF(baboon_mat, 100.0, true, cvIHPF100);
	Mat IHPF_10_without_shift = hw5.Ideal_HPF(baboon_mat, 10.0, false, cvIHPF10);
	Mat IHPF_20_without_shift = hw5.Ideal_HPF(baboon_mat, 20.0, false, cvIHPF20);
	Mat IHPF_40_without_shift = hw5.Ideal_HPF(baboon_mat, 40.0, false, cvIHPF40);
	Mat IHPF_100_without_shift = hw5.Ideal_HPF(baboon_mat, 100.0, false, cvIHPF100);

	imwrite("(2_3)IDFT_ILPF_10.png", ILPF_10 * 255);
	imwrite("(2_3)IDFT_ILPF_20.png", ILPF_20 * 255);
	imwrite("(2_3)IDFT_ILPF_40.png", ILPF_40 * 255);
	imwrite("(2_3)IDFT_ILPF_100.png", ILPF_100 * 255);
	imwrite("(2_3)IDFT_ILPF_10_noshift.png", ILPF_10_without_shift * 255);
	imwrite("(2_3)IDFT_ILPF_20_noshift.png", ILPF_20_without_shift * 255);
	imwrite("(2_3)IDFT_ILPF_40_noshift.png", ILPF_40_without_shift * 255);
	imwrite("(2_3)IDFT_ILPF_100_noshift.png", ILPF_100_without_shift * 255);
	imwrite("(2_3)IDFT_IHPF_10.png", IHPF_10 * 255);
	imwrite("(2_3)IDFT_IHPF_20.png", IHPF_20 * 255);
	imwrite("(2_3)IDFT_IHPF_40.png", IHPF_40 * 255);
	imwrite("(2_3)IDFT_IHPF_100.png", IHPF_100 * 255);
	imwrite("(2_3)IDFT_IHPF_10_noshift.png", IHPF_10_without_shift * 255);
	imwrite("(2_3)IDFT_IHPF_20_noshift.png", IHPF_20_without_shift * 255);
	imwrite("(2_3)IDFT_IHPF_40_noshift.png", IHPF_40_without_shift * 255);
	imwrite("(2_3)IDFT_IHPF_100_noshift.png", IHPF_100_without_shift * 255);
}
void hw::HW3()
{
	rw rw;
	hw5 hw5;
	double* real = new double[632 * 474];
	double* imagine = new double[632 * 474];
	double* s_real = new double[632 * 474];
	double* s_imagine = new double[632 * 474];
	double* o_real = new double[632 * 474];
	double* o_imagine = new double[632 * 474];
	char building[] = "building_474x632.raw";
	char building_dft[] = "building_dft_474x632.raw";
	char building_IDFT_y[] = "(3)building_474x632_IDFT_y.raw";
	char building_IDFT_x[] = "(3)building_474x632_IDFT_x.raw";
	char sobel_DFT_y[] = "(3)sobel_IDFT_y.raw";
	char sobel_DFT_x[] = "(3)sobel_IDFT_x.raw";
	float* Sobel_x = new float[9]{ 1, 0, -1, 2, 0, -2, 1, 0, -1 };
	float* Sobel_y = new float[9]{ 1, 2, 1, 0, 0, 0, -1, -2, -1 };
	unsigned char* building_mat = rw.read_Raw_data(building, 632, 474);

	unsigned char* building256_DFT = hw5.DFT(building_mat, 632, 474, real, imagine);
	unsigned char* Sobel_y_DFT = hw5.Sobel_DFT(Sobel_x, 3, 3, s_real, s_imagine);
	hw5.Sobel_DFT_mul(real, imagine, s_real, s_imagine, o_real, o_imagine, 632, 474);
	unsigned char* IDFT_y = hw5.IDFT(building256_DFT, 632, 474, o_real, o_imagine);

	unsigned char* Sobel_x_DFT = hw5.Sobel_DFT(Sobel_y, 3, 3, s_real, s_imagine);
	hw5.Sobel_DFT_mul(real, imagine, s_real, s_imagine, o_real, o_imagine, 632, 474);
	unsigned char* IDFT_x = hw5.IDFT(building256_DFT, 632, 474, o_real, o_imagine);
	
	rw.write_raw_data(building_dft, building256_DFT, 632, 474);
	rw.write_raw_data(sobel_DFT_y, Sobel_y_DFT, 632, 474);
	rw.write_raw_data(sobel_DFT_x, Sobel_x_DFT, 632, 474);
	rw.write_raw_data(building_IDFT_y, IDFT_y, 632, 474);
	rw.write_raw_data(building_IDFT_x, IDFT_x, 632, 474);
}