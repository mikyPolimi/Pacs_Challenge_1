#pragma once 

#include "parameters.hpp"


Real norm(const Vector& x){
    Real sum = 0;
    for(const auto& i : x)
        sum += i*i;
    return std::sqrt(sum);

};

Vector scalar_vector( const Real alpha, Vector& x){
  // Scalar * vector
  // @param x: vector
  //  @param alpha: scalar
  Vector y(x);
  for(auto & i : y)
    i *= alpha;
  return y;
}
Vector subtraction(const Vector & x1, const Vector & x2){
  /** @brief Subtraction of two vectors
   *  @param x1: vector
   *  @param x2: vector to subtract
   *  @return subtraction of the two vectors
   */
  Vector y(x1.size());
  for(size_t i = 0; i < x1.size(); ++i)
    y[i] = x1[i] - x2[i];
  return y;

}

Vector sum(const Vector & x1, const Vector & x2){
  /** @brief Sum of two vectors
   *  @param x1: vector
   *  @param x2: vector to subtract
   *  @return element-wise sum of the two vectors
   */
  Vector y(x1.size());
  for(size_t i = 0; i < x1.size(); ++i)
    y[i] = x1[i] + x2[i];
  return y;
};