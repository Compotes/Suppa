#include <SPI.h>  
#include <Pixy.h>

#define GOAL_COLOR 3 // 3 ak chceme zltu // 6 ak chceme modru

Pixy pixy;

void setup()
{
    Serial.begin(9600);
    Serial.print("Starting...\n");
    pixy.init();
}

void loop()
{ 
    int goal_number;  
    int blocks = pixy.getBlocks(); // zistim pocet blokov
    int left_point_goal, right_point_goal , x_point_goal;

    if(blocks) // ak vidime aspon jeden blok tak je to super 
    {
        for (int i = 0; i < blocks; i++) // zistime kvalitnym forcyklom kolko objektov mame
        {
            if(pixy.blocks[i].signature == GOAL_COLOR && pixy.blocks[i].width > 15) // ak sa nam farba objektu zhoduje s KONSTANTOU GOAL_COLOR tak vieme ze je to brana 
            { 
                goal_number = i; // nastavime hodnotu brany
            }
        }
        x_point_goal = pixy.blocks[goal_number].x;
        left_point_goal = pixy.blocks[goal_number].x - pixy.blocks[goal_number].width/2; // nacitam lavy bod brany // lpg = x - sirka/2    
        right_point_goal = pixy.blocks[goal_number].x + pixy.blocks[goal_number].width/2; // nacitam pravy bod brany // rpg = x + sirka/2   
        
        Serial.println("");
        Serial.println(left_point_goal);
        Serial.println(right_point_goal);
        Serial.println(x_point_goal);
        delay(100);
    }
}


