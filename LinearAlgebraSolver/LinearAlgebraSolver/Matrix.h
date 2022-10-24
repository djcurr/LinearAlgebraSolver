#pragma once
#include <vector>
#include <string>

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
	void scalarRowDivide(int row, double scalar);
	void addRow(int rowNum, std::vector<double> row);
	void subtractRow(int rowNum, std::vector<double> row);
	size_t getNumCols();
	size_t getNumRows();
	std::string toString();
private:
	std::vector<std::vector<double>> matrix;
};

