#include "Matrix.h"

Matrix::Matrix(std::vector<std::vector<int>> matrix)
{
	this->matrix = matrix;
}

int Matrix::getIJ(int i, int j)
{
	return matrix[i][j];
}

std::vector<int> Matrix::getRow(int row)
{
	return matrix[row];
}

std::vector<int> Matrix::getCol(int col)
{
	std::vector<int> column;
	for (size_t i = 0; i < matrix.size(); i++)
	{
		column.push_back(matrix[i][col]);
	}
	return column;
}

int Matrix::getNumRows()
{
	return matrix.size();
}

int Matrix::getNumCols()
{
	return matrix[0].size();
}

std::string Matrix::toString()
{
	std::string out = "";
	for (int i = 0; i < matrix.size(); i++) {

		for (int j = 0; j < matrix[0].size(); j++)
		{
			out = out + " " + std::to_string(this->getIJ(i, j));
		}
		out = out + "\n";
	}
	return out;
}
