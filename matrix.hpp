#ifndef MF_MATRIX
#define MF_MATRIX
#include <vector>
#include <iostream>
#include "matrix_operation.hpp"

template<class number>
class Matrix
{
	int N, M;
	std::vector< std::vector<number> > data;

public:
	Matrix(const int N, const int M);

	template<class T>
	Matrix(const T& source);

	const number get(const int i, const int j) const;
	void set(const int i, const int j, const number value);

	void print() const;

	void fill_with(const number value);

	template<class RightOp>
	matrix_operation::plus<number, Matrix<number>, RightOp> operator+(const RightOp& right) const;
};

#include "matrix.tlt"

#endif
