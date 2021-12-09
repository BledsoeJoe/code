#include "node.h"
#include "list.h"
#include<iostream>

using namespace std;

int main(){

  list linked = list();
  cout<<"Please enter the desired length of test list: ";
  int length = 0;
  cin>>length;
  double temp;
  for(int i=0; i < length; i++){
    cout<<"Enter element #"+to_string(i)+" :";
    cin>>temp;
    linked.add(temp);
  }
  linked.printTo();
  cout<<"Enter a number to remove:";
  cin>>temp;
  linked.findAndRemove(temp);
  linked.printTo();
  return 0;
}
