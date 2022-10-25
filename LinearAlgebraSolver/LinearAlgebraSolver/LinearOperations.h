#pragma once
#include "Matrix.h"
class LinearOperations
{
public:
	enum Operations
	{
		row_ecehelon_form,
		outer_product
	};
	Matrix computeOuterProduct(Matrix matrices[2]);
	Matrix computeRowEcehelonForm(Matrix matrix);
	double computeDeterminant(Matrix matrix);

};

