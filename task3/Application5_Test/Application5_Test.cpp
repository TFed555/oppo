#include "pch.h"
#include "CppUnitTest.h"
//#include "..\ConsoleApplication5\Estate.h"
#include "..\ConsoleApplication5\Data.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Application5Test
{
	TEST_CLASS(Application5Test)
	{
	public:
		//���� ������������ ����� ���� / ���������� ����
		TEST_METHOD(correctDataTest)
		{
			std::vector<int[3]> cases{
				{ 29, 2, 2020 },
				{ 28, 2, 2022 },
				{ 1, 5, 1995 },
			};

			for (int i = 0; i < cases.size(); ++i) 
			{
				try {
					Data date(cases[i][0], cases[i][1], cases[i][2]);
				}
				catch (...) {
					Assert::Fail();
				}
			}

		}
		//���� ������������ ����� ���� / ������������ ����	
		TEST_METHOD(incorrectDataTest)
		{

			std::vector<int[3]> cases{
				{ 29, 2, 2023 },
				{ 32, 3, 2022 },
				{ 0, 0, 0 },
			};

			for (int i = 0; i < cases.size(); ++i)
			{

				try {
					Data date(cases[i][0], cases[i][1], cases[i][2]);
					Assert::Fail();
				}
				catch (...) {
				}
			}

		}

		//���� ������������ ����� ��������� ������������
		TEST_METHOD(correctEstateTest)
		{
			Estate est;
			est.set_host("A1ex");

			est.valid_host_format();
		}
		//���� ������������ ����� ���� ������������
		TEST_METHOD(correctCostTest)
		{
			Estate est;
			est.set_cost(-2000);

			est.valid_cost_format();
		}

		//
		TEST_METHOD(correctDataPrintTest)
		{
			Data date;
			date.Data(31, 11, 2023);
			std::string t = "31/11/2023";
			std::stringstream out;
			date.print(out);
			Assert::AreEqual(t, out.str());
		}
	};
}
