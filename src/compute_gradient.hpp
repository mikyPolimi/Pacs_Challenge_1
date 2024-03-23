#pragma once

#include "../include/wrappers.hpp"

void print_result(Vector & x,const function_wrapper& f, int k, bool convergence){
  std::cout << "number iterations: " << k << std::endl;
  std::cout << "argmin is equal to" << std::endl;
  for(auto& i : x)
    std::cout << i << std::endl;
  std::cout << "The function evaluated in that point is: " << f(x) << std::endl;
  return;
}


// Function template with a method enum as a template parameter
// in this way the if statement will be known at compile time, and not computed everytime 
template<Method M>
Real compute_alpha(const parameters& p, const function_wrapper& f, const Vector& x, Vector grad_k, int k) {
    if constexpr (M == Method::Exponential)
     // exponential decay
        return p.alpha_0*std::exp(-p.mu*k);
    else if constexpr (M == Method::Inverse)
     // Inverse Decay
        return p.alpha_0 / ( 1 + p.mu * k );
    else if constexpr (M == Method::Armijo){
      // Armijo rule
    Real alpha = p.alpha_0;
    bool armijo_condition = false;
    // loop until the Armijo condition is verified
    while(!armijo_condition){
      armijo_condition = f(x) - f(subtraction(x, scalar_vector(alpha,grad_k) )) >= p.sigma*alpha*norm(grad_k)*norm(grad_k);
      alpha /= 2;
    }
        return alpha; 
    }
    else {
        std::cerr << "Unknown method" << std::endl;
        return 0.0;
    }
}




// in un caso G è un gradient_wrapper 
// nell'altro è un vettore 
template <typename G>
Vector compute_minimum(const parameters& p, const function_wrapper& f){
   Real alpha = p.alpha_0;
  Vector x_old = p.x0;
  Vector x_new(x_old.size());
  bool convergence = false;
  int k = 0;
  while (!convergence and k < p.max_iter){
    // compute grad(x_k)
    Vector grad_k = G(x_old);

    //
    Vector grad_k = grad_approx(f,x_old)
}















// compute minimum
template <Grad grad_mode>
Vector compute_minimum(const parameters& p, const function_wrapper& f, const gradient_wrapper& grad){
  Real alpha = p.alpha_0;
  Vector x_old = p.x0;
  Vector x_new(x_old.size());
  bool convergence = false;
  int k = 0;
  while (!convergence and k < p.max_iter){
    // compute grad(x_k)
    Vector grad_k(x_old.size());
    if constexpr (grad_mode == Grad::Exact)
      Vector grad_k = grad(x_old);
    else // ( grad_mode == Grad::Approx)
    {
      Vector grad_k = grad_approx(f,x_old);
      std::cout << grad_k[0] << grad_k[1] << std::endl;
     }
    //else
      //std::cerr << "grad mode not valid" << std::endl;

    // find alpha
    alpha = compute_alpha<M>(p,f,x_old,grad_k, k);


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
  print_result(x_new,f,k,convergence);
  return x_new;

}
