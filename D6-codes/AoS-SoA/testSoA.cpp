#include <iostream>
#include <cstdlib>
#include <sys/time.h>

using namespace std;

double seconds()
{
  struct timeval tmp;
  double sec;
  gettimeofday( &tmp, (struct timezone *)0 );
  sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
  return sec;
}

//AoS
typedef struct
{
        double x;
        double y;
        double z;

} point;


//SoA
typedef struct 
{
	double* x;
	double* y;
	double* z;

} points;


point centerOfMassSoA(points state, int num, int iter)
{
        point p;
        double posX,posY,posZ;
	for (int j=0; j< iter; j++)
		{
		#pragma simd
	        for(int i=0;i<num;i++)
        	        {
                	posX+=state.x[i];
			}
		#pragma simd
                for(int i=0;i<num;i++)
                        {
                	posY+=state.y[i];
			}
		#pragma simd
                for(int i=0;i<num;i++)
                        {
               		posZ+=state.z[i];
               		}
		}
        p.x=posX/num;
        p.y=posY/num;
        p.z=posZ/num;

 
        return p;

}



int main(int argc, char** argv)
{
        if ( argc != 3)
                {
		cout << " Center of Mass SoA " << endl;
                cout << " Usage : " << argv[0] << " [number of points] [iterations] " << endl;
                return 0;
                }

        cout << " Center of Mass SoA " << endl;
	
	int num=atoi(argv[1]);
	int iter=atoi(argv[2]);

	//SoA
	points pointSoA;
	pointSoA.x=new double[num];
	pointSoA.y=new double[num];
	pointSoA.z=new double[num];

	cout << " Size " << num*3.0*sizeof(double)/1000000 << " MB " << iter<<endl;

        double t1=seconds();
	point s=centerOfMassSoA(pointSoA, num, iter);
        cout << " SoA center of mass took " << seconds() - t1 << " s  " << s.x << endl;
	
	delete [] pointSoA.x;
	delete [] pointSoA.y;
	delete [] pointSoA.z;
	return 0;
}
