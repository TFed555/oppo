#include <iostream>
#include <clocale>
#include <string>
#include <fstream>
#include <vector>
#include "Data.h"
#include "Estate.h"
using namespace std;
//Вариант 12

vector<Estate> loadestd(ifstream& ist) {
	vector<Estate> ests;
	Estate obj;
	int i = 0;
	while (!ist.eof()) {
		obj.load(ist);
		ests.push_back(obj);
	}
	return ests;
}
void print_estates(vector<Estate>& ests) {
	for (int i = 0; i < ests.size(); i++) {
		ests[i].print(cout);
	}
}


int main() {
	ifstream ist("1.txt");
	vector<Estate> ests;
	ests = loadestd(ist);
	print_estates(ests);
}