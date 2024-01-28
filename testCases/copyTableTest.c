#include "../testing.h"

bool copy_table_test_null_table(void) {
    bool testPass = false;
    phylib_table *table = NULL;
    phylib_table *copy = phylib_copy_table(table);
    if (!copy) {
        pass("NULL_table");
        testPass = true;
    } else {
        fail("NULL_table");
        testPass = false;
    }
    return testPass;
}

bool copy_table_test_time(void) {
    bool testPass = false;
    phylib_table *table = phylib_new_table();
    table->time = 2341.64;
    phylib_table *copy = phylib_copy_table(table);
    if (copy->time == table->time) {
        pass("time");
        testPass = true;
    } else {
        fail("time");
        testPass = false;
    }
    return testPass;
}

bool copy_table_test_no_object(void) {
    
    bool testPass = true;
    phylib_table *table = phylib_new_table();
    table->time = 21342;
    for (int i = 0; i < PHYLIB_MAX_OBJECTS; i++) {
        if (table->object[i]) {
            free(table->object[i]);
            table->object[i] = NULL;
        }
    }
    phylib_table *copy = phylib_copy_table(table);
    for (int i = 0; i < PHYLIB_MAX_OBJECTS; i++) {
        if (!assert_objects_equal(table->object[i], copy->object[i])) {
            testPass = false;
        }
    }
    if (testPass) {
        pass("no_object");
    } else {
        fail("no_object");
    }
    free(table);
    free(copy);
    return testPass;
}

bool copy_table_test_base_objects(void) {
    bool testPass = false;
    phylib_table *table = phylib_new_table();
    phylib_table *copy = phylib_copy_table(table);
    if (assert_tables_equal(table, copy)) {
        pass("base_objects");
        testPass = true;
    } else {
        fail("base_objects");
        testPass = false;
    }
    phylib_free_table(table);
    phylib_free_table(copy);
    return testPass;
}

bool copy_table_test_table_full(void) {
    bool testPass = false;
    phylib_table *table = phylib_new_table();
    //1
    phylib_coord pos = phylib_new_coord(21.1, 452.9);
    phylib_coord vel = phylib_new_coord(624.1, 112);
    phylib_coord acc = phylib_new_coord(90.0, 0.0);
    phylib_object *new = phylib_new_rolling_ball(2, &pos, &vel, &acc);
    phylib_add_object(table, new);
    //2
    pos = phylib_new_coord(345.1234, 62);
    vel = phylib_new_coord(01,23);
    acc = phylib_new_coord(1,2);
    new = phylib_new_rolling_ball(5, &pos, &vel, &acc);
    phylib_add_object(table, new);
    //3
    pos = phylib_new_coord(0, 0);
    vel = phylib_new_coord(0,0);
    acc = phylib_new_coord(0,0);
    new = phylib_new_rolling_ball(0, &pos, &vel, &acc);
    phylib_add_object(table, new);
    //4
    pos = phylib_new_coord(134.642, 173.13);
    new = phylib_new_still_ball(69, &pos);
    phylib_add_object(table, new);
    //5
    pos = phylib_new_coord(12345, 1223.3);
    new = phylib_new_still_ball(60, &pos);
    phylib_add_object(table, new);
    //6
    pos = phylib_new_coord(2452, 50643);
    new = phylib_new_still_ball(29, &pos);
    phylib_add_object(table, new);
    //7
    pos = phylib_new_coord(1111, 2222);
    new = phylib_new_still_ball(33, &pos);
    phylib_add_object(table, new);
    //8
    pos = phylib_new_coord(09123.0, 0.420);
    new = phylib_new_still_ball(69, &pos);
    phylib_add_object(table, new);
    //9
    pos = phylib_new_coord(023.0, 083.0);
    new = phylib_new_hole(&pos);
    phylib_add_object(table, new);
    //10
    pos = phylib_new_coord(00, 00);
    new = phylib_new_hole(&pos);
    phylib_add_object(table, new);
    //11
    pos = phylib_new_coord(2131231,12003);
    new = phylib_new_hole(&pos);
    phylib_add_object(table, new);
    //12
    pos = phylib_new_coord(0.0001,111.444);
    new = phylib_new_hole(&pos);
    phylib_add_object(table, new);
    //13
    new = phylib_new_hcushion(1341.2);
    phylib_add_object(table, new);
    //14
    new = phylib_new_hcushion(12.1);
    phylib_add_object(table, new);
    //15
    new = phylib_new_hcushion(1.1);
    phylib_add_object(table, new);
    //16
    new = phylib_new_vcushion(420.69);
    phylib_add_object(table, new);

    phylib_table *copy = phylib_copy_table(table);

    if (assert_tables_equal(table, copy)) {
        pass("full_table");
        testPass = true;
    } else {
        print_table(table);
        print_table(copy);
        fail("full_table");
        testPass = false;
    }

    phylib_free_table(table);
    return testPass;
}

bool copy_table_test_different_mem(void) {
    bool testPass = true;
    phylib_table *table = phylib_new_table();
    phylib_table *copy = phylib_copy_table(table);

    if (table == copy) {
        testPass = false;
    }
    for (int i = 0; i < PHYLIB_MAX_OBJECTS; i++) {
        if (table->object[i] == NULL) {
            continue;
        }
        if (table->object[i] == copy->object[i]) {
            testPass = false;
        }
    }
    if (testPass) {
        pass("different_mem");
    } else {
        fail("different_mem");
    }
    phylib_free_table(table);
    phylib_free_table(copy);
    return testPass;
}
