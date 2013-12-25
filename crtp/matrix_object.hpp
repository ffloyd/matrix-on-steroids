#ifndef  MATRIX_BASE_INC
#define  MATRIX_BASE_INC

#include "base_object.hpp"

template<class T, class element>
class MatrixObject : public BaseObject<T>
{
	int N, M;
public:
	MatrixObject(const int N, const int M) :
		N(N), M(M)
	{
	}

	element operator()(const int i, const int j) const
	{
		return this->self()(i, j);
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

#include "matrix_operation.hpp"

#endif   /* ----- #ifndef MATRIX_BASE_INC  ----- */
