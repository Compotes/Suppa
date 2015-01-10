#include <Nemt.h>
#include <SPI.h>  
#include <Pixy.h>

Pixy pixy;
int goal_number;  
int blocks;
int left_point_goal, right_point_goal , x_point_goal;
int goal_color;
int counter;
int counter_limit;

Nemt::Nemt(int color, int cl) {
    this->pixy.init();
    this->counter_limit = cl;
    this->counter = 0;
    this->goal_color = color;
}

int Nemt::giveX() {
    this->giveV();
    return this->x_point_goal;
}

int Nemt::giveLeft() {
    this->giveV();
    return this->left_point_goal;
}

int Nemt::giveRight() {
    this->giveV();
    return this->right_point_goal;
}

void Nemt::giveV() {
    this->blocks = this->pixy.getBlocks();
    if(this->blocks) // if we see at least one objects we can be happy 
    {
        for (int i = 0; i < this->blocks; i++) // runnig through all objects 
        {
            // if object i == goal_color and is bigger that captured object that it is object with bigger priority
            if(this->pixy.blocks[i].signature == this->goal_color && this->pixy.blocks[i].width > this->pixy.blocks[this->goal_number].width) 
            { 
                this->goal_number = i; // we set color of goal
            }            
        } 

        this->x_point_goal = this->pixy.blocks[this->goal_number].x;
        this->left_point_goal = this->pixy.blocks[goal_number].x - this->pixy.blocks[goal_number].width/2; // left pint of goal // lpg = x - width/2    
        this->right_point_goal = this->pixy.blocks[goal_number].x + this->pixy.blocks[goal_number].width/2; // right point of goal // rpg = x + width/2   
        this->counter = 0;
    } else {
        this->counter++;
        
        if (this->counter > this->counter_limit) {
            if(this->x_point_goal > 150) {
                this->x_point_goal = 404;
                this->left_point_goal = 404;
                this->right_point_goal = 404;
                this->counter = 0;
            } else {
                this->x_point_goal = -404;
                this->left_point_goal = -404;
                this->right_point_goal = -404;
                this->counter = 0;
            }
        }
    }
}

