#include "complex.h"
#include<iostream>

using namespace std;

int main(){
  double real1;
  double real2;
  double imag1;
  double imag2;
  
  cout<<"Enter the real part of number 1: ";
  cin>>real1;

  cout<<"Enter the imaginary part of number 1: ";
  cin>>imag1;

  cout<<"Enter the real part of number 2: ";
  cin>>real2;

  cout<<"Enter the imaginary par of number 2: ";
  cin>>imag2;

  complex num1 = complex(real1,imag1);
  complex num2 = complex(real2,imag2);

  complex * added = num1.add(&num2);
  complex * mult = num1.mult(&num2);
  complex * squ = num1.sq();

  cout<<num1.real<<"+"<<num1.imag<<"i + "<<num2.real<<"+"<<num2.imag<<"i = "<<added->real<<"+"<<added->imag<<"i"<<endl;

  cout<<"("<<num1.real<<"+"<<num1.imag<<"i) * ("<<num2.real<<"+"<<num2.imag<<"i) = "<<mult->real<<"+"<<mult->imag<<"i"<<endl;

  cout<<"("<<num1.real<<"+"<<num1.imag<<"i)^2"<<" = "<<squ->real<<"+"<<squ->imag<<"i"<<endl;
  return 0;
}
