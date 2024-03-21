#include <vector>
#include <cmath>
#include <functional>

using Real = double;
using Vector = std::vector<Real>;

struct parameters{
  int max_iter = 1000;
  Real eps_r = 1e-6;
  Real eps_s = 1e-6;

    // initial values
    Vector x0 = {0,0};
    Real alpha_0 = 0.1;

  // mu param for decay methods
  Real mu = 0.2;

  // Armijio rule

  // 0 < sigma < 0.5
  Real sigma = 0.1;


};


Real function_(const Vector & x){
  /** @brief Function to be minimized
   *  @param x: vector of variables
   *  @return value of the function
   */

  return x[0]*x[1] + 4*std::pow(x[0], 4) + std::pow(x[1], 2) + 3*x[0];
}


Vector gradient_(const Vector & x){
  /** @brief Gradient of the function to be minimized
   *  @param x: vector of variables
   *  @return gradient of the function
   */
  Vector grad(x.size());
  grad[0] = x[1] + 16*std::pow(x[0], 3) + 3;
  grad[1] = x[0] + 2*x[1];

  return grad;
}