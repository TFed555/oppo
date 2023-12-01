#include "Data.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "Exception.h"

using namespace std;

Data::Data() : dd{ 18 }, mm{ 02 }, yyyy{ 1995 }
{}

Data::Data(int day, int month, int year)
{
	valid_data(day, month, year);
	dd = day;
	mm = month;
	yyyy = year;
}

void Data::print(std::ostream& ost) {
	if (dd < 10 && mm >=10) {
		string d = "0" + to_string(dd);
		ost << d << "/" << mm << "/" << yyyy;
	}
	else if (mm < 10&&dd>=10) {
		string m = "0" + to_string(mm);
		ost << dd << "/" << m << "/" << yyyy;
	}
	else if (mm < 10 && dd < 10) {
		string d = "0" + to_string(dd);
		string m = "0" + to_string(mm);
		ost << d << "/" << m << "/" << yyyy;
	}
	else {
		ost << dd << "/" << mm << "/" << yyyy;
	}
}

void Data::valid_data(int d, int m, int y) {
	int mas[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (y % 4 == 0 || y%400==0) {
		mas[1] = 29;
	}
	int i = m - 1;
	if (d > mas[i]||d == 0||m>12||m<1) throw Exception{"Wrong format"};
}

void Data::load(std::istream& ist) {
	ist.exceptions(ios_base::failbit);

	int day{ 0 }, month{ 0 }, year{ 0 };

	try {
		ist >> day;
		char dot = ist.get();
		if (dot != '.') {
			throw Exception{ std::string("Wrong format '") + dot + "'"};
		}
		ist >> month;
		dot = ist.get();
		if (dot != '.') {
			throw Exception{ std::string("Wrong format '") + dot + "'" };
		}
		ist >> year;
	}
	catch (std::ios_base::failure) {
		throw Exception{"Wrong date"};
	}

	Data::valid_data(day, month, year);
	dd = day;
	mm = month;
	yyyy = year;
}
