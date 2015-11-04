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
### Assignment

 - *Mandatory:* `grid-hyper_cube_00` revieals a bug. Solve it and make the test pass.
 - *Mandatory:* Templetize the `Matrix` class with the variable type, `double` or `float`. `lac-matrix_01` should be passing.
 - *Not so optional:* Write an application, templetized for the matrix type, that compares the execution time for the `Matrix` you developed, and the provided *wrapper* to the boost matrix.
 - *Optional, but fun:* Optimize the provided wrapper, so that the private attribute is an `std::shared_ptr<boost::numeric::ublas::matrix>`. 
