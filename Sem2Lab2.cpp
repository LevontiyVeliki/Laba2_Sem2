#include <iostream>
#include <fstream> 
#include <stdlib.h> 
#include <iomanip>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
	ifstream fa, fa1, fa2, fa4, years, polik;
	float a, a1, a2, a4, yea;
	int cnt_0_a = 0, min_chet = 100000000, poz = 1, poz_y = 1, min_year = 1000000;
	double summ = 0;
	double proiz_a1 = 1, proiz_a2 = 1;
	int num_of_task = 1;
	string mas[23], pazient;
	cin >> num_of_task;
	switch (num_of_task) {
	case 1:
		fa.open("a.txt");
		if (fa.is_open())
		{
			while (!fa.eof())
			{
				fa >> a;
				if (a == 0) {
					cnt_0_a++;
				}
				if (a > 0) {
					summ += a;
				}
			}
			fa.close();
			cout << "Count of null ellements = " << cnt_0_a << endl;
			cout << "Summ of pozitive = " << summ << endl;
		}
		break;

	case 2:
		fa1.open("a1.txt");
		fa2.open("a2.txt");
		if (fa1.is_open() and fa2.is_open())
		{
			while (!fa1.eof())
			{
				fa1 >> a1;
				if (a1 < 0) {
					proiz_a1 *= a1;
				}
			}
			while (!fa2.eof())
			{
				fa2 >> a2;
				if (a2 < 0) {
					proiz_a2 *= a2;
				}
			}
			fa1.close();
			fa2.close();
			cout << "Composition = " << proiz_a1 * proiz_a2 << endl;
		}
		break;

	case 4:
		fa4.open("a4.txt");
		if (fa4.is_open())
		{
			while (!fa4.eof())
			{
				fa4 >> a4;
				if (a4 < min_chet and poz % 2 == 0 and a4 > 0) {
					min_chet = a4;
				}
				poz += 1;
			}
			fa4.close();
			cout << "Min = " << min_chet << endl;
		}
		break;

	case 6:
		years.open("years.txt");
		if (years.is_open())
		{
			while (!years.eof())
			{
				years >> yea;
				if (yea < min_year and poz_y % 3 == 0) {
					min_year = yea;
				}
				poz_y += 1;
			}
			years.close();
			cout << "Min year number = " << min_year << endl;
		}
		break;
	}
}
