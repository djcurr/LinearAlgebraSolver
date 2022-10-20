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
	LinearOperations(Operations operation, []Matrix matrices);
	Matrix computeOuterProduct([]Matrix matrices);
	Matrix computeRowEcehelonForm(Matrix matrix);

};

