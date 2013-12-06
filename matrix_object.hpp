#ifndef MF_MATRIX_OBJECT
#define MF_MATRIX_OBJECT

template<class number>
class MatrixObject
{
protected:
	int N, M;
public:
	virtual const number get(const int i, const int j) const = 0; 
};

#endif
