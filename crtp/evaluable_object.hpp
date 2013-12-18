#ifndef  EVALUABLE_OBJECT_INC
#define  EVALUABLE_OBJECT_INC

#include "base_object.hpp"

template<class T>
struct EvaluableObject : public BaseObject< EvaluableObject<T> >
{
};

#endif   /* ----- #ifndef EVALUABLE_OBJECT_INC  ----- */
