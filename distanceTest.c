#include "testing.h"

// obj1 null
void distance_obj1_null(void) {
    phylib_object *obj1 = NULL;
    phylib_object *obj2 = phylib_new_hcushion(0.0);
    double dist = phylib_distance(obj1, obj2);
    if (dist == -1.0) {
        pass("obj1_null");
    } else {
        fail("obj1_null");
    }
    free(obj2);
}
// obj2 null
void distance_obj2_null(void) {
    phylib_coord pos = phylib_new_coord(62.12, 341.9);
    phylib_coord vel = phylib_new_coord(234.123, 5642.0);
    phylib_coord acc = phylib_new_coord(52.2, 456.3);
    phylib_object *obj1 = phylib_new_rolling_ball(1, &pos, &vel, &acc);
    phylib_object *obj2 = NULL;
    double dist = phylib_distance(obj1, obj2);
    if (dist == -1.0) {
        pass("obj2_null");
    } else {
        fail("obj2_null");
    }
    free(obj1);
}
// obj1 is not a rolling ball
void distance_obj1_invalid_type(void) {
    phylib_coord pos = phylib_new_coord(52.3, 734.9);
    phylib_object *obj1 = phylib_new_still_ball(2, &pos);

    pos = phylib_new_coord(5012.1, 8809.1);
    phylib_coord vel = phylib_new_coord(23.1, 2100.1);
    phylib_coord acc = phylib_new_coord(52.2, 31.2);
    phylib_object *obj2 = phylib_new_rolling_ball(1, &pos, &vel, &acc);
    double dist = phylib_distance(obj1, obj2);
    if (dist == -1.0) {
        pass("obj1_invalid_type");
    } else {
        fail("obj1_invalid_type");
    }
    free(obj1);
    free(obj2);
}
// obj2 is not a valid type
void distance_obj2_invalid_type(void) {
    phylib_coord pos = phylib_new_coord(5012.1, 8809.1);
    phylib_coord vel = phylib_new_coord(23.1, 2100.1);
    phylib_coord acc = phylib_new_coord(52.2, 31.2);
    phylib_object *obj1 = phylib_new_rolling_ball(1, &pos, &vel, &acc);

    pos = phylib_new_coord(52.3, 734.9);
    phylib_object *obj2 = phylib_new_still_ball(2, &pos);
    obj2->type = 10;
    double dist = phylib_distance(obj1, obj2);
    if (dist == -1.0) {
        pass("obj2_invalid_type");
    } else {
        fail("obj2_invalid_type");
    }
    free(obj1);
    free(obj2);
}
// obj2 is still ball
void distance_still_ball_normal(void) {
    phylib_coord pos = phylib_new_coord(53.2, 506.8);
    phylib_coord vel = phylib_new_coord(23.1, 2100.1);
    phylib_coord acc = phylib_new_coord(52.2, 31.2);
    phylib_object *obj1 = phylib_new_rolling_ball(3, &pos, &vel, &acc);

    pos = phylib_new_coord(103.6, 103.6);
    phylib_object *obj2 = phylib_new_still_ball(1, &pos);

    //expected == 349.33779
    double dist = phylib_distance(obj1, obj2);
    if (fabs(dist - 349.33779) < 0.001) {
        pass("still_ball");
    } else {
        fail("still_ball");
    }
    free(obj1);
    free(obj2);
}
    // on the same exact position
void distance_still_ball_same(void) {
    phylib_coord pos = phylib_new_coord(208.3, 769.8);
    phylib_coord vel = phylib_new_coord(23.1, 2100.1);
    phylib_coord acc = phylib_new_coord(52.2, 31.2);
    phylib_object *obj1 = phylib_new_rolling_ball(3, &pos, &vel, &acc);

    pos = phylib_new_coord(208.3, 769.8);
    phylib_object *obj2 = phylib_new_still_ball(1, &pos);

    //expected == -57.000
    double dist = phylib_distance(obj1, obj2);
    if (fabs(dist - (-57.0)) < 0.001) {
        pass("still_ball_same");
    } else {
        fail("still_ball_same");
    }
    free(obj1);
    free(obj2);
}
// obj2 is rolling ball
void distance_rolling_ball(void) {
    phylib_coord pos = phylib_new_coord(1308.7, 2124.1);
    phylib_coord vel = phylib_new_coord(23.1, 2100.1);
    phylib_coord acc = phylib_new_coord(52.2, 31.2);
    phylib_object *obj1 = phylib_new_rolling_ball(3, &pos, &vel, &acc);

    pos = phylib_new_coord(56.7, 942.9);
    vel = phylib_new_coord(23.1, 2100.1);
    acc = phylib_new_coord(52.2, 31.2);
    phylib_object *obj2 = phylib_new_rolling_ball(3, &pos, &vel, &acc);

    //expected == 1664.26042
    double dist = phylib_distance(obj1, obj2);
    if (fabs(dist - 1664.26042) < 0.001) {
        pass("rolling_ball");
    } else {
        fail("rolling_ball");
    }
    free(obj1);
    free(obj2);
}
// obj2 is hole
void distance_hole(void) {
    phylib_coord pos = phylib_new_coord(56.4, 89.1);
    phylib_coord vel = phylib_new_coord(23.1, 2100.1);
    phylib_coord acc = phylib_new_coord(52.2, 31.2);
    phylib_object *obj1 = phylib_new_rolling_ball(3, &pos, &vel, &acc);

    pos = phylib_new_coord(0, 0);
    phylib_object *obj2 = phylib_new_hole(&pos);

    //expected == 48.45032006
    double dist = phylib_distance(obj1, obj2);
    if (fabs(dist - 48.45032006) < 0.001) {
        pass("hole");
    } else {
        fail("hole");
    }
    free(obj1);
    free(obj2);
}
// obj2 is hcushion
void distance_hcushion(void) {
    phylib_coord pos = phylib_new_coord(56.4, 89.1);
    phylib_coord vel = phylib_new_coord(23.1, 2100.1);
    phylib_coord acc = phylib_new_coord(52.2, 31.2);
    phylib_object *obj1 = phylib_new_rolling_ball(3, &pos, &vel, &acc);

    phylib_object *obj2 = phylib_new_hcushion(20.0);
    double dist = phylib_distance(obj1, obj2);
    // expected == 41.6
    if (fabs(dist - 41.6) < 0.001) {
        pass("hcushion");
    } else {
        fail("hcushion");
    }
    free(obj1);
    free(obj2);
}
// obj2 is vcushion
void distance_vcushion(void) {
    phylib_coord pos = phylib_new_coord(56.4, 89.1);
    phylib_coord vel = phylib_new_coord(23.1, 2100.1);
    phylib_coord acc = phylib_new_coord(52.2, 31.2);
    phylib_object *obj1 = phylib_new_rolling_ball(3, &pos, &vel, &acc);

    phylib_object *obj2 = phylib_new_vcushion(1300.45);
    double dist = phylib_distance(obj1, obj2);
    // expected == 1216.55
    if (fabs(dist - 1216.55) < 0.001) {
        pass("vcushion");
    } else {
        fail("vcushion");
    }
    free(obj1);
    free(obj2);
}
