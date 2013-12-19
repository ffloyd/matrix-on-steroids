#ifndef  MATRIX_BASE_INC
#define  MATRIX_BASE_INC

#include "base_object.hpp"

template<class T>
struct MatrixBase : public BaseObject<T>
{
	// DOESN'T WORK =(
	//auto operator()(const int i, const int j) const -> decltype(this->self().operator()(i, j))
	//{
	//	return this->self()(i, j);
	//}
};

#endif   /* ----- #ifndef MATRIX_BASE_INC  ----- */
