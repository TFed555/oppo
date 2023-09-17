#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Data.h"
using namespace std;
struct Estate
{
	string host;
	int cost;
	Data date;
	void load(std::ifstream& ist);
	void print(std::ostream& ost);
};

