#ifndef _TESTING_H
#define _TESTING_H
#include "../phylib.h"

    void pass();
    void fail();
    bool assert_objects_equal(phylib_object *obj1, phylib_object *obj2);
    bool assert_tables_equal(phylib_table *table1, phylib_table *table2);

    void copy_object_test_null();
    void copy_object_existing_object();
    void copy_object_dest_null();

#endif
