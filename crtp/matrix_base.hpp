#ifndef  MATRIX_BASE_INC
#define  MATRIX_BASE_INC

#include "base_object.hpp"

template<class T, class element>
struct MatrixBase : public BaseObject<T>
{
	element operator()(const int i, const int j) const
	{
		return this->self()(i, j);
	}
};

#endif   /* ----- #ifndef MATRIX_BASE_INC  ----- */
