# Day 4 Assignment

## Install Toy Lib

Your first library.

```
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/home/nicola/local/usr/toy_lib ../
make
make install
export TOY_LIB_PATH=/home/nicola/local/usr/toy_lib
```
go to the `tests` directory:
```
mkdir build
cd build
cmake ../
ctest
```
The output should be this:
```
Test project /home/nicola/local/mhpc/toy_lib/tests/build
    Start 1: grid-hyper_ball_00
1/5 Test #1: grid-hyper_ball_00 ...............   Passed    0.09 sec
    Start 2: grid-hyper_cube_00
2/5 Test #2: grid-hyper_cube_00 ...............***Failed    0.14 sec
    Start 3: base-basic_test
3/5 Test #3: base-basic_test ..................   Passed    0.09 sec
    Start 4: lac-matrix_01
4/5 Test #4: lac-matrix_01 ....................***Failed    0.58 sec
    Start 5: lac-matrix_00
5/5 Test #5: lac-matrix_00 ....................***Failed    0.48 sec

40% tests passed, 3 tests failed out of 5

Total Test time (real) =   1.39 sec

The following tests FAILED:
	  2 - grid-hyper_cube_00 (Failed)
	  4 - lac-matrix_01 (Failed)
	  5 - lac-matrix_00 (Failed)
Errors while running CTest
```


### Assignment 0 

`grid-hyper_cube_00` revieals a bug. Solve it and make the test pass.

### Assignment 1  
Make a template version of your matrix and squarematrix classes, such that the blockdata can be of arbitrary type.
The declaration of your matrix and square matrix object would be then
```
Matrix<double> a;
SquareMatrix<float> b;
```
Provide unit test for each matrix.

Provide template specialization to allow the offload to cblas_dgemm for double and cblas_fgemm for float, if specified at compilation time. Use 
```
#ifdef USEBLAS
```
to selectively compile the blas or the version of matrix multiplication you wrote.

Locate where CMakeLists that discovers blas and sets in case the above macro

### Assignment 2 

Write an application, templetized for the matrix type, that compares the execution time for the `Matrix` you developed, and the provided *wrapper* to the boost matrix.

### Assignment 3 

Optimize the provided wrapper, so that the private attribute is an `std::shared_ptr<boost::numeric::ublas::matrix>`. 

### Assignment 4 

Use an stl vector to containt 2 (or more) pointers to matrix (base)  class like 
```
Matrix<double> a(3,4);
SquareMatrix<double> b(4);
std::vector< matrix<double>* > vec;
vec.push_back(&a);
```
Iterate through the vector using iterators and, by dereferencing the iterator and calling the trace(), check that the polymorphism works.

