#include "sudoku.h"

char sudokuIn[99999999];
char sudokuOut[99999999];
int result[20000000][9];//结果生成的数独终局 

void sudoku::makesudokutofile(int num)
{
	ofstream WriteFile("sudoku.txt");
	if (WriteFile.fail())
	{
		cout << "文件创建失败，无法写回数独数据!";
		return;
	}
	int n, i, j;//n是9*9矩阵的个数，i是矩阵行,j是矩阵列 
	int p = 0;
	for (n = 0; n < num; n++)
	{
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				if (result[n * 9 + i][j] != 0)
					sudokuOut[p] = result[n * 9 + i][j] + '0';//将int型二维数组转换成char型字符串 
				else
					sudokuOut[p] = '$';
				p++;
				if (j == 8 && n == num - 1 && i == 8)
				{
					break;
				}
				if (j == 8)
				{
					sudokuOut[p] = '\n';//如果是最后一列需要换行 
					p++;
				}
				else
				{
					sudokuOut[p] = ' ';//数与数之间需要空格 
					p++;
				}
			}
		}
		if (n != num - 1)
		{
			sudokuOut[p] = '\n';//9*9矩阵之间需要换行 
			p++;
		}
	}
	WriteFile << sudokuOut;
	cout << "sudoku.txt已成功生成" << endl;
}
void sudoku::gen_sudoku_result(int num)
{
	memset(result, 0, sizeof(result));
	int currNum = 0;//现已经生成的数独个数 
	int first_row[9] = { 1,2,3,4,5,6,7,8,9 };//基本数独的第一行，第一个数位(0+1)%9+1=2 
	int row_shift[9] = { 0,3,6,1,4,7,2,5,8 };//分别向左移动0,3,6,1,4,7,2,5,8位
	int swap[9] = { 0,1,2,3,4,5,6,7,8 };//交换行和列所用的数组 
	do
	{
		/*先用下面双层for循环生成基本数独，加上外面的循环可以全排列生成
		第一行9！（362，880）种基本数独，然后再紧接着下面的do-while循环进行前三行的
		行变换，所以可以生成3！*9！（2177，280）*/

		//本轮基本数独
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				sudoku[i][j] = first_row[(j + row_shift[i]) % 9];
			}
		}
		//行变换
		do
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					result[i + currNum * 9][j] = sudoku[swap[i]][j];//swap里的0，1，2会进行全排列
				}
			}
			currNum++;
			if (currNum == num)
				return;
		} while (next_permutation(swap, swap + 3));
	} while (next_permutation(first_row, first_row + 9));
}
