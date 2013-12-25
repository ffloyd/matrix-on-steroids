#ifndef  MATRIX_BASE_INC
#define  MATRIX_BASE_INC

#include "base_object.hpp"

template<class T, class element>
struct MatrixObject : public BaseObject<T>
{
	element operator()(const int i, const int j) const
	{
		return this->self()(i, j);
	}

	int getN() const
	{
		return this->self().getN();
	}

	int getM() const
	{
		return this->self().getM();
	}
};

#include "matrix_operation.hpp"

#endif   /* ----- #ifndef MATRIX_BASE_INC  ----- */
