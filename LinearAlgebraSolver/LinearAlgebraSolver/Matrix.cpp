#include "Matrix.h"


Matrix::Matrix(std::vector<std::vector<double>> matrix)
{
	this->matrix = matrix;
}


double Matrix::getIJ(int i, int j)
{
	return matrix[i][j];
}

std::vector<double> Matrix::getRow(int row)
{
	return matrix[row];
}

std::vector<double> Matrix::getCol(int col)
{
	std::vector<double> column;
	for (size_t i = 0; i < matrix.size(); i++)
	{
		column.push_back(matrix[i][col]);
	}
	return column;
}

void Matrix::setRow(int rowNum, std::vector<double> row)
{
	matrix[rowNum] = row;
}

//void Matrix::setCol(int colNum, std::vector<int> col)
//{
//	for (size_t i = 0; i < col.size(); i++)
//	{
//		matrix[i][colNum] = col[i];
//	}
//
//}

size_t Matrix::getNumRows()
{
	return matrix.size();
}

void Matrix::swapRow(int row1, int row2)
{
	std::vector<double> tempRow = matrix[row2];
	matrix[row2] = matrix[row1];
	matrix[row1] = tempRow;
}

void Matrix::scalarRowMultiply(int row, double scalar)
{
	for (int i = 0; i < matrix[row].size(); i++) {
		matrix[row][i] = matrix[row][i] * scalar;
	}
}

void Matrix::scalarRowDivide(int row, double scalar)
{
	for (int i = 0; i < matrix[row].size(); i++) {
		matrix[row][i] = matrix[row][i] / scalar;
	}
}

void Matrix::addRow(int rowNum, std::vector<double> row)
{
	std::vector<double> tempRow = matrix[rowNum];
	for (int i = 0; i < row.size(); i++) {
		tempRow[i] = tempRow[i] + row[i];
	}
	setRow(rowNum, tempRow);
}

void Matrix::subtractRow(int rowNum, std::vector<double> row)
{
	std::vector<double> tempRow = matrix[rowNum];
	for (int i = 0; i < row.size(); i++) {
		tempRow[i] = tempRow[i] - row[i];
	}
	setRow(rowNum, tempRow);
}

size_t Matrix::getNumCols()
{
	return matrix[0].size();
}

std::string Matrix::toString()
{
	std::string out = "";
	for (int i = 0; i < matrix.size(); i++) {

		for (int j = 0; j < matrix[0].size(); j++)
		{
			// std::to_string(this->getIJ(i, j)).substr(0, std::to_string(this->getIJ(i, j)).find_last_of(".")) + "\t"
			out = out + " " + std::to_string(this->getIJ(i, j));
		}
		out = out + "\n";
	}
	return out;
}
