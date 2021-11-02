#include "pch.h"
#include "CppUnitTest.h"
#include "..\Calculator\Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace CalcF;



namespace Test
{
	TEST_CLASS(Divide)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(CalcF::divF(1, 2), 0.5);
		}
		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(CalcF::divF(125, 5), 25.);
		}
		TEST_METHOD(TestMethod3)
		{
			Assert::IsTrue(isinf(CalcF::divF(1, 0)));
		}
	};
	TEST_CLASS(Multiply)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(CalcF::multF(1, 2), 2.);
		}
		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(CalcF::multF(2, .1), .2);
		}
		TEST_METHOD(TestMethod3)
		{
			Assert::AreEqual(CalcF::multF(-5, .5), -2.5);
		}
	};
	TEST_CLASS(Substract)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(CalcF::subF(2, 5), -3.);
		}
		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(CalcF::subF(5, -2), 7.);
		}
		TEST_METHOD(TestMethod3)
		{
			Assert::AreEqual(CalcF::subF(-5, 2), -7.);
		}
	};
	TEST_CLASS(Plus)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(CalcF::plusF(2, 2), 4.);
		}
		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(CalcF::plusF(-2, -2), -4.);
		}
		TEST_METHOD(TestMethod3)
		{
			Assert::AreEqual(CalcF::plusF(2, -2), 0.);
		}
	};
	TEST_CLASS(Xx)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(CalcF::xF(2), 4.);
		}
		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(CalcF::xF(-2), 4.);
		}
		TEST_METHOD(TestMethod3)
		{
			Assert::AreEqual(CalcF::xF(11), 121.);
		}
	};
	TEST_CLASS(Sqrt)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(CalcF::sF(25), 5.);
		}
		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(CalcF::sF(1), 1.);
		}
		TEST_METHOD(TestMethod3)
		{
			Assert::IsTrue(isnan(CalcF::sF(-1)));
		}
	};
	TEST_CLASS(LN)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Assert::IsTrue(CalcF::lnF(2.718281828) > 0.999999 && CalcF::lnF(2.718281828) < 1.000001);
		}
		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(CalcF::lnF(1), 0.);
		}
		TEST_METHOD(TestMethod3)
		{
			Assert::IsTrue(isinf(CalcF::lnF(0)));
		}
		TEST_METHOD(TestMethod4)
		{
			Assert::IsTrue(isnan(CalcF::lnF(-1)));
		}
	};
	TEST_CLASS(Log10)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(CalcF::lgF(1000), 3.);
		}
		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(CalcF::lgF(10), 1.);
		}
		TEST_METHOD(TestMethod3)
		{
			Assert::AreEqual(CalcF::lgF(1), 0.);
		}
		TEST_METHOD(TestMethod4)
		{
			Assert::IsTrue(isinf(CalcF::lgF(0)));
		}
	};
}
