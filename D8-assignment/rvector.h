#ifndef RVECTOR_HEADER
#define RVECTOR_HEADER

#include "MyMatrix.h"

template <typename T>

//class lvector<T>;

class rvector : public Matrix<T>{

 public:
  rvector(int);
  ~rvector();
  T norm() const;
  void normalize();
};

#endif /* RVECTOR_HEADER */
