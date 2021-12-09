#include "window.h"
#include "video.h"
#include<iostream>

using namespace std;

int main(){
  //prompt for size of test screen
  int size;
  int fps;
  cout<<"Enter test video screen size: ";
  cin>>size;
  cout<<"Enter the desired FPS of video: ";
  cin>>fps;

  //create video instance
  video vid = video(fps, size, size);

  for(int i = 0; i < size; i++){
    window temp = window(size, size);
    temp.set_pixel(i,i,'A');
    temp.set_pixel(0,i,'x');
    temp.set_pixel(i,0,'x');
    vid.addFrame(temp);
  }
  

  vid.play();
  system("clear");


}
