/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: November 2015
 */

#ifndef __MYBOOSTMATRIX_H
#define __MYBOOSTMATRIX_H
#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>


template<class T>
class MyBoostMatrix
{
public:
    MyBoostMatrix(unsigned int m,unsigned int n) : mat(m,n)
    {};

    MyBoostMatrix(const boost::numeric::ublas::matrix<T> &in) : mat(in)
    {};

    void non_zero_init() {

        for (unsigned int i=0; i<mat.size1(); i++)
            for (unsigned int j=0; j<mat.size2(); j++)
                mat(i,j)=i*mat.size1()+j+1.;
    };

    void print() const
    {
        std::cout << mat << std::endl;
    };

    boost::numeric::ublas::matrix<T> get_boost_matrix() const 
    {
        return mat;
    };

    const MyBoostMatrix<T> operator*(const MyBoostMatrix<T>& B) const
    {
        const boost::numeric::ublas::matrix<T> b = B.get_boost_matrix();
        boost::numeric::ublas::matrix<T>  c = boost::numeric::ublas::prod(mat, b);

        return MyBoostMatrix<T>(c);
    };


private:
    boost::numeric::ublas::matrix<T> mat;
};

#endif
