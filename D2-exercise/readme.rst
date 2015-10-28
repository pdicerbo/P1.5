D2-exercise
===========

Write a matrix class. 

1. The matrix object should contain:

     - nrows and ncols
     - a contiguous data block

2. The matrix should have as methods
   
     - costum constructor 
     - copy constructor and operator=  (prototype matrix& matrix::operator=(const matrix& mat) )
     - operator*  (prototype    matrix matrix::operator*(const matrix& mat) const )

3. Separate class declaration, class implementation and main program. Provide a makefile

4. (Optional) By overloading the () operator, provide safe access (i.e. bound check) to the matrix elements. (prototype    float& matrix::operator()(const int i, const int j) )

5. (Optional) Try to create a safe array overloading the [] operator, to achieve an indexing such that a[4][3]. Please notice that [][] is not an operator, only [] is. 
