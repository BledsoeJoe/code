#ifndef NODE_H
#define NODE_H

class node{
  
 public:
  double value;
  node * left;
  node * right;
  node();
  node(double val);
  ~node();
};
  

#endif

