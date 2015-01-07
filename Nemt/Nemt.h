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
  		Nemt(int color);
  		int giveX();
  		int giveLeft();
  		int giveRight();
  	private:
  		Pixy pixy;
  		void giveV();	
    	int goal_number;  
		int blocks;
		int left_point_goal, right_point_goal , x_point_goal;
		int goal_color;
};

#endif
