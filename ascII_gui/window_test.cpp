#include "window.h"
#include<iostream>

using namespace std;

int main(){
  //make a window object
  int w;
  int h;
  char a;
  cout<<"Enter screen width: ";
  cin>>w;
  cout<<"Enter screen height: ";
  cin>>h;
  cout<<"Enter character: ";
  cin>>a;
  window win = window(w, h);

  for(int i = 0; i < w; i++){
    for(int j = 0; j < h; j++){
      win.set_pixel(i, j, a);
    }
  }
  win.set_pixel(2,5,'x');
  win.set_pixel(5,2,'y');
  win.print_window();
  return 0;
}
