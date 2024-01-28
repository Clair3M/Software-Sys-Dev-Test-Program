#include "testing.h"

void copy_object_test_null(void) {
    // null as input
    phylib_object *dest = phylib_new_hcushion(0.0);
    phylib_object *src = NULL;
    phylib_copy_object(&dest, &src);
    if (!(dest)) {
        pass("NULL");
    } else {
        fail("NULL");
    }
    fflush(stdout);
}

void copy_object_test_outer_null(void) {
    phylib_object **dest = NULL;
    phylib_object **src = NULL;
    phylib_copy_object(dest, src);
    if (!(dest)) {
        pass("outer_NULL");
    } else {
        fail("outer_NULL");
    }
    fflush(stdout);
}

void copy_object_existing_object(void) {
    phylib_coord pos = phylib_new_coord(21.1, 452.9);
    phylib_object *dest = phylib_new_still_ball((unsigned char) 3, &pos);
    pos = phylib_new_coord(89.1, 12412.75);
    phylib_object *src = phylib_new_still_ball((unsigned char) 9, &pos);
    phylib_copy_object(&dest, &src);
    if (dest->obj.still_ball.number == src->obj.still_ball.number
        && dest->obj.still_ball.pos.x == src->obj.still_ball.pos.x
        && dest->obj.still_ball.pos.y == src->obj.still_ball.pos.y
        && dest != src) {
            pass("existing_object");
    } else {
        fail("existing_object");
    }
    free(dest);
    free(src);
}

void copy_object_dest_null(void) {
    phylib_coord pos = phylib_new_coord(21.1, 452.9);
    phylib_coord vel = phylib_new_coord(624.1, 112);
    phylib_coord acc = phylib_new_coord(90.0, 0.0);
    phylib_object *src = phylib_new_rolling_ball((unsigned char) 3, &pos, &vel, &acc);
    phylib_object *dest = NULL;
    phylib_copy_object(&dest, &src);
    if (dest->obj.rolling_ball.number == src->obj.rolling_ball.number
        && dest->obj.rolling_ball.pos.x == src->obj.rolling_ball.pos.x
        && dest->obj.rolling_ball.pos.y == src->obj.rolling_ball.pos.y
        && dest->obj.rolling_ball.vel.x == src->obj.rolling_ball.vel.x
        && dest->obj.rolling_ball.vel.y == src->obj.rolling_ball.vel.y
        && dest->obj.rolling_ball.acc.x == src->obj.rolling_ball.acc.x
        && dest->obj.rolling_ball.acc.y == src->obj.rolling_ball.acc.y
        && dest != src) {
            pass("dest_NULL");
    } else {
        fail("dest_NULL");
    }
    free(dest);
    free(src);
}
