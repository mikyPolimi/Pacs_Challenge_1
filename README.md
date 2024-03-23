# PACS Challenge 1

This project is a part of the Advanced Programming for Scientific Computing course at Politecnico di Milano. The goal of the project is to develop an iterative solver that computes the following:.
$$ x = \argmin_{\forall y \in \mathbb{R}^n} f(y) $$

## Introduction
Given an initial guess $x_0$ at every time step the algorithm computes: 
$$ x_{k+1} = x_k - \alpha_k \nabla f(x_k)   \enspace     k = 1,..., k_{max} $$
Where $\alpha$ is computed depending on the choice of the method used ( Exponential decay, Inverse decay or Aramijo)


## How to use

To use this project, follow these steps:

1. Clone the repository:
   ```bash
   $ git clone https://github.com/mikyPolimi/PACS_Challenge_1.git
   $ cd PACS_Challenge_1

2. If you want to modify the default choices go in `parameter.hpp` and select:


  - Function to minimize
  - Method for computing $\alpha$ (Exponential, Inverse, Aramijo)
  - Parameters for selected method ( $\mu$ for Exponential and Inverse, $\sigma$ for Aramijo)
  - Step length ($\varepsilon_s$)
  - Residual ($\varepsilon_r$)
  - Maximum number of iterations ($max \; iter$)


3. Run the code:
```bash
$ make
$ ./main
