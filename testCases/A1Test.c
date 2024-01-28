#include "../testing.h"

void createTables(phylib_table *table_one, phylib_table *table_two, phylib_table *table_three, phylib_table *table_four) {
  table_one = phylib_new_table();
  table_two = phylib_new_table();
  table_three = phylib_new_table();
  table_four = NULL;

  table_one->time = 1.6;
  table_two->time = 4.0;
  table_one->time = 4.5;

  phylib_coord pos = phylib_new_coord(634.7, 634.7);
  phylib_coord vel = phylib_new_coord(-358.5, -358.3);
  phylib_coord acc = phylib_new_coord(106.1, 106.0);
  phylib_object *rolling_ball = phylib_new_rolling_ball(1, &pos, &vel, &acc);
  table_one->object[10] = rolling_ball;
  
  pos = phylib_new_coord(675.0, 675.0);
  vel = phylib_new_coord(358.5, -358.7);
  vel = phylib_new_coord(-106.0, -106.1);
  rolling_ball = phylib_new_rolling_ball(0, &pos, &vel, &acc);
  table_one->object[11] = rolling_ball;

  pos = phylib_new_coord(1229.4, 120.2);
  vel = phylib_new_coord(104.5, -104.6);
  vel = phylib_new_coord(-106.0, -106.1);
  rolling_ball = phylib_new_rolling_ball(0, &pos, &vel, &acc);
  table_two->object[11] = rolling_ball;
}

// test case adapted from A1Test written by Stefan C. Kremer
bool providedTest(void) {
  phylib_coord pos, vel, acc;
  phylib_table *table;
  phylib_object *sb;
  phylib_object *rb;

  table = phylib_new_table();

  // create a still ball 1/4 of the way "down" the middle of the table,
  // shift it up, and to the left just a little bit
  pos.x = PHYLIB_TABLE_WIDTH / 2.0 
          - sqrt( PHYLIB_BALL_DIAMETER*PHYLIB_BALL_DIAMETER / 2.0 );
  pos.y = PHYLIB_TABLE_WIDTH / 2.0
          - sqrt( PHYLIB_BALL_DIAMETER*PHYLIB_BALL_DIAMETER / 2.0 );
  sb = phylib_new_still_ball( 1, &pos );

  // create a rolling ball 3/4 of the way "down the table,
  // rolling up along the centre
  pos.x = PHYLIB_TABLE_WIDTH / 2.0;
  pos.y = PHYLIB_TABLE_LENGTH - PHYLIB_TABLE_WIDTH / 2.0;
  vel.x = 0.0;
  vel.y = -1000.0; // 1m/s (medium speed)
  acc.x = 0.0;
  acc.y = 180.0;
  rb = phylib_new_rolling_ball( 0, &pos, &vel, &acc );

  phylib_add_object( table, sb );
  phylib_add_object( table, rb );

  phylib_table *table_one = NULL
             , *table_two = NULL
             , *table_three = NULL
             , *table_four = NULL;
  createTables(table_one, table_two, table_three, table_four);

  bool testPass = true;

  phylib_table *result_one = phylib_segment(table);
  if (!assert_tables_equal(table_one, result_one)) {
    testPass = false;
  }
  phylib_free_table(table);

  phylib_table *result_two = phylib_segment(result_one);
  if (!assert_tables_equal(table_two, result_two)) {
    testPass = false;
  }
  phylib_free_table(result_one);

  phylib_table *result_three = phylib_segment(result_two);
  if (!assert_tables_equal(table_three, result_three)) {
    testPass = false;
  }
  phylib_free_table(result_two);
  
  phylib_table *result_four = phylib_segment(result_three);
  if (!assert_tables_equal(table_four, result_four)) {
    testPass = false;
  }
  if (testPass) {
    pass("provided");
  } else {
    fail("provided");
  }
  return testPass;
}
