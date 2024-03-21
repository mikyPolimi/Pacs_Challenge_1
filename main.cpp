#include <iostream>
#include "parameters.hpp"


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


void print_result(Vector & x,const function_wrapper& f, int k, bool convergence,Real alpha){
  std::cout << "number iterations: " << k << std::endl;
  std::cout << "argmin is equal to" << std::endl;
  for(auto& i : x)
    std::cout << i << std::endl;
  std::cout << "The function evaluated in that point is: " << f(x) << std::endl;
  std::cout << "alpha: " << alpha << std::endl;
  return;
}


// compute minimum

Vector compute_minimum(const parameters& p, const function_wrapper& f, const gradient_wrapper& grad){
  Real alpha = p.alpha_0;
  Vector x_old = p.x0;
  Vector x_new(x_old.size());
  bool convergence = false;
  int k = 0;
  while (!convergence and k < p.max_iter){

    // compute grad(x_k)
    Vector grad_k = grad(x_old);

    // find alpha
    
    // exponential decay
    alpha = p.alpha_0*std::exp(-p.mu*k);
    
    // Inverse Decay
   // alpha = p.alpha_0 / ( 1 + p.mu * k );
    /*
    // Armijo rule
    alpha = p.alpha_0;
    bool armijio_condition = false;
    while(!armijio_condition){

      armijio_condition = f(x_old) - f(subtraction(x_old, scalar_vector(alpha,grad_k) )) >= p.sigma*alpha*norm(grad_k)*norm(grad_k);
      alpha /= 2;
    }
*/

    // x_{k+1} = x_{k} - alpha_{k} * grad(f(x_{k}))
    x_new = subtraction(x_old,scalar_vector(alpha, grad_k));


    // update convergence
    Real step = norm(subtraction(x_new,x_old));
    Real residual = std::abs(f(x_new)-f(x_old));
    convergence = step < p.eps_s or residual < p.eps_r;

    
    
    // updating n_iter
    ++k;

    // updating x_k
    x_old = x_new;

  }
  print_result(x_new,f,k,convergence,alpha);
  return x_new;

}



int main (){

    std::cout<<"hello world"<<std::endl;
    parameters p;
    Vector x = p.x0;

    // create function we want to find a minimumm of and its gradient as wrappers
    function_wrapper f(function_);
    gradient_wrapper grad(gradient_);

    Vector min = compute_minimum(p,f,grad);

    return 0;
}