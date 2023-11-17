#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "class.h"
#include "hw.h"
using namespace std;

void hw::HW1_1() 
{
	rw rw;
	hw4 hw4;
	char file1[] = "shape100_1.raw";
	char file2[] = "shape100_2.raw";
	char file3[] = "shape100_3.raw";
	char file4[] = "shape100_4.raw";
	char file5[] = "shape100_5.raw";
	char file6[] = "shape100_6.raw";
	char file7[] = "shape100_7.raw";
	char file8[] = "shape100_8.raw";
	unsigned char* shape1 = rw.read_Raw_data(file1, 100, 100);
	unsigned char* shape2 = rw.read_Raw_data(file2, 100, 100);
	unsigned char* shape3 = rw.read_Raw_data(file3, 100, 100);
	unsigned char* shape4 = rw.read_Raw_data(file4, 100, 100);
	unsigned char* shape5 = rw.read_Raw_data(file5, 100, 100);
	unsigned char* shape6 = rw.read_Raw_data(file6, 100, 100);
	unsigned char* shape7 = rw.read_Raw_data(file7, 100, 100);
	unsigned char* shape8 = rw.read_Raw_data(file8, 100, 100);
	double* shape1_centroid = hw4.centroid(shape1, 100, 100, file1);
	double* shape2_centroid = hw4.centroid(shape2, 100, 100, file2);
	double* shape3_centroid = hw4.centroid(shape3, 100, 100, file3);
	double* shape4_centroid = hw4.centroid(shape4, 100, 100, file4);
	double* shape5_centroid = hw4.centroid(shape5, 100, 100, file5);
	double* shape6_centroid = hw4.centroid(shape6, 100, 100, file6);
	double* shape7_centroid = hw4.centroid(shape7, 100, 100, file7);
	double* shape8_centroid = hw4.centroid(shape8, 100, 100, file8);
	delete[] shape1, shape2, shape3, shape4, shape5, shape6, shape7, shape8;
	delete[] shape1_centroid, shape2_centroid, shape3_centroid, shape4_centroid, shape5_centroid, shape6_centroid, shape7_centroid, shape8_centroid;
}
void hw::HW1_2() 
{
	rw rw;
	hw4 hw4;
	char file1[] = "shape100_1.raw";
	char file2[] = "shape100_2.raw";
	char file3[] = "shape100_3.raw";
	char file4[] = "shape100_4.raw";
	char file5[] = "shape100_5.raw";
	char file6[] = "shape100_6.raw";
	char file7[] = "shape100_7.raw";
	char file8[] = "shape100_8.raw";
	unsigned char* shape1 = rw.read_Raw_data(file1, 100, 100);
	unsigned char* shape2 = rw.read_Raw_data(file2, 100, 100);
	unsigned char* shape3 = rw.read_Raw_data(file3, 100, 100);
	unsigned char* shape4 = rw.read_Raw_data(file4, 100, 100);
	unsigned char* shape5 = rw.read_Raw_data(file5, 100, 100);
	unsigned char* shape6 = rw.read_Raw_data(file6, 100, 100);
	unsigned char* shape7 = rw.read_Raw_data(file7, 100, 100);
	unsigned char* shape8 = rw.read_Raw_data(file8, 100, 100);
	double* shape1_centroid = hw4.centroid(shape1, 100, 100, file1);
	double* shape2_centroid = hw4.centroid(shape2, 100, 100, file2);
	double* shape3_centroid = hw4.centroid(shape3, 100, 100, file3);
	double* shape4_centroid = hw4.centroid(shape4, 100, 100, file4);
	double* shape5_centroid = hw4.centroid(shape5, 100, 100, file5);
	double* shape6_centroid = hw4.centroid(shape6, 100, 100, file6);
	double* shape7_centroid = hw4.centroid(shape7, 100, 100, file7);
	double* shape8_centroid = hw4.centroid(shape8, 100, 100, file8);

	double shape1_central_moment01 = hw4.central_moment(shape1, 100, 100, shape1_centroid, 0, 1, file1);
	double shape1_central_moment10 = hw4.central_moment(shape1, 100, 100, shape1_centroid, 1, 0, file1);
	double shape1_central_moment11 = hw4.central_moment(shape1, 100, 100, shape1_centroid, 1, 1, file1);
	double shape1_central_moment02 = hw4.central_moment(shape1, 100, 100, shape1_centroid, 0, 2, file1);
	double shape1_central_moment20 = hw4.central_moment(shape1, 100, 100, shape1_centroid, 2, 0, file1);
	double shape1_central_moment12 = hw4.central_moment(shape1, 100, 100, shape1_centroid, 1, 2, file1);
	double shape1_central_moment21 = hw4.central_moment(shape1, 100, 100, shape1_centroid, 2, 1, file1);
	double shape1_central_moment30 = hw4.central_moment(shape1, 100, 100, shape1_centroid, 3, 0, file1);
	double shape1_central_moment03 = hw4.central_moment(shape1, 100, 100, shape1_centroid, 0, 3, file1);

	double shape2_central_moment01 = hw4.central_moment(shape2, 100, 100, shape2_centroid, 0, 1, file2);
	double shape2_central_moment10 = hw4.central_moment(shape2, 100, 100, shape2_centroid, 1, 0, file2);
	double shape2_central_moment11 = hw4.central_moment(shape2, 100, 100, shape2_centroid, 1, 1, file2);
	double shape2_central_moment02 = hw4.central_moment(shape2, 100, 100, shape2_centroid, 0, 2, file2);
	double shape2_central_moment20 = hw4.central_moment(shape2, 100, 100, shape2_centroid, 2, 0, file2);
	double shape2_central_moment12 = hw4.central_moment(shape2, 100, 100, shape2_centroid, 1, 2, file2);
	double shape2_central_moment21 = hw4.central_moment(shape2, 100, 100, shape2_centroid, 2, 1, file2);
	double shape2_central_moment30 = hw4.central_moment(shape2, 100, 100, shape2_centroid, 3, 0, file2);
	double shape2_central_moment03 = hw4.central_moment(shape2, 100, 100, shape2_centroid, 0, 3, file2);

	double shape3_central_moment01 = hw4.central_moment(shape3, 100, 100, shape3_centroid, 0, 1, file3);
	double shape3_central_moment10 = hw4.central_moment(shape3, 100, 100, shape3_centroid, 1, 0, file3);
	double shape3_central_moment11 = hw4.central_moment(shape3, 100, 100, shape3_centroid, 1, 1, file3);
	double shape3_central_moment02 = hw4.central_moment(shape3, 100, 100, shape3_centroid, 0, 2, file3);
	double shape3_central_moment20 = hw4.central_moment(shape3, 100, 100, shape3_centroid, 2, 0, file3);
	double shape3_central_moment12 = hw4.central_moment(shape3, 100, 100, shape3_centroid, 1, 2, file3);
	double shape3_central_moment21 = hw4.central_moment(shape3, 100, 100, shape3_centroid, 2, 1, file3);
	double shape3_central_moment30 = hw4.central_moment(shape3, 100, 100, shape3_centroid, 3, 0, file3);
	double shape3_central_moment31 = hw4.central_moment(shape3, 100, 100, shape3_centroid, 0, 3, file3);

	double shape4_central_moment01 = hw4.central_moment(shape4, 100, 100, shape4_centroid, 0, 1, file4);
	double shape4_central_moment10 = hw4.central_moment(shape4, 100, 100, shape4_centroid, 1, 0, file4);
	double shape4_central_moment11 = hw4.central_moment(shape4, 100, 100, shape4_centroid, 1, 1, file4);
	double shape4_central_moment02 = hw4.central_moment(shape4, 100, 100, shape4_centroid, 0, 2, file4);
	double shape4_central_moment20 = hw4.central_moment(shape4, 100, 100, shape4_centroid, 2, 0, file4);
	double shape4_central_moment12 = hw4.central_moment(shape4, 100, 100, shape4_centroid, 1, 2, file4);
	double shape4_central_moment21 = hw4.central_moment(shape4, 100, 100, shape4_centroid, 2, 1, file4);
	double shape4_central_moment30 = hw4.central_moment(shape4, 100, 100, shape4_centroid, 3, 0, file4);
	double shape4_central_moment31 = hw4.central_moment(shape4, 100, 100, shape4_centroid, 0, 3, file4);

	double shape5_central_moment01 = hw4.central_moment(shape5, 100, 100, shape5_centroid, 0, 1, file5);
	double shape5_central_moment10 = hw4.central_moment(shape5, 100, 100, shape5_centroid, 1, 0, file5);
	double shape5_central_moment11 = hw4.central_moment(shape5, 100, 100, shape5_centroid, 1, 1, file5);
	double shape5_central_moment02 = hw4.central_moment(shape5, 100, 100, shape5_centroid, 0, 2, file5);
	double shape5_central_moment20 = hw4.central_moment(shape5, 100, 100, shape5_centroid, 2, 0, file5);
	double shape5_central_moment12 = hw4.central_moment(shape5, 100, 100, shape5_centroid, 1, 2, file5);
	double shape5_central_moment21 = hw4.central_moment(shape5, 100, 100, shape5_centroid, 2, 1, file5);
	double shape5_central_moment30 = hw4.central_moment(shape5, 100, 100, shape5_centroid, 3, 0, file5);
	double shape5_central_moment31 = hw4.central_moment(shape5, 100, 100, shape5_centroid, 0, 3, file5);

	double shape6_central_moment01 = hw4.central_moment(shape6, 100, 100, shape6_centroid, 0, 1, file6);
	double shape6_central_moment10 = hw4.central_moment(shape6, 100, 100, shape6_centroid, 1, 0, file6);
	double shape6_central_moment11 = hw4.central_moment(shape6, 100, 100, shape6_centroid, 1, 1, file6);
	double shape6_central_moment02 = hw4.central_moment(shape6, 100, 100, shape6_centroid, 0, 2, file6);
	double shape6_central_moment20 = hw4.central_moment(shape6, 100, 100, shape6_centroid, 2, 0, file6);
	double shape6_central_moment12 = hw4.central_moment(shape6, 100, 100, shape6_centroid, 1, 2, file6);
	double shape6_central_moment21 = hw4.central_moment(shape6, 100, 100, shape6_centroid, 2, 1, file6);
	double shape6_central_moment30 = hw4.central_moment(shape6, 100, 100, shape6_centroid, 3, 0, file6);
	double shape6_central_moment31 = hw4.central_moment(shape6, 100, 100, shape6_centroid, 0, 3, file6);

	double shape7_central_moment01 = hw4.central_moment(shape7, 100, 100, shape7_centroid, 0, 1, file7);
	double shape7_central_moment10 = hw4.central_moment(shape7, 100, 100, shape7_centroid, 1, 0, file7);
	double shape7_central_moment11 = hw4.central_moment(shape7, 100, 100, shape7_centroid, 1, 1, file7);
	double shape7_central_moment02 = hw4.central_moment(shape7, 100, 100, shape7_centroid, 0, 2, file7);
	double shape7_central_moment20 = hw4.central_moment(shape7, 100, 100, shape7_centroid, 2, 0, file7);
	double shape7_central_moment12 = hw4.central_moment(shape7, 100, 100, shape7_centroid, 1, 2, file7);
	double shape7_central_moment21 = hw4.central_moment(shape7, 100, 100, shape7_centroid, 2, 1, file7);
	double shape7_central_moment30 = hw4.central_moment(shape7, 100, 100, shape7_centroid, 3, 0, file7);
	double shape7_central_moment31 = hw4.central_moment(shape7, 100, 100, shape7_centroid, 0, 3, file7);

	double shape8_central_moment01 = hw4.central_moment(shape8, 100, 100, shape8_centroid, 0, 1, file8);
	double shape8_central_moment10 = hw4.central_moment(shape8, 100, 100, shape8_centroid, 1, 0, file8);
	double shape8_central_moment11 = hw4.central_moment(shape8, 100, 100, shape8_centroid, 1, 1, file8);
	double shape8_central_moment02 = hw4.central_moment(shape8, 100, 100, shape8_centroid, 0, 2, file8);
	double shape8_central_moment20 = hw4.central_moment(shape8, 100, 100, shape8_centroid, 2, 0, file8);
	double shape8_central_moment12 = hw4.central_moment(shape8, 100, 100, shape8_centroid, 1, 2, file8);
	double shape8_central_moment21 = hw4.central_moment(shape8, 100, 100, shape8_centroid, 2, 1, file8);
	double shape8_central_moment30 = hw4.central_moment(shape8, 100, 100, shape8_centroid, 3, 0, file8);
	double shape8_central_moment31 = hw4.central_moment(shape8, 100, 100, shape8_centroid, 0, 3, file8);

	delete[] shape1, shape2, shape3, shape4, shape5, shape6, shape7, shape8;
	delete[] shape1_centroid, shape2_centroid, shape3_centroid, shape4_centroid, shape5_centroid, shape6_centroid, shape7_centroid, shape8_centroid;
}
void hw::HW2_1() 
{
	rw rw;
	hw4 hw4;
	const char* Gaussian_filter = "Gaussian_filter";
	const char* Boxed_filter = "Box_filter";

	char file1[] = "slate_700x421.raw";
	char file2[] = "slate_noise_700x421.raw";

	char Boxed3x3_outfile[] = "2_1slate_Boxed3x3.raw";
	char Boxed5x5_outfile[] = "2_1slate_Boxed5x5.raw";
	char Boxed3x3_outfile2[] = "2_1slate_noise_Boxed3x3.raw";
	char Boxed5x5_outfile2[] = "2_1slate_noise_Boxed5x5.raw";
	char Gaussian3x3_outfile[] = "2_1slate_Gaussian3x3.raw";
	char Gaussian5x5_outfile[] = "2_1slate_Gaussian5x5.raw";
	char Gaussian3x3_outfile2[] = "2_1slate_noise_Gaussian3x3.raw";
	char Gaussian5x5_outfile2[] = "2_1slate_noise_Gaussian5x5.raw";

	unsigned char* slate = rw.read_Raw_data(file1, 421, 700);
	unsigned char* slate_noise = rw.read_Raw_data(file2, 421, 700);

	unsigned char* Boxed3x3 = hw4.filter3x3_move(slate, 421, 700, Boxed_filter);
	unsigned char* Gaussian3x3 = hw4.filter3x3_move(slate, 421, 700, Gaussian_filter);
	unsigned char* Boxed3x3_noise = hw4.filter3x3_move(slate_noise, 421, 700, Boxed_filter);
	unsigned char* Gaussian3x3_noise = hw4.filter3x3_move(slate_noise, 421, 700, Gaussian_filter);
	unsigned char* Boxed5x5 = hw4.filter5x5_move(slate, 421, 700, Boxed_filter);
	unsigned char* Gaussian5x5 = hw4.filter5x5_move(slate, 421, 700, Gaussian_filter);
	unsigned char* Boxed5x5_noise = hw4.filter5x5_move(slate_noise, 421, 700, Boxed_filter);
	unsigned char* Gaussian5x5_noise = hw4.filter5x5_move(slate_noise, 421, 700, Gaussian_filter);

	rw.write_raw_data(Boxed3x3_outfile, Boxed3x3, 421, 700);
	rw.write_raw_data(Boxed3x3_outfile2, Boxed3x3_noise, 421, 700);
	rw.write_raw_data(Gaussian3x3_outfile, Gaussian3x3, 421, 700);
	rw.write_raw_data(Gaussian3x3_outfile2, Gaussian3x3_noise, 421, 700);
	rw.write_raw_data(Boxed5x5_outfile, Boxed5x5, 421, 700);
	rw.write_raw_data(Boxed5x5_outfile2, Boxed5x5_noise, 421, 700);
	rw.write_raw_data(Gaussian5x5_outfile, Gaussian5x5, 421, 700);
	rw.write_raw_data(Gaussian5x5_outfile2, Gaussian5x5_noise, 421, 700);
}
void hw::HW2_2() 
{
	rw rw;
	hw4 hw4;
	char file1[] = "slate_700x421.raw";
	char file2[] = "slate_noise_700x421.raw";
	char robert_filter_45_outfile[] = "2_2slate_robert_45.raw";
	char robert_filter_315_outfile[] = "2_2slate_robert_315.raw";
	char robert_noise_filter_45_outfile[] = "2_2slate_noise_robert_45.raw";
	char robert_noise_filter_315_outfile[] = "2_2slate_noise_robert_315.raw";
	char img_combine_outfile[] = "2_2combine_filter.raw";
	char noise_img_combine_outfile[] = "2_2combine_filter_noise.raw";

	unsigned char* slate = rw.read_Raw_data(file1, 421, 700);
	unsigned char* slate_noise = rw.read_Raw_data(file2, 421, 700);

	unsigned char* slate_robert_1 = hw4.robert_filter_1(slate, 421, 700);
	unsigned char* slate_noise_robert_1 = hw4.robert_filter_1(slate_noise, 421, 700);
	unsigned char* slate_robert_2 = hw4.robert_filter_2(slate, 421, 700);
	unsigned char* slate_noise_robert_2 = hw4.robert_filter_2(slate_noise, 421, 700);
	unsigned char* slate_combine = hw4.img_combine(slate_robert_1, slate_robert_2, 421, 700);
	unsigned char* slate_noise_combine = hw4.img_combine(slate_noise_robert_1, slate_noise_robert_2, 421, 700);


	rw.write_raw_data(robert_filter_45_outfile, slate_robert_1, 421, 700);
	rw.write_raw_data(robert_noise_filter_45_outfile, slate_noise_robert_1, 421, 700);
	rw.write_raw_data(robert_filter_315_outfile, slate_robert_2, 421, 700);
	rw.write_raw_data(robert_noise_filter_315_outfile, slate_noise_robert_2, 421, 700);
	rw.write_raw_data(img_combine_outfile, slate_combine, 421, 700);
	rw.write_raw_data(noise_img_combine_outfile, slate_noise_combine, 421, 700);
}
void hw::HW2_3()
{
	rw rw;
	hw4 hw4;
	char file1[] = "slate_700x421.raw";
	char file2[] = "slate_noise_700x421.raw";
	const char* Perwitt_filter = "Perwitt_filter";
	const char* Perwitt_filter2 = "Perwitt_filter90";
	char Perwitt_filter_outfile[] = "2_3slate_Perwitt_0.raw";
	char Perwitt_filter_180_outfile[] = "2_3slate_Perwitt_180.raw";
	char Perwitt_filter_noise_outfile[] = "2_3slate_noise_Perwitt_0.raw";
	char Perwitt_filter_180_noise_outfile[] = "2_3slate_noise_Perwitt_180.raw";
	char img_combine_outfile[] = "2_3combine_filter.raw";
	char noise_img_combine_outfile[] = "2_3combine_filter_noise.raw";

	unsigned char* slate = rw.read_Raw_data(file1, 421, 700);
	unsigned char* slate_noise = rw.read_Raw_data(file2, 421, 700);

	unsigned char* Perwitt_filter_slate = hw4.filter3x3_move(slate, 421, 700, Perwitt_filter);
	unsigned char* Perwitt_filter_slate90 = hw4.filter3x3_move(slate, 421, 700, Perwitt_filter2);
	unsigned char* Perwitt_filter_slate_noise = hw4.filter3x3_move(slate_noise, 421, 700, Perwitt_filter);
	unsigned char* Perwitt_filter_slate_noise90 = hw4.filter3x3_move(slate_noise, 421, 700, Perwitt_filter2);
	unsigned char* slate_combine = hw4.img_combine(Perwitt_filter_slate, Perwitt_filter_slate90, 421, 700);
	unsigned char* slate_noise_combine = hw4.img_combine(Perwitt_filter_slate_noise, Perwitt_filter_slate_noise90, 421, 700);

	rw.write_raw_data(Perwitt_filter_outfile, Perwitt_filter_slate, 421, 700);
	rw.write_raw_data(Perwitt_filter_180_outfile, Perwitt_filter_slate90, 421, 700);
	rw.write_raw_data(Perwitt_filter_noise_outfile, Perwitt_filter_slate_noise, 421, 700);
	rw.write_raw_data(Perwitt_filter_180_noise_outfile, Perwitt_filter_slate_noise90, 421, 700);
	rw.write_raw_data(img_combine_outfile, slate_combine, 421, 700);
	rw.write_raw_data(noise_img_combine_outfile, slate_noise_combine, 421, 700);
}
void hw::HW2_4()
{
	rw rw;
	hw4 hw4;
	char file1[] = "slate_700x421.raw";
	char file2[] = "slate_noise_700x421.raw";
	const char* Sobel_filter = "Sobel_filter";
	const char* Sobel_filter2 = "Sobel_filter90";

	char Sobel_filter_outfile[] = "2_4slate_Sobel_0.raw";
	char Sobel_filter_180_outfile[] = "2_4slate_Sobel_180.raw";
	char Sobel_filter_noise_outfile[] = "2_4slate_noise_Sobel_0.raw";
	char Sobel_filter_180_noise_outfile[] = "2_4slate_noise_Sobel_180.raw";
	char img_combine_outfile[] = "2_4combine_filter.raw";
	char noise_img_combine_outfile[] = "2_4combine_filter_noise.raw";

	unsigned char* slate = rw.read_Raw_data(file1, 421, 700);
	unsigned char* slate_noise = rw.read_Raw_data(file2, 421, 700);

	unsigned char* Sobel_filter_slate = hw4.filter3x3_move(slate, 421, 700, Sobel_filter);
	unsigned char* Sobel_filter_slate90 = hw4.filter3x3_move(slate, 421, 700, Sobel_filter2);
	unsigned char* Sobel_filter_slate_noise = hw4.filter3x3_move(slate_noise, 421, 700, Sobel_filter);
	unsigned char* Sobel_filter_slate_noise90 = hw4.filter3x3_move(slate_noise, 421, 700, Sobel_filter2);
	unsigned char* slate_combine = hw4.img_combine(Sobel_filter_slate, Sobel_filter_slate90, 421, 700);
	unsigned char* slate_noise_combine = hw4.img_combine(Sobel_filter_slate_noise, Sobel_filter_slate_noise90, 421, 700);

	rw.write_raw_data(Sobel_filter_outfile, Sobel_filter_slate, 421, 700);
	rw.write_raw_data(Sobel_filter_180_outfile, Sobel_filter_slate90, 421, 700);
	rw.write_raw_data(Sobel_filter_noise_outfile, Sobel_filter_slate_noise, 421, 700);
	rw.write_raw_data(Sobel_filter_180_noise_outfile, Sobel_filter_slate_noise90, 421, 700);
	rw.write_raw_data(img_combine_outfile, slate_combine, 421, 700);
	rw.write_raw_data(noise_img_combine_outfile, slate_noise_combine, 421, 700);
}
void hw::HW2_5()
{
	rw rw;
	hw4 hw4;
	char file1[] = "slate_700x421.raw";
	char file2[] = "slate_noise_700x421.raw";
	const char* Sobel_filter45 = "Sobel_filter45";
	const char* Sobel_filter45_2 = "Sobel_filter_45";

	char Sobel_filter45_outfile[] = "2_5slate_Sobel_45.raw";
	char Sobel_filter45_2_outfile[] = "2_5slate_Sobel_45_2.raw";
	char Sobel_filter45_noise_outfile[] = "2_5slate_noise_Sobel_45.raw";
	char Sobel_filter45_2_noise_outfile[] = "2_5slate_noise_Sobel_45_2.raw";
	char img_combine_outfile[] = "2_5combine_filter.raw";
	char noise_img_combine_outfile[] = "2_5combine_filter_noise.raw";

	unsigned char* slate = rw.read_Raw_data(file1, 421, 700);
	unsigned char* slate_noise = rw.read_Raw_data(file2, 421, 700);
	unsigned char* Sobel_filter45_slate = hw4.filter3x3_move(slate, 421, 700, Sobel_filter45);
	unsigned char* Sobel_filter45_2_slate = hw4.filter3x3_move(slate, 421, 700, Sobel_filter45_2);
	unsigned char* Sobel_filter45_slate_noise = hw4.filter3x3_move(slate_noise, 421, 700, Sobel_filter45);
	unsigned char* Sobel_filter45_2_slate_noise = hw4.filter3x3_move(slate_noise, 421, 700, Sobel_filter45_2);
	unsigned char* slate_combine = hw4.img_combine(Sobel_filter45_slate, Sobel_filter45_2_slate, 421, 700);
	unsigned char* slate_noise_combine = hw4.img_combine(Sobel_filter45_slate_noise, Sobel_filter45_2_slate_noise, 421, 700);

	rw.write_raw_data(Sobel_filter45_outfile, Sobel_filter45_slate, 421, 700);
	rw.write_raw_data(Sobel_filter45_2_outfile, Sobel_filter45_2_slate, 421, 700);
	rw.write_raw_data(Sobel_filter45_noise_outfile, Sobel_filter45_slate_noise, 421, 700);
	rw.write_raw_data(Sobel_filter45_2_noise_outfile, Sobel_filter45_2_slate_noise, 421, 700);
	rw.write_raw_data(img_combine_outfile, slate_combine, 421, 700);
	rw.write_raw_data(noise_img_combine_outfile, slate_noise_combine, 421, 700);
}
void hw::HW2_6()
{
	rw rw;
	hw4 hw4;
	char file1[] = "slate_700x421.raw";
	char file2[] = "slate_noise_700x421.raw";
	const char* Laplacian_filter_4 = "Laplacian_filter_4";
	const char* Laplacian_filter_8 = "Laplacian_filter_8";

	char Laplacian_filter_4_outfile[] = "2_6slate_Laplacian4.raw";
	char Laplacian_filter_8_outfile[] = "2_6slate_Laplacian8.raw";
	char Laplacian_filter_4_noise_outfile[] = "2_6slate_noise_Laplacian4.raw";
	char Laplacian_filter_8_noise_outfile[] = "2_6slate_noise_Laplacian8.raw";

	unsigned char* slate = rw.read_Raw_data(file1, 421, 700);
	unsigned char* slate_noise = rw.read_Raw_data(file2, 421, 700);
	unsigned char* Laplacian_filter_4_slate = hw4.filter3x3_move(slate, 421, 700, Laplacian_filter_4);
	unsigned char* Laplacian_filter_8_slate = hw4.filter3x3_move(slate, 421, 700, Laplacian_filter_8);
	unsigned char* Laplacian_filter_4_slate_noise = hw4.filter3x3_move(slate_noise, 421, 700, Laplacian_filter_4);
	unsigned char* Laplacian_filter_8_slate_noise = hw4.filter3x3_move(slate_noise, 421, 700, Laplacian_filter_8);

	rw.write_raw_data(Laplacian_filter_4_outfile, Laplacian_filter_4_slate, 421, 700);
	rw.write_raw_data(Laplacian_filter_8_outfile, Laplacian_filter_8_slate, 421, 700);
	rw.write_raw_data(Laplacian_filter_4_noise_outfile, Laplacian_filter_4_slate_noise, 421, 700);
	rw.write_raw_data(Laplacian_filter_8_noise_outfile, Laplacian_filter_8_slate_noise, 421, 700);
}
void hw::HW2_8()
{
	rw rw;
	hw4 hw4;
	char file1[] = "slate_700x421.raw";
	char file2[] = "slate_noise_700x421.raw";
	const char* High_boost_filter_4_4 = "High_boost_filter_4";
	const char* High_boost_filter_8_2 = "High_boost_filter_8";

	char High_boost_filter_4_outfile[] = "2_8slate_High_boost_4.raw";
	char High_boost_filter_8_outfile[] = "2_8slate_High_boost_8.raw";
	char High_boost_filter_4_noise_outfile[] = "2_8slate_noise_High_boost_4.raw";
	char High_boost_filter_8_noise_outfile[] = "2_8slate_noise_High_boost_8.raw";

	unsigned char* slate = rw.read_Raw_data(file1, 421, 700);
	unsigned char* slate_noise = rw.read_Raw_data(file2, 421, 700);
	unsigned char* High_boost_filter_4_slate = hw4.filter3x3_move(slate, 421, 700, High_boost_filter_4_4);
	unsigned char* High_boost_filter_8_slate = hw4.filter3x3_move(slate, 421, 700, High_boost_filter_8_2);
	unsigned char* High_boost_filter_4_slate_noise = hw4.filter3x3_move(slate_noise, 421, 700, High_boost_filter_4_4);
	unsigned char* High_boost_filter_8_slate_noise = hw4.filter3x3_move(slate_noise, 421, 700, High_boost_filter_8_2);

	rw.write_raw_data(High_boost_filter_4_outfile, High_boost_filter_4_slate, 421, 700);
	rw.write_raw_data(High_boost_filter_8_outfile, High_boost_filter_8_slate, 421, 700);
	rw.write_raw_data(High_boost_filter_4_noise_outfile, High_boost_filter_4_slate_noise, 421, 700);
	rw.write_raw_data(High_boost_filter_8_noise_outfile, High_boost_filter_8_slate_noise, 421, 700);
}
void hw::HW3_1()
{
	rw rw;
	hw4 hw4;
	char file1[] = "flower_512x384.raw";
	char outfile[] = "3_1flower_out.raw";
	const char* Laplacian_filter = "Laplacian_filter";
	const char* Gaussian_filter = "Gaussian_filter";
	const char* filter_3_1 = "Filter3_1";

	unsigned char* flower = rw.read_Raw_data(file1, 384, 512);
	unsigned char* Gaussian5x5_flower = hw4.filter5x5_move(flower, 384, 512, Gaussian_filter);
	unsigned char* flower_out = hw4.img_thresholding(Gaussian5x5_flower, 384, 512, 180);
	rw.write_raw_data(outfile, flower_out, 384, 512);
}
void hw::HW3_2()
{
	rw rw;
	hw4 hw4;
	char file1[] = "flower_512x384.raw";
	char file2[] = "3_1flower_out.raw";
	char outfile[] = "3_2flower_out.raw";
	unsigned char* flower = rw.read_Raw_data(file1, 384, 512);
	unsigned char* mask = rw.read_Raw_data(file2, 384, 512);

	unsigned char* img_out = hw4.OR_Gate(flower, mask, 384, 512);
	rw.write_raw_data(outfile, img_out, 384, 512);
}