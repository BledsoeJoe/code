#include "list.h"
#include<iostream>

using namespace std;

list::list(){
  length = 0;
  head = new node();
  tail = NULL;
}

void list::add(double val){
  length++;
  iter = new node(val);
  iter->right = head;
  head->left = iter;
  head = iter;
}

double list::pop(){
  double pop = head->value;
  remove(head);
  return pop;
}

double list::top(){
  return head->value;
}

node * list::find(double val){
  iter = head;
  while(iter->right != NULL){  
    if(iter->value == val){
      return iter;
    }else{
      iter = iter->right;
    }
  }
  return NULL;
}

void list::remove(node * rem){
  if(rem->left != NULL){
    rem->left->right = rem->right;
  }else{
    rem->right->left = NULL;
  }
  if(rem->right != NULL){
    rem->right->left = rem->left;
  }else{
    rem->left->right = NULL;
  }
  delete rem;
  
}

bool list::findAndRemove(double val){
  node * temp = find(val);
  if(temp == NULL){
    return false;
  }else{
    remove(temp);
    return true;
  }
}

void list::printTo(){
  string str = to_string(head->value);
  iter = head;
  while(iter->right != NULL){
    str = str + ", " + to_string(iter->right->value);
    iter = iter->right;
  }
  cout<< str + "\n"; 
}

list::~list(){

}
