#pragma once
#include <iostream>
#include <fstream>
using namespace std;
struct Data
{
	int dd, mm, yyyy;
	void load(std::ifstream& ist);
	void print();
};

