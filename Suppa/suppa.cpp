#include <suppa.h>
#include <SPI.h>
#include <Pixy.h>

Suppa::Suppa(int ori, int cl) {
    pixy.init();
    counter_limit = cl;
    counter = 0;
    orientation = ori * (-1);
}

inline int Suppa::convert_angle(int return_value) {
    if (return_value < NOT_FOUND && return_value > -NOT_FOUND) {
        return orientation * ((return_value * CAMERA_HORIZONTAL_ANGLE / CAMERA_WIDTH) -
               CAMERA_HORIZONTAL_ANGLE / 2);
    } else {
        return orientation * return_value;
    }
}

int Suppa::give_x(int block_color) {
    give_v(block_color);
    return convert_angle(x_point_goal);
}

int Suppa::give_left(int block_color) {
    give_v(block_color);
    return convert_angle(left_point_goal);
}

int Suppa::give_right(int block_color) {
    give_v(block_color);
    return convert_angle(right_point_goal);
}

void Suppa::give_v(int block_color) {
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
            if (x_point_goal > CAMERA_CENTER) {
                x_point_goal = NOT_FOUND;
                left_point_goal = NOT_FOUND;
                right_point_goal = NOT_FOUND;
                counter = 0;
            } else {
                x_point_goal = -NOT_FOUND;
                left_point_goal = -NOT_FOUND;
                right_point_goal = -NOT_FOUND;
                counter = 0;
            }
        }
    }
}

