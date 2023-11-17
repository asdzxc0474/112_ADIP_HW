#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include"HWclass.h"

int main(void) {
	int num = 0;
	HW hw;
	printf("1:1_2a answer \n2:1_2b answer\n3:1_2c answer\n4:1_2d answer\n5:1_3a answer\n6:1_3b answer\n7:2_b answer");
	printf("\n\n\nEnter the question number to select output result : ");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		hw.HW1_2a();
		break;
	case 2:
		hw.HW1_2b();
		printf("Done! \nImage have save to lena256out.raw\n");
		break;
	case 3:
		hw.HW1_2c();
		printf("Done! \nImage have save to (1_2c)lena256out.raw\n");
		break;
	case 4:
		hw.HW1_2d();
		printf("Done! \nImage have save to (1_2d)lena256out.raw\n");
		break;
	case 5:
		hw.HW1_3a();
		printf("Done! \nImage have save to (1_3a)lena256out.raw\n");
		break;
	case 6:
		hw.HW1_3b();
		printf("Done! \nImage have save to (1_3b)lena256out.raw\n");
		break;
	case 7:
		hw.HW2_b();
		printf("\n\nDone! \nImage have save to doraemon.png\n");
		break;
	}
}