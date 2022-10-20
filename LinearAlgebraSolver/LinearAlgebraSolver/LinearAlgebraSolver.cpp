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

    std::vector<std::vector<int>> matrix1
    {
        {3, 4, 2}
    };

    std::vector<std::vector<int>> matrix2
    {
        {13,9,7,15},
        {8,7,4,6},
        {6,4,0,3}
    };
    Matrix m1 = Matrix(matrix1);
    Matrix m2 = Matrix(matrix2);
    //matrix2[0][2];
    Matrix matrices[2] = { m1, m2 };
    LinearOperations linearOperations;
    Matrix out = linearOperations.computeOuterProduct(matrices);
    std::cout << out.toString();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
