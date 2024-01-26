#include "testing.h"

int main(int argc, char** argv) {

    for (int i = 0; i < 10; i++)
        printf("*");
    printf(" Test ");
    for (int i = 0; i < 10; i++)
        printf("*");
    printf("\n\n");
    
    printf("phylib_copy_object:\n");
    copy_object_test_null();
    copy_object_dest_null();
    copy_object_existing_object();
    printf("\n\n");

    printf("phylib_copy_table:\n");
    copy_table_test_null_table();
    copy_table_test_time();
    copy_table_test_no_object();
    copy_table_test_base_objects();
    copy_table_test_table_full();
    copy_table_test_different_mem();
    printf("\n\n");
}
