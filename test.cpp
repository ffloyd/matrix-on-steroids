#include "matrix.hpp"

int main() {
	Matrix<int, 5, 5> a;
	Matrix<int, 5, 5> b;

	a.fill_with(1);
	b.fill_with(2);

	Matrix<int, 5, 5> c = a + b;

	c.print();

	return 0;
}
