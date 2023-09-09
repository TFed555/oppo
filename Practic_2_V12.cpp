#include <iostream>
#include <clocale>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
//Вариант 12

struct Data {
	int dd, mm, yyyy;
	void load(std::ifstream& ist);
	void print();
};

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

struct Estate {
	string host;
	int cost;
	Data date;
};

void load(std::ifstream &ist, vector<Estate> &ests, vector<Data> &date) {
	while (!ist.eof()) {
		Estate obj;
		Data obj1;
		ist >> obj.host;
		obj1.load(ist);
		ist >> obj.cost;
		ests.push_back(obj);
		date.push_back(obj1);
	}
}

void print_data(vector<Estate>& ests, vector<Data>& date) {
	for (int i = 0; i < ests.size(); i++) {
		cout << ests[i].host << " ";
		date[i].print();
		cout << " ";
		cout << ests[i].cost;
		cout << endl;
	}
}

int main() {
	ifstream ist("1.txt");
	vector<Estate> ests;
	vector<Data> date;
	load(ist, ests, date);
	print_data(ests, date);
}