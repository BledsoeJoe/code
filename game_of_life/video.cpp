#include "video.h"

using namespace std;

video::video(int f, int w, int h){
  fps = f;
  width = w;
  height = h;
}

void video::addFrame(window &win){
  /* if(win->width != width || win->height != height){
    cout<<"This frame's dimensions do not match that of the video!"<<endl;
    return;
  }else{
    frames.push_back(win);
  }
  */
  frames.push_back(win);
}

void video::play(){
  play(true);
}

void video::play(bool replay){
  while(true){
    for(int i = 0; i < frames.size(); i++){
      system("clear");
      frames[i].print_window();
      this_thread::sleep_for(chrono::milliseconds(1000/fps));
    }
    system("clear");
    if(!replay){
      break;
    }
  }
}



