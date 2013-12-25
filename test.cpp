#include <iostream>

#include "dense_matrix.hpp"

template<class T, class E>
void test_matrix_base_crtp(const MatrixObject<T, E>& matrix)
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
	DenseMatrix<int> a(5, 5);
	DenseMatrix<int> b(5, 5);
	
	a.set(0, 0, 10);
	b.set(0, 0,  5);

	test_matrix_base_crtp(a);
	test_base_object_crtp(a);

	// test + operator itself
	DenseMatrix<int> c = a + (b + a) -b;
	std::cout << c(0, 0) << std::endl;

	return 0;
}
