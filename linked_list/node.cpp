#include "node.h"
#include<iostream>

using namespace std;

node::node(){
  value = 0;
  left = NULL;
  right = NULL;
}

node::node(double val){
  value = val;
  left = NULL;
  right = NULL;
}

node::~node(){
}



