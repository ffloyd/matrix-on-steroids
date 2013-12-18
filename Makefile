test: test.cpp crtp/base_object.hpp crtp/evaluable_object.hpp crtp/matrix_base.hpp dense_matrix.hpp
	g++ $(CFLAGS) -o test test.cpp
