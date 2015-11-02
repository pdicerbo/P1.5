cmake_minimum_required (VERSION 2.6)

project(matrix_class)

find_package(BLAS)

if(BLAS_FOUND)

add_definitions(-DBFOUND)
add_executable(prog.x prog.cpp MyMatrix.cpp MySquareMatrix.cpp)
target_link_libraries(prog.x cblas)

else(NOT BLAS_FOUND)

add_executable(prog.x prog.cpp MyMatrix.cpp MySquareMatrix.cpp)

endif(BLAS_FOUND)
