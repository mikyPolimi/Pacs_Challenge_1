#pragma once 

#include "parameters.hpp"


Real norm(const Vector& x){
  // compute the norm of a given vector
    Real sum = 0;
    for(const auto& i : x)
        sum += i*i;
    return std::sqrt(sum);

};

Vector scalar_vector( const Real alpha, Vector& x){
  // compute Scalar * vector
  Vector y(x);
  for(auto & i : y)
    i *= alpha;
  return y;
}

Vector subtraction(const Vector & x1, const Vector & x2){
  // compute the difference of the two vectors
  Vector y(x1.size());
  for(size_t i = 0; i < x1.size(); ++i)
    y[i] = x1[i] - x2[i];
  return y;

}

Vector sum(const Vector & x1, const Vector & x2){
// compute the sum of the two vectors
  Vector y(x1.size());
  for(size_t i = 0; i < x1.size(); ++i)
    y[i] = x1[i] + x2[i];
  return y;
};