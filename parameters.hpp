#pragma once



#include <vector>
#include <cmath>
#include <functional>

using Real = double;
using Vector = std::vector<Real>;


// Define an enumeration for different optimization methods
enum class Method { Exponential, Inverse, Armijo };


// selecting method of resolution:
constexpr Method M = Method::Armijo;


struct parameters{
  int max_iter = 1000;
  Real eps_r = 1e-6;
  Real eps_s = 1e-6;


 
 // constexpr Method M = Method::Armijo;
  // initial values
  Vector x0 = {0,0};
  Real alpha_0 = 0.1;

  // mu param for decay methods
  Real mu = 0.2;

  // Armijio rule

  // 0 < sigma < 0.5
  Real sigma = 0.1;


};



// Insert here the function you want to find the minimum of
Real function_(const Vector & x){
  return x[0]*x[1] + 4*std::pow(x[0], 4) + std::pow(x[1], 2) + 3*x[0];
}

// and here its gradient
Vector gradient_(const Vector & x){
  Vector grad(x.size());
  grad[0] = x[1] + 16*std::pow(x[0], 3) + 3;
  grad[1] = x[0] + 2*x[1];

  return grad;
}


void print_parameters(const parameters &params) {
  std::cout << std::endl;
    std::cout << "These are the parameters selected:" << std::endl;
    std::cout << "max_iter: " << params.max_iter << std::endl;
    std::cout << "eps_r: " << params.eps_r << std::endl;
    std::cout << "eps_s: " << params.eps_s << std::endl;
    std::cout << "x0: {";
    if (!params.x0.empty()) {
        auto it = params.x0.begin();
        std::cout << *it;
        ++it;
        for (; it != params.x0.end(); ++it)
            std::cout << ", " << *it;
    }
    std::cout << "}" << std::endl;
    std::cout << "alpha_0: " << params.alpha_0 << std::endl;
    std::cout << "mu: " << params.mu << std::endl;
    std::cout << "sigma: " << params.sigma << std::endl;
}