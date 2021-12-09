#ifndef COMPLEX_H
#define COMPLEX_H

class complex{
 public:
  double real;
  double imag;
  complex(double r, double i);
  complex * add(complex * num);
  complex * mult(complex * num);
  complex * sq();
};

#endif
