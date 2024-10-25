#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\HP\source\repos\lab 7.1 itr\lab 7.1 itr\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int rowCount = 3;
            const int colCount = 3;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            // Створюємо матрицю вручну
            a[0][0] = 5; a[0][1] = 2; a[0][2] = 7;
            a[1][0] = 9; a[1][1] = 3; a[1][2] = 8;
            a[2][0] = 4; a[2][1] = 6; a[2][2] = 10;

            int S = 0, k = 0;
            Calc(a, rowCount, colCount, S, k);

            // Перевіряємо суму і кількість
            Assert::AreEqual(28, S);  // Очікувана сума
            Assert::AreEqual(5, k);   // Очікувана кількість елементів

           
            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;

		}
	};
}
