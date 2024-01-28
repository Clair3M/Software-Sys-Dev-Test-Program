#include "../testing.h"

// obj1 null
bool distance_obj1_null(void) {
    bool testPass = false;
    phylib_object *obj1 = NULL;
    phylib_object *obj2 = phylib_new_hcushion(0.0);
    double dist = phylib_distance(obj1, obj2);
    if (dist == -1.0) {
        pass("obj1_null");
        testPass = true;
    } else {
        fail("obj1_null");
        printf("expected: -1.0, got: %f\n", dist);
        testPass = false;
    }
    free(obj2);
    return testPass;
}
// obj2 null
bool distance_obj2_null(void) {
    bool testPass = false;
    phylib_coord pos = phylib_new_coord(62.12, 341.9);
    phylib_coord vel = phylib_new_coord(234.123, 5642.0);
    phylib_coord acc = phylib_new_coord(52.2, 456.3);
    phylib_object *obj1 = phylib_new_rolling_ball(1, &pos, &vel, &acc);
    phylib_object *obj2 = NULL;
    double dist = phylib_distance(obj1, obj2);
    if (dist == -1.0) {
        pass("obj2_null");
        testPass = true;
    } else {
        fail("obj2_null");
        printf("expected: -1.0, got: %f\n", dist);
        testPass = false;
    }
    free(obj1);
    return testPass;
}
// obj1 is not a rolling ball
bool distance_obj1_invalid_type(void) {
    bool testPass = false;
    phylib_coord pos = phylib_new_coord(52.3, 734.9);
    phylib_object *obj1 = phylib_new_still_ball(2, &pos);

    pos = phylib_new_coord(5012.1, 8809.1);
    phylib_coord vel = phylib_new_coord(23.1, 2100.1);
    phylib_coord acc = phylib_new_coord(52.2, 31.2);
    phylib_object *obj2 = phylib_new_rolling_ball(1, &pos, &vel, &acc);
    double dist = phylib_distance(obj1, obj2);
    if (dist == -1.0) {
        pass("obj1_invalid_type");
        testPass = true;
    } else {
        fail("obj1_invalid_type");
        printf("expected: -1.0, got: %f\n", dist);
        testPass = false;
    }
    free(obj1);
    free(obj2);
    return testPass;
}
// obj2 is not a valid type
bool distance_obj2_invalid_type(void) {
    bool testPass = false;
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
        testPass = true;
    } else {
        fail("obj2_invalid_type");
        printf("expected: -1.0, got: %f\n", dist);
        testPass = false;
    }
    free(obj1);
    free(obj2);
    return testPass;
}
// obj2 is still ball
bool distance_still_ball_normal(void) {
    bool testPass = false;
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
        testPass = true;
    } else {
        fail("still_ball");
        printf("expected: 349.3378, got: %f\n", dist);
        testPass = false;
    }
    free(obj1);
    free(obj2);
    return testPass;
}
    // on the same exact position
bool distance_still_ball_same(void) {
    bool testPass = false;
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
        testPass = true;
    } else {
        fail("still_ball_same");
        printf("expected: -57.0, got: %f\n", dist);
        testPass = false;
    }
    free(obj1);
    free(obj2);
    return testPass;
}
// obj2 is rolling ball
bool distance_rolling_ball(void) {
    bool testPass = false;
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
        testPass = true;
    } else {
        fail("rolling_ball");
        printf("expected: 1664.2604, got: %f\n", dist);
        testPass = false;
    }
    free(obj1);
    free(obj2);
    return testPass;
}
// obj2 is hole
bool distance_hole(void) {
    bool testPass = false;
    phylib_coord pos = phylib_new_coord(56.4, 89.1);
    phylib_coord vel = phylib_new_coord(23.1, 2100.1);
    phylib_coord acc = phylib_new_coord(52.2, 31.2);
    phylib_object *obj1 = phylib_new_rolling_ball(3, &pos, &vel, &acc);

    pos = phylib_new_coord(0, 0);
    phylib_object *obj2 = phylib_new_hole(&pos);

    //expected == -8.54968
    double dist = phylib_distance(obj1, obj2);
    if (fabs(dist - (-8.54968)) < 0.001) {
        pass("hole");
        testPass = true;
    } else {
        fail("hole");
        printf("expected: -8.54968, got: %f\n", dist);
        testPass = false;
    }
    free(obj1);
    free(obj2);
    return testPass;
}
// obj2 is hcushion
bool distance_hcushion(void) {
    bool testPass = false;
    phylib_coord pos = phylib_new_coord(56.4, 89.1);
    phylib_coord vel = phylib_new_coord(23.1, 2100.1);
    phylib_coord acc = phylib_new_coord(52.2, 31.2);
    phylib_object *obj1 = phylib_new_rolling_ball(3, &pos, &vel, &acc);

    phylib_object *obj2 = phylib_new_hcushion(20.0);
    double dist = phylib_distance(obj1, obj2);
    // expected == 40.6
    if (fabs(dist - 40.6) < 0.001) {
        pass("hcushion");
        testPass = true;
    } else {
        fail("hcushion");
        printf("expected: 40.6, got: %f\n", dist);
        testPass = false;
    }
    free(obj1);
    free(obj2);
    return testPass;
}
// obj2 is vcushion
bool distance_vcushion(void) {
    bool testPass = false;
    phylib_coord pos = phylib_new_coord(56.4, 89.1);
    phylib_coord vel = phylib_new_coord(23.1, 2100.1);
    phylib_coord acc = phylib_new_coord(52.2, 31.2);
    phylib_object *obj1 = phylib_new_rolling_ball(3, &pos, &vel, &acc);

    phylib_object *obj2 = phylib_new_vcushion(1300.45);
    double dist = phylib_distance(obj1, obj2);
    // expected == 1215.55
    if (fabs(dist - 1215.55) < 0.001) {
        pass("vcushion");
        testPass = true;
    } else {
        fail("vcushion");
        printf("expected: 1215.55, got: %f\n", dist);
        testPass = false;
    }
    free(obj1);
    free(obj2);
    return testPass;
}
