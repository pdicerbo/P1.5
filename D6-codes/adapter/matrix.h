/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: November 2015
 */

#ifndef __MATRIX_H
#define __MATRIX_H
#ifdef USEBLAS
#include <cblas.h>
#endif
#include <iostream>

template <class T>
class matrix
{

	private:
		T* data;
		T dump;

	protected:
                int m_n, m_m;
		matrix();
      
	public:
		virtual const T trace(void) const { return 0.0f; };
		matrix(int, int);
		virtual ~matrix();
		matrix(const matrix<T> & mat);
		int get_n(void) const;
		int get_m(void) const;
		void print(void) const;
        	matrix<T> &operator=(const matrix<T>& );
		const matrix<T> operator*(const matrix<T>&) const;
		T* operator[](int ) const;
		const T &operator()(int, int ) const;
		T &operator()(int, int );
};

template<class T>
matrix< T > ::matrix()
{
#ifdef DEBUG
        std::cout << " default matrix constructor " << std::endl;
#endif
}

template<class T>
matrix< T >::matrix(int n, int m) 
:
m_n(n),
m_m(m)
{
#ifdef DEBUG
        std::cout << " custom matrix constructor " << std::endl;
#endif
	data=new T[m_m*m_n];
}

template<class T>
matrix< T >::~matrix()
{
#ifdef DEBUG
        std::cout << " matrix destructor " << std::endl;
#endif
	delete [] data;
}

template<class T>
matrix<T>::matrix(const matrix<T> & mat)
{
#ifdef DEBUG
	std::cout << " matrix copy constructor" << std::endl; 
#endif
	m_m=mat.get_m();
	m_n=mat.get_n();
        data=new T[m_m*m_n];
	for (int i=0; i<m_n;i++)
		for (int j=0; j<m_m; j++)
			data[i*m_m+j]=mat.data[i*m_m+j];
}

template<class T>
int matrix<T>::get_n() const
{
  return m_n;
}


template<class T>
int matrix<T>::get_m() const
{
  return m_m;
}


template<class T>
void matrix<T>::print() const
{
	for (int i=0; i<m_n;i++)
		{
		for (int j=0; j<m_m; j++)
                	std::cout << " " << data[i*m_m+j];
      		std::cout<<std::endl;
		}
}

template<class T>
matrix<T>& matrix<T>::operator=(const matrix& mat)
{
	if (this != &mat)
		{
#ifdef DEBUG
		std::cout << " matrix assignment operator " << std::endl;
#endif
		delete [] data;
		m_m=mat.m_m;
		m_n=mat.m_n;
		data=new T[m_m*m_n];
        	for (int i=0; i<m_n;i++)
                	for (int j=0; j<m_m; j++)
                        	data[i*m_m+j]=mat.data[i*m_m+j];
		}
	return *this;	
}

template<class T>
const matrix<T> matrix<T>::operator*(const matrix<T>& mat) const
{
	matrix c(get_n(), mat.get_m());
	if (get_m() != mat.get_n())
		{
		std::cerr <<"incompatible shapes" << std::endl;
		for(int i=0; i < c.get_n()*c.get_m();i++)
			c.data[i] = 0.0f;
		return c;
		}

	T temp;
	for(int i=0; i < get_n();i++)
		for (int j=0; j < mat.get_m(); j++)
			{
			temp = 0.0f;
			for (int k=0; k< get_m(); k++)
				temp += data[i*get_m()+k] * mat.data[k*mat.get_m()+j];
			c.data[i*c.get_m()+j] = temp;
			}
	return c;		
}

template<class T>
T* matrix<T>::operator[](int i) const
{
	return &data[i*m_m];
}

template<class T>
const T& matrix<T>::operator()(int i, int j) const 
{
#if DEBUG == 2 
	std::cout << " const matrix operator()(int i, int j)  " << std::endl;
#endif
	if (i>=0 and j>=0 and i<m_n and j<m_m)
		{
		return data[i*m_m+j];
		}
	else
		{
		std::cerr << " index out of bound! " << std::endl;
		return dump; 
		}
}

template<class T>
T& matrix<T>::operator()(int i, int j)
{
#if DEBUG == 2
	std::cout << " non-const matrix operator()(int i, int j) " << std::endl;
#endif
        if (i>=0 and j>=0 and i<m_n and j<m_m)
                {
                return data[i*m_m+j];
                }
        else
                {
                std::cerr << " index out of bound! " << std::endl;
                return dump;
                }
}


template<>
const matrix<double> matrix<double>::operator*(const matrix<double>& mat) const
{
        matrix c(get_n(), mat.get_m());
        if (get_m() != mat.get_n())
                {
                std::cerr <<"incompatible shapes" << std::endl;
                for(int i=0; i < c.get_n()*c.get_m();i++)
                        c.data[i] = 0.0;
                return c;
                }

#ifdef USEBLAS
#ifdef DEBUG
	std::cout << " specialized operator* - using cblas_dgemm " << std::endl;
#endif
	double alpha=1.0;
	double beta=0.0;
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m_n, mat.m_m, m_m, alpha, data, m_m, mat.data, mat.m_m, beta, c.data, c.m_m);
#else
#ifdef DEBUG
	std::cout << " specialized operator* - using local implementation for double " << std::endl;
#endif
	double temp;
        for(int i=0; i < get_n();i++)
                for (int j=0; j < mat.get_m(); j++)
                        {
                        temp = 0.0;
                        for (int k=0; k< get_m(); k++)
                                temp += data[i*get_m()+k] * mat.data[k*mat.get_m()+j];
                        c.data[i*c.get_m()+j] = temp;
                        }
#endif
        return c;
}

template<>
const matrix<float> matrix<float>::operator*(const matrix<float>& mat) const
{
        matrix c(get_n(), mat.get_m());
        if (get_m() != mat.get_n())
                {
                std::cerr <<"incompatible shapes" << std::endl;
                for(int i=0; i < c.get_n()*c.get_m();i++)
                        c.data[i] = 0.0f;
                return c;
                }

#ifdef USEBLAS
#ifdef DEBUG
        std::cout << " specialized operator* - using cblas_sgemm " << std::endl;
#endif
        float alpha=1.0f;
        float beta=0.0f;
        cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m_n, mat.m_m, m_m, alpha, data, m_m, mat.data, mat.m_m, beta, c.data, c.m_m);
#else
#ifdef DEBUG
        std::cout << " specialized operator* - using local implementation for float " << std::endl;
#endif
        float temp;
        for(int i=0; i < get_n();i++)
                for (int j=0; j < mat.get_m(); j++)
                        {
                        temp = 0.0f;
                        for (int k=0; k< get_m(); k++)
                                temp += data[i*get_m()+k] * mat.data[k*mat.get_m()+j];
                        c.data[i*c.get_m()+j] = temp;
                        }
#endif
        return c;
}


#endif
