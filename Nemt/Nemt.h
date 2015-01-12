/*
  Created by Gk
*/

#ifndef Nemt_h
#define Nemt_h
#include <Nemt.h>
#include <SPI.h>  
#include <Pixy.h>

class Nemt
{
	public:
  		Nemt(int cl = 50);
  		int giveX(int x);
  		int giveLeft(int x);
  		int giveRight(int x);
  	private:
  		Pixy pixy;
  		void giveV(int block_color);	
    	int goal_number;  
		  int blocks;
		  int left_point_goal, right_point_goal , x_point_goal;
		  int goal_color;
      int counter;
      int counter_limit;
};

#endif
