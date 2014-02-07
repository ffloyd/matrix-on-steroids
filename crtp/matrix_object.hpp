#ifndef  MATRIX_BASE_INC
#define  MATRIX_BASE_INC

#include "base_object.hpp"

/**
 * @brief Базовый класс для всех объектов, которые ведут себя как матрицы.
 * @detailed Реализует логику размерности (не забудьте вызвать родительский конструктор
 * в классе наследнике) и требует наличия оператора получения элемента матрицы.
 */
template<class T, class element>
class MatrixObject : public BaseObject<T>
{
	int N, M;
public:
	/**
	 * @brief Не забудьте вызвать родительский конструктор в классе наследнике!
	 */
	MatrixObject(const int N, const int M) :
		N(N), M(M)
	{
	}

	/**
	 * @brief CRTP-вызов оператора получения элемента.
	 */
	element operator()(const int i, const int j) const
	{
		return this->self()(i, j);
	}

	int getN() const
	{
		return N;
	}

	int getM() const
	{
		return M;
	}
};

#include "matrix_operation.hpp"

#endif   /* ----- #ifndef MATRIX_BASE_INC  ----- */
