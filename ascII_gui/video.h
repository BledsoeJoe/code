#ifndef VIDEO_H
#define VIDEO_H

#include "window.h"
#include<iostream>
#include<cstdlib>
#include<chrono>
#include<thread>
#include<vector>

class video{
  int fps; //frames per second for video playing
  int width; //width of the video window
  int height; //height of the video window
  std::vector<window> frames; //vector of the individual frames
 public:
  video(int fps, int w, int h); //constructor
  void addFrame(window &win); //adds a frame to the video's frame vector
  void play();
  void play(bool replay);
};

#endif
