#ifndef LIST_H
#define LIST_H

#include "node.h"

class list{
  int length;
  node * iter;
  node * head;
  node * tail;
 public:
  list();
  void add(double val);
  double pop();
  double top();
  node * find(double val);
  void remove(node * rem);
  bool findAndRemove(double val);
  void printTo();
  ~list();
};

#endif
