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
    size_t numRows = matrix.getNumRows();
    size_t numCols = matrix.getNumCols();
    int i = 0;

    for (int r = 0; r < numRows; r++) {
        /*std::string str = "---------------------\n";
        std::cout << str + matrix.toString() << std::endl << "Row: " + std::to_string(r + 1) + "\n";*/

        if (pivot > numCols - 1) {
            return matrix;
        }
        i = r;

        while (matrix.getIJ(i, pivot) == 0) {
            i = i + 1;

            if (i > numRows - 1) {
                i = r;
                pivot = pivot + 1;

                if (pivot > numCols - 1) {
                    return matrix;
                }
            }
        }

        if (i != r) {
            matrix.swapRow(i, r);
            // std::cout << str + matrix.toString() + "\nSwapped rows " + std::to_string(i + 1) + " and " + std::to_string(r + 1) << std::endl;
        }

        if (matrix.getIJ(r, pivot) != 0 && matrix.getIJ(r, pivot) != 1) {
            matrix.scalarRowDivide(r, matrix.getIJ(r, pivot));
            // std::cout << str + matrix.toString() + "\nDivided row " + std::to_string(r + 1) + " by " + std::to_string(matrix.getIJ(r, pivot)) << std::endl;
        }

        for (i = 0; i < numRows; ++i) {
            if (i != r) {
                std::vector<double> row = matrix.getRow(r);
                for (size_t k = 0; k < row.size(); k++) {
                    row[k] = row[k] * matrix.getIJ(i, pivot) * -1;
                }
                // std::string temp = std::to_string(matrix.getIJ(i, pivot) * -1);
                matrix.addRow(i, row);
                // std::cout << str + matrix.toString() + "\nAdded " + temp + "*row" + std::to_string(r+1) + " to row " + std::to_string(i + 1) << std::endl;
            }
        }

        pivot = pivot + 1;
    }

    return matrix;
}
