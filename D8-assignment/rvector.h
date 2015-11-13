#ifndef RVECTOR_HEADER
#define RVECTOR_HEADER

#include "MyMatrix.h"

template <typename T>
class lvector;

template<typename T>
class rvector : public Matrix<T>{

 public:
  rvector(int);
  ~rvector();
  rvector(const lvector<T>&);
  rvector& operator=(const lvector<T>&);
  T& operator()(const int);
  T norm() const;
  void normalize();
};

#endif /* RVECTOR_HEADER */
