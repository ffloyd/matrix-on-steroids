#include "matrix.hpp"

int main() {
	Matrix<int> a(5);
	Matrix<int> b(5);

	a.fill_with(1);
	b.fill_with(2);

	Matrix<int> c = a + b;

	c.print();

	return 0;
}
