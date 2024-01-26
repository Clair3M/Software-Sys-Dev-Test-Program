#include "testing.h"

bool proper_copy(phylib_table *table, phylib_table *copy) {
    bool passed = true;
    for (int i = 0; i < PHYLIB_MAX_OBJECTS; i++) {
        if (table->object[i] != copy->object[i])
    }
}

void copy_table_test_null_table() {
    printf("null_table: ");
    phylib_table *table = NULL;
    phylib_table *copy = phylib_copy_table(table);
    if (!copy) {
        pass();
    } else {
        fail();
    }
}

void copy_table_test_time() {
    printf("time: ");
    phylib_table *table = phylib_new_table();
    table->time = 2341.64;
    phylib_table *copy = phylib_copy_table(table);
    if (copy->time == table->time) {
        pass();
    } else {
        fail();
    }
}

void copy_table_test_no_object() {
    printf("no_object: ");
    bool passed = true;
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
        if (!assert_objects_equal(table->objects[i], copy->objects[i])) {
            passed = false;
        }
    }
    if (passed) {
        pass();
    } else {
        fail();
    }
    free(table);
    free(copy);
}

void copy_table_test_base_objects() {
    printf("base_objects: ");
    bool passed = true;
    phylib_table *table = phylib_new_table();
    phylib_table *copy = phylib_copy_table();
    for (int i = 0; i < PHYLIB_MAX_OBJECTS; i++) {
        if (!assert_objects_equal(table->objects[i], copy->objects[i])) {
            passed = false;
        }
    }
    
}

void copy_table_test_table_full() {
    printf("table_full: ");
}

void copy_table_test_different_mem() {
    printf("different_mem: ");
}
