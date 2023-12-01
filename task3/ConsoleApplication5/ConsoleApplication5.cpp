#include <iostream>
#include <clocale>
#include <string>
#include <fstream>
#include <vector>
#include "Data.h"
#include "Estate.h"
#include "Exception.h"
using namespace std;
//Вариант 12

vector<Estate> loadestd(istream& ist) {
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
	if (!ist.is_open())
	{
		cout << "Файл не открыт";
		return 1;
	}
	vector<Estate> ests;
	try {
		ests = loadestd(ist);
		print_estates(ests);
	}
	catch (Exception& except) {
		cerr << except.what();
	}
}