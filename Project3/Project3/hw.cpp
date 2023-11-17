#include <stdio.h>
#include <iostream>
#include"class.h"
#include"hw.h"

#define _CRT_SECURE_NO_WARNINGS

void hw::HW1_1()
{
	rw rw;
	hw3 hw3;
	char file[] = "doraemon256.raw";
	char outfile[] = "1_1doraemon.raw";
	unsigned char* doraemon = rw.read_Raw_data(file, 256, 256);
	doraemon = hw3.Binarlize(doraemon, 256, 256);
	rw.write_raw_data(outfile, doraemon, 256, 256);
}
void hw::HW1_2()
{
	rw rw;
	hw3 hw3;
	char file[] = "lena256.raw";
	char file2[] = "1_1doraemon.raw";
	char outfile[] = "1_2replace_0.raw";
	unsigned char* lena256 = rw.read_Raw_data(file, 256, 256);
	unsigned char* doraemon = rw.read_Raw_data(file2, 256, 256);
	unsigned char* out_img1 = hw3.Replace(lena256, doraemon, 256, 256, 0);
	for (int i = 0; i < 256*256; i++)
	{
		printf("%d %d\n", lena256[i], out_img1[i]);
	}
	rw.write_raw_data(outfile, out_img1, 256, 256);
}
void hw::HW1_3()
{
	rw rw;
	hw3 hw3;
	char file[] = "lena256.raw";
	char file2[] = "1_1doraemon.raw";
	char outfile1[] = "1_3replace_1.raw";
	char outfile2[] = "1_3replace_2.raw";
	char outfile3[] = "1_3replace_3.raw";
	char outfile4[] = "1_3replace_4.raw";
	char outfile5[] = "1_3replace_5.raw";
	char outfile6[] = "1_3replace_6.raw";
	char outfile7[] = "1_3replace_7.raw";
	unsigned char* lena256 = rw.read_Raw_data(file, 256, 256);
	unsigned char* doraemon = rw.read_Raw_data(file2, 256, 256);
	unsigned char* out_img1 = hw3.Replace(lena256, doraemon, 256, 256, 1);
	unsigned char* out_img2 = hw3.Replace(lena256, doraemon, 256, 256, 2);
	unsigned char* out_img3 = hw3.Replace(lena256, doraemon, 256, 256, 3);
	unsigned char* out_img4 = hw3.Replace(lena256, doraemon, 256, 256, 4);
	unsigned char* out_img5 = hw3.Replace(lena256, doraemon, 256, 256, 5);
	unsigned char* out_img6 = hw3.Replace(lena256, doraemon, 256, 256, 6);
	unsigned char* out_img7 = hw3.Replace(lena256, doraemon, 256, 256, 7);
	rw.write_raw_data(outfile1, out_img1, 256, 256);
	rw.write_raw_data(outfile2, out_img2, 256, 256);
	rw.write_raw_data(outfile3, out_img3, 256, 256);
	rw.write_raw_data(outfile4, out_img4, 256, 256);
	rw.write_raw_data(outfile5, out_img5, 256, 256);
	rw.write_raw_data(outfile6, out_img6, 256, 256);
	rw.write_raw_data(outfile7, out_img7, 256, 256);
}
void hw::HW2_1()
{
	rw rw;
	hw3 hw3;
	char file[] = "log512.raw";
	char outfile1[] = "2_1log512_log.raw";
	char outfile2[] = "2_1log512_inverselog.raw";
	unsigned char* log512 = rw.read_Raw_data(file, 512, 512);
	unsigned char* log512_log = hw3.logtransform(log512, 512, 512);
	unsigned char* log512_invlog = hw3.inverse_logtransform(log512, 512, 512);
	rw.write_raw_data(outfile1, log512_log, 512, 512);
	rw.write_raw_data(outfile2, log512_invlog, 512, 512);
}
void hw::HW2_2()
{
	rw rw;
	hw3 hw3;
	char file[] = "log512.raw";
	char outfile1[] = "2_2log512_power_law(1).raw";
	char outfile2[] = "2_2log512_power_law(2).raw";
	char outfile3[] = "2_2log512_power_law(3).raw";
	char outfile4[] = "2_2log512_power_law(4).raw";
	unsigned char* log512 = rw.read_Raw_data(file, 512, 512);
	unsigned char* powerlaw1 = hw3.power_lowtransform(log512, 512, 512, 5);
	unsigned char* powerlaw2 = hw3.power_lowtransform(log512, 512, 512, 2);
	unsigned char* powerlaw3 = hw3.power_lowtransform(log512, 512, 512, 0.5);
	unsigned char* powerlaw4 = hw3.power_lowtransform(log512, 512, 512, 0.2);
	rw.write_raw_data(outfile1, powerlaw1, 512, 512);
	rw.write_raw_data(outfile2, powerlaw2, 512, 512);
	rw.write_raw_data(outfile3, powerlaw3, 512, 512);
	rw.write_raw_data(outfile4, powerlaw4, 512, 512);
}
void hw::HW2_3()
{
	rw rw;
	hw3 hw3;
	char file[] = "log512.raw";
	char neg_file[] = "2_3neg_log512.raw";
	char outfile1[] = "2_3neg_log512_log.raw";
	char outfile2[] = "2_3neg_log512_inverselog.raw";
	char outfile3[] = "2_3neg_log512_power_law(1).raw";
	char outfile4[] = "2_3neg_log512_power_law(2).raw";
	char outfile5[] = "2_3neg_log512_power_law(3).raw";
	char outfile6[] = "2_3neg_log512_power_law(4).raw";
	unsigned char* log512 = rw.read_Raw_data(file, 512, 512);
	unsigned char* neg_log512 = hw3.negative(log512, 512, 512);
	unsigned char* neg_log512_log = hw3.logtransform(neg_log512, 512, 512);
	unsigned char* neg_log512_invlog = hw3.inverse_logtransform(neg_log512, 512, 512);
	unsigned char* neg_powerlaw1 = hw3.power_lowtransform(neg_log512, 512, 512, 5);
	unsigned char* neg_powerlaw2 = hw3.power_lowtransform(neg_log512, 512, 512, 2);
	unsigned char* neg_powerlaw3 = hw3.power_lowtransform(neg_log512, 512, 512, 0.5);
	unsigned char* neg_powerlaw4 = hw3.power_lowtransform(neg_log512, 512, 512, 0.2);
	rw.write_raw_data(neg_file, neg_log512, 512, 512);
	rw.write_raw_data(outfile1, neg_log512_log, 512, 512);
	rw.write_raw_data(outfile2, neg_log512_invlog, 512, 512);
	rw.write_raw_data(outfile3, neg_powerlaw1, 512, 512);
	rw.write_raw_data(outfile4, neg_powerlaw2, 512, 512);
	rw.write_raw_data(outfile5, neg_powerlaw3, 512, 512);
	rw.write_raw_data(outfile6, neg_powerlaw4, 512, 512);
}
void hw::HW3_1()
{
	rw rw;
	hw3 hw3;
	char file[] = "log512.raw";
	char neg_file[] = "2_3neg_log512.raw";
	char out_file[] = "3_1_log512_histogram.png";
	char neg_out_file[] = "3_1_neglog512_histogram.png";
	unsigned char* log512 = rw.read_Raw_data(file, 512, 512);
	unsigned char* neg_log512 = rw.read_Raw_data(neg_file, 512, 512);
	float* list = hw3.Histogram(log512, 512, 512);
	hw3.Plot_histogram(list, out_file);
	list = hw3.Histogram(neg_log512, 512, 512);
	hw3.Plot_histogram(list, neg_out_file);
}
void hw::HW3_2()
{
	rw rw;
	hw3 hw3;
	char file[] = "log512.raw";
	char neg_file[] = "2_3neg_log512.raw";
	char outfile[] = "3_2log512.raw";
	char outfile2[] = "3_2log512negative.raw";
	char out_file[] = "3_2log512_histogram.png";
	char neg_out_file[] = "3_2log512negative_histogram.png";
	unsigned char* log512 = rw.read_Raw_data(file, 512, 512);
	unsigned char* neg_log512 = rw.read_Raw_data(neg_file, 512, 512);
	float* list = hw3.Histogram(log512, 512, 512);
	unsigned char* log512_histogram_equalization = hw3.Histogram_equalization(log512, list, 512, 512);
	list = hw3.Histogram(log512_histogram_equalization, 512, 512);
	float* list2 = hw3.Histogram(neg_log512, 512, 512);
	unsigned char* log512negative_histogram_equalization = hw3.Histogram_equalization(neg_log512, list2, 512, 512);
	list2 = hw3.Histogram(log512negative_histogram_equalization, 512, 512);
	hw3.Plot_histogram(list, out_file);
	hw3.Plot_histogram(list2, neg_out_file);
	rw.write_raw_data(outfile, log512_histogram_equalization, 512, 512);
	rw.write_raw_data(outfile2, log512negative_histogram_equalization, 512, 512);
}
void hw::HW3_3()
{
	rw rw;
	hw3 hw3;
	char file[] = "log512.raw";
	char out_file[] = "3_3log512_matching.raw";
	char histogram_out_file[] = "3_3_matching_histogram.png";
	unsigned char* log512 = rw.read_Raw_data(file, 512, 512);
	unsigned char* img_matching = hw3.Histogram_matching(log512, 77, 153, 512,512);
	float* list = hw3.Histogram(img_matching, 512, 512);
	hw3.Plot_histogram(list, histogram_out_file);
	rw.write_raw_data(out_file, img_matching, 512, 512);
}