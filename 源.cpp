#include <iostream>
#include <string>
#include <fstream>
#include<stdio.h>
#include<opencv2/opencv.hpp>
#include<vector>
using namespace std;
const int rows = 281;             //define the size of Mat variable
const int cols = 361;
using namespace cv;
void f_get(FILE* fp,string s1);
int main()
{
	for (int dat_i = 0; dat_i <=4380; dat_i++) {

		char inputpath0[100] = "F:\\5canshu0\\data_anal_";
		char temp_dat_i[20];
		_itoa(dat_i, temp_dat_i, 10);
		char temp_txt[10] = ".txt";
		strcat(inputpath0, temp_dat_i);
		strcat(inputpath0, temp_txt);

		char inputpath1[100] = "F:\\5canshu1\\canshu";
		strcat(inputpath1, temp_dat_i);
		strcat(inputpath1, temp_txt);

		char outputpath[100] = "F:\\5canshu\\data_anal_";
		strcat(outputpath, temp_dat_i);
		strcat(outputpath, temp_txt);
		string s0, s1;
		ifstream fp0(inputpath0);
		ifstream fp1(inputpath1);
		if (!fp0 || !fp1)
		{
			continue;
		}
		FILE *fp =fopen(outputpath,"w");      //saveroute
		while (getline(fp0, s0))          //get a line of datas then ergodic and chartofloat
		{
			char buffer0[20];
			memset(buffer0, 0, 20);
			int pos0 = 0;
			int count_0 = 0;
			int len_s0 = s0.length();
			for (int i = 0; i < len_s0; i++) {
				if (s0[i] != ' ') {
					buffer0[pos0++] = s0[i];
					if (i == len_s0 - 1 || s0[i + 1] == ' ') {
						if (count_0 == 0) {
							fprintf(fp, "%s  ", buffer0);
							memset(buffer0, 0, 20);
							getline(fp1, s1);
							f_get(fp,s1);
						}
						else if(count_0>5){
							fprintf(fp, "%s  ", buffer0);
							memset(buffer0, 0, 20);
						}
						memset(buffer0, 0, 20);
						count_0++;
						pos0 = 0;
						}
					}
				}
			fprintf(fp, "\n");
			}
		fclose(fp);
		}
			
	

	return 0;
}
