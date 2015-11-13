D8-assignment
=============


General setting
~~~~~~~~~~~~~~~

The aim of the exercise is to create a linear algebra system suitable for quantum mechanics calculations in a fashion in 
which analytical calculations can be easily written in C++.

This amounts to have the possibility to handle operators (matrices) and states (vectors) as well as finding eigenvalues and eigenvectors of operators.

In particular, we would like to be able to write expectation values such

::

  <a|O|b>

as
 
::

  a*O*b

where b is a vector, a is (dual) vector and O is a matrix.
For example
::

            | 4 0 0 | | 1 | 
  | 1 1 1 | | 0 3 0 | ! 1 | = 9 
            | 0 0 2 | | 1 |

Moreover, we would like to be able to ask for eigenvalues and eigenvectors of a matrix as 
::

  O.eigenvalues();
  O.eigenvectors();

Change of basis would be easily implemented by triple products
::

   Ttransp * O * T

So we would end up with a generic framework to handle quantum systems! 

Assignment
~~~~~~~~~~

1. Using your matrix class (either the templated or the non-templated implementation), create two derived classes, rvector and and lvector.
   An rvector of size n would be a matrix with size (n,1) while an lvector would be a matrix of size (1,n). 

   In this way, the product a*O*b would be correctly calculated using the inherithed matrix::operator*

2. The rvector and lvector classes should implement a norm() function and a normalize() function. The former returns the norm without changing the object, 
   while the latter modifies the object, normalizing its components. You can use std::sqrt, contained in <cmath>

3. The result of the operation a*O*b would be matrix of size (1,1), not a number. By overloading the casting operator
   ::

     operator T() const;

   and making it return the first element of the data block, you would be to write expressions like
   ::

     double e = a*O*b;

   since the operator double() would take care of the conversion.
   
   (You may want to add a check that the matrix being casted is of (1,1), and issue a warning/error/exception in case the matrix is bigger) 

4. It may be handy to be able to transform an rvector into an lvector and viceversa. To this end create two copy constructors that create an
   lvector from rvector and viceversa. 

   (Optional) provide also an assignment operator.

5. Implement an eigenvalues() and eigenvectors() method. The signature can be
   ::
     
     T* eigenvalues() const; // return an array of T
     matrix<T> eigenvectors() const: // return a matrix with coefficients of eigenvectors

   Use dsyev and ssyev 
   ::
  
     LAPACKE_dsyev( int matrix_order, char jobz, char uplo, lapack_int n,
                          double* a, lapack_int lda, double* w );
     LAPACKE_ssyev (int matrix_order, char jobz, char uplo, lapack_int n, 
                          float *a, lapack_int lda, float *w)
  
   Where
   ::

     int matrix_order=LAPACK_ROW_MAJOR;
     char jobz='N'; // 'N' eigenvalues only, 'V' eigenvectors as well
     char uplo= 'U'; // just the upper triangluar part of the matrix is read
     double* a  // array of size m_n*m_n. On return, if jobz='V' contains the eigenvectors in its columns, if jobz='N' THE UPPER OR LOWER TRIANGULAR PART IS DESTROYED!!!!. 
     double* w // array of size m_n. On return contains the eigenvalues
   
   You will need 
   ::

     #include <lapacke.h>

   and link with 
   ::

     -llapack

6. Modify your eigenvalues() function to return either an lvector or an rvector. In this way, through inheritance, you would be able to write things like 
   :: 
   
     matrix<double> a;
     a.eigenvalues().print();

   if you have a print() method defined in your base class. 

7. (Optional) Implement a matrix::determinant(), by taking the product of its eigenvalues

8. (Optional) Specialize the template to handle complex number.
   Please notice that in the case of complex number, the rvector <---> lvector transformations would imply complex conjugation of the components.
  
   Moreover, in the norm() you should perform complex conjugation as well.

   To specialize the eigenvalues and eigenvectors() functions, and be able to use std::complex, you will need to define two preprocessor macros before including lapacke
   ::
  
     #define HAVE_LAPACK_CONFIG_H
     #define LAPACK_COMPLEX_CPP 
     #include <lapacke.h>

9. Implement a transpose method. For complex matrices, this will mean hermitian conjugation.

10. (Extension idea) In a non-euclidean space, you will need to use the metric to transform rvector in lvector. Think, without provinding implementation, on how to implement it. 

    Suggestions: you can consider that every matrix will be always considered with the first index covariant and the second countervariant. Your rvector and lvector will then be a strategy pattern, 
    that on construction can take an optional argument, a pointer to a matrix that is the metric. The rvector would take the purely countervariant version of the metric, while the lvector would 
    take the purely covariant version. In this way, when an rvector needs to be created from an lvector, a matrix multiplication (done in the proper way) can return the correct value.
   
    The metric pointer can be set by default to NULL. Your rvector <---> lvector transformations can then check if the pointer is NULL, and decide wheter to perform
    the matrix multiplication using the metric, or perform to usual transformation, by copy coordinantes (at most with a complex conjugation).


