#include <Nemt.h>
#include <SPI.h>  
#include <Pixy.h>

Pixy pixy;
int goal_number;  
int blocks; // zistim pocet blokov
int left_point_goal, right_point_goal , x_point_goal;
int goal_color;

Nemt::Nemt() {
    pixy.init();
    goal_color = 3;
}

int Nemt::giveX() {
    giveV();
    return x_point_goal;
}

int Nemt::giveLeft() {
    giveV();
    return left_point_goal;
}

int Nemt::giveRight() {
    giveV();
    return right_point_goal;
}

void Nemt::giveV() {
    blocks = pixy.getBlocks();
    if(blocks) // ak vidime aspon jeden blok tak je to super 
    {
        for (int i = 0; i < blocks; i++) // zistime kvalitnym forcyklom kolko objektov mame
        {
            if(pixy.blocks[i].signature == goal_color && pixy.blocks[i].width > 15) // ak sa nam farba objektu zhoduje s KONSTANTOU GOAL_COLOR tak vieme ze je to brana 
            { 
                goal_number = i; // nastavime hodnotu brany
            }
        }
        x_point_goal = pixy.blocks[goal_number].x;
        left_point_goal = pixy.blocks[goal_number].x - pixy.blocks[goal_number].width/2; // nacitam lavy bod brany // lpg = x - sirka/2    
        right_point_goal = pixy.blocks[goal_number].x + pixy.blocks[goal_number].width/2; // nacitam pravy bod brany // rpg = x + sirka/2   
    }
}

