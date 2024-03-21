#include <iostream>
#include "parameters.hpp"


struct function_wrapper{
    std::function<Real(const Vector&)> f;
    function_wrapper(std::function<Real(const Vector&)> fun): f(fun){};
    Real operator()(const Vector& x){
        return f(x);
    }
};


struct gradient_wrapper{
    std::function<Vector(const Vector&)> grad;
    gradient_wrapper(std::function<Vector(const Vector&)> g): grad(g){};
    Vector operator()(const Vector& x) const{
        return grad(x);
    }
};

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


// compute minimum

Real compute_minimum(const parameters& p, const function_wrapper& f, const gradient_wrapper& grad){
    Real alpha = p.alpha_0;
    Vector x_old = p.x0;
    Vector x_new(x_old.size());
    bool convergence = false;
    int n = 0;
    while (!convergence and n < p.max_iter){
      Vector v = grad(x_old);
      x_new = subtraction(x_old,scalar_vector(alpha, v));
    }

}



int main (){

    std::cout<<"hello world"<<std::endl;

    return 0;
}