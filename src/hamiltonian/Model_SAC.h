#ifndef MODEL_SAC_H
#define MODEL_SAC_H

#include "../mmath/libmmath.h"
using namespace libmmath;

namespace libhamiltonian{


void SAC_Ham(double x, MATRIX* H, MATRIX* dH, MATRIX* d2H, vector<double>& params_);
boost::python::list SAC_Ham(double x, boost::python::list params_);


}//namespace libhamiltonian

#endif // MODEL_SAC
