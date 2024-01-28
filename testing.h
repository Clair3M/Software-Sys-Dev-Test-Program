#ifndef _TESTING_H
#define _TESTING_H
#include "../A1/phylib.h"
#include <stdbool.h>

    void pass(char *);
    void fail(char *);
    bool assert_objects_equal(phylib_object *obj1, phylib_object *obj2);
    bool assert_tables_equal(phylib_table *table1, phylib_table *table2);
    void print_table( phylib_table *table );
    void print_object( phylib_object *object );

    void copy_object_test_null(void);
    void copy_object_existing_object(void);
    void copy_object_dest_null(void);
    void copy_object_test_outer_null(void);

    void copy_table_test_null_table(void);
    void copy_table_test_time(void);
    void copy_table_test_no_object(void);
    void copy_table_test_base_objects(void);
    void copy_table_test_table_full(void);
    void copy_table_test_different_mem(void);

    void distance_obj1_null(void);
    void distance_obj2_null(void);
    void distance_obj1_invalid_type(void);
    void distance_obj2_invalid_type(void);
    void distance_still_ball_normal(void);
    void distance_still_ball_same(void);
    void distance_rolling_ball(void);
    void distance_hole(void);
    void distance_hcushion(void);
    void distance_vcushion(void);

#endif
