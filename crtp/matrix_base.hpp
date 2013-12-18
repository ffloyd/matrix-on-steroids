#ifndef  MATRIX_BASE_INC
#define  MATRIX_BASE_INC

#include "base_object.hpp"
#include "evaluable_object.hpp"

template<class T, class element>
struct MatrixBase : public BaseObject< MatrixBase<T, element> >, public EvaluableObject< MatrixBase<T, element> >
{
	using BaseObject< MatrixBase<T, element> >::self;
    using EvaluableObject< MatrixBase<T, element> >::self;

	element operator()(const int i, const int j) const
	{
		return static_cast<const T&>(*this)(i, j);
	}
};

#endif   /* ----- #ifndef MATRIX_BASE_INC  ----- */
