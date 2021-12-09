#include "complex.h"
#include<iostream>

complex::complex(double r, double i){
  real = r;
  imag = i;
}

complex * complex::add(complex * num){
  return new complex(real + num->real, imag + num->imag);
}

complex * complex::mult(complex * num){
  return new complex(real*num->real - imag*num->imag, real*num->imag + imag*num->real);
}

complex * complex::sq(){
  return new complex(real*real - imag*imag, 2*real*imag);
}
