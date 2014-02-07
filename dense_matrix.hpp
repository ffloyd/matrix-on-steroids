#ifndef  DENSE_MATRIX_INC
#define  DENSE_MATRIX_INC

#include <vector>

#include "crtp/matrix_object.hpp"

/**
 * @brief "Плотные" матрицы. Хранит все элементы в памяти.
 */
template<class element>
class DenseMatrix : public MatrixObject< DenseMatrix<element>, element >
{
	std::vector<element> data;

public:
	/**
	 * @brief Тип соответсвующий конкретной реализации
	 * @detailed Наличие этого typedef'а облегчает определение
	 * некоторых методов.
	 */
	typedef MatrixObject< DenseMatrix, element > BaseType;

	/**
	 * @brief Стандартный конструктор
	 * @param N размерность матрицы
	 * @param M размерность матрицы
	 */
	DenseMatrix(const int N, const int M) :
		BaseType(N, M)
	{
		data.reserve(N*M); 
	}

	/**
	 * @brief Копирующий конструктор
	 * @param matrix Матрица для копирования. Должна иметь тот же тип элементов.
	 */
	template<class A>
	DenseMatrix(const MatrixObject<A, element>& matrix) :
		BaseType(matrix.getN(), matrix.getM())
	{
		data.reserve(this->getN() * this->getM());
		for (int i = 0; i < this->getN(); i++)
		{
			for (int j = 0; j < this->getM(); j++)
			{
				set(i, j, matrix(i, j));
			}
		}
	}

	/**
	 * @brief Оператор чтения элемента.
	 */
	element operator()(const int i, const int j) const
	{
		return data[i * this->getM() + j];	
	}


	/**
	 * @brief Setter для элемента
	 */
	void set(const int i, const int j, const element value)
	{
		data[i * this->getM() + j] = value;
	}

};

#endif   /* ----- #ifndef DENSE_MATRIX_INC  ----- */
