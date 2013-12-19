#ifndef  DENSE_MATRIX_INC
#define  DENSE_MATRIX_INC

#include <cstring>

#include "crtp/matrix_base.hpp"

template<class element>
class DenseMatrix : public MatrixBase< DenseMatrix<element>, element >
{
	element *data;
	int N, M;

public:
	DenseMatrix(const int N, const int M, const bool do_nulify = true) : N(N), M(M)
	{
		data = new element[N*M];
		if (do_nulify)
		{
			nulify();
		}
	}

	template<class A>
	DenseMatrix(const MatrixBase<A, element>& matrix)
	{
		N = matrix.getN();
		M = matrix.getM();
		data = new element[N*M];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				set(i, j, matrix(i, j));
			}
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

	int getN() const
	{
		return N;
	}	

	int getM() const
	{
		return M;
	}
};

#endif   /* ----- #ifndef DENSE_MATRIX_INC  ----- */
