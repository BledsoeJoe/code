#include "window.h"
#include<string>
#include<iostream>

using namespace std;

window::window(int w, int h){
  width = w;
  height = h;
  pixel = new char[w*h];
  for(int i=0; i < h*w; i++){
    pixel[i] = ' ';
  }
}

void window::set_pixel(int x, int y){
  if((x<0 || x>=width)||(y<0 || y>=height)){
    cout<<"You've entered an invalid pixel location!\n"<<endl;
  }else{
    //pixel[x+y*height] = '.';
    pixel[x*height+y] = '.';
  }
}

void window::set_pixel(int x, int y, char a){
  if((x<0 || x>=width)||(y<0 || y>=height)){
    cout<<"You've entered an invalid pixel location!\n"<<endl;
  }else{
    //pixel[x+y*height] = a;
    pixel[x*height+y] = a;
  }
}



void window::print_window(){
  for(int y = 0; y < height; y++){
    for(int x = 0; x < width; x++){
      if(x == 0){
	cout<<endl;
      }
      cout<<pixel[x*height+y]<<" ";
    }
  }
  cout<<endl;
}

window::~window(){
  
}
