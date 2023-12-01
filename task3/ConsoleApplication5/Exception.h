#pragma once
#include <string>
#include <stdexcept>
using namespace std;
class Exception : public std::runtime_error
{
	using std::runtime_error::runtime_error;
};
