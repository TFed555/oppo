#include <iostream>
#include <clocale>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct estate {
	string host;
	int dd, mm, yyyy;
	int cost;
};

int main() {
	ifstream ist("1.txt");

	vector<estate> ests;
	
	while (!ist.eof()) {
	    estate obj;
	    
		ist >> obj.host;
		ist >> obj.dd;
		ist.get();
		ist >> obj.mm;
	    ist.get();
		ist >> obj.yyyy;
		ist >> obj.cost;
		
		ests.push_back(obj);
	}

	for (int i = 0; i < ests.size(); i++) {
		cout << ests[i].host<<" ";
		cout << ests[i].dd << "." << ests[i].mm << "." << ests[i].yyyy<< " ";
		cout << ests[i].cost;
		cout<< endl;
	}

}