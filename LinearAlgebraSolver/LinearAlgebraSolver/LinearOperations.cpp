#include "LinearOperations.h"


Matrix LinearOperations::computeOuterProduct(Matrix matrices[2])
{
	Matrix matrix1 = matrices[0];
	Matrix matrix2 = matrices[1];
	std::vector<std::vector<int>> output(matrix1.getNumRows(), std::vector<int> (matrix2.getNumCols(), 0));

	for (int i = 0; i < matrix1.getNumRows(); i++) {
		for (int j = 0; j < matrix2.getNumCols(); j++)
		{
			for (int k = 0; k < matrix1.getNumCols(); k++)
			{
				output[i][j] = output[i][j] + matrix1.getIJ(i, k) * matrix2.getIJ(k, j);
			}
		}
	}

	return Matrix(output);
}

Matrix LinearOperations::computeRowEcehelonForm(Matrix matrix)
{
	std::vector<std::vector<int>> output(1, std::vector<int>(1, 0));
	return Matrix(output);
}
