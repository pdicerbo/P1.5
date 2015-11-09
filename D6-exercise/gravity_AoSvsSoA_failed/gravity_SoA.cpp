/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: November 2015
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <sys/time.h>  
#define G 1.0
#define ALIGN 32

using namespace std;

double seconds()
{
  struct timeval tmp;
  double sec;
  gettimeofday( &tmp, (struct timezone *)0 );
  sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
  return sec;
}


template< typename T >
class planets
{
    public:
	/*vector<T> x;
	vector<T> y;
	vector<T> v_x;
	vector<T> v_y;
	vector<T> a_x;
	vector<T> a_y;
	vector<T> m;*/
	T* x;
	T* y;
	T* v_x;
	T* v_y;
	T* a_x;
	T* a_y;
	T* m;	
	planets(int);
	~planets();
	int get_n() const;
    private:
	int m_n;
	planets();


};

template< typename T >	
planets<T>::planets()
{

}

template< typename T >
planets<T>::planets(int n)
{
	m_n=n;
	/*x.reserve(m_n);
	y.reserve(m_n);
	v_x.reserve(m_n);
	v_y.reserve(m_n);
	a_x.reserve(m_n);
	a_y.reserve(m_n);
	m.reserve(m_n);*/
	posix_memalign((void **)&x, ALIGN, m_n*sizeof(T));
	posix_memalign((void **)&y, ALIGN, m_n*sizeof(T));
	posix_memalign((void **)&v_x, ALIGN, m_n*sizeof(T));
	posix_memalign((void **)&v_y, ALIGN, m_n*sizeof(T));
	posix_memalign((void **)&a_x, ALIGN, m_n*sizeof(T));
	posix_memalign((void **)&a_y, ALIGN, m_n*sizeof(T));
	posix_memalign((void **)&m, ALIGN, m_n*sizeof(T));
}

template< typename T >
planets<T>::~planets()
{
	free(x);
	free(y);
	free(v_x);
	free(v_y);
	free(a_x);
	free(a_y);
	free(m);

}

template< typename T >
int planets<T>::get_n() const
{
	return m_n;
}


template<typename T>
T CalcDen( T x1, T y1, T x2, T y2)
{
        return pow(sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)),3);
}


template <typename T>
void UpdateAccelerations( planets< T > & state)
{
	int size=state.get_n();
	T den;
	for (int i=0; i<size ; i++)
		{
		T sum_x=static_cast<T>(0.0);
	        T sum_y=static_cast<T>(0.0);
		T x_pos = state.x[i];
		T y_pos = state.y[i];
		for (int j=0; j<size; j++)
			{
			if (j!=i)
				{
                                den=CalcDen(x_pos,y_pos, state.x[j], state.y[j]);
                                sum_x += - (state.m[j])/den*(x_pos-state.x[j]);
                                sum_y += - (state.m[j])/den*(y_pos-state.y[j]);
				}
			}
		state.a_x[i]=G*sum_x;
		state.a_y[i]=G*sum_y;
		}
}


template <typename T>
void UpdatePositions( planets< T > & state, T dt)
{
	int size=state.get_n();
	for (int i=0; i<size ; i++)
                {
		state.x[i] += state.v_x[i] * dt;
		state.y[i] += state.v_y[i] * dt;
		}
}

template <typename T>
void UpdateVelocities( planets< T > & state, T dt)
{
	int size=state.get_n();
        for (int i=0; i<size ; i++)
                {
                state.v_x[i] += state.a_x[i] * dt;
                state.v_y[i] += state.a_y[i] * dt;
                }
}


template <typename T>
void evolve( planets< T > & state, T dt)
{

	UpdateAccelerations<T>(state);
	UpdatePositions<T>(state,dt);
	UpdateVelocities<T>(state,dt);
}

template <typename T>
T random_range( T min, T max)
{
	T range=max-min;
	return static_cast<T>(rand())/RAND_MAX*range + min;
}

template <typename T>
void print_out(ofstream& output, planets< T > & state)
{
	int size=state.get_n();
	// set xc and yc to re-center the system
	T xc=0.0; //state.x[0];
	T yc=0.0; //state.y[0];
        for (int i=0; i<size ; i++)
                {
		output << fixed <<  state.x[i]-xc << " " << state.y[i]-yc << endl;
		}
	output << endl << endl;
}


int main(int argc, char** argv)
{
	if ( argc != 4)
		{
		cout << " Usage : " << argv[0] << " [number of planets] [number of time steps] [dt] " << endl; 
		return 0;
		}

	cout << " Gravity code : SoA version " << endl;
	double max_pos= 10;
	double max_v= 1;
	int num=atoi(argv[1]);
	int steps=atoi(argv[2]);
	double dt=atof(argv[3]);
	planets<double> state(num);

	srand(time(NULL));
        for (int i=0; i<state.get_n() ; i++)
                {
		state.x[i]= random_range( -max_pos, max_pos);
		state.y[i]= random_range( -max_pos, max_pos);	
		state.v_x[i]= random_range( -max_v, max_v);
		state.v_y[i]= random_range( -max_v, max_v);
		state.a_x[i]=0.0;
		state.a_y[i]=0.0;
		state.m[i]=random_range( 1.0, 100.0);
		}
/*
	state.x[0]=1.0;
	state.y[0]=0.0;
	state.v_x[0]=0.0;
	state.v_y[0]=sqrt(1.5);
	state.x[1]=0.0;
        state.y[1]=0.0;
        state.v_x[1]=0.0;
        state.v_y[1]=0.0;
	state.m[0]=1.0;
	state.m[1]=1.0;
*/
#ifdef DEBUG
	ofstream output("output.dat");
#endif
	double t1=seconds();
	for (int t=0; t<steps; t++)
		{
#ifdef DEBUG
		if (t%100==0)
			{
			print_out<double>(output, state);
			}
#endif
		evolve<double>(state, dt);
		}
	t1=seconds()-t1;
	cout << " planets: " << num << " time/iter: " << t1/steps << " s   total time: " << t1 << " s " << endl;
#ifdef DEBUG
	output.close();
#endif
	return 0;

}
