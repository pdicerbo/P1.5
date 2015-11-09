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
class planet
{
    public:
	T x;
	T y;
	T v_x;
	T v_y;
	T a_x;
	T a_y;
	T m;	
};

template<typename T>
T CalcDen( T x1, T y1, T x2, T y2)
{
        return pow(sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)),3);
}


template <typename T>
void UpdateAccelerations( vector< planet< T > >& state)
{
	int size=state.size();
	T den;
	for (int i=0; i<size ; i++)
		{
		T sum_x=static_cast<T>(0.0);
	        T sum_y=static_cast<T>(0.0);
		T x_pos = state[i].x;
		T y_pos = state[i].y;
		for (int j=0; j<size; j++)
			{
			if (j!=i)
				{
				den=CalcDen(x_pos,y_pos, state[i].x, state[j].y);
				sum_x += - (state[j].m)/den*(x_pos-state[j].x);
				sum_y += - (state[j].m)/den*(y_pos-state[j].y);
				}
			}
		state[i].a_x=G*sum_x;
		state[i].a_y=G*sum_y;
		}
}


template <typename T>
void UpdatePositions( vector< planet< T > >& state, T dt)
{
	int size=state.size();
	for (int i=0; i<size ; i++)
                {
		state[i].x += state[i].v_x * dt;
		state[i].y += state[i].v_y * dt;
		}
}

template <typename T>
void UpdateVelocities( vector< planet< T > >& state, T dt)
{
	int size=state.size();
        for (int i=0; i<size ; i++)
                {
                state[i].v_x += state[i].a_x * dt;
                state[i].v_y += state[i].a_y * dt;
                }
}


template <typename T>
void evolve( vector< planet< T > >& state, T dt)
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
void print_out(ofstream& output, vector< planet< T > >& state)
{
	int size=state.size();
	// set xc and yc to re-center the system
	T xc=0.0; //state[0].x;
	T yc=0.0; //state00].y;
        for (int i=0; i<size ; i++)
                {
		output << fixed <<  state[i].x-xc << " " << state[i].y-yc << endl;
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
	cout << " Gravity code : AoS version " << endl;
	double max_pos= 10;
	double max_v= 1;
	int num=atoi(argv[1]);
	int steps=atoi(argv[2]);
	double dt=atof(argv[3]);
	vector<planet<double> > state(num);

	srand(time(NULL));
        for (int i=0; i<state.size() ; i++)
                {
		state[i].x= random_range( -max_pos, max_pos);
		state[i].y= random_range( -max_pos, max_pos);	
		state[i].v_x= random_range( -max_v, max_v);
		state[i].v_y= random_range( -max_v, max_v);
		state[i].a_x=0.0;
		state[i].a_y=0.0;
		state[i].m=random_range( 1.0, 100.0);
		}
/*
	state[0].x=1.0;
	state[0].y=0.0;
	state[0].v_x=0.0;
	state[0].v_y=sqrt(1.5);
	state[1].x=0.0;
        state[1].y=0.0;
        state[1].v_x=0.0;
        state[1].v_y=0.0;
	state[0].m=1.0;
	state[1].m=1.0;
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
