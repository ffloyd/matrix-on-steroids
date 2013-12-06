#ifndef MF_MATRIX
#define MF_MATRIX
#include <vector>
#include "matrix_object.hpp"

template<class number>
class Matrix : public MatrixObject<number>
{
	
	std::vector< std::vector<number> > data;

public:
	Matrix(const int N, const int M);

	const number get(const int i, const int j) const;
	void set(const int i, const int j, const number value);

	void print() const;

	void fill_with(const number value);

	Matrix<number> operator+(const MatrixObject<number>& second) const;
};

#include "matrix.tlt"

#endif
