#ifndef  DENSE_MATRIX_INC
#define  DENSE_MATRIX_INC

#include <cstring>

#include "crtp/base_object.hpp"
#include "crtp/matrix_base.hpp"

template<class element>
class DenseMatrix :
	public BaseObject< DenseMatrix<element> >,
	public MatrixBase< DenseMatrix<element>, element >
{
	element *data;
	int N, M;

public:
	using BaseObject< DenseMatrix<element> >::self;
	using MatrixBase< DenseMatrix<element>, element >::self;

	DenseMatrix(const int N, const int M, const bool do_nulify = true) : N(N), M(M)
	{
		data = new element[N*M];
		if (do_nulify)
		{
			nulify();
		}
	}

	~DenseMatrix()
	{
		delete[] data;
	}

	void nulify()
	{
		std::memset(data, 0, sizeof(element)*M*N);
	}

	element operator()(const int i, const int j) const
	{
		return data[N*i + j];	
	}

	void set(const int i, const int j, const element value)
	{
		data[i*N + j] = value;
	}
};


#endif   /* ----- #ifndef DENSE_MATRIX_INC  ----- */