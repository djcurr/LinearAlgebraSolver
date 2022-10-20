#pragma once
#include <vector>
#include <string>
class Matrix
{
public:
	Matrix(std::vector<std::vector<int>> matrix);
	int getIJ(int i, int j);
	std::vector<int> getRow(int row);
	std::vector<int> getCol(int col);
	int getNumCols();
	int getNumRows();
	std::string toString();
private:
	std::vector<std::vector<int>> matrix;
};

