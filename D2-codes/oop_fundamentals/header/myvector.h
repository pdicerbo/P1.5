/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */
#ifndef MY_VECTOR_HEADER
#define MY_VECTOR_HEADER
class myvector
{
   private:
        int m_n;
        myvector();
   public:
        float *data;
        int get_n();
        float norm();
        myvector(int n);
        ~myvector();
};
#endif
