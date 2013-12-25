CRTP=crtp/base_object.hpp crtp/matrix_object.hpp crtp/matrix_operation.hpp

test: test.cpp dense_matrix.hpp $(CRTP)
	g++ $(CFLAGS) -o test test.cpp
