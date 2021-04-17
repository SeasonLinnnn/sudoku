#include "pch.h"
#include "CppUnitTest.h"
#include "../sudoku/sudoku.h"
#include "../sudoku/sudoku.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			sudoku sudo;
			int matrix[9][9] =
			{
				1,2,3,4,5,6,7,8,9,
				4,5,6,7,8,9,1,2,0,
				7,8,9,0,2,3,0,5,6,
				0,3,4,5,0,7,8,0,1,
				5,0,7,8,0,1,2,3,0,
				8,9,0,2,3,0,5,6,0,
				3,4,5,0,7,8,0,1,2,
				0,7,8,0,1,2,3,0,5,
				9,0,2,3,0,5,6,7,0
			};
			sudo.dfs(0, 0, 0, matrix);
			Assert::AreEqual(1, matrix[2][3]);
			Assert::AreEqual(4, matrix[2][6]);
			Assert::AreEqual(2, matrix[3][0]);
			Assert::AreEqual(6, matrix[3][4]);
			Assert::AreEqual(9, matrix[3][7]);
			Assert::AreEqual(6, matrix[4][1]);
			Assert::AreEqual(9, matrix[4][4]);
			Assert::AreEqual(4, matrix[4][8]);
			Assert::AreEqual(1, matrix[5][2]);
			Assert::AreEqual(4, matrix[5][5]);
			Assert::AreEqual(7, matrix[5][8]);
			Assert::AreEqual(6, matrix[6][3]);
			Assert::AreEqual(9, matrix[6][6]);
			Assert::AreEqual(6, matrix[7][0]);
			Assert::AreEqual(9, matrix[7][3]);
			Assert::AreEqual(4, matrix[7][7]);
			Assert::AreEqual(1, matrix[8][1]);
			Assert::AreEqual(4, matrix[8][4]);
			Assert::AreEqual(8, matrix[8][8]);
		}
		TEST_METHOD(TestMethod2)
		{
			sudoku sudo;
			int matrix[9][9] =
			{
				1,2,0,4,5,0,7,8,0,
				7,8,9,0,2,3,0,5,6,
				0,5,6,0,8,9,1,0,3,
				2,0,4,5,0,7,8,0,1,
				5,6,0,8,9,0,2,3,0,
				8,9,1,0,3,4,0,6,7,
				0,4,5,0,7,8,9,0,2,
				6,0,8,9,0,2,3,0,5,
				9,1,2,3,4,5,6,7,0
			};
			sudo.dfs(0, 0, 0, matrix);
			Assert::AreEqual(3, matrix[0][2]);
			Assert::AreEqual(6, matrix[0][5]);
			Assert::AreEqual(9, matrix[0][8]);
			Assert::AreEqual(1, matrix[1][3]);
			Assert::AreEqual(4, matrix[1][6]);
			Assert::AreEqual(4, matrix[2][0]);
			Assert::AreEqual(7, matrix[2][3]);
			Assert::AreEqual(2, matrix[2][7]);
			Assert::AreEqual(3, matrix[3][1]);
			Assert::AreEqual(6, matrix[3][4]);
			Assert::AreEqual(9, matrix[3][7]);
			Assert::AreEqual(7, matrix[4][2]);
			Assert::AreEqual(1, matrix[4][5]);
			Assert::AreEqual(4, matrix[4][8]);
			Assert::AreEqual(2, matrix[5][3]);
			Assert::AreEqual(5, matrix[5][6]);
			Assert::AreEqual(3, matrix[6][0]);
			Assert::AreEqual(6, matrix[6][3]);
			Assert::AreEqual(1, matrix[6][7]);
			Assert::AreEqual(7, matrix[7][1]);
			Assert::AreEqual(1, matrix[7][4]);
			Assert::AreEqual(4, matrix[7][7]);
			Assert::AreEqual(8, matrix[8][8]);
		}
		TEST_METHOD(TestMethod3)
		{
			sudoku sudo;
			int matrix[9][9] =
			{
				4,5,0,7,8,9,0,2,3,
				0,2,3,0,5,6,0,8,9,
				7,0,9,1,0,3,4,0,6,
				2,3,0,5,6,0,8,9,1,
				5,6,7,8,9,1,2,3,4,
				8,9,1,2,3,4,5,6,7,
				3,4,5,6,7,8,9,1,2,
				6,7,8,9,1,2,3,0,5,
				9,1,0,3,4,0,6,7,0
			};
			sudo.dfs(0, 0, 0, matrix);
			Assert::AreEqual(6, matrix[0][2]);
			Assert::AreEqual(1, matrix[0][6]);
			Assert::AreEqual(1, matrix[1][0]);
			Assert::AreEqual(4, matrix[1][3]);
			Assert::AreEqual(7, matrix[1][6]);
			Assert::AreEqual(8, matrix[2][1]);
			Assert::AreEqual(2, matrix[2][4]);
			Assert::AreEqual(5, matrix[2][7]);
			Assert::AreEqual(4, matrix[3][2]);
			Assert::AreEqual(7, matrix[3][5]);
			Assert::AreEqual(4, matrix[7][7]);
			Assert::AreEqual(2, matrix[8][2]);
			Assert::AreEqual(5, matrix[8][5]);
			Assert::AreEqual(8, matrix[8][8]);
		}
		TEST_METHOD(TestMethod4)
		{
			sudoku sudo;
			int matrix[9][9] =
			{
				0,5,6,0,8,9,1,2,3,
				7,8,9,1,2,3,4,5,6,
				1,2,3,4,5,6,7,8,9,
				2,3,4,5,6,0,8,9,0,
				5,6,0,8,9,1,0,3,4,
				0,9,1,0,3,4,0,6,7,
				3,0,5,6,0,8,9,0,2,
				6,7,8,9,1,0,3,4,5,
				9,1,2,3,4,5,6,7,8
			};
			sudo.dfs(0, 0, 0, matrix);
			Assert::AreEqual(4, matrix[0][0]);
			Assert::AreEqual(7, matrix[0][3]);
			Assert::AreEqual(7, matrix[3][5]);
			Assert::AreEqual(1, matrix[3][8]);
			Assert::AreEqual(7, matrix[4][2]);
			Assert::AreEqual(2, matrix[4][6]);
			Assert::AreEqual(8, matrix[5][0]);
			Assert::AreEqual(2, matrix[5][3]);
			Assert::AreEqual(5, matrix[5][6]);
			Assert::AreEqual(4, matrix[6][1]);
			Assert::AreEqual(7, matrix[6][4]);
			Assert::AreEqual(1, matrix[6][7]);
			Assert::AreEqual(2, matrix[7][5]);
		}
		TEST_METHOD(TestMethod5)
		{
			sudoku sudo;
			int matrix[9][9] =
			{
				7,8,9,1,0,3,0,5,6,
				1,0,3,4,0,6,7,8,0,
				4,5,6,7,8,0,1,2,0,
				2,3,4,5,6,7,8,9,1,
				0,6,7,0,9,1,0,3,4,
				8,9,1,2,3,4,5,0,7,
				3,4,5,6,7,8,9,1,2,
				6,7,8,9,1,0,3,4,5,
				0,1,2,3,4,5,0,7,8
			};
			sudo.dfs(0, 0, 0, matrix);
			Assert::AreEqual(2, matrix[0][4]);
			Assert::AreEqual(4, matrix[0][6]);
			Assert::AreEqual(2, matrix[1][1]);
			Assert::AreEqual(5, matrix[1][4]);
			Assert::AreEqual(9, matrix[1][8]);
			Assert::AreEqual(9, matrix[2][5]);
			Assert::AreEqual(3, matrix[2][8]);
			Assert::AreEqual(5, matrix[4][0]);
			Assert::AreEqual(8, matrix[4][3]);
			Assert::AreEqual(2, matrix[4][6]);
			Assert::AreEqual(6, matrix[5][7]);
			Assert::AreEqual(2, matrix[7][5]);
			Assert::AreEqual(9, matrix[8][0]);
			Assert::AreEqual(6, matrix[8][6]);
		}

	};
}
