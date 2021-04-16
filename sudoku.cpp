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
bool sudoku::is_unique(int current_sudoku_index, int row, int column, int num, int sudo[][9])
{
	int temp_sudoku[9][9][9];//用于判断生成的数独结果是否唯一,至少要测试其他八个数
	sudo[row + current_sudoku_index * 9][column] = 0;
	//将这些要测试的数需要用到的临时数独都初始化
	for (int m = 0; m < 9; m++)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				temp_sudoku[m][i][j] = sudo[current_sudoku_index * 9 + i][j];
			}
		}
	}
	int answerCount = 0;
	for (int i = 1; i < 10; i++)
	{
		if (is_right(0, row, column, i, temp_sudoku[i - 1]))
		{
			temp_sudoku[i - 1][row][column] = i;
			if (dfs(0, row, column, temp_sudoku[i - 1]))
				answerCount++;
		}
	}
	if (answerCount != 1)
	{
		sudo[row + current_sudoku_index * 9][column] = num;
		return false;
	}
	return true;
}
bool sudoku::is_right(int current_sudoku_index, int row, int column, int num, int sudo[][9])
{
	/*数独需要一行里出现1-9九个数字没有重复，同理行和
	九个九宫格都是如此*/

	//列判断
	for (int i = 0; i < 9; i++)
	{
		if (sudo[current_sudoku_index * 9 + i][column] == num)
			return false;
	}
	//行判断
	for (int i = 0; i < 9; i++)
	{
		if (sudo[current_sudoku_index * 9 + row][i] == num)
			return false;
	}
	//九宫格判断
	for (int i = row / 3 * 3; i < row / 3 * 3 + 3; i++)
	{
		for (int j = column / 3 * 3; j < column / 3 * 3 + 3; j++)
		{
			if (sudo[current_sudoku_index * 9 + i][j] == num)
				return false;
		}
	}
	return true;
}
void sudoku::gen_sudoku(int num, int level, int* holeNumber, bool ifOnly)
{
	//先生成所有的数独终局，然后再挖洞
	gen_sudoku_result(num);
	int row = 0, column = 0;
	//自定义空格数的情况
	if ((level < 1 || level>3) && holeNumber != nullptr && ifOnly == false)
	{
		for (int currSudoku = 0; currSudoku < num; currSudoku++)
		{
			srand(time(NULL));
			int totalHole = rand() % (holeNumber[1] - holeNumber[0]) + holeNumber[0];
			for (int i = 0; i < totalHole; i++)
			{
				srand(time(NULL));
				int currHole = rand() % 81;
				row = currHole / 9;
				column = currHole % 9;
				if (result[currSudoku * 9 + row][column] != 0)
					result[currSudoku * 9 + row][column] = 0;
				else
					i--;
			}
		}
	}
	//生成唯一解
	else if (ifOnly)
	{
		for (int currSudoku = 0; currSudoku < num; currSudoku++)
		{
			srand(time(NULL));
			int totalHole = rand() % 20 + 10;
			for (int i = 0; i < totalHole; i++)
			{
				srand(time(NULL));
				int currHole = rand() % 81;
				row = currHole / 9;
				column = currHole % 9;
				if (result[currSudoku * 9 + row][column] != 0 && is_unique(currSudoku, row, column, result[currSudoku * 9 + row][column],result))
					result[currSudoku * 9 + row][column] = 0;
				else
					i--;
			}
		}
	}
	//分等级
	else
	{
		int leveledNum = 0;
		switch (level)
		{
		case 1:
			leveledNum = 20;
			break;
		case 2:
			leveledNum = 40;
			break;
		case 3:
			leveledNum = 60;
			break;
		default:
			leveledNum = 20;
			break;
		}
		for (int currSudoku = 0; currSudoku < num; currSudoku++)
		{
			srand(time(NULL));
			int totalHole = rand() % leveledNum + 10;
			for (int i = 0; i < totalHole; i++)
			{
				srand(time(NULL));
				int currHole = rand() % 81;
				row = currHole / 9;
				column = currHole % 9;
				if (result[currSudoku * 9 + row][column] != 0)
					result[currSudoku * 9 + row][column] = 0;
				else
					i--;
			}
		}
	}
}
