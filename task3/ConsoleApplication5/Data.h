#pragma once
#include <iostream>
#include <fstream>
using namespace std;
struct Data
{
	Data();
	Data(int day, int month, int year);
	void load(std::istream& ist);
	void print(std::ostream& ost);
	void valid_data(int dd, int mm, int yy);
	//методы доступа к полям
	int get_dd() const {
		return dd; 
	}
	int get_mm() const { 
		return mm;
	}
	int get_yyyy() const { 
		return yyyy;
	}
	//методы изменения полей
	void set_dd(int day) { 
		valid_data(day, 1, 1);
		dd = day;
	}
	void set_mm(int month) { 
		valid_data(1, month, 1);
		mm = month;
	}
	void set_yyyy(int year) { 
		valid_data(1, 1, year);
		yyyy = year;
	}
private:
	int dd, mm, yyyy;
};

