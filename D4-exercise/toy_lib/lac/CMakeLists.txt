find_package(BLAS)

if(BLAS_FOUND)
    add_definitions(-DUSEBLAS)
endif(BLAS_FOUND)


add_library(lac MyMatrix.cpp MySquareMatrix.cpp)

install (TARGETS lac DESTINATION bin)
install (FILES MyMatrix.h MySquareMatrix.h DESTINATION include)
