#include <iostream>
#include "compute_gradient.hpp"

int main (){

    parameters p;
    Vector x = p.x0;

    // create function_wrapper giving the value of function_ defined in parameters, that is the function we want to find the minimum
    function_wrapper f(function_);
    gradient_wrapper grad(gradient_);
    // compute the argmin 
    print_parameters(p);
    Vector min = compute_minimum(p,f,grad);

    return 0;
}