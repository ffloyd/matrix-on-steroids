#ifndef MF_MATRIX
#define MF_MATRIX
#include <vector>

template<class number>
class Matrix {
	
	std::vector< std::vector<number> > data;
	int n;

public:

	Matrix(const int n);

	void set(const int i, const int j, number value);

	const number& get(const int i, const int j);

	void fill_with(number value);

	void print();

	Matrix<number> operator+ (const Matrix<number> second);
};

#endif
