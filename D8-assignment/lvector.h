#ifndef LVECTOR_HEADER
#define LVECTOR_HEADER

#include "MyMatrix.h"

template <typename T>

//class lvector<T>;

class lvector : public Matrix<T>{

 public:
  lvector(int);
  ~lvector();
  T norm() const;
  void normalize();
};

#endif /* LVECTOR_HEADER */
