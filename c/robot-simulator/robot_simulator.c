#include <stdlib.h>
#include <stdio.h>
#include "robot_simulator.h"


robot_status_t robot_create(robot_direction_t direction, int x, int y) {
    return (robot_status_t) {
        .direction = direction,
        .position.x = x,
        .position.y = y
    };
}

void robot_move(robot_status_t *robot, const char *commands) {
    if (!commands || !robot)
        exit(-1);
    
    robot_direction_t new_dir = robot->direction;

    for(; *commands != '\0';)
        if ( *commands == 'R' || *commands == 'L' || *commands == 'A' )
            switch (*commands) {
            case 'R':
                new_dir = (robot->direction + 1) % 4;
                robot->direction = new_dir;
                commands++;
                break;
            case 'L':
                new_dir = (robot->direction - 1) % 4;
                robot->direction = new_dir;
                commands++;
                break;
            case 'A':
                if (new_dir % 2)
                    robot->position.x += 2 - new_dir;
                else
                    robot->position.y += 1 - new_dir;
                commands++;
                break;
            }
        else
        {
            exit(-1);
        }
}
