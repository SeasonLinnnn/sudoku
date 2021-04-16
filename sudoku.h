#pragma once
#include <iostream>
#include <string> 
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <fstream>
#include <istream>
#include <algorithm>
#include <vector> 
#include <string.h>
using namespace std;
class sudoku
{
private:
	int sudoku[9][9];//�������� 
public:
	void gen_sudoku_result(int num);//���������վ�
	void gen_sudoku(int num, int level, int *holeNumber, bool ifOnly);//����������Ϸ
	void makesudokutofile(int num);
	bool is_right(int current_sudoku_index, int row, int column, int num, int sudo[][9]);
	bool is_unique(int current_sudoku_index, int row, int column, int num,int sudo[][9]);
	bool dfs(int current_sudoku_index, int row, int column, int sudo[][9]);
	void solve_sudoku(string filepath);
};
