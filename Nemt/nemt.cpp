#include <nemt.h>
#include <SPI.h>  
#include <Pixy.h>

Nemt::Nemt(int cl) {
    pixy.init();
    counter_limit = cl;
    counter = 0;
}

int Nemt::give_x(int block_color) {
    give_v(block_color);
    return x_point_goal;
}

int Nemt::give_left(int block_color) {
    give_v(block_color);
    return left_point_goal;
}

int Nemt::give_right(int block_color) {
    give_v(block_color);
    return right_point_goal;
}

void Nemt::give_v(int block_color) {
    blocks = pixy.getBlocks();

    if (blocks != 0) {
        for (int i = 0; i < blocks; i++) {
            if (pixy.blocks[i].signature == block_color &&
                    pixy.blocks[i].width > pixy.blocks[goal_number].width) {
                goal_number = i;
            }
        }

        x_point_goal = pixy.blocks[goal_number].x;

        left_point_goal = pixy.blocks[goal_number].x
                        - pixy.blocks[goal_number].width/2;

        right_point_goal = pixy.blocks[goal_number].x
                         + pixy.blocks[goal_number].width/2;

        counter = 0;
    } else {
        ++counter;
        
        if (counter > counter_limit) {
            if (x_point_goal > 150) {
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

