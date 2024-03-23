#pragma once

#include "operations.hpp"

struct function_wrapper{
    std::function<Real(const Vector&)> f;
    function_wrapper(std::function<Real(const Vector&)> fun): f(fun){};
    Real operator()(const Vector& x) const{
        return f(x);
    }
};


Vector grad_approx(const Vector& x, std::function<Real(const Vector&)> f, Real h = 1e-6){
  Vector grad(x.size());
  for(size_t i = 0 ; i < x.size() ; ++i){
    Vector x_next{x}, x_prev{x};
    x_next[i] += h;
    x_prev[i] -= h;
    grad[i] = 0.5 * (f(x_next) - f(x_prev)) / h;
  }
return grad;
}


// template < int grad_mode > 
struct gradient_wrapper{

  std::function<Vector(const Vector&)> grad;
  gradient_wrapper(std::function<Vector(const Vector&)> g): grad(g){};
  Vector operator()(const Vector& x) const{
      return grad(x);
  }

};