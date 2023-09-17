#include "Estate.h"
#include "Data.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void Estate::load(std::ifstream& ist) {
	ist >> this->host;
	this->date.load(ist);
	ist >> this->cost;
}

void Estate::print(std::ostream& ost) {
	ost << this->host<<" ";
	this->date.print();
	ost << " ";
	ost << this->cost << endl;
}