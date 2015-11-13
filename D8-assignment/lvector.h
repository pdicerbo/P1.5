#ifndef LVECTOR_HEADER
#define LVECTOR_HEADER

#include "MyMatrix.h"

/* template class rvector; */
template<typename T>
class rvector;

template <typename T>
class lvector : public Matrix<T>{

 public:
  lvector(int);
  ~lvector();
  lvector(const rvector<T>&);
  lvector& operator=(const rvector<T>&);
  T norm() const;
  void normalize();
};

#endif /* LVECTOR_HEADER */
