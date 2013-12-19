#ifndef  MATRIX_OPERATION_INC
#define  MATRIX_OPERATION_INC

#include <functional>
#include "matrix_base.hpp"


// for operations like plus and minus
template<class A1, class A2, class binary_f, class element>
struct SimpleMatrixOperation : public MatrixBase< SimpleMatrixOperation<A1, A2, binary_f, element>, element >
{
	const MatrixBase<A1, element>& arg1;
	const MatrixBase<A2, element>& arg2;
	const binary_f calc;
	int N;
	int M;

	SimpleMatrixOperation(const MatrixBase<A1, element>& arg1, const MatrixBase<A2, element>& arg2) : 
		arg1(arg1),
		arg2(arg2),
		calc(binary_f())
	{
		if ( (arg1.getN() != arg2.getN()) || (arg1.getM() != arg2.getM()))
		{
			throw std::logic_error("Incompatible matrices size");
		}

		N = arg1.getN();
		M = arg1.getM();
	}

	int operator()(const int i, const int j) const
	{
		return calc( arg1(i, j), arg2(i, j) );
	}

	int getN() const
	{
		return N;
	}

	int getM() const
	{
		return M;
	}
};

template<class A1, class A2, class element>
inline SimpleMatrixOperation< A1, A2, std::plus<element>, element > operator+(const MatrixBase<A1, element>& left_op, const MatrixBase<A2, element>& right_op)
{
	return SimpleMatrixOperation< A1, A2, std::plus<element>, element >(left_op, right_op);
}

template<class A1, class A2, class element>
inline SimpleMatrixOperation< A1, A2, std::minus<element>, element > operator-(const MatrixBase<A1, element>& left_op, const MatrixBase<A2, element>& right_op)
{
	return SimpleMatrixOperation< A1, A2, std::minus<element>, element >(left_op, right_op);
}


#endif   /* ----- #ifndef MATRIX_OPERATION_INC  ----- */
