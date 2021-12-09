#ifndef WINDOW_H
#define WINDOW_H

class window{
  int height;
  int width;
  char * pixel;
 public:
  window(int w, int h);
  void set_pixel(int x, int y);
  void set_pixel(int x, int y, char a);
  void print_window();
  ~window();
};

#endif
