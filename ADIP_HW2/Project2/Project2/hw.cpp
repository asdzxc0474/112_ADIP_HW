#include <stdio.h>
#include <iostream>
#include"class.h"
#include"hw.h"

#define _CRT_SECURE_NO_WARNINGS

void hw::HW1_1()
{
	rw rw;
	hw2function hw2fc;
	char file[] = "lena256.raw";
	char file2[] = "lena512.raw";
	char output_img[] = "1_1lena512out.raw";
	unsigned char* img_lena = rw.read_Raw_data(file, 256, 256);
	unsigned char* img_lena512 = rw.read_Raw_data(file2, 512, 512);
	unsigned char* img_lena512out = hw2fc.RCzoom_in(img_lena, 256, 256, 2);
	printf("======================================\n(Row Column replication lena512)\n");
	float MSE = hw2fc.MSE(512, 512, img_lena512out, img_lena512);
	float PSNR = hw2fc.PSNR(MSE, 255);
	printf("======================================\n\n\n");
	rw.write_raw_data(output_img, img_lena512out, 512, 512);
}
void hw::HW1_2()
{
	rw rw;
	hw2function hw2fc;
	char file[] = "lena512.raw";
	char file2[] = "lena512blur.raw";
	char output_img[] = "1_2lena128out.raw";
	char output_img2[] = "1_2lena128out_b.raw";
	unsigned char* img_lena512 = rw.read_Raw_data(file, 512, 512);
	unsigned char* img_lena512_b = rw.read_Raw_data(file2, 512, 512);
	unsigned char* img_lena128out = hw2fc.RC_deletion(img_lena512, 512, 512, 4);
	unsigned char* img_lena128out_b = hw2fc.RC_deletion(img_lena512_b, 512, 512, 4);
	rw.write_raw_data(output_img, img_lena128out, 128, 128);
	rw.write_raw_data(output_img2, img_lena128out_b, 128, 128);
}
void hw::HW1_3()
{
	//initial
	rw rw;
	hw2function hw2fc;
	clock_t a, b;
	float MSE;
	float PSNR;
	char file[] = "lena128.raw";
	char file256[] = "lena256.raw";
	char file512[] = "lena512.raw";
	unsigned char* img_lena128 = rw.read_Raw_data(file, 128, 128);
	unsigned char* img_lena256 = rw.read_Raw_data(file256, 256, 256);
	unsigned char* img_lena512 = rw.read_Raw_data(file512, 512, 512);
	//initial

	//nearest neighbor
	char nn_output_img256[] = "1_3(nn)_lena256out.raw";
	char nn_output_img512[] = "1_3(nn)_lena512out.raw";
	a = clock();
	unsigned char* img_lena256out = hw2fc.Nneighbor(img_lena128, 128, 128, 2);
	b = clock();
	printf("======================================\nnearest neighborhood 2x");
	hw2fc.executiontime(a, b);
	MSE = hw2fc.MSE(256, 256, img_lena256out, img_lena256);
	PSNR = hw2fc.PSNR(MSE, 255);
	printf("======================================\n");
	a = clock();
	unsigned char* img_lena512out = hw2fc.Nneighbor(img_lena128, 128, 128, 4);
	b = clock();
	printf("======================================\nnearest neighborhood 4x");
	hw2fc.executiontime(a, b);
	MSE = hw2fc.MSE(512, 512, img_lena512out, img_lena512);
	PSNR = hw2fc.PSNR(MSE, 255);
	printf("======================================\n");
	rw.write_raw_data(nn_output_img256, img_lena256out, 256, 256);
	rw.write_raw_data(nn_output_img512, img_lena512out, 512, 512);
	//nearest neighbor

	//bilinear
	char bil_output_img256[] = "1_3(bilinear)_lena256out.raw";
	char bil_output_img512[] = "1_3(bilinear)_lena512out.raw";
	a = clock();
	unsigned char* bilinearimg_lena256out = hw2fc.Bilinear(img_lena128, 128, 128, 2);
	b = clock();
	printf("======================================\nbilinear 2x");
	hw2fc.executiontime(a, b);
	MSE = hw2fc.MSE(256, 256, bilinearimg_lena256out, img_lena256);
	PSNR = hw2fc.PSNR(MSE, 255);
	printf("======================================\n");
	a = clock();
	unsigned char* bilinearimg_lena512out = hw2fc.Bilinear(img_lena128, 128, 128, 4);
	b = clock();
	printf("======================================\nbilinear 4x");
	hw2fc.executiontime(a, b);
	MSE = hw2fc.MSE(512, 512, bilinearimg_lena512out, img_lena512);
	PSNR = hw2fc.PSNR(MSE, 255);
	printf("======================================\n");
	rw.write_raw_data(bil_output_img256, bilinearimg_lena256out, 256, 256);
	rw.write_raw_data(bil_output_img512, bilinearimg_lena512out, 512, 512);
	//bilinear

	//bicubic
	char bic_output_img256[] = "1_3(bicubic)_lena256out.raw";
	char bic_output_img512[] = "1_3(bicubic)_lena512out.raw";
	a = clock();
	unsigned char* bicubicimg_lena256out = hw2fc.Bicubic(img_lena128, 128, 128, 2);
	b = clock();
	printf("======================================\nbicubic 2x");
	hw2fc.executiontime(a, b);
	MSE = hw2fc.MSE(256, 256, bicubicimg_lena256out, img_lena256);
	PSNR = hw2fc.PSNR(MSE, 255);
	printf("======================================\n");
	a = clock();
	unsigned char* bicubicimg_lena512out = hw2fc.Bicubic(img_lena128, 128, 128, 4);
	b = clock();
	printf("======================================\nbicubic 4x");
	hw2fc.executiontime(a, b);
	MSE = hw2fc.MSE(512, 512, bicubicimg_lena512out, img_lena512);
	PSNR = hw2fc.PSNR(MSE, 255);
	printf("======================================\n");
	rw.write_raw_data(bic_output_img256, bicubicimg_lena256out, 256, 256);
	rw.write_raw_data(bic_output_img512, bicubicimg_lena512out, 512, 512);
	//bicubic
}
void hw::HW1_4() 
{
	rw rw;
	hw2function hw2fc;
	clock_t a, b;
	char fileblur[] = "lena512blur.raw";
	char nn_output_img384[] = "1_4(nn)_lena384out.raw";
	char bil_output_img384[] = "1_4(bilinear)_lena384out.raw";
	char bic_output_img384[] = "1_4(bicubic)_lena384out.raw";
	unsigned char* img_lena512_b = rw.read_Raw_data(fileblur, 512, 512);
	a = clock();
	unsigned char* nnimg_lena384out = hw2fc.Nneighbor(img_lena512_b, 512, 512, 0.75);
	b = clock();
	printf("======================================\nnearest neighborhood");
	hw2fc.executiontime(a, b);
	printf("======================================\n");
	a = clock();
	unsigned char* bilimg_lena384out = hw2fc.Bilinear(img_lena512_b, 512, 512, 0.75);
	b = clock();
	printf("======================================\nBilinear");
	hw2fc.executiontime(a, b);
	printf("======================================\n");
	a = clock();
	unsigned char* bicimg_lena384out = hw2fc.Bicubic(img_lena512_b, 512, 512, 0.75);
	b = clock();
	printf("======================================\nBicubic");
	hw2fc.executiontime(a, b);
	printf("======================================\n");
	rw.write_raw_data(nn_output_img384, nnimg_lena384out, 384, 384);
	rw.write_raw_data(bil_output_img384, bilimg_lena384out, 384, 384);
	rw.write_raw_data(bic_output_img384, bicimg_lena384out, 384, 384);
}
void hw::HW1_5()
{
	rw rw;
	hw2function hw2fc;
	clock_t a, b;
	char file[] = "lena256blur.raw";
	char file1_1[] = "1_5(nn_1)lena.raw";
	char file1_2[] = "1_5(nn_2)lena.raw";
	char file1_3[] = "1_5(nn_3)lena.raw";
	char file2_1[] = "1_5(bilinear_1)lena.raw";
	char file2_2[] = "1_5(bilinear_2)lena.raw";
	char file2_3[] = "1_5(bilinear_3)lena.raw";
	char file3_1[] = "1_5(bicubic_1)lena.raw";
	char file3_2[] = "1_5(bicubic_2)lena.raw";
	char file3_3[] = "1_5(bicubic_3)lena.raw";
	unsigned char* lena256 = rw.read_Raw_data(file, 256, 256);
	// nn1
	a = clock();
	unsigned char* lena1 = hw2fc.Nneighbor(lena256, 256, 256, 2.25);
	unsigned char* lena1_1 = hw2fc.Nneighbor(lena1, 576, 576, 0.66666f);
	b = clock();
	printf("======================================\nnearest neighborhood¡ô2.25¡õ1.5");
	hw2fc.executiontime(a, b);
	printf("======================================\n");
	rw.write_raw_data(file1_1, lena1_1, 384, 384);
	// nn1
	
	// nn2
	a = clock();
	unsigned char* lena1_2_1 = hw2fc.Nneighbor(lena256, 256, 256, 0.66666f);
	unsigned char* lena1_2_2 = hw2fc.Nneighbor(lena1_2_1, 171, 171, 2.25);
	b = clock();
	printf("======================================\nnearest neighborhood¡õ1.5¡ô2.25");
	hw2fc.executiontime(a, b);
	printf("======================================\n");
	rw.write_raw_data(file1_2, lena1_2_2, 385, 385);
	// nn2
	
	// nn3
	a = clock();
	unsigned char* lena1_2_3 = hw2fc.Nneighbor(lena256, 256, 256, 1.5);
	rw.write_raw_data(file1_3, lena1_2_3, 384, 384);
	b = clock();
	printf("======================================\nnearest neighborhood¡ô1.5");
	hw2fc.executiontime(a, b);
	printf("======================================\n");
	// nn3

	// bi1inear1
	a = clock();
	unsigned char* lena2 = hw2fc.Bilinear(lena256, 256, 256, 2.25);
	unsigned char* lena2_1 = hw2fc.Bilinear(lena2, 576, 576, 0.66666f);
	b = clock();
	printf("======================================\nBilinear¡ô2.25¡õ1.5");
	hw2fc.executiontime(a, b);
	printf("======================================\n");
	rw.write_raw_data(file2_1, lena2_1, 384, 384);
	// bi1inear1

	// bi1inear2
	unsigned char* lena2_2 = hw2fc.Bilinear(lena256, 256, 256, 0.66666f);
	unsigned char* lena2_22 = hw2fc.Bilinear(lena2_2, 171, 171, 2.25);
	b = clock();
	printf("======================================\nBilinear¡õ1.5¡ô2.25");
	hw2fc.executiontime(a, b);
	printf("======================================\n");
	rw.write_raw_data(file2_2, lena2_22, 385, 385);
	// bi1inear2

	// bi1inear3
	a = clock();
	unsigned char* lena2_3 = hw2fc.Bilinear(lena256, 256, 256, 1.5);
	b = clock();
	printf("======================================\nBilinear¡ô1.5");
	hw2fc.executiontime(a, b);
	printf("======================================\n");
	rw.write_raw_data(file2_3, lena2_3, 384, 384);
	// bi1inear3
	
	//bicubic1
	a = clock();
	unsigned char* lena3 = hw2fc.Bicubic(lena256, 256, 256, 2.25);
	unsigned char* lena3_1 = hw2fc.Bicubic(lena2, 576, 576, 0.66666f);
	b = clock();
	printf("======================================\nBicubic¡ô2.25¡õ1.5");
	hw2fc.executiontime(a, b);
	printf("======================================\n");
	rw.write_raw_data(file3_1, lena3_1, 384, 384);
	//bicubic1

	//bicubic2
	unsigned char* lena3_2 = hw2fc.Bicubic(lena256, 256, 256, 0.66666f);
	unsigned char* lena3_22 = hw2fc.Bicubic(lena2_2, 171, 171, 2.25);
	b = clock();
	printf("======================================\nBicubic¡õ1.5¡ô2.25");
	hw2fc.executiontime(a, b);
	printf("======================================\n");
	rw.write_raw_data(file3_2, lena3_22, 385, 385);
	//bicubic2

	//bicubic3
	a = clock();
	unsigned char* lena3_3 = hw2fc.Bicubic(lena256, 256, 256, 1.5);
	b = clock();
	printf("======================================\nBicubic¡ô1.5");
	hw2fc.executiontime(a, b);
	printf("======================================\n");
	rw.write_raw_data(file3_3, lena3_3, 384, 384);
	//bicubic2
}
void hw::HW2_1()
{
	rw rw;
	hw2function hw2fc;
	int arr[] = {72};
	char file[] = "map10x10.raw";
	char pathfile[] = "map_path(1_D4).raw";
	char pathfile2[] = "map_path(1_D8).raw";
	char pathfile3[] = "map_path(1_Dm).raw";
	unsigned char* img_lena = rw.read_Raw_data(file, 10, 10);
	printf("======================================\nV = {72}\n");
	unsigned char* path = hw2fc.HW2_1Path_img(img_lena, 10, 10, arr);
	unsigned char* D4path_1 = hw2fc.D4Path(path, 10, 10);
	path = hw2fc.HW2_1Path_img(img_lena, 10, 10, arr);
	unsigned char* D8path_1 = hw2fc.D8Path(path, 10, 10);
	path = hw2fc.HW2_1Path_img(img_lena, 10, 10, arr);
	unsigned char* Dmpath_1 = hw2fc.DmPath(path, 10, 10);
	printf("======================================\n\n\n");
	rw.write_raw_data(pathfile, D4path_1, 10, 10);
	rw.write_raw_data(pathfile2, D8path_1, 10, 10);
	rw.write_raw_data(pathfile3, Dmpath_1, 10, 10);
}
void hw::HW2_2()
{
	rw rw;
	hw2function hw2fc;
	int arr[] = { 72, 145 };
	char file[] = "map10x10.raw";
	char pathfile[] = "map_path(2_D4).raw";
	char pathfile2[] = "map_path(2_D8).raw";
	char pathfile3[] = "map_path(2_Dm).raw";
	unsigned char* img_lena = rw.read_Raw_data(file, 10, 10);
	printf("======================================\nV = {72, 145}\n");
	unsigned char* path = hw2fc.HW2_2Path_img(img_lena, 10, 10, arr);
	unsigned char* D4path_2 = hw2fc.D4Path(path, 10, 10);
	path = hw2fc.HW2_2Path_img(img_lena, 10, 10, arr);
	unsigned char* D8path_2 = hw2fc.D8Path(path, 10, 10);
	path = hw2fc.HW2_2Path_img(img_lena, 10, 10, arr);
	unsigned char* Dmpath_2 = hw2fc.DmPath(path, 10, 10);
	printf("======================================\n\n\n");
	rw.write_raw_data(pathfile, D4path_2, 10, 10);
	rw.write_raw_data(pathfile2, D8path_2, 10, 10);
	rw.write_raw_data(pathfile3, Dmpath_2, 10, 10);
}
void hw::HW2_3()
{
	rw rw;
	hw2function hw2fc;
	int arr[] = { 72, 145, 218 };
	char file[] = "map10x10.raw";
	char pathfile[] = "map_path(3_D4).raw";
	char pathfile2[] = "map_path(3_D8).raw";
	char pathfile3[] = "map_path(3_Dm).raw";
	unsigned char* img_lena = rw.read_Raw_data(file, 10, 10);
	printf("======================================\nV = {72, 145, 218}\n");
	unsigned char* path = hw2fc.HW2_3Path_img(img_lena, 10, 10, arr);
	unsigned char* D4path_3 = hw2fc.D4Path(path, 10, 10);
	path = hw2fc.HW2_2Path_img(img_lena, 10, 10, arr);
	unsigned char* D8path_3 = hw2fc.D8Path(path, 10, 10);
	path = hw2fc.HW2_2Path_img(img_lena, 10, 10, arr);
	unsigned char* Dmpath_3 = hw2fc.DmPath(path, 10, 10);
	printf("======================================\n\n\n");
	rw.write_raw_data(pathfile, D4path_3, 10, 10);
	rw.write_raw_data(pathfile2, D8path_3, 10, 10);
	rw.write_raw_data(pathfile3, Dmpath_3, 10, 10);
}
void hw::HW3()
{
	rw rw;
	hw2function hw2fc;
	float mse;
	float psnr;
	char lenafile[] = "lena256.raw";
	char baboonfile[] = "baboon256.raw";
	unsigned char* img_lena256 = rw.read_Raw_data(lenafile, 256, 256);
	unsigned char* baboon256 = rw.read_Raw_data(baboonfile, 256, 256);

	char lena256_7bit[] = "7bitlena256.raw";
	char baboon_7bit[] = "7bitbaboon256.raw";
	unsigned char* img_lena256_7 = hw2fc.quantize(img_lena256, 256, 256, 7);
	unsigned char* baboon_7 = hw2fc.quantize(baboon256, 256, 256, 7);
	rw.write_raw_data(lena256_7bit, img_lena256_7, 256, 256);
	rw.write_raw_data(baboon_7bit, baboon_7, 256, 256);
	printf("======================================\n7bit lena256 vs lena256\n");
	mse = hw2fc.MSE(256, 256, img_lena256_7, img_lena256);
	psnr = hw2fc.PSNR(mse, 255);
	printf("======================================\n7bit baboon256 vs baboon256\n");
	mse = hw2fc.MSE(256, 256, baboon_7, baboon256);
	psnr = hw2fc.PSNR(mse, 255);

	char lena256_6bit[] = "6bitlena256.raw";
	char baboon_6bit[] = "6bitbaboon256.raw";
	unsigned char* img_lena256_6 = hw2fc.quantize(img_lena256, 256, 256, 6);
	unsigned char* baboon_6 = hw2fc.quantize(baboon256, 256, 256, 6);
	rw.write_raw_data(lena256_6bit, img_lena256_6, 256, 256);
	rw.write_raw_data(baboon_6bit, baboon_6, 256, 256);
	printf("======================================\n6bit lena256 vs lena256\n");
	mse = hw2fc.MSE(256, 256, img_lena256_6, img_lena256);
	psnr = hw2fc.PSNR(mse, 255);
	printf("======================================\n6bit baboon256 vs baboon256\n");
	mse = hw2fc.MSE(256, 256, baboon_6, baboon256);
	psnr = hw2fc.PSNR(mse, 255);

	char lena256_5bit[] = "5bitlena256.raw";
	char baboon_5bit[] = "5bitbaboon256.raw";
	unsigned char* img_lena256_5 = hw2fc.quantize(img_lena256, 256, 256, 5);
	unsigned char* baboon_5 = hw2fc.quantize(baboon256, 256, 256, 5);
	rw.write_raw_data(lena256_5bit, img_lena256_5, 256, 256);
	rw.write_raw_data(baboon_5bit, baboon_5, 256, 256);
	printf("======================================\n5bit lena256 vs lena256\n");
	mse = hw2fc.MSE(256, 256, img_lena256_5, img_lena256);
	psnr = hw2fc.PSNR(mse, 255);
	printf("======================================\n5bit baboon256 vs baboon256\n");
	mse = hw2fc.MSE(256, 256, baboon_5, baboon256);
	psnr = hw2fc.PSNR(mse, 255);

	char lena256_4bit[] = "4bitlena256.raw";
	char baboon_4bit[] = "4bitbaboon256.raw";
	unsigned char* img_lena256_4 = hw2fc.quantize(img_lena256, 256, 256, 4);
	unsigned char* baboon_4 = hw2fc.quantize(baboon256, 256, 256, 4);
	rw.write_raw_data(lena256_4bit, img_lena256_4, 256, 256);
	rw.write_raw_data(baboon_4bit, baboon_4, 256, 256);
	printf("======================================\n4bit lena256 vs lena256\n");
	mse = hw2fc.MSE(256, 256, img_lena256_4, img_lena256);
	psnr = hw2fc.PSNR(mse, 255);
	printf("======================================\n4bit baboon256 vs baboon256\n");
	mse = hw2fc.MSE(256, 256, baboon_4, baboon256);
	psnr = hw2fc.PSNR(mse, 255);

	char lena256_3bit[] = "3bitlena256.raw";
	char baboon_3bit[] = "3bitbaboon256.raw";
	unsigned char* img_lena256_3 = hw2fc.quantize(img_lena256, 256, 256, 3);
	unsigned char* baboon_3 = hw2fc.quantize(baboon256, 256, 256, 3);
	rw.write_raw_data(lena256_3bit, img_lena256_3, 256, 256);
	rw.write_raw_data(baboon_3bit, baboon_3, 256, 256);
	printf("======================================\n3bit lena256 vs lena256\n");
	mse = hw2fc.MSE(256, 256, img_lena256_3, img_lena256);
	psnr = hw2fc.PSNR(mse, 255);
	printf("======================================\n3bit baboon256 vs baboon256\n");
	mse = hw2fc.MSE(256, 256, baboon_3, baboon256);
	psnr = hw2fc.PSNR(mse, 255);

	char lena256_2bit[] = "2bitlena256.raw";
	char baboon_2bit[] = "2bitbaboon256.raw";
	unsigned char* img_lena256_2 = hw2fc.quantize(img_lena256, 256, 256, 2);
	unsigned char* baboon_2 = hw2fc.quantize(baboon256, 256, 256, 2);
	rw.write_raw_data(lena256_2bit, img_lena256_2, 256, 256);
	rw.write_raw_data(baboon_2bit, baboon_2, 256, 256);
	printf("======================================\n2bit lena256 vs lena256\n");
	mse = hw2fc.MSE(256, 256, img_lena256_2, img_lena256);
	psnr = hw2fc.PSNR(mse, 255);
	printf("======================================\n2bit baboon256 vs baboon256\n");
	mse = hw2fc.MSE(256, 256, baboon_2, baboon256);
	psnr = hw2fc.PSNR(mse, 255);

	char lena256_1bit[] = "1bitlena256.raw";
	char baboon_1bit[] = "1bitbaboon256.raw";
	unsigned char* img_lena256_1 = hw2fc.quantize(img_lena256, 256, 256, 1);
	unsigned char* baboon_1 = hw2fc.quantize(baboon256, 256, 256, 1);
	rw.write_raw_data(lena256_1bit, img_lena256_1, 256, 256);
	rw.write_raw_data(baboon_1bit, baboon_1, 256, 256);
	printf("======================================\n1bit lena256 vs lena256\n");
	mse = hw2fc.MSE(256, 256, img_lena256_1, img_lena256);
	psnr = hw2fc.PSNR(mse, 255);
	printf("======================================\n1bit baboon256 vs baboon256\n");
	mse = hw2fc.MSE(256, 256, baboon_1, baboon256);
	psnr = hw2fc.PSNR(mse, 255);
	printf("======================================\n\n\n");
}
void hw::HW4() 
{
	rw rw;
	hw2function hw2fc;
	char file[] = "lena1024.raw";
	char fileout[] = "lena1024_halftone.raw";
	unsigned char* img_lena1024 = rw.read_Raw_data(file, 1024, 1024);
	unsigned char* img_hw4 = hw2fc.HW4average(img_lena1024, 1024, 1024, 16);
	unsigned char* img = hw2fc.HW4draw(img_hw4);
	rw.write_raw_data(fileout, img, 1024, 1024);
}