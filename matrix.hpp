#ifndef MF_MATRIX
#define MF_MATRIX
#include <vector>
#include "matrix_object.hpp"

template<class number, int N, int M>
class Matrix : public MatrixObject<number, N, M>
{
	
	std::vector< std::vector<number> > data;

public:
	Matrix();

	const number get(const int i, const int j) const;
	void set(const int i, const int j, const number value);

	void print() const;

	void fill_with(const number value);

	Matrix<number, N, M> operator+(const MatrixObject<number, N, M>& second) const;
};

#include "matrix.tlt"

#endif
