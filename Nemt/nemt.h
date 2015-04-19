#ifndef nemt_h
#define nemt_h
#include <nemt.h>
#include <SPI.h>  
#include <Pixy.h>

#define DEFAULT_COUNTER_LIMIT 50
#define CAMERA_HORIZONTAL_ANGLE 70
#define CAMERA_WIDTH 320
#define CAMERA_CENTER 160
#define NOT_FOUND 404

class Nemt {
public:
    Nemt(int cl = DEFAULT_COUNTER_LIMIT);
    int give_x(int block_color);
    int give_left(int block_color);
    int give_right(int block_color);
private:
    Pixy pixy;
    void give_v(int block_color);
    inline int convert_angle(int return_value);
    int goal_number;
    int blocks;
    int left_point_goal, right_point_goal , x_point_goal;
    int goal_color;
    int counter;
    int counter_limit;
};

#endif
