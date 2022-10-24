// LinearAlgebraSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "LinearOperations.h"

int main()
{
    /*std::string selection;
    std::cout << "Choose an operation.\n1. Row Ecehelon Form\n2. Outer Product\nOperation: \n";
    std::cin >> selection;
    switch (stoi(selection)) {
        case 1:
            break;
        case 2:
            break;
    }*/

    std::vector<std::vector<double>> matrix1
    {
        {3, 4, 2}
    };

    std::vector<std::vector<double>> matrix2
    {
        {1,2,-1,-4},
        {1,3,-1,-11},
        {-2,0,-3,22}
    };

    std::vector<std::vector<double>> matrix3
    {
        {15, 53, 19, 52, 65},
        {25, 111, 58, 39, 34},
        {53, 65, 12, 74, 43},
        {35, 62, 52, 82, 464}
    };

    Matrix m1 = Matrix(matrix1);
    Matrix m2 = Matrix(matrix2);
    Matrix m3 = Matrix(matrix3);
    //matrix2[0][2];
    Matrix matrices[2] = { m1, m2 };
    LinearOperations linearOperations;
    //Matrix out = linearOperations.computeOuterProduct(matrices);
    Matrix out = linearOperations.computeRowEcehelonForm(m3);
    std::cout << out.toString();
}


