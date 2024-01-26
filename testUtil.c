#include "testing.h"

void pass() {
    printf("\033[0;32m");
    printf("Pass\n");
    printf("\033[0m"); 
}
void fail() {
    printf("\033[0;31m");
    printf("Fail\n");
    printf("\033[0m"); 
}

bool assert_tables_equal(phylib_table *table1, phylib_table *table2) {
    bool equal = true;
    if (table1->time != table2->time) {
        equal = false;
    }
    for (int i = 0; i < PHYLIB_MAX_OBJECTS; i++) {
        if (!assert_objects_equal(table1->objects[i], table2->objects[i])) {
            equal = false;
        }
    }
    return equal;
}

bool assert_objects_equal(phylib_object *obj1, phylib_object *obj2) {
    if (!obj1) {
        if (!obj2) {
            return true;
        }
        return false;
    }
    switch(obj1->type) {
        case PHYLIB_STILL_BALL:
        {
            if (obj2->type != PHYLIB_STILL_BALL) {
                return false;
            }
            if (
                obj1->obj.still_ball.number == obj2->obj.still_ball.number;
                && obj1->obj.still_ball.pos.x == obj2->obj.still_ball.pos.x;
                && obj1->obj.still_ball.pos.y == obj2->obj.still_ball.pos.y;
            ) {
                return true;
            } else {
                return false;
            }
        }
        case PHYLIB_ROLLING_BALL:
        {
            if (obj2->type != PHYLIB_ROLLING_BALL) {
                return false;
            }
            if (
                obj1->obj.rolling_ball.number == obj2->obj.rolling_ball.number;
                && obj1->obj.rolling_ball.pos.x == obj2->obj.rolling_ball.pos.x;
                && obj1->obj.rolling_ball.pos.y == obj2->obj.rolling_ball.pos.y;
                && obj1->obj.rolling_ball.vel.x == obj2->obj.rolling_ball.vel.x;
                && obj1->obj.rolling_ball.vel.y == obj2->obj.rolling_ball.vel.y;
                && obj1->obj.rolling_ball.acc.x == obj2->obj.rolling_ball.acc.x;
                && obj1->obj.rolling_ball.acc.y == obj2->obj.rolling_ball.acc.y;
            ) {
                return true;
            } else {
                return false;
            }
        }
        case PHYLIB_HOLE:
        {
            if (obj2->type != PHYLIB_HOLE) {
                return false;
            }
            if (
                obj1->obj.hole.pos.x == obj2->obj.hole.pos.x;
                obj1->obj.hole.pos.y == obj2->obj.hole.pos.y;
            ) {
                return true;
            } else {
                return false;
            }
        }
        case PHYLIB_HCUSHION:
        {
            if (obj2->type != PHYLIB_HCUSHION) {
                return false;
            }
            if (
                obj1->obj.hcushion.y == obj2->obj.hcushion.y;
            ) {
                return true;
            } else {
                return false;
            }
        }
        case PHYLIB_VCUSHION:
        {
            if (obj2->type != PHYLIB_VCUSHION) {
                return false;
            }
            if (
                obj1->obj.vcushion.x == obj2->obj.vcushion.x;
            ) {
                return true;
            } else {
                return false;
            }
        }
        default: 
        {
            return false;
        }
    }
    return false;
}