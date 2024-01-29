#include "../testing.h"
// obj1 null
// obj2 null
// both null
// obj1 not a rolling_ball
// obj2 is invalid object

// hcushion above
bool bounce_hcushion_above(void) {
    bool testPass = false;

    phylib_coord pos = phylib_new_coord(30.7, 123.1);
    phylib_coord vel = phylib_new_coord(783.1, 425.81);
    phylib_coord acc = phylib_new_coord(-161.1, -161.1);
    phylib_object *rolling_ball = phylib_new_rolling_ball(1, &pos, &vel, &acc);

    phylib_object *hcushion = phylib_new_hcushion(151.6);

    pos = phylib_new_coord(30.7, 123.1);
    vel = phylib_new_coord(783.1, -425.81);
    acc = phylib_new_coord(-161.1, 161.1);
    phylib_object *expected_ball = phylib_new_rolling_ball(1, &pos, &vel, &acc);

    phylib_bounce(&rolling_ball, &hcushion);
    if (assert_objects_equal(expected_ball, rolling_ball)) {
        testPass = true;
        pass("bounce_hcushion_above");
    } else {
        testPass = false;
        fail("bounce_hcushion_above");
    }
    free(rolling_ball);
    free(hcushion);
    free(expected_ball);
    return testPass;
}
// hcushion below
bool bounce_hcushion_below(void) {
    bool testPass = false;

    phylib_coord pos = phylib_new_coord(2461.2, 983.11);
    phylib_coord vel = phylib_new_coord(623.1, -624.9);
    phylib_coord acc = phylib_new_coord(-912.1, 952.7);
    phylib_object *rolling_ball = phylib_new_rolling_ball(1, &pos, &vel, &acc);

    phylib_object *hcushion = phylib_new_hcushion(954.61);

    pos = phylib_new_coord(2461.2, 983.11);
    vel = phylib_new_coord(623.1, 624.9);
    acc = phylib_new_coord(-912.1, -952.7);
    phylib_object *expected_ball = phylib_new_rolling_ball(1, &pos, &vel, &acc);

    phylib_bounce(&rolling_ball, &hcushion);
    if (assert_objects_equal(expected_ball, rolling_ball)) {
        testPass = true;
        pass("bounce_hcushion_below");
    } else {
        testPass = false;
        fail("bounce_hcushion_below");
    }
    free(rolling_ball);
    free(hcushion);
    free(expected_ball);
    return testPass;
}
// vcushion left
bool bounce_vcushion_left(void) {
    bool testPass = false;

    phylib_coord pos = phylib_new_coord(912.3, 983.11);
    phylib_coord vel = phylib_new_coord(745.9, 1359);
    phylib_coord acc = phylib_new_coord(-103.4, -341.0);
    phylib_object *rolling_ball = phylib_new_rolling_ball(1, &pos, &vel, &acc);

    phylib_object *vcushion = phylib_new_vcushion(940.8);

    pos = phylib_new_coord(912.3, 983.11);
    vel = phylib_new_coord(-745.9, 1359);
    acc = phylib_new_coord(103.4, -341.0);
    phylib_object *expected_ball = phylib_new_rolling_ball(1, &pos, &vel, &acc);

    phylib_bounce(&rolling_ball, &vcushion);
    if (assert_objects_equal(expected_ball, rolling_ball)) {
        testPass = true;
        pass("bounce_vcushion_left");
    } else {
        testPass = false;
        fail("bounce_vcushion_left");
    }
    free(rolling_ball);
    free(vcushion);
    free(expected_ball);
    return testPass;
}
// vcushion right
bool bounce_vcushion_right(void) {
    bool testPass = false;

    phylib_coord pos = phylib_new_coord(9103.02, 231.7);
    phylib_coord vel = phylib_new_coord(-1402.4, 1056.8);
    phylib_coord acc = phylib_new_coord(259.3, -521.3);
    phylib_object *rolling_ball = phylib_new_rolling_ball(1, &pos, &vel, &acc);

    phylib_object *vcushion = phylib_new_vcushion(9074.52);

    pos = phylib_new_coord(9103.02, 231.7);
    vel = phylib_new_coord(1402.4, 1056.8);
    acc = phylib_new_coord(-259.3, -521.3);
    phylib_object *expected_ball = phylib_new_rolling_ball(1, &pos, &vel, &acc);

    phylib_bounce(&rolling_ball, &vcushion);
    if (assert_objects_equal(expected_ball, rolling_ball)) {
        testPass = true;
        pass("bounce_vcushion_right");
    } else {
        testPass = false;
        fail("bounce_vcushion_right");
    }
    free(rolling_ball);
    free(vcushion);
    free(expected_ball);
    return testPass;
}
// arbitrary hole
bool bounce_hole(void) {
    bool testPass = false;

    phylib_coord pos = phylib_new_coord(28.5,-28.5);
    phylib_coord vel = phylib_new_coord(821.1, 93.2);
    phylib_coord acc = phylib_new_coord(-842.1, -374.2);
    phylib_object *rolling_ball = phylib_new_rolling_ball(1, &pos, &vel, &acc);

    pos = phylib_new_coord(0,0);
    phylib_object *hole = phylib_new_hole(&pos);

    phylib_object *expected_ball = NULL;

    phylib_bounce(&rolling_ball, &hole);
    if (assert_objects_equal(expected_ball, rolling_ball)) {
        testPass = true;
        pass("bounce_hole");
    } else {
        testPass = false;
        fail("bounce_hole");
    }
    free(rolling_ball);
    free(hole);
    return testPass;
}
// still ball is converted to rolling
bool bounce_still_to_rolling(void) {
    bool testPass = false;

    phylib_coord pos = phylib_new_coord(1239.0,-697.225);
    phylib_coord vel = phylib_new_coord(89.53, -173.2);
    phylib_coord acc = phylib_new_coord(-23.8, 89.3);
    phylib_object *rolling_ball = phylib_new_rolling_ball(1, &pos, &vel, &acc);

    pos = phylib_new_coord(1203.6, -741.90);
    phylib_object *ball_two = phylib_new_still_ball(4, &pos);

    phylib_bounce(&rolling_ball, &ball_two);
    if (ball_two->type == PHYLIB_ROLLING_BALL) {
        testPass = true;
        pass("still_to_rolling");
    } else {
        testPass = false;
        fail("still_to_rolling");
    }
    free(rolling_ball);
    free(ball_two);
    return testPass;
}
// still ball direct hit
// brush side of still ball
// a ball going just slower than epsilon hitting still ball
// complete oposite rolling ball
// rolling ball same direction
// 2 random rolling ball cases
