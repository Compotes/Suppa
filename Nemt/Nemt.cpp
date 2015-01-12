#include <Nemt.h>
#include <SPI.h>  
#include <Pixy.h>

Pixy pixy;
int goal_number;  
int blocks;
int left_point_goal, right_point_goal , x_point_goal;
int counter;
int counter_limit;

Nemt::Nemt(int cl) {
    pixy.init();
    counter_limit = cl;
    counter = 0;
}

int Nemt::giveX(int x) {
    giveV(x);
    return x_point_goal;
}

int Nemt::giveLeft(int x) {
    giveV(x);
    return left_point_goal;
}

int Nemt::giveRight(int x) {
    giveV(x);
    return right_point_goal;
}

void Nemt::giveV(int block_color) {
    blocks = pixy.getBlocks();
    if(blocks) // if we see at least one objects we can be happy 
    {
        for (int i = 0; i < blocks; i++) // runnig through all objects 
        {
            // if object i == goal_color and is bigger that captured object that it is object with bigger priority
            if(pixy.blocks[i].signature == block_color &&
               pixy.blocks[i].width > pixy.blocks[goal_number].width)
            { 
                goal_number = i; // we set color of goal
            }            
        } 

        x_point_goal = pixy.blocks[goal_number].x;
        left_point_goal = pixy.blocks[goal_number].x - pixy.blocks[goal_number].width/2; // left pint of goal // lpg = x - width/2    
        right_point_goal = pixy.blocks[goal_number].x + pixy.blocks[goal_number].width/2; // right point of goal // rpg = x + width/2   
        counter = 0;
    } else {
        counter++;
        
        if (counter > counter_limit) {
            if(x_point_goal > 150) {
                x_point_goal = 404;
                left_point_goal = 404;
                right_point_goal = 404;
                counter = 0;
            } else {
                x_point_goal = -404;
                left_point_goal = -404;
                right_point_goal = -404;
                counter = 0;
            }
        }
    }
}

