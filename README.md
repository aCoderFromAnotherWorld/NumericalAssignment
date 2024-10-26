<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Numerical Methods Console Application</title>
  <style>
    body { font-family: Arial, sans-serif; margin: 0 2em; }
    h1, h2, h3, h4 { color: #333; }
    ul { list-style-type: none; padding: 0; }
    li { margin: 0.5em 0; }
    code { background-color: #f4f4f4; padding: 0.2em 0.4em; border-radius: 4px; }
  </style>
</head>
<body>

<h1>Numerical Methods Console Application</h1>

<p>This console application, written in C++, provides implementations of several numerical methods for solving linear equations, non-linear equations, differential equations, and performing matrix inversion. All methods are modularly included in header files for easy integration and usage.</p>

<h2>Table of Contents</h2>
<ul>
  <li><a href="#solution-of-linear-equations">Solution of Linear Equations</a></li>
  <li><a href="#solution-of-non-linear-equations">Solution of Non-linear Equations</a></li>
  <li><a href="#solution-of-differential-equations">Solution of Differential Equations</a></li>
  <li><a href="#matrix-inversion">Matrix Inversion</a></li>
  <li><a href="#requirements">Requirements</a></li>
  <li><a href="#how-to-run">How to Run</a></li>
  <li><a href="#usage-example">Usage Example</a></li>
</ul>

<h2 id="solution-of-linear-equations">Solution of Linear Equations</h2>

<h3>Jacobi Iterative Method</h3>
<p>The Jacobi method is an iterative technique to solve a system of linear equations. Each equation is solved for a specific variable, assuming the remaining variables' values are constant in each iteration. This method is suitable for diagonally dominant matrices.</p>

<h3>Gauss-Seidel Iterative Method</h3>
<p>The Gauss-Seidel method is similar to the Jacobi method, but each variable is updated as soon as a new value is available in each iteration. This often results in faster convergence than the Jacobi method.</p>

<h3>Gauss Elimination</h3>
<p>The Gauss elimination method transforms a system of linear equations into an upper triangular matrix form. The solution can then be found using back-substitution. This method is one of the most commonly used elimination techniques.</p>

<h3>Gauss-Jordan Elimination</h3>
<p>Gauss-Jordan elimination extends Gauss elimination by transforming the matrix into a reduced row-echelon form. This allows for a direct reading of the solution without needing back-substitution.</p>

<h3>LU Factorization</h3>
<p>LU factorization decomposes a matrix into the product of a lower triangular matrix (L) and an upper triangular matrix (U). This decomposition simplifies solving systems of linear equations, matrix inversions, and calculating matrix determinants.</p>

<h2 id="solution-of-non-linear-equations">Solution of Non-linear Equations</h2>

<h3>Bisection Method</h3>
<p>The bisection method is a root-finding method that repeatedly divides an interval and selects a subinterval in which a root exists. The interval is chosen based on the change of sign of the function, ensuring that a root lies within the interval.</p>

<h3>False Position Method</h3>
<p>The false position method is similar to the bisection method but uses a secant line instead of the midpoint to find the root. This can converge faster for certain types of functions compared to bisection.</p>

<h3>Secant Method</h3>
<p>The secant method is a root-finding algorithm that uses a sequence of roots of secant lines to approximate the solution. This method doesn’t require knowledge of the derivative and can be faster than the bisection method.</p>

<h3>Newton-Raphson Method</h3>
<p>The Newton-Raphson method uses the function's derivative to find successively better approximations to the root. It is known for its rapid convergence, although it requires an initial guess close to the actual root for best results.</p>

<h2 id="solution-of-differential-equations">Solution of Differential Equations</h2>

<h3>Runge-Kutta Method</h3>
<p>The Runge-Kutta method is a popular technique for numerically solving ordinary differential equations (ODEs). The fourth-order Runge-Kutta is particularly well-known for its accuracy and stability, using four evaluations of the derivative per step to improve approximation.</p>

<h2 id="matrix-inversion">Matrix Inversion</h2>
<p>Matrix inversion involves finding a matrix that, when multiplied with the original matrix, yields the identity matrix. The Gauss-Jordan elimination technique is commonly used for inverting matrices, especially when dealing with square matrices.</p>

<h2 id="requirements">Requirements</h2>
<ul>
  <li>C++ Compiler</li>
</ul>

<h2 id="how-to-run">How to Run</h2>
<p>Include the required header files in your project directory:</p>
<pre><code>#include "2107100.hpp"
#include "2107086.hpp"
#include "2107102.hpp"
</code></pre>

<p>Run the main function provided below, which offers a console-based user interface to select and execute the different numerical methods.</p>

<h2 id="usage-example">Usage Example</h2>

<h3>Start the Application</h3>
<p>Run the program to open the console-based interface.</p>

<h3>Select a Numerical Method</h3>
<ul>
  <li>You will be prompted with a list of main categories:
    <ul>
      <li>Solution For Linear Equations</li>
      <li>Solution of Non-linear Equations</li>
      <li>Solution of Differential Equations</li>
      <li>Matrix Inversion</li>
      <li>Exit</li>
    </ul>
  </li>
</ul>

<h3>Choose a Sub-method</h3>
<ul>
  <li>Selecting <strong>Solution For Linear Equations</strong> will list options such as:
    <ul>
      <li>Jacobi Iterative Method</li>
      <li>Gauss-Seidel Iterative Method</li>
      <li>Gauss Elimination</li>
      <li>Gauss-Jordan Elimination</li>
      <li>LU Factorization</li>
    </ul>
  </li>
  <li>Similarly, choosing <strong>Solution of Non-linear Equations</strong> or <strong>Solution of Differential Equations</strong> will prompt for the specific method to use, such as:
    <ul>
      <li>Bisection Method</li>
      <li>Secant Method</li>
      <li>Newton-Raphson Method</li>
      <li>Runge-Kutta Method for differential equations</li>
    </ul>
  </li>
</ul>

<h3>View Results</h3>
<p>After selecting a method, input any required parameters as prompted by the console. The program will execute the method and display the results directly.</p>
<li>Video for explaning the app shortly in 2 minute: <a href="https://drive.google.com/file/d/16ksPmfLmEK-rr0NbPeYCmhEEvGz7DBMV/view?usp=drive_link">Click Here</a></li>

<h3>Exit the Program</h3>
<p>Select <strong>Exit</strong> to close the application.</p>

</body>
</html>
