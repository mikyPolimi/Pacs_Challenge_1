#pragma once

#include "operations.hpp"

struct function_wrapper{
    std::function<Real(const Vector&)> f;
    function_wrapper(std::function<Real(const Vector&)> fun): f(fun){};
    Real operator()(const Vector& x) const{
        return f(x);
    }
   
};



struct gradient_wrapper{

  std::function<Vector(const Vector&)> grad;
  gradient_wrapper(std::function<Vector(const Vector&)> g): grad(g){};
 // gradient_wrapper(std::function<Real(const Vector&)> g): grad(g){};
  Vector operator()(const Vector& x) const{
      return grad(x);
  }

};


struct approx_gradient_wrapper