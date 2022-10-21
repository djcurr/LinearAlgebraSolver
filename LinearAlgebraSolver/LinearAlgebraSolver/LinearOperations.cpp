#include "LinearOperations.h"
#include <iostream>


Matrix LinearOperations::computeOuterProduct(Matrix matrices[2])
{
	Matrix matrix1 = matrices[0];
	Matrix matrix2 = matrices[1];
	std::vector<std::vector<double>> output(matrix1.getNumRows(), std::vector<double> (matrix2.getNumCols(), 0));

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
    int pivot = 0;
    int numRows = matrix.getNumRows();
    int numCols = matrix.getNumCols();
    int i = 0;

    for (int r = 0; r < numRows; r++) {
        std::cout << matrix.toString() + "\n";

        if (numCols < pivot) {
            break;
        }
        i = r;

        while (matrix.getIJ(i, pivot) == 0) {
            i = i + 1;

            if (numRows == i) {
                i = r;
                pivot = pivot + 1;

                if (numCols == pivot) {
                    break;
                }
            }
        }
        matrix.swapRow(i, r);
        if (matrix.getIJ(r, pivot) != 0) {
            matrix.scalarRowMultiply(r, matrix.getIJ(r, pivot));
        }

        for (i = 0; i < numRows; i++) {
            if (i != r) {
                std::vector<double> row = matrix.getRow(r);
                for (size_t k = 0; k < row.size(); k++) {
                    row[i] = row[i] * matrix.getIJ(i, pivot);
                }
                matrix.subtractRow(i, row);
            }
        }

        pivot = pivot + 1;
    }

    return matrix;
}
