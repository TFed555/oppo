#include "Estate.h"
#include "Data.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <clocale>
#include "Exception.h"
using namespace std;

Estate::Estate() : host{ "" }, cost{ 0 }, date{}
{}

Estate::Estate(string h, int c) {
	valid_host_format(h);
	valid_cost_format(c);
	host = h;
	cost = c;
}

void Estate::load(std::istream& ist) {
	ist.exceptions(ios_base::failbit);
	string h{ "" };
	int c{ 0 };
	try {
		ist >> h;
		date.load(ist);
		ist >> c;
	}
	catch (std::ios_base::failure) {
		throw Exception{ "Wrong date" };
	}
	Estate::valid_host_format(h);
	Estate::valid_cost_format(c);
	host = h;
	cost = c;
}


void Estate::valid_host_format(string h) {
	string t = h;
	for (char c : t) {
		if (!(c >= 65 && c <= 90 || c>=97 && c<=122)) {
			throw Exception{ std::string("Wrong symbol '") + c + "'" + " in " + "'" + t + "'"};
		}
	}

}

void Estate::valid_cost_format(int c) {
	int t = c;
	if (c < 0) {
		throw Exception{ std::string("Wrong format '") + (char)(t) + "'" };
	}

}

void Estate::print(std::ostream& ost) {
	ost << host<<" ";
	date.print(ost);
	ost << " ";
	ost << cost << endl;
}