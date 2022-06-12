#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Misha\source\repos\6.7 oop\6.7 oop\6.7 oop.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int x = 10;
			int a[x];
			for (int i = 0; i < x; i++)
			{
				a[i] = i;
			}
			int b[x * 3];
			Predicate<int>* even = new Even<int>();
			int n = replace_if(&a[0], &a[x], &b[0], *even);
			Assert::AreEqual(5, n);
		}
	};
}
