// returns the number of rolling balls on a table
#include "../testing.h"

// null table, expect 0
bool rolling_null_table(void) {
    bool testPass = false;
    phylib_table *table = NULL;
    if (phylib_rolling(table) == (unsigned char) 0) {
        testPass = true;
    }
    if (testPass) {
        pass("rolling_t_null");
    } else {
        fail("rolling_t_null");
    }
    phylib_free_table(table);
    return testPass;
}
// entire table is NULL, expect 0
bool rolling_all_null(void) {
    bool testPass = false;
    phylib_table *table = phylib_new_table();
    for (int i = 0; i < PHYLIB_MAX_OBJECTS; i++) {
        if (table->object[i]) {
            free(table->object[i]);
        }
        table->object[i] = NULL;
    }
    if (phylib_rolling(table) == (unsigned char) 0) {
        testPass = true;
    }
    if (testPass) {
        pass("all_null");
    } else {
        fail("all_null");
    }
    phylib_free_table(table);
    return testPass;
}
// every object is a rolling ball, expect 26
bool rolling_all_rolling(void) {
    bool testPass = false;
    phylib_table *table = phylib_new_table();

    phylib_coord pos = phylib_new_coord(31.1, 63.2);
    phylib_coord vel = phylib_new_coord(912.4, 62.23);
    phylib_coord acc = phylib_new_coord(9241.2, 2682.1);
    phylib_object *new_ball = phylib_new_rolling_ball(2, &pos, &vel, &acc);

    table->object[0] = new_ball;
    phylib_object *another_ball;
    for (int i = 1; i < PHYLIB_MAX_OBJECTS; i++) {
        phylib_copy_object(&another_ball, &new_ball); 
        table->object[i] = another_ball;
    }
    if (phylib_rolling(table) == (unsigned char) 26) {
        testPass = true;
        pass("all_rolling");
    } else {
        testPass = false;
        fail("all_rolling");
    }
    phylib_free_table(table);
    return testPass;
}

// mixed number of rolling balls, expect 5
bool rolling_mixed(void) {
    bool testPass = false;
    phylib_table *table = phylib_new_table();

    phylib_coord pos = phylib_new_coord(31.1, 63.2);
    phylib_coord vel = phylib_new_coord(912.4, 62.23);
    phylib_coord acc = phylib_new_coord(9241.2, 2682.1);
    phylib_object *rolling_ball = phylib_new_rolling_ball(2, &pos, &vel, &acc);
    phylib_add_object(table, rolling_ball); // 1

    pos = phylib_new_coord(8913.1, 923.97);
    phylib_object *still_ball = phylib_new_still_ball(1, &pos);
    phylib_add_object(table, still_ball);

    phylib_object *rolling_copy;
    phylib_object *still_copy;
    phylib_copy_object(&rolling_copy, &rolling_ball);
    phylib_add_object(table, rolling_copy); // 2

    phylib_copy_object(&rolling_copy, &rolling_ball);
    table->object[PHYLIB_MAX_OBJECTS-1] = rolling_copy; // 3
    phylib_copy_object(&still_copy, &still_ball);
    phylib_add_object(table, still_copy);

    phylib_copy_object(&rolling_copy, &rolling_ball);
    phylib_add_object(table, rolling_copy); // 4
    phylib_copy_object(&rolling_copy, &rolling_ball);
    phylib_add_object(table, rolling_copy); // 5

    if (phylib_rolling(table) == (unsigned char) 5) {
        testPass = true;
        pass("mixed_rolling");
    } else {
        testPass = false;
        print_table(table);
        fail("mixed_rolling");
    }
    phylib_free_table(table);
    return testPass;
}
