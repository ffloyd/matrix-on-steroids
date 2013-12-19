CRTP=crtp/base_object.hpp crtp/matrix_base.hpp

test: test.cpp dense_matrix.hpp $(CRTP)
	g++ $(CFLAGS) -o test test.cpp
