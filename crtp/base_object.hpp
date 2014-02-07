#ifndef  BASE_OBJECT_INC
#define  BASE_OBJECT_INC

/**
 * @brief Базовый класс для всех элементов системы.
 * Используется модель статического наследования CRTP.
 */
template<class T>
struct BaseObject
{
	/**
	 * @brief Возвращает экземпляр класса, приведенный к самому к конечному типу в цепочке наследования.
	 * @detailed Для лучшего понимания "зачем этот метод" следует ознакомиться с
	 * идеей CRTP.
	 */
	const T& self() const
	{
		return static_cast<const T&>(*this);
	}
};

#endif   /* ----- #ifndef BASE_OBJECT_INC  ----- */
