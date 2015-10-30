D3-exercise
===========

Create a square matrix class, by deriving from the matrix class.

Requirments

  - the custom constructor should take one argument squarematrix(int i). The matrix constructo should be called in initialization list
  - rememeber to make you destructor virtual, to correctly destroy the squarematrix object from a matrix pointer. This means that 
    ::

      squarematrix* a=new squarematrix(2); 
      matrix* b=a;
      delete b;
    
    should correctly call the squarematrix destructor first.
  - implement in both matrix and squarematrix a virtual trace() method. For the matrix class this should just return 0.0 and maybe a warning. The following code should be giving the right result
    ::

      squarematrix* a=new squarematrix(2);
      a(0,0)=3.0;
      a(1,0)=0.0;
      a(0,1)=2.0;
      a(1,1)=5.0;
      matrix* b=a;
      b->trace();  //should give 8 and not 0

  - to be able to use the operator* of your base class, you need to define a copy constructor from matrix to squarematrix in your derived class
    ::

      squarematrix::squarematrix(const matrix& mat)

    Remember that user-defined copy constructors WILL NOT call any of the parent copy-constructor (while compiler provided ones do call parent copy constructor.. This is also true for compiler provided assignment operators).  

  - check that the above step it is enough to do
    ::

      squarematrix a(2),b(2);
      sqaurematrix c=a*b;
      c=b*a;

    without the need of defining operator* and operator= in your derived class (although with some additional copies)
