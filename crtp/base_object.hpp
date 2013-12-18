#ifndef  BASE_OBJECT_INC
#define  BASE_OBJECT_INC

template<class T>
struct BaseObject
{
	const T& self() const
	{
		return static_cast<const T&>(*this);
	}
};

#endif   /* ----- #ifndef BASE_OBJECT_INC  ----- */
