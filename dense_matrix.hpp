#ifndef  DENSE_MATRIX_INC
#define  DENSE_MATRIX_INC

#include <cstring>

#include "crtp/matrix_object.hpp"

template<class element>
class DenseMatrix : public MatrixObject< DenseMatrix<element>, element >
{
	element *data;

public:
	typedef MatrixObject< DenseMatrix, element > BaseType;

	DenseMatrix(const int N, const int M, const bool do_nulify = true) :
		BaseType(N, M)
	{
		data = new element[this->getN() * this->getM()];
		if (do_nulify)
		{
			nulify();
		}
	}

	template<class A>
	DenseMatrix(const MatrixObject<A, element>& matrix) :
		BaseType(matrix.getN(), matrix.getM())
	{
		data = new element[this->getN() * this->getM()];
		for (int i = 0; i < this->getN(); i++)
		{
			for (int j = 0; j < this->getM(); j++)
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
		std::memset(data, 0, sizeof(element) * this->getM() * this->getN());
	}

	element operator()(const int i, const int j) const
	{
		return data[i * this->getM() + j];	
	}

	void set(const int i, const int j, const element value)
	{
		data[i * this->getM() + j] = value;
	}

};

#endif   /* ----- #ifndef DENSE_MATRIX_INC  ----- */
