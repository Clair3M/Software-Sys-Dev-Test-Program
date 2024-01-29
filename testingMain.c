#include "testing.h"

int main(int argc, char** argv) {
    int tests = 31;

    for (int i = 0; i < 10; i++)
        printf("*");
    printf(" Test ");
    for (int i = 0; i < 10; i++)
        printf("*");
    printf("\n\n");

    bool (*testCase[31])(void) = {
                                   copy_object_test_null,
                                   copy_object_dest_null,
                                   copy_object_existing_object,
                                   copy_object_test_outer_null,
                                   copy_table_test_null_table,
                                   copy_table_test_time,
                                   copy_table_test_no_object,
                                   copy_table_test_base_objects,
                                   copy_table_test_table_full,
                                   copy_table_test_different_mem,
                                   distance_obj1_null,
                                   distance_obj2_null,
                                   distance_obj1_invalid_type,
                                   distance_obj2_invalid_type,
                                   distance_still_ball_normal,
                                   distance_still_ball_same,
                                   distance_rolling_ball,
                                   distance_hole,
                                   distance_hcushion,
                                   distance_vcushion,
                                   rolling_null_table,
                                   rolling_all_null,
                                   rolling_all_rolling,
                                   rolling_mixed,
                                   bounce_hcushion_above,
                                   bounce_hcushion_below,
                                   bounce_vcushion_left,
                                   bounce_vcushion_right,
                                   bounce_hole,
                                   bounce_still_to_rolling,
                                   bounce_still_direct_hit
                                 };

    int num_passes = 0;
    for (int i = 0; i < tests; i++) {
        if (testCase[i]()) {
            num_passes++;
        }
    }
    printf("\n");
    printf("Tests passed: %d/%d\n", num_passes, tests);
}
