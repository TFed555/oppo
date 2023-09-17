#include "Data.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
void Data::print() {
	cout << this->dd << "/" << this->mm << "/" << this->yyyy;
}

void Data::load(std::ifstream& ist) {
	ist >> this->dd;
	ist.get();
	ist >> this->mm;
	ist.get();
	ist >> this->yyyy;
}
