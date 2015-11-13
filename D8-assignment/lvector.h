#ifndef LVECTOR_HEADER
#define LVECTOR_HEADER

#include "MyMatrix.h"

template <typename T>

//class lvector<T>;

class lvector : public Matrix<T>{

 public:
  lvector(int);
  ~lvector();

};

#endif /* LVECTOR_HEADER */
