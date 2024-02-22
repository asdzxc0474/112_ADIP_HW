#include <stdio.h>
#include <iostream>
#include"class.h"
#include"hw.h"

#define _CRT_SECURE_NO_WARNINGS


void hw::HW1_1()
{
	rw rw;
	hw6 hw6;
	char lena_sp[] = "lean_256_salt&pepper.raw";
	char lena_g_1[] = "lena_gussuian_1_256.raw";
	char lena_g_2[] = "lena_gussuian_2_256.raw";
	char lena_sp_out_3[] = "(1_1)lena_256_salt&pepper_out_3.raw";
	char lena_sp_out_5[] = "(1_1)lena_256_salt&pepper_out_5.raw";
	char lena_sp_out_7[] = "(1_1)lena_256_salt&pepper_out_7.raw";
	char lena_sp_out_9[] = "(1_1)lena_256_salt&pepper_out_9.raw";
	char lena_g1_out_3[] = "(1_1)lena_256_gussuian_1_out_3.raw";
	char lena_g1_out_5[] = "(1_1)lena_256_gussuian_1_out_5.raw";
	char lena_g1_out_7[] = "(1_1)lena_256_gussuian_1_out_7.raw";
	char lena_g1_out_9[] = "(1_1)lena_256_gussuian_1_out_9.raw";
	char lena_g2_out_3[] = "(1_1)lena_256_gussuian_2_out_3.raw";
	char lena_g2_out_5[] = "(1_1)lena_256_gussuian_2_out_5.raw";
	char lena_g2_out_7[] = "(1_1)lena_256_gussuian_2_out_7.raw";
	char lena_g2_out_9[] = "(1_1)lena_256_gussuian_2_out_9.raw";
	char lena256[] = "lena_256.raw";

	unsigned char* lena_256_sp = rw.read_Raw_data(lena_sp, 256, 256);
	unsigned char* lena_256_g1 = rw.read_Raw_data(lena_g_1, 256, 256);
	unsigned char* lena_256_g2 = rw.read_Raw_data(lena_g_2, 256, 256);
	unsigned char* lena_256 = rw.read_Raw_data(lena256, 256, 256);
	
	unsigned char* lena_256_sp_f = hw6.adaptive_local_noise_filter_run(lena_256_sp, 256, 256, 3);
	printf("MSE = % f\n",hw6.MSE(lena_256_sp_f, lena_256, 256, 256));
	rw.write_raw_data(lena_sp_out_3, lena_256_sp_f, 256, 256);
	lena_256_sp_f = hw6.adaptive_local_noise_filter_run(lena_256_sp, 256, 256, 5);
	printf("MSE = % f\n", hw6.MSE(lena_256_sp_f, lena_256, 256, 256));
	rw.write_raw_data(lena_sp_out_5, lena_256_sp_f, 256, 256);
	lena_256_sp_f = hw6.adaptive_local_noise_filter_run(lena_256_sp, 256, 256, 7);
	printf("MSE = % f\n", hw6.MSE(lena_256_sp_f, lena_256, 256, 256));
	rw.write_raw_data(lena_sp_out_7, lena_256_sp_f, 256, 256);
	lena_256_sp_f = hw6.adaptive_local_noise_filter_run(lena_256_sp, 256, 256, 9);
	printf("MSE = % f\n", hw6.MSE(lena_256_sp_f, lena_256, 256, 256));
	rw.write_raw_data(lena_sp_out_9, lena_256_sp_f, 256, 256);

	unsigned char* lena_256_g1_f = hw6.adaptive_local_noise_filter_run(lena_256_g1, 256, 256, 3);
	printf("MSE = % f\n", hw6.MSE(lena_256_g1_f, lena_256, 256, 256));
	rw.write_raw_data(lena_g1_out_3, lena_256_g1_f, 256, 256);
	lena_256_g1_f = hw6.adaptive_local_noise_filter_run(lena_256_g1, 256, 256, 5);
	printf("MSE = % f\n", hw6.MSE(lena_256_g1_f, lena_256, 256, 256));
	rw.write_raw_data(lena_g1_out_5, lena_256_g1_f, 256, 256);
	lena_256_g1_f = hw6.adaptive_local_noise_filter_run(lena_256_g1, 256, 256, 7);
	printf("MSE = % f\n", hw6.MSE(lena_256_g1_f, lena_256, 256, 256));
	rw.write_raw_data(lena_g1_out_7, lena_256_g1_f, 256, 256);
	lena_256_g1_f = hw6.adaptive_local_noise_filter_run(lena_256_g1, 256, 256, 9);
	printf("MSE = % f\n", hw6.MSE(lena_256_g1_f, lena_256, 256, 256));
	rw.write_raw_data(lena_g1_out_9, lena_256_g1_f, 256, 256);

	unsigned char* lena_256_g2_f = hw6.adaptive_local_noise_filter_run(lena_256_g2, 256, 256, 3);
	printf("MSE = % f\n", hw6.MSE(lena_256_g2_f, lena_256, 256, 256));
	rw.write_raw_data(lena_g2_out_3, lena_256_g2_f, 256, 256);
	lena_256_g2_f = hw6.adaptive_local_noise_filter_run(lena_256_g2, 256, 256, 5);
	printf("MSE = % f\n", hw6.MSE(lena_256_g2_f, lena_256, 256, 256));
	rw.write_raw_data(lena_g2_out_5, lena_256_g2_f, 256, 256);
	lena_256_g2_f = hw6.adaptive_local_noise_filter_run(lena_256_g2, 256, 256, 7);
	printf("MSE = % f\n", hw6.MSE(lena_256_g2_f, lena_256, 256, 256));
	rw.write_raw_data(lena_g2_out_7, lena_256_g2_f, 256, 256);
	lena_256_g2_f = hw6.adaptive_local_noise_filter_run(lena_256_g2, 256, 256, 9);
	printf("MSE = % f\n", hw6.MSE(lena_256_g2_f, lena_256, 256, 256));
	rw.write_raw_data(lena_g2_out_9, lena_256_g2_f, 256, 256);
}
void hw::HW1_2()
{
	rw rw;
	hw6 hw6;
	char lena256[] = "lena_256.raw";
	char lena_sp[] = "lean_256_salt&pepper.raw";
	char lena_g_1[] = "lena_gussuian_1_256.raw";
	char lena_g_2[] = "lena_gussuian_2_256.raw";
	char lena_sp_out_3_1[] = "(1_2)lena_256_salt&pepper_out_3_1.raw";
	char lena_sp_out_3_2[] = "(1_2)lena_256_salt&pepper_out_3_2.raw";
	char lena_sp_out_5_1[] = "(1_2)lena_256_salt&pepper_out_5_1.raw";
	char lena_sp_out_5_2[] = "(1_2)lena_256_salt&pepper_out_5_2.raw";
	char lena_sp_out_5_3[] = "(1_2)lena_256_salt&pepper_out_5_3.raw";
	char lena_sp_out_7_1[] = "(1_2)lena_256_salt&pepper_out_7_1.raw";
	char lena_sp_out_7_2[] = "(1_2)lena_256_salt&pepper_out_7_2.raw";
	char lena_sp_out_7_3[] = "(1_2)lena_256_salt&pepper_out_7_3.raw";
	char lena_sp_out_7_4[] = "(1_2)lena_256_salt&pepper_out_7_4.raw";
	char lena_sp_out_9_1[] = "(1_2)lena_256_salt&pepper_out_9_1.raw";
	char lena_sp_out_9_2[] = "(1_2)lena_256_salt&pepper_out_9_2.raw";
	char lena_sp_out_9_3[] = "(1_2)lena_256_salt&pepper_out_9_3.raw";
	char lena_sp_out_9_4[] = "(1_2)lena_256_salt&pepper_out_9_4.raw";
	char lena_sp_out_9_5[] = "(1_2)lena_256_salt&pepper_out_9_5.raw";
	char lena_g1_out_3_1[] = "(1_2)lena_256_gussuian_1_out_3_1.raw";
	char lena_g1_out_3_2[] = "(1_2)lena_256_gussuian_1_out_3_2.raw";
	char lena_g1_out_5_1[] = "(1_2)lena_256_gussuian_1_out_5_1.raw";
	char lena_g1_out_5_2[] = "(1_2)lena_256_gussuian_1_out_5_2.raw";
	char lena_g1_out_5_3[] = "(1_2)lena_256_gussuian_1_out_5_3.raw";
	char lena_g1_out_7_1[] = "(1_2)lena_256_gussuian_1_out_7_1.raw";
	char lena_g1_out_7_2[] = "(1_2)lena_256_gussuian_1_out_7_2.raw";
	char lena_g1_out_7_3[] = "(1_2)lena_256_gussuian_1_out_7_3.raw";
	char lena_g1_out_7_4[] = "(1_2)lena_256_gussuian_1_out_7_4.raw";
	char lena_g1_out_9_1[] = "(1_2)lena_256_gussuian_1_out_9_1.raw";
	char lena_g1_out_9_2[] = "(1_2)lena_256_gussuian_1_out_9_2.raw";
	char lena_g1_out_9_3[] = "(1_2)lena_256_gussuian_1_out_9_3.raw";
	char lena_g1_out_9_4[] = "(1_2)lena_256_gussuian_1_out_9_4.raw";
	char lena_g1_out_9_5[] = "(1_2)lena_256_gussuian_1_out_9_5.raw";
	char lena_g2_out_3_1[] = "(1_2)lena_256_gussuian_2_out_3_1.raw";
	char lena_g2_out_3_2[] = "(1_2)lena_256_gussuian_2_out_3_2.raw";
	char lena_g2_out_5_1[] = "(1_2)lena_256_gussuian_2_out_5_1.raw";
	char lena_g2_out_5_2[] = "(1_2)lena_256_gussuian_2_out_5_2.raw";
	char lena_g2_out_5_3[] = "(1_2)lena_256_gussuian_2_out_5_3.raw";
	char lena_g2_out_7_1[] = "(1_2)lena_256_gussuian_2_out_7_1.raw";
	char lena_g2_out_7_2[] = "(1_2)lena_256_gussuian_2_out_7_2.raw";
	char lena_g2_out_7_3[] = "(1_2)lena_256_gussuian_2_out_7_3.raw";
	char lena_g2_out_7_4[] = "(1_2)lena_256_gussuian_2_out_7_4.raw";
	char lena_g2_out_9_1[] = "(1_2)lena_256_gussuian_2_out_9_1.raw";
	char lena_g2_out_9_2[] = "(1_2)lena_256_gussuian_2_out_9_2.raw";
	char lena_g2_out_9_3[] = "(1_2)lena_256_gussuian_2_out_9_3.raw";
	char lena_g2_out_9_4[] = "(1_2)lena_256_gussuian_2_out_9_4.raw";
	char lena_g2_out_9_5[] = "(1_2)lena_256_gussuian_2_out_9_5.raw";

	unsigned char* lena_256_sp = rw.read_Raw_data(lena_sp, 256, 256);
	unsigned char* lena_256_g1 = rw.read_Raw_data(lena_g_1, 256, 256);
	unsigned char* lena_256_g2 = rw.read_Raw_data(lena_g_2, 256, 256);
	unsigned char* lena_256 = rw.read_Raw_data(lena256, 256, 256);

	printf("MSE between lena_gussuian_1_256.raw using alpha_trimmed_mean_filter and lena_256.raw\n");
	unsigned char* lena_sp_alpha_trimmed_3_1 = hw6.alpha_trimmed_mean_filter_run(lena_256_sp, 256, 256, 3, 1);
	printf("MSE = % f\n", hw6.MSE(lena_sp_alpha_trimmed_3_1, lena_256, 256, 256));
	unsigned char* lena_sp_alpha_trimmed_3_2 = hw6.alpha_trimmed_mean_filter_run(lena_256_sp, 256, 256, 3, 2);
	printf("MSE = % f\n", hw6.MSE(lena_sp_alpha_trimmed_3_2, lena_256, 256, 256));
	unsigned char* lena_sp_alpha_trimmed_5_1 = hw6.alpha_trimmed_mean_filter_run(lena_256_sp, 256, 256, 5, 1);
	printf("MSE = % f\n", hw6.MSE(lena_sp_alpha_trimmed_5_1, lena_256, 256, 256));
	unsigned char* lena_sp_alpha_trimmed_5_2 = hw6.alpha_trimmed_mean_filter_run(lena_256_sp, 256, 256, 5, 2);
	printf("MSE = % f\n", hw6.MSE(lena_sp_alpha_trimmed_5_2, lena_256, 256, 256));
	unsigned char* lena_sp_alpha_trimmed_5_3 = hw6.alpha_trimmed_mean_filter_run(lena_256_sp, 256, 256, 5, 3);
	printf("MSE = % f\n", hw6.MSE(lena_sp_alpha_trimmed_5_3, lena_256, 256, 256));
	unsigned char* lena_sp_alpha_trimmed_7_1 = hw6.alpha_trimmed_mean_filter_run(lena_256_sp, 256, 256, 7, 1);
	printf("MSE = % f\n", hw6.MSE(lena_sp_alpha_trimmed_7_1, lena_256, 256, 256));
	unsigned char* lena_sp_alpha_trimmed_7_2 = hw6.alpha_trimmed_mean_filter_run(lena_256_sp, 256, 256, 7, 2);
	printf("MSE = % f\n", hw6.MSE(lena_sp_alpha_trimmed_7_2, lena_256, 256, 256));
	unsigned char* lena_sp_alpha_trimmed_7_3 = hw6.alpha_trimmed_mean_filter_run(lena_256_sp, 256, 256, 7, 3);
	printf("MSE = % f\n", hw6.MSE(lena_sp_alpha_trimmed_7_3, lena_256, 256, 256));
	unsigned char* lena_sp_alpha_trimmed_7_4 = hw6.alpha_trimmed_mean_filter_run(lena_256_sp, 256, 256, 7, 4);
	printf("MSE = % f\n", hw6.MSE(lena_sp_alpha_trimmed_7_4, lena_256, 256, 256));
	unsigned char* lena_sp_alpha_trimmed_9_1 = hw6.alpha_trimmed_mean_filter_run(lena_256_sp, 256, 256, 9, 1);
	printf("MSE = % f\n", hw6.MSE(lena_sp_alpha_trimmed_9_1, lena_256, 256, 256));
	unsigned char* lena_sp_alpha_trimmed_9_2 = hw6.alpha_trimmed_mean_filter_run(lena_256_sp, 256, 256, 9, 2);
	printf("MSE = % f\n", hw6.MSE(lena_sp_alpha_trimmed_9_2, lena_256, 256, 256));
	unsigned char* lena_sp_alpha_trimmed_9_3 = hw6.alpha_trimmed_mean_filter_run(lena_256_sp, 256, 256, 9, 3);
	printf("MSE = % f\n", hw6.MSE(lena_sp_alpha_trimmed_9_3, lena_256, 256, 256));
	unsigned char* lena_sp_alpha_trimmed_9_4 = hw6.alpha_trimmed_mean_filter_run(lena_256_sp, 256, 256, 9, 4);
	printf("MSE = % f\n", hw6.MSE(lena_sp_alpha_trimmed_9_4, lena_256, 256, 256));
	unsigned char* lena_sp_alpha_trimmed_9_5 = hw6.alpha_trimmed_mean_filter_run(lena_256_sp, 256, 256, 9, 5);
	printf("MSE = % f\n", hw6.MSE(lena_sp_alpha_trimmed_9_5, lena_256, 256, 256));

	printf("MSE between lena_gussuian_1_256.raw using alpha_trimmed_mean_filter and lena_256.raw\n");
	unsigned char* lena_g1_alpha_trimmed_3_1 = hw6.alpha_trimmed_mean_filter_run(lena_256_g1, 256, 256, 3, 1);
	printf("MSE = % f\n", hw6.MSE(lena_g1_alpha_trimmed_3_1, lena_256, 256, 256));
	unsigned char* lena_g1_alpha_trimmed_3_2 = hw6.alpha_trimmed_mean_filter_run(lena_256_g1, 256, 256, 3, 2);
	printf("MSE = % f\n", hw6.MSE(lena_g1_alpha_trimmed_3_2, lena_256, 256, 256));
	unsigned char* lena_g1_alpha_trimmed_5_1 = hw6.alpha_trimmed_mean_filter_run(lena_256_g1, 256, 256, 5, 1);
	printf("MSE = % f\n", hw6.MSE(lena_g1_alpha_trimmed_5_1, lena_256, 256, 256));
	unsigned char* lena_g1_alpha_trimmed_5_2 = hw6.alpha_trimmed_mean_filter_run(lena_256_g1, 256, 256, 5, 2);
	printf("MSE = % f\n", hw6.MSE(lena_g1_alpha_trimmed_5_2, lena_256, 256, 256));
	unsigned char* lena_g1_alpha_trimmed_5_3 = hw6.alpha_trimmed_mean_filter_run(lena_256_g1, 256, 256, 5, 3);
	printf("MSE = % f\n", hw6.MSE(lena_g1_alpha_trimmed_5_3, lena_256, 256, 256));
	unsigned char* lena_g1_alpha_trimmed_7_1 = hw6.alpha_trimmed_mean_filter_run(lena_256_g1, 256, 256, 7, 1);
	printf("MSE = % f\n", hw6.MSE(lena_g1_alpha_trimmed_7_1, lena_256, 256, 256));
	unsigned char* lena_g1_alpha_trimmed_7_2 = hw6.alpha_trimmed_mean_filter_run(lena_256_g1, 256, 256, 7, 2);
	printf("MSE = % f\n", hw6.MSE(lena_g1_alpha_trimmed_7_2, lena_256, 256, 256));
	unsigned char* lena_g1_alpha_trimmed_7_3 = hw6.alpha_trimmed_mean_filter_run(lena_256_g1, 256, 256, 7, 3);
	printf("MSE = % f\n", hw6.MSE(lena_g1_alpha_trimmed_7_3, lena_256, 256, 256));
	unsigned char* lena_g1_alpha_trimmed_7_4 = hw6.alpha_trimmed_mean_filter_run(lena_256_g1, 256, 256, 7, 4);
	printf("MSE = % f\n", hw6.MSE(lena_g1_alpha_trimmed_7_4, lena_256, 256, 256));
	unsigned char* lena_g1_alpha_trimmed_9_1 = hw6.alpha_trimmed_mean_filter_run(lena_256_g1, 256, 256, 9, 1);
	printf("MSE = % f\n", hw6.MSE(lena_g1_alpha_trimmed_9_1, lena_256, 256, 256));
	unsigned char* lena_g1_alpha_trimmed_9_2 = hw6.alpha_trimmed_mean_filter_run(lena_256_g1, 256, 256, 9, 2);
	printf("MSE = % f\n", hw6.MSE(lena_g1_alpha_trimmed_9_2, lena_256, 256, 256));
	unsigned char* lena_g1_alpha_trimmed_9_3 = hw6.alpha_trimmed_mean_filter_run(lena_256_g1, 256, 256, 9, 3);
	printf("MSE = % f\n", hw6.MSE(lena_g1_alpha_trimmed_9_3, lena_256, 256, 256));
	unsigned char* lena_g1_alpha_trimmed_9_4 = hw6.alpha_trimmed_mean_filter_run(lena_256_g1, 256, 256, 9, 4);
	printf("MSE = % f\n", hw6.MSE(lena_g1_alpha_trimmed_9_4, lena_256, 256, 256));
	unsigned char* lena_g1_alpha_trimmed_9_5 = hw6.alpha_trimmed_mean_filter_run(lena_256_g1, 256, 256, 9, 5);
	printf("MSE = % f\n", hw6.MSE(lena_g1_alpha_trimmed_9_5, lena_256, 256, 256));

	printf("MSE between lena_gussuian_2_256.raw using alpha_trimmed_mean_filter and lena_256.raw\n");
	unsigned char* lena_g2_alpha_trimmed_3_1 = hw6.alpha_trimmed_mean_filter_run(lena_256_g2, 256, 256, 3, 1);
	printf("MSE = % f\n", hw6.MSE(lena_g2_alpha_trimmed_3_1, lena_256, 256, 256));
	unsigned char* lena_g2_alpha_trimmed_3_2 = hw6.alpha_trimmed_mean_filter_run(lena_256_g2, 256, 256, 3, 2);
	printf("MSE = % f\n", hw6.MSE(lena_g2_alpha_trimmed_3_2, lena_256, 256, 256));
	unsigned char* lena_g2_alpha_trimmed_5_1 = hw6.alpha_trimmed_mean_filter_run(lena_256_g2, 256, 256, 5, 1);
	printf("MSE = % f\n", hw6.MSE(lena_g2_alpha_trimmed_5_1, lena_256, 256, 256));
	unsigned char* lena_g2_alpha_trimmed_5_2 = hw6.alpha_trimmed_mean_filter_run(lena_256_g2, 256, 256, 5, 2);
	printf("MSE = % f\n", hw6.MSE(lena_g2_alpha_trimmed_5_2, lena_256, 256, 256));
	unsigned char* lena_g2_alpha_trimmed_5_3 = hw6.alpha_trimmed_mean_filter_run(lena_256_g2, 256, 256, 5, 3);
	printf("MSE = % f\n", hw6.MSE(lena_g2_alpha_trimmed_5_3, lena_256, 256, 256));
	unsigned char* lena_g2_alpha_trimmed_7_1 = hw6.alpha_trimmed_mean_filter_run(lena_256_g2, 256, 256, 7, 1);
	printf("MSE = % f\n", hw6.MSE(lena_g2_alpha_trimmed_7_1, lena_256, 256, 256));
	unsigned char* lena_g2_alpha_trimmed_7_2 = hw6.alpha_trimmed_mean_filter_run(lena_256_g2, 256, 256, 7, 2);
	printf("MSE = % f\n", hw6.MSE(lena_g2_alpha_trimmed_7_2, lena_256, 256, 256));
	unsigned char* lena_g2_alpha_trimmed_7_3 = hw6.alpha_trimmed_mean_filter_run(lena_256_g2, 256, 256, 7, 3);
	printf("MSE = % f\n", hw6.MSE(lena_g2_alpha_trimmed_7_3, lena_256, 256, 256));
	unsigned char* lena_g2_alpha_trimmed_7_4 = hw6.alpha_trimmed_mean_filter_run(lena_256_g2, 256, 256, 7, 4);
	printf("MSE = % f\n", hw6.MSE(lena_g2_alpha_trimmed_7_4, lena_256, 256, 256));
	unsigned char* lena_g2_alpha_trimmed_9_1 = hw6.alpha_trimmed_mean_filter_run(lena_256_g2, 256, 256, 9, 1);
	printf("MSE = % f\n", hw6.MSE(lena_g2_alpha_trimmed_9_1, lena_256, 256, 256));
	unsigned char* lena_g2_alpha_trimmed_9_2 = hw6.alpha_trimmed_mean_filter_run(lena_256_g2, 256, 256, 9, 2);
	printf("MSE = % f\n", hw6.MSE(lena_g2_alpha_trimmed_9_2, lena_256, 256, 256));
	unsigned char* lena_g2_alpha_trimmed_9_3 = hw6.alpha_trimmed_mean_filter_run(lena_256_g2, 256, 256, 9, 3);
	printf("MSE = % f\n", hw6.MSE(lena_g2_alpha_trimmed_9_3, lena_256, 256, 256));
	unsigned char* lena_g2_alpha_trimmed_9_4 = hw6.alpha_trimmed_mean_filter_run(lena_256_g2, 256, 256, 9, 4);
	printf("MSE = % f\n", hw6.MSE(lena_g2_alpha_trimmed_9_4, lena_256, 256, 256));
	unsigned char* lena_g2_alpha_trimmed_9_5 = hw6.alpha_trimmed_mean_filter_run(lena_256_g2, 256, 256, 9, 5);
	printf("MSE = % f\n", hw6.MSE(lena_g2_alpha_trimmed_9_5, lena_256, 256, 256));

	rw.write_raw_data(lena_sp_out_3_1, lena_sp_alpha_trimmed_3_1, 256, 256);
	rw.write_raw_data(lena_sp_out_3_2, lena_sp_alpha_trimmed_3_2, 256, 256);
	rw.write_raw_data(lena_sp_out_5_1, lena_sp_alpha_trimmed_5_1, 256, 256);
	rw.write_raw_data(lena_sp_out_5_2, lena_sp_alpha_trimmed_5_2, 256, 256);
	rw.write_raw_data(lena_sp_out_5_3, lena_sp_alpha_trimmed_5_3, 256, 256);
	rw.write_raw_data(lena_sp_out_7_1, lena_sp_alpha_trimmed_7_1, 256, 256);
	rw.write_raw_data(lena_sp_out_7_2, lena_sp_alpha_trimmed_7_2, 256, 256);
	rw.write_raw_data(lena_sp_out_7_3, lena_sp_alpha_trimmed_7_3, 256, 256);
	rw.write_raw_data(lena_sp_out_7_4, lena_sp_alpha_trimmed_7_4, 256, 256);
	rw.write_raw_data(lena_sp_out_9_1, lena_sp_alpha_trimmed_9_1, 256, 256);
	rw.write_raw_data(lena_sp_out_9_2, lena_sp_alpha_trimmed_9_2, 256, 256);
	rw.write_raw_data(lena_sp_out_9_3, lena_sp_alpha_trimmed_9_3, 256, 256);
	rw.write_raw_data(lena_sp_out_9_4, lena_sp_alpha_trimmed_9_4, 256, 256);
	rw.write_raw_data(lena_sp_out_9_5, lena_sp_alpha_trimmed_9_5, 256, 256);

	rw.write_raw_data(lena_g1_out_3_1, lena_g1_alpha_trimmed_3_1, 256, 256);
	rw.write_raw_data(lena_g1_out_3_2, lena_g1_alpha_trimmed_3_2, 256, 256);
	rw.write_raw_data(lena_g1_out_5_1, lena_g1_alpha_trimmed_5_1, 256, 256);
	rw.write_raw_data(lena_g1_out_5_2, lena_g1_alpha_trimmed_5_2, 256, 256);
	rw.write_raw_data(lena_g1_out_5_3, lena_g1_alpha_trimmed_5_3, 256, 256);
	rw.write_raw_data(lena_g1_out_7_1, lena_g1_alpha_trimmed_7_1, 256, 256);
	rw.write_raw_data(lena_g1_out_7_2, lena_g1_alpha_trimmed_7_2, 256, 256);
	rw.write_raw_data(lena_g1_out_7_3, lena_g1_alpha_trimmed_7_3, 256, 256);
	rw.write_raw_data(lena_g1_out_7_4, lena_g1_alpha_trimmed_7_4, 256, 256);
	rw.write_raw_data(lena_g1_out_9_1, lena_g1_alpha_trimmed_9_1, 256, 256);
	rw.write_raw_data(lena_g1_out_9_2, lena_g1_alpha_trimmed_9_2, 256, 256);
	rw.write_raw_data(lena_g1_out_9_3, lena_g1_alpha_trimmed_9_3, 256, 256);
	rw.write_raw_data(lena_g1_out_9_4, lena_g1_alpha_trimmed_9_4, 256, 256);
	rw.write_raw_data(lena_g1_out_9_5, lena_g1_alpha_trimmed_9_5, 256, 256);

	rw.write_raw_data(lena_g2_out_3_1, lena_g2_alpha_trimmed_3_1, 256, 256);
	rw.write_raw_data(lena_g2_out_3_2, lena_g2_alpha_trimmed_3_2, 256, 256);
	rw.write_raw_data(lena_g2_out_5_1, lena_g2_alpha_trimmed_5_1, 256, 256);
	rw.write_raw_data(lena_g2_out_5_2, lena_g2_alpha_trimmed_5_2, 256, 256);
	rw.write_raw_data(lena_g2_out_5_3, lena_g2_alpha_trimmed_5_3, 256, 256);
	rw.write_raw_data(lena_g2_out_7_1, lena_g2_alpha_trimmed_7_1, 256, 256);
	rw.write_raw_data(lena_g2_out_7_2, lena_g2_alpha_trimmed_7_2, 256, 256);
	rw.write_raw_data(lena_g2_out_7_3, lena_g2_alpha_trimmed_7_3, 256, 256);
	rw.write_raw_data(lena_g2_out_7_4, lena_g2_alpha_trimmed_7_4, 256, 256);
	rw.write_raw_data(lena_g2_out_9_1, lena_g2_alpha_trimmed_9_1, 256, 256);
	rw.write_raw_data(lena_g2_out_9_2, lena_g2_alpha_trimmed_9_2, 256, 256);
	rw.write_raw_data(lena_g2_out_9_3, lena_g2_alpha_trimmed_9_3, 256, 256);
	rw.write_raw_data(lena_g2_out_9_4, lena_g2_alpha_trimmed_9_4, 256, 256);
	rw.write_raw_data(lena_g2_out_9_5, lena_g2_alpha_trimmed_9_5, 256, 256);
	delete[] lena_256_sp, lena_256_g1, lena_256_g2, lena_256;

	delete[] lena_sp_alpha_trimmed_3_1, lena_sp_alpha_trimmed_3_2, lena_sp_alpha_trimmed_5_1, lena_sp_alpha_trimmed_5_2\
		, lena_sp_alpha_trimmed_5_3, lena_sp_alpha_trimmed_7_1, lena_sp_alpha_trimmed_7_2, lena_sp_alpha_trimmed_7_3, lena_sp_alpha_trimmed_7_4\
		, lena_sp_alpha_trimmed_9_1, lena_sp_alpha_trimmed_9_2, lena_sp_alpha_trimmed_9_3, lena_sp_alpha_trimmed_9_4, lena_sp_alpha_trimmed_9_5;

	delete[] lena_g1_alpha_trimmed_3_1, lena_g1_alpha_trimmed_3_2, lena_g1_alpha_trimmed_5_1, lena_g1_alpha_trimmed_5_2\
		, lena_g1_alpha_trimmed_5_3, lena_g1_alpha_trimmed_7_1, lena_g1_alpha_trimmed_7_2, lena_g1_alpha_trimmed_7_3, lena_g1_alpha_trimmed_7_4\
		, lena_g1_alpha_trimmed_9_1, lena_g1_alpha_trimmed_9_2, lena_g1_alpha_trimmed_9_3, lena_g1_alpha_trimmed_9_4, lena_g1_alpha_trimmed_9_5;

	delete[] lena_g2_alpha_trimmed_3_1, lena_g2_alpha_trimmed_3_2, lena_g2_alpha_trimmed_5_1, lena_g2_alpha_trimmed_5_2\
		, lena_g2_alpha_trimmed_5_3, lena_g2_alpha_trimmed_7_1, lena_g2_alpha_trimmed_7_2, lena_g2_alpha_trimmed_7_3, lena_g2_alpha_trimmed_7_4\
		, lena_g2_alpha_trimmed_9_1, lena_g2_alpha_trimmed_9_2, lena_g2_alpha_trimmed_9_3, lena_g2_alpha_trimmed_9_4, lena_g2_alpha_trimmed_9_5;
}
void hw::HW2_1()
{
	rw rw;
	hw6 hw6;
	char lena256[] = "lena_256.raw";
	char lena256_blur[] = "lena_256_blur.raw";
	char lena256_blur_noise[] = "lena_256_blur_noise.raw";
	char lena256_DFT_out[] = "(2_1)lena_256_DFT.raw";
	char lena256_blur_DFT_out[] = "(2_1)lena_256_blur_DFT.raw";
	char lena256_blur_noise_DFT_out[] = "lena_256_blur_noise_DFT.raw";
	
	char lena256_blur_inverse_flter__No_r_out[] = "(2_1)lena256_blur_inverse_flter_No_R.raw";
	char lena256_blur_inverse_flter_15_out[] = "(2_1)lena256_blur_inverse_flter15.raw";
	char lena256_blur_inverse_flter_20_out[] = "(2_1)lena256_blur_inverse_flter30.raw";
	char lena256_blur_inverse_flter_25_out[] = "(2_1)lena256_blur_inverse_flter40.raw";
	char lena256_blur_noise_inverse_flter__No_r_out[] = "(2_1)lena256_blur_noise_inverse_flterNo_R.raw";
	char lena256_blur_noise_inverse_flter_15_out[] = "(2_1)lena256_blur_noise_inverse_flter15.raw";
	char lena256_blur_noise_inverse_flter_20_out[] = "(2_1)lena256_blur_noise_inverse_flter30.raw";
	char lena256_blur_noise_inverse_flter_25_out[] = "(2_1)lena256_blur_noise_inverse_flter40.raw";

	double* real = new double[256 * 256];
	double* imagine = new double[256 * 256];
	long double* blur_real = new long double[256 * 256];
	long double* blur_imagine = new long double[256 * 256];

	unsigned char* lena_256 = rw.read_Raw_data(lena256, 256, 256);
	unsigned char* lena_256_b = rw.read_Raw_data(lena256_blur, 256, 256);
	unsigned char* lena_256_b_n = rw.read_Raw_data(lena256_blur_noise, 256, 256);
	unsigned char* lena256_DFT = hw6.IID_DFT(lena_256, 256, 256, real, imagine);
	
	hw6.Motion_blur_IID_DFT(256, 256, 0.07, -0.07, 1, blur_real, blur_imagine);
	unsigned char* lena256_b_DFT = hw6.IID_DFT(lena_256_b, 256, 256, real, imagine);
	unsigned char* lena_256_b_Inverse_filter_NoR = hw6.Inverse_Filter(real, imagine, blur_real, blur_imagine, 256, 256, false, 0);
	unsigned char* lena_256_b_Inverse_filter_15 = hw6.Inverse_Filter(real, imagine, blur_real, blur_imagine, 256, 256, true, 15);
	unsigned char* lena_256_b_Inverse_filter_30 = hw6.Inverse_Filter(real, imagine, blur_real, blur_imagine, 256, 256, true, 20);
	unsigned char* lena_256_b_Inverse_filter_40 = hw6.Inverse_Filter(real, imagine, blur_real, blur_imagine, 256, 256, true, 25);
	
	unsigned char* lena256__bn_DFT = hw6.IID_DFT(lena_256_b_n, 256, 256, real, imagine);
	unsigned char* lena_256_bn_Inverse_filter_NoR = hw6.Inverse_Filter(real, imagine, blur_real, blur_imagine, 256, 256, false, 0);
	unsigned char* lena_256_bn_Inverse_filter_15 = hw6.Inverse_Filter(real, imagine, blur_real, blur_imagine, 256, 256, true, 15);
	unsigned char* lena_256_bn_Inverse_filter_30 = hw6.Inverse_Filter(real, imagine, blur_real, blur_imagine, 256, 256, true, 20);
	unsigned char* lena_256_bn_Inverse_filter_40 = hw6.Inverse_Filter(real, imagine, blur_real, blur_imagine, 256, 256, true, 50);
	
	rw.write_raw_data(lena256_DFT_out, lena256_DFT, 256, 256);
	rw.write_raw_data(lena256_blur_DFT_out, lena256_b_DFT, 256, 256);
	rw.write_raw_data(lena256_blur_noise_DFT_out, lena256__bn_DFT, 256, 256);

	rw.write_raw_data(lena256_blur_inverse_flter__No_r_out, lena_256_b_Inverse_filter_NoR, 256, 256);
	rw.write_raw_data(lena256_blur_inverse_flter_15_out, lena_256_b_Inverse_filter_15, 256, 256);
	rw.write_raw_data(lena256_blur_inverse_flter_20_out, lena_256_b_Inverse_filter_30, 256, 256);
	rw.write_raw_data(lena256_blur_inverse_flter_25_out, lena_256_b_Inverse_filter_40, 256, 256);
	rw.write_raw_data(lena256_blur_noise_inverse_flter__No_r_out, lena_256_bn_Inverse_filter_NoR, 256, 256);
	rw.write_raw_data(lena256_blur_noise_inverse_flter_15_out, lena_256_bn_Inverse_filter_15, 256, 256);
	rw.write_raw_data(lena256_blur_noise_inverse_flter_20_out, lena_256_bn_Inverse_filter_30, 256, 256);
	rw.write_raw_data(lena256_blur_noise_inverse_flter_25_out, lena_256_bn_Inverse_filter_40, 256, 256);
}
void hw::HW2_2()
{

	rw rw;
	hw6 hw6;
	char lena256[] = "lena_256.raw";
	char lena256_blur[] = "lena_256_blur.raw";
	char lena256_blur_noise[] = "lena_256_blur_noise.raw";
	
	char lena256_blur_wiener_flter_1[]= "(2_2)lena256_blur_wiener_flter_005.raw";
	char lena256_blur_wiener_flter_10[] = "(2_2)lena256_blur_wiener_flter_001.raw";
	char lena256_blur_wiener_flter_20[] = "(2_2)lena256_blur_wiener_flter_01.raw";
	char lena256_blur_n_wiener_flter_1[] = "(2_2)lena256_blur_noise_wiener_flter_005.raw";
	char lena256_blur_n_wiener_flter_10[] = "(2_2)lena256_blur_noise_wiener_flter_001.raw";
	char lena256_blur_n_wiener_flter_20[] = "(2_2)lena256_blur_noise_wiener_flter_01.raw";

	double* real = new double[256 * 256];
	double* imagine = new double[256 * 256];
	long double* blur_real = new long double[256 * 256];
	long double* blur_imagine = new long double[256 * 256];

	unsigned char* lena_256 = rw.read_Raw_data(lena256, 256, 256);
	unsigned char* lena_256_b = rw.read_Raw_data(lena256_blur, 256, 256);
	unsigned char* lena_256_b_n = rw.read_Raw_data(lena256_blur_noise, 256, 256);

	hw6.Motion_blur_IID_DFT(256, 256, 0.07, -0.07, 1, blur_real, blur_imagine);
	unsigned char* lena256_b_DFT = hw6.IID_DFT(lena_256_b, 256, 256, real, imagine);
	unsigned char* lena_256_b_wiener_filter1 = hw6.Weiner_Filter(real, imagine, blur_real, blur_imagine, 256, 256, 0.05);
	unsigned char* lena_256_b_wiener_filter10 = hw6.Weiner_Filter(real, imagine, blur_real, blur_imagine, 256, 256, 0.01);
	unsigned char* lena_256_b_wiener_filter20 = hw6.Weiner_Filter(real, imagine, blur_real, blur_imagine, 256, 256, 0.1);

	unsigned char* lena256__bn_DFT = hw6.IID_DFT(lena_256_b_n, 256, 256, real, imagine);
	unsigned char* lena_256_bn_wiener_filter1 = hw6.Weiner_Filter(real, imagine, blur_real, blur_imagine, 256, 256, 0.05);
	unsigned char* lena_256_bn_wiener_filter10 = hw6.Weiner_Filter(real, imagine, blur_real, blur_imagine, 256, 256, 0.01);
	unsigned char* lena_256_bn_wiener_filter20 = hw6.Weiner_Filter(real, imagine, blur_real, blur_imagine, 256, 256, 0.1);
	
	rw.write_raw_data(lena256_blur_wiener_flter_1, lena_256_b_wiener_filter1, 256, 256);
	rw.write_raw_data(lena256_blur_wiener_flter_10, lena_256_b_wiener_filter10, 256, 256);
	rw.write_raw_data(lena256_blur_wiener_flter_20, lena_256_b_wiener_filter20, 256, 256);
	rw.write_raw_data(lena256_blur_n_wiener_flter_1, lena_256_bn_wiener_filter1, 256, 256);
	rw.write_raw_data(lena256_blur_n_wiener_flter_10, lena_256_bn_wiener_filter10, 256, 256);
	rw.write_raw_data(lena256_blur_n_wiener_flter_20, lena_256_bn_wiener_filter20, 256, 256);
}
void hw::HW2_3()
{
	rw rw;
	hw6 hw6;
	char lena256[] = "lena_256.raw";
	char lena256_blur[] = "lena_256_blur.raw";
	char lena256_blur_noise[] = "lena_256_blur_noise.raw";

	char lena256_blur_CLSF1[] = "(2_3)lena256_blur_CLSF_1.raw";
	char lena256_blur_CLSF2[] = "(2_3)lena256_blur_CLSF_2.raw";
	char lena256_blur_CLSF3[] = "(2_3)lena256_blur_CLSF_3.raw";
	char lena256_blur_noise_CLSF1[] = "(2_3)lena256_blur_noise_CLSF_1.raw";
	char lena256_blur_noise_CLSF2[] = "(2_3)lena256_blur_noise_CLSF_2.raw";
	char lena256_blur_noise_CLSF3[] = "(2_3)lena256_blur_noise_CLSF_3.raw";

	double* real = new double[256 * 256];
	double* imagine = new double[256 * 256];
	long double* blur_real = new long double[256 * 256];
	long double* blur_imagine = new long double[256 * 256];

	unsigned char* lena_256 = rw.read_Raw_data(lena256, 256, 256);
	unsigned char* lena_256_b = rw.read_Raw_data(lena256_blur, 256, 256);
	unsigned char* lena_256_b_n = rw.read_Raw_data(lena256_blur_noise, 256, 256);

	hw6.Motion_blur_IID_DFT(256, 256, 0.07, -0.07, 1, blur_real, blur_imagine);
	unsigned char* lena256_b_DFT = hw6.IID_DFT(lena_256_b, 256, 256, real, imagine);
	unsigned char* lena_256_b_CLSF1 = hw6.Constrained_Least_Squares_Filtering(real, imagine, blur_real, blur_imagine, 256, 256, 0.01);
	unsigned char* lena_256_b_CLSF2 = hw6.Constrained_Least_Squares_Filtering(real, imagine, blur_real, blur_imagine, 256, 256, 0.5);
	unsigned char* lena_256_b_CLSF3 = hw6.Constrained_Least_Squares_Filtering(real, imagine, blur_real, blur_imagine, 256, 256, 10);

	unsigned char* lena256__bn_DFT = hw6.IID_DFT(lena_256_b_n, 256, 256, real, imagine);
	unsigned char* lena_256_bn_CLSF1 = hw6.Constrained_Least_Squares_Filtering(real, imagine, blur_real, blur_imagine, 256, 256, 0.01);
	unsigned char* lena_256_bn_CLSF2 = hw6.Constrained_Least_Squares_Filtering(real, imagine, blur_real, blur_imagine, 256, 256, 0.5);
	unsigned char* lena_256_bn_CLSF3 = hw6.Constrained_Least_Squares_Filtering(real, imagine, blur_real, blur_imagine, 256, 256, 10);

	rw.write_raw_data(lena256_blur_CLSF1, lena_256_b_CLSF1, 256, 256);
	rw.write_raw_data(lena256_blur_CLSF2, lena_256_b_CLSF2, 256, 256);
	rw.write_raw_data(lena256_blur_CLSF3, lena_256_b_CLSF3, 256, 256);
	rw.write_raw_data(lena256_blur_noise_CLSF1, lena_256_bn_CLSF1, 256, 256);
	rw.write_raw_data(lena256_blur_noise_CLSF2, lena_256_bn_CLSF2, 256, 256);
	rw.write_raw_data(lena256_blur_noise_CLSF3, lena_256_bn_CLSF3, 256, 256);
}
void hw::HW3_1()
{
	rw rw;
	hw6 hw6;
	char chessboard_distorted_256[] = "chessboard_distorted_256.raw";
	char chessboard[] = "chessboard_256.raw";
	char cat_distorted_256[] = "cat_distorted_256.raw";

	char test[] = "(3)chessboard_edge.raw";
	char test2[] = "(3)chessboard_re.raw";
	char cat_restore_256[] = "(3)cat_256.raw";

	unsigned char* chessboard256d = rw.read_Raw_data(chessboard_distorted_256, 256, 256);
	unsigned char* chessboard256 = rw.read_Raw_data(chessboard, 256, 256);
	unsigned char* cat256d = rw.read_Raw_data(cat_distorted_256, 256, 256);
	
	unsigned char* chessboard256d_edge = hw6.contour_detect(chessboard256d, 256, 256);
	unsigned char* chessboard_re = hw6.warping_relationship(chessboard256d, 256, 256);
	unsigned char* cat_256 = hw6.warping_relationship(cat256d, 256, 256);
	
	rw.write_raw_data(test, chessboard256d_edge, 256, 256);
	rw.write_raw_data(test2, chessboard_re, 256, 256);
	rw.write_raw_data(cat_restore_256, cat_256, 256, 256);
}