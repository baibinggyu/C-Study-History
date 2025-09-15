#include "MathFunctions.h"

#include <cmath>

#ifdef USE_MYMATH
#  include "mysqrt.h"
#endif

namespace mathfunctions {
double sqrt(double x)
{
// 我们应该使用哪个平方根函数？
#ifdef USE_MYMATH
  return detail::mysqrt(x);
#else
  return std::sqrt(x);
#endif
}
}
