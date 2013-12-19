#include <iostream>

#include "dense_matrix.hpp"
#include "crtp/matrix_base.hpp"
//#include "crtp/matrix_operation.hpp"

template<class T, class E>
void test_matrix_base_crtp(const MatrixBase<T, E>& matrix)
{
	std::cout << matrix(0, 0) << std::endl;
}

template<class T>
void test_base_object_crtp(const BaseObject<T>& m)
{
	std::cout << m.self()(0, 0) << std::endl;
}

int main() 
{
	DenseMatrix<int> m(5, 5);
	
	m.set(0, 0, 10);
	test_matrix_base_crtp(m);
	test_base_object_crtp(m);

	return 0;
}
