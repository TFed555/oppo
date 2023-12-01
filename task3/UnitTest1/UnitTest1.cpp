#include "CppUnitTest.h"
#include "../ConsoleApplication5/Estate.h"
#include "../ConsoleApplication5/Data.h"
#include <vector>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		//тест корректности ввода даты, правильные даты
		TEST_METHOD(correctDataTest)
		{
			const auto f = [&](std::vector<size_t*>& cases) {
				for (size_t i = 0; i < cases.size(); i++) {
					try {
						size_t* arr = cases.at(i);
						Data date(arr[0], arr[1], arr[2]);
					}
					catch (...) {
						Assert::Fail();
					}
				}
			};
			std::vector<size_t*> cases;
			size_t* arr = new size_t[3];
			arr[0] = 19; arr[1] = 2; arr[2] = 2023;
			cases.push_back(arr);
			arr = new size_t[3];
			arr[0] = 22; arr[1] = 8; arr[2] = 1990;
			cases.push_back(arr);
			arr = new size_t[3];
			arr[0] = 29; arr[1] = 2; arr[2] = 2020;
			cases.push_back(arr);
			f(cases);
		}
		//тест корректности ввода даты, неправильные даты
		TEST_METHOD(incorrectDataTest)
		{
			const auto f = [&](std::vector<size_t*>& cases) {
				for (size_t i = 0; i < cases.size(); i++) {
					try {
						size_t* arr = cases.at(i);
						Data date(arr[0],arr[1],arr[2]);
						Assert::Fail();	
						delete arr;
					}
					catch (...) {
						
					}
				}
			};
			std::vector<size_t*> cases;
			size_t* arr = new size_t[3];
			arr[0] = 29; arr[1] = 2; arr[2] = 2023;
			cases.push_back(arr);
			arr = new size_t[3];
			arr[0] = 31; arr[1] = 9; arr[2] = 1990;
			cases.push_back(arr);
			arr = new size_t[3];
			arr[0] = 0; arr[1] = 13; arr[2] = 1990;
			cases.push_back(arr);
			f(cases);
		}
		//тест корректности ввода имени владельца / правильные имена
		TEST_METHOD(correctHostTest)
		{
			const auto f = [&](std::vector<string*>& cases) {
				for (size_t i = 0; i < cases.size(); i++) {
					try {
						string* arr = cases.at(i);
						Estate est(arr[0], 0);
					}
					catch (...) {
						Assert::Fail();
					}
				}
			};
			
			std::vector<string*> cases;
			string* arr = new string[1];
			arr[0] = "Alex";
			cases.push_back(arr);
			arr = new string[1];
			arr[0] = "Greg";
			cases.push_back(arr);
			f(cases);
		}
		////тест корректности ввода имени владельца / неправильные имена
		TEST_METHOD(incorrectHostTest)
		{
			const auto f = [&](std::vector<string*>& cases) {
				for (size_t i = 0; i < cases.size(); i++) {
					try {
						string* arr = cases.at(i);
						Estate est(arr[0], 0);
						Assert::Fail();
						delete arr;
					}
					catch (...) {

					}
				}
			};
			std::vector<string*> cases;
			string* arr = new string[1];
			arr[0] = "A1ex";
			cases.push_back(arr);
			arr = new string[1];
			arr[0] = "Gre10";
			cases.push_back(arr);
			f(cases);
		}
		//тест корректности ввода цены / пр значения
		TEST_METHOD(correctCostTest) {
			const auto f = [&](std::vector<int*>& cases) {
				for (size_t i = 0; i < cases.size(); i++) {
					try {
						int* arr = cases.at(i);
						Estate est("",arr[0]);
						delete arr;
					}
					catch (...) {
						Assert::Fail();
					}
				}
			};
			std::vector<int*> cases;
			int* arr = new int[1];
			arr[0] = 1000000;
			cases.push_back(arr);
			arr = new int[1];
			arr[0] = 200000000;
			cases.push_back(arr);
			f(cases);
		}
		//тест корректности ввода цены / непр значения
		TEST_METHOD(incorrectCostTest) {
			const auto f = [&](std::vector<int*>& cases) {
				for (size_t i = 0; i < cases.size(); i++) {
					try {
						int* arr = cases.at(i);
						Estate est("", arr[0]);
						Assert::Fail();
						delete arr;
					}
					catch (...) {

					}
				}
			};
			std::vector<int*> cases;
			int* arr = new int[1];
			arr[0] = -10000000;
			cases.push_back(arr);
			arr = new int[1];
			arr[0] = -200000000;
			cases.push_back(arr);

			f(cases);
		}
		//тесты на принт
		TEST_METHOD(correctPrintDate)
		{
			Data date;
			date.set_dd(28);
			date.set_mm(05);
			date.set_yyyy(2023);
			std::string str = "28/05/2023";
			std::stringstream sout;
			date.print(sout);
			Assert::AreEqual(str, sout.str());
		}
		TEST_METHOD(correctPrintEstate)
		{
			Data d;
			Estate est("Oleg", 2000000);
			vector<Estate> vec;
			std::string str = "Oleg 27/01/2005 2000000\n";
			std::stringstream sout;
			d.set_dd(27);
			d.set_mm(1);
			d.set_yyyy(2005);
			est.set_date(d);
			est.print(sout);
			Assert::AreEqual(str, sout.str());
		}
		TEST_METHOD(incorrectPrintDate)
		{
			Data date;
			date.set_dd(28);
			date.set_mm(05);
			date.set_yyyy(2023);
			std::string str = "29/05/2023";
			std::stringstream sout;
			date.print(sout);
			Assert::AreNotEqual(str, sout.str());
		}
		TEST_METHOD(incorrectPrintEstate)
		{
			Estate est("Oleg", 2000000);
			Data date;
			date.set_dd(27);
			date.set_mm(01);
			date.set_yyyy(2005);
			est.set_date(date);
			std::string str = "Oleg 27/01/2005 200000\n";
			std::stringstream sout;
			est.print(sout);
			Assert::AreNotEqual(str, sout.str());
		}
		//тесты методов валидности
		TEST_METHOD(validDate)
		{
			Data d;
			d.valid_data(12,04,2023);
		}
		TEST_METHOD(invalidDate)
		{
			Data date;
			try {
				date.valid_data(12, 04, 2023);
			}
			catch (const std::runtime_error& mes) {
				return;
			}
			Assert::Fail;
		}
		TEST_METHOD(validHost)
		{
			Estate h;
			h.valid_host_format("Alex");
		}
		TEST_METHOD(invalidHost) {
			Estate h;
			try {
				h.valid_host_format("A6p");
			}
			catch (const std::runtime_error& mes) {
				return;
			}
			Assert::Fail;
		}
		TEST_METHOD(validCost)
		{
			Estate h;
			h.valid_cost_format(100000);
		}
		TEST_METHOD(invalidCost) {
			Estate h;
			try {
				h.valid_cost_format(-502399980);
			}
			catch (const std::runtime_error& mes) {
				return;
			}
			Assert::Fail;
		}
	};
}
