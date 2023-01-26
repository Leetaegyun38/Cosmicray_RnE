#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>

int time_info[10][10]; //세로, 가로
//int ch2_data[110][1000];
//int ch3_data[110][1000];
int temp[7];// index, ch1, ch2, ch3, ch4
int old_temp[7]; //
double average_ch2;
double average_ch3;
long double integral_ch2[100000000];
long double integral_ch3[100000000];
FILE* fpData;
errno_t err;
char filename[50];

FILE* fp_ch2;
FILE* fp_ch3;
FILE* fp_integral_ch2;
FILE* fp_integral_ch3;

errno_t err_ch2;
errno_t err_ch3;
errno_t err_integral_ch2;
errno_t err_integral_ch3;

//char filename_ch2[15] = { "ch2_"};
//char filename_ch3[15] = {"ch3_"};

int number_of_particle;

void Fill_array(int* data, int* copy) // data -> copy 로 복사
{
	for (int i = 0; i < 5; i++)
		*(data + i) = *(copy + i);

}

int exp(int n)
{
	int temp = 1;
	for (int i = 0; i < n; i++)
		temp = temp * 10;

	return temp;
}

int main(void)
{
	printf("데이터를 복붙 하세요\n");
	err_ch2 = fopen(&fp_ch2, "ch2.txt", "w");
	err_ch3 = fopen_s(&fp_ch3, "ch3.txt", "w");
	err_integral_ch2 = fopen_s(&fp_integral_ch2, "integral_ch2.txt", "w");
	err_integral_ch3 = fopen_s(&fp_integral_ch3, "integral_ch3.txt", "w");

	if (err_ch3 == 0 && fp_ch2 != 0 && err_ch3 == 0 && fp_ch3 != 0 && err_integral_ch2 == 0 && fp_integral_ch2 != 0 && err_integral_ch3 == 0 && fp_integral_ch3 != 0)
	{
		fclose(fp_ch2);
		fclose(fp_ch3);
		fclose(fp_integral_ch2);
		fclose(fp_integral_ch3);
	}
	
		err_ch2 = fopen_s(&fp_ch2, "ch2.txt", "a");
		err_ch3 = fopen_s(&fp_ch3, "ch3.txt", "a");
		err_integral_ch2 = fopen_s(&fp_integral_ch2, "integral_ch2.txt", "a");
		err_integral_ch3 = fopen_s(&fp_integral_ch3, "integral_ch3.txt", "a");

		if (err_ch3 == 0 && fp_ch2 != 0 && err_ch3 == 0 && fp_ch3 != 0 && err_integral_ch2 == 0 && fp_integral_ch2 != 0 && err_integral_ch3 == 0 && fp_integral_ch3 != 0)
		{
			while (1)
			{
				if (number_of_particle >= 100000000)
					break;

				scanf("%d %d  %d %d %d", &temp[0], &temp[1], &temp[2], &temp[3], &temp[4]);
				Fill_array(temp, time_info[0]);

				for (int i = 1; i <= 7; i++)
				{
					scanf_s("%d %d %d %d %d", &temp[0], &temp[1], &temp[2], &temp[3], &temp[4]);
					Fill_array(temp, time_info[i]);
				}

				for (int i = 0; i < 94; i++)
				{
					scanf_s("%d %d %d %d %d", &temp[0], &temp[1], &temp[2], &temp[3], &temp[4]);

					average_ch2 = ((long double)temp[2] + (long double)old_temp[2]) / 2.0;
					integral_ch2[number_of_particle] = integral_ch2[number_of_particle] + average_ch2 * 10.0;
					integral_ch3[number_of_particle] = integral_ch3[number_of_particle] + average_ch3 * 10.0;

					for (int i = 0; i < 5; i++)
						old_temp[i] = temp[i];


					//ch2_data[i][number_of_particle] = temp[2];
					//ch3_data[i][number_of_particle] = temp[3];
					fprintf(fp_ch2, "%d,", temp[2]);
					fprintf(fp_ch3, "%d,", temp[3]);
				}

				fprintf(fp_ch2, "\n");
				fprintf(fp_ch3, "\n");

				fprintf(fp_integral_ch2, "%lf\n", integral_ch2[number_of_particle]);
				fprintf(fp_integral_ch3, "%lf\n", integral_ch3[number_of_particle]);

				number_of_particle++;
			}
/*
			for (int i = 0; i < number_of_particle; i++)
			{
				for (int j = 0; j < 101; j++)
				{
					fprintf(fp_ch2, "%d,", ch2_data[j][i]);
					fprintf(fp_ch3, "%d,", ch3_data[j][i]);
				}
				fprintf(fp_ch2,"\n");
				fprintf(fp_ch3, "\n");
			}
*/
			printf("program end");

			fclose(fp_ch2);
			fclose(fp_ch3);
			fclose(fp_integral_ch2);
			fclose(fp_integral_ch3);
		}
		else
			printf("fail to create data file!!");

	
	return 0;
}
