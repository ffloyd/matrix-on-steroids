#ifndef MF_MATRIX_OBJECT
#define MF_MATRIX_OBJECT

template<class number, int N, int M>
class MatrixObject
{
public:
	virtual const number get(const int i, const int j) const = 0; 
};

#endif
