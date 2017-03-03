
#include <iostream>
#include <string>
#include <fstream>
#include<stdio.h>
#include<opencv2/opencv.hpp>
#include<vector>
using namespace std;
void f_get(FILE *fp,string s1)
{
	char buffer1[20];
	memset(buffer1, 0, 20);
	int pos1 = 0;
	int len_s1 = s1.length();
	for (int ii = 0; ii < len_s1; ii++) {
		if (s1[ii] != ' ') {
			buffer1[pos1++] = s1[ii];
			if (ii == len_s1 - 1 || s1[ii + 1] == ' ') {
				fprintf(fp, "%s  ", buffer1);
				pos1 = 0;
				memset(buffer1, 0, 20);
			}
		}
	}
}