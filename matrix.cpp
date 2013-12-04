#include "matrix.hpp"
#include "iostream"

template<class number>
Matrix<number>::Matrix(const int n):n(n) {
	// allocate memory
	data.resize(n,  std::vector<number>(n, 0) );
}

template<class number>
void Matrix<number>::set(const int i, const int j, number value) {
	data[i][j] = value;
}

template<class number>
const number& Matrix<number>::get(const int i, const int j) {
	return data[i][j];
}

template<class number>
void Matrix<number>::fill_with(number value) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			data[i][j] = value;
		}
	}
}

template<class number>
void Matrix<number>::print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << data[i][j] << " ";
		}
		std::cout << "\n";
	}
}

template<class number>
Matrix<number> Matrix<number>::operator+ (Matrix<number> second) {
	Matrix<number> result(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result.set(i, j, data[i][j] + second.get(i, j));
		}
	}
	return result;
}

