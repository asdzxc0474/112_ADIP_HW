#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include"hw.h"

int main()
{
	hw hw;
	int a = 0;
	bool flag = false;
	while (true)
	{	
		printf("1:1_1 answer \n2:1_2 answer\n3:1_3 answer\n4:1_4 answer\n5:1_5 answer\n6:2_1 answer\n7:2_2 answer\n8:2_3 answer\n9:  3 answer\n10: 4 answer\n99: quit\n");
		printf("Enter the question number to select output result :");
		scanf("%d", &a);
		printf("\n");
	
		switch (a)
		{
		case 1:
			hw.HW1_1();
			break;

		case 2:
			hw.HW1_2();
			break;

		case 3:
			hw.HW1_3();
			break;

		case 4:
			hw.HW1_4();
			break;

		case 5:
			hw.HW1_5();
			break;

		case 6:
			hw.HW2_1();
			break;

		case 7:
			hw.HW2_2();
			break;

		case 8:
			hw.HW2_3();
			break;

		case 9:
			hw.HW3();
			break;

		case 10:
			hw.HW4();
			break;
		
		case 99:
			flag = true;
			exit;
		}
		if (flag)
		{
			break;
		}
	}
}