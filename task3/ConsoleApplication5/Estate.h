#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Data.h"
using namespace std;
class Estate
{
public:
	Estate();
	Estate(string h, int c);
	void load(std::istream& ist);
	void print(std::ostream& ost);
	//Методы изменения полей
	void set_host(string host) { this->host = host; };
	void set_cost(int cost) { this->cost = cost; };
	void set_date(Data date) { this->date = date; };
	void valid_host_format(string h);
	void valid_cost_format(int c);
private:
	string host;
	int cost;
	Data date;
};

