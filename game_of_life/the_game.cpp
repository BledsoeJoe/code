#include "video.h"
#include "the_game.h"
#include<iostream>

using namespace std;

//copy function for the arrays
void copy_ar(){
  for(int i = 0; i <size; i++){
    for(int j = 0; j<size; j++){
      cells[i*size+j] = cells_next[i*size+j];
    }
  }
}

//function to translate cells configuration to window
void add_frame(){
  for(int i=0; i<size; i++){
    for(int j=0; j<size; j++){
      if(cells[i*size+j] == 1){
        win.add_pixel(i,j, 'o');
      }else{
        win.add_pixel(i,j, ' ');
      }
    }
  }
}

void alive(int neighbors, int i, int j){
  if(cells[i*size+j] == 1 && neighbors > 3){
    cells_next[i*size+j] = 0;
  }else if(cells[i*size+j] == 1 && neighbors < 2){
    cells_next[i*size+j] = 0;
  }else if(cells[i*size+j] == 0 && neighbors == 3){
    cells_next[i*size+j] = 1;
  }
}


void cycle(){
  //useful indicies for the four corners
  int ind = size -1;
  int ind_ = size -2;
  //determine the neighbors of the four corners
  int top_left_neighbors = cells[size]+cells[size+1]+cells[1];
  alive(top_left_neighbors, 0, 0);
  int top_right_neighbors = cells[ind_*size]+cells[ind_*size+1]+cells[ind*size+1];
  alive(top_right_neighbors, ind, 0);
  int bot_left_neighbors = cells[ind_]+cells[size+ind_]+cells[size+ind];
  alive(bot_left_neighbors, 0, ind);
  int bot_right_neighbors = cells[ind*size+ind_]+cells[ind_*size+ind_]+cells[ind_*size+ind];
  alive(bot_right_neighbors, ind, ind);

  //determine the edges
  for(int i = 1; i < ind; i++){
    int _i = i-1;
    int i_ = i+1;
    int top;
    int bottom;
    int left;
    int right;
    
    //top edge
    top = cells[_i*size]+cells[_i*size+1]+cells[i*size+1]+cells[i_*size+1]+cells[i_*size];
    alive(top,i,0);
    //bottom edge
    bottom = cells[_i*size+ind]+cells[_i*size+ind_]+cells[i*size+ind_]+cells[i_*size+ind_]+cells[i_*size+ind];
    alive(bottom,i,ind);

    //left edge
    left = cells[_i]+cells[size+ _i]+cells[size+i]+cells[size+ i_]+cells[i_];
    alive(left,0,i);
    //right edge
    right = cells[ind*size+ _i]+cells[ind_*size+ _i]+cells[ind_*size+i]+cells[ind_*size+ i_]+cells[ind*size+ i_];
    alive(right,ind,i);
  }
    
      
  //the rest of the cells
  for(int i=1; i<(size-1); i++){
    for(int j=1; j<(size-1); j++){
      int _i = i-1;
      int _j = j-1;
      int i_ = j+1;
      int j_ = j+1;
      int neighbors;
      neighbors = cells[_i*size+ j_]+cells[i*size+ j_]+cells[i_*size+ j_]+cells[_i*size+ j]+cells[i_*size+ j]+cells[_i*size+ _j]+cells[i*size+ _j]+cells[i_*size+ _j];
      alive(neighbors, i, j);
    }
  }

  //set the cells array to the cells next array
  copy_ar();
}
  


int main(){

  //prompt user for size of life board
  cout<<"Enter dimension size of game board: ";
  cin>>size;

  //create video object to hold frames
  vid = new video(1,size, size);
  //create window object and load initial pixels
  win = new window(size, size);
  //create 2-D array to hold cell values
  cells = new int[size*size];
  //2-D array to hold next iterations cells
  cells_next = new int[size*size];

  //set arrays initially to zero
  for(int i = 0; i <size; i++){
    for(int j = 0; j <size; j++){
      cells[i*size+j] = 0;
      cells_next[i*size+j] = 0;
    }
  }  

  
  return 0;
}

 
	