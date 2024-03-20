#include <vector>
#include <cmath>
#include <functional>

using real = double;
using vector = std::vector<real>;

struct parameters{
    int max_iter = 1000;
};


real function(const vector & x){
  /** @brief Function to be minimized
   *  @param x: vector of variables
   *  @return value of the function
   */

  return x[0]*x[1] + 4*std::pow(x[0], 4) + std::pow(x[1], 2) + 3*x[0];
}


vector gradient(const vector & x){
  /** @brief Gradient of the function to be minimized
   *  @param x: vector of variables
   *  @return gradient of the function
   */
  vector grad(x.size());
  grad[0] = x[1] + 16*std::pow(x[0], 3) + 3;
  grad[1] = x[0] + 2*x[1];

  return grad;
}