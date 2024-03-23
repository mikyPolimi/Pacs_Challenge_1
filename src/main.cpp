#include <iostream>
#include "compute_gradient.hpp"



int main (){

    parameters p;
    Vector x = p.x0;

    // create function_wrapper giving the value of function_ defined in parameters, that is the function we want to find the minimum
    function_wrapper f(function_);
    gradient_wrapper grad(gradient_);
    // compute the argmin 
    if constexpr (grad_mode == Grad::Exact);
    Vector min = compute_minimum<grad_mode>(p,f,grad);

    return 0;
}