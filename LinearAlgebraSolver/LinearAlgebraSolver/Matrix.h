#pragma once
#include <vector>
#include <string>
using namespace std;
using namespace System::Diagnostics;
[DebuggerDisplay("{toString()}")]
class Matrix
{
public:
	Matrix(std::vector<std::vector<double>> matrix);
	double getIJ(int i, int j);
	std::vector<double> getRow(int row);
	std::vector<double> getCol(int col);
	void setRow(int rowNum, std::vector<double> row);
	//void setCol(int colNum, std::vector<int> col);
	void swapRow(int row1, int row2);
	void scalarRowMultiply(int row, double scalar);
	void addRow(int rowNum, std::vector<double> row);
	void subtractRow(int rowNum, std::vector<double> row);
	int getNumCols();
	int getNumRows();
	std::string toString();
private:
	std::vector<std::vector<double>> matrix;
};

