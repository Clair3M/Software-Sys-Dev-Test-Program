#include "testing.h"

void pass(char *name) {
    printf("%-22s", name);
    printf("\033[0;32m");
    printf("Pass\n");
    printf("\033[0m"); 
}
void fail(char *name) {
    printf("%-22s", name);
    printf("\033[0;31m");
    printf("Fail\n");
    printf("\033[0m"); 
}

bool assert_tables_equal(phylib_table *expected, phylib_table *result) {
    bool equal = true;
    if (result == NULL || expected == NULL) {
        if ((result == NULL) != (expected == NULL)) {
            return false;
        }
        return true;
    }
    if (fabs(expected->time - result->time) > 0.1) {
        printf("Time was %6.1fs, expected %6.1fs\n", result->time, expected->time);
        return false;
    }
    for (int i = 0; i < PHYLIB_MAX_OBJECTS; i++) {
        if (!assert_objects_equal(expected->object[i], result->object[i])) {
            printf("Objects at index %d are not equal\n", i);
            printf("expected: ");
            print_object(expected->object[i]);
            printf("got: ");
            print_object(result->object[i]);
            equal = false;
        }
    }
    return equal;
}

bool assert_objects_equal(phylib_object *obj1, phylib_object *obj2) {
    if (!obj1) {
        if (!obj2) {
            return true;
        }
        return false;
    }
    switch(obj1->type) {
        case PHYLIB_STILL_BALL:
        {
            if (obj2->type != PHYLIB_STILL_BALL) {
                return false;
            }
            if (
                obj1->obj.still_ball.number == obj2->obj.still_ball.number
                && fabs(obj1->obj.still_ball.pos.x - obj2->obj.still_ball.pos.x) < 0.1
                && fabs(obj1->obj.still_ball.pos.y - obj2->obj.still_ball.pos.y) < 0.1
            ) {
                return true;
            } else {
                return false;
            }
        }
        case PHYLIB_ROLLING_BALL:
        {
            if (obj2->type != PHYLIB_ROLLING_BALL) {
                return false;
            }
            if (
                obj1->obj.rolling_ball.number == obj2->obj.rolling_ball.number
                && fabs(obj1->obj.rolling_ball.pos.x - obj2->obj.rolling_ball.pos.x) < 0.1
                && fabs(obj1->obj.rolling_ball.pos.y - obj2->obj.rolling_ball.pos.y) < 0.1
                && fabs(obj1->obj.rolling_ball.vel.x - obj2->obj.rolling_ball.vel.x) < 0.1
                && fabs(obj1->obj.rolling_ball.vel.y - obj2->obj.rolling_ball.vel.y) < 0.1
                && fabs(obj1->obj.rolling_ball.acc.x - obj2->obj.rolling_ball.acc.x) < 0.1
                && fabs(obj1->obj.rolling_ball.acc.y - obj2->obj.rolling_ball.acc.y) < 0.1
            ) {
                return true;
            } else {
                return false;
            }
        }
        case PHYLIB_HOLE:
        {
            if (obj2->type != PHYLIB_HOLE) {
                return false;
            }
            if (
                fabs(obj1->obj.hole.pos.x - obj2->obj.hole.pos.x) < 0.1
                && fabs(obj1->obj.hole.pos.y - obj2->obj.hole.pos.y) < 0.1
            ) {
                return true;
            } else {
                return false;
            }
        }
        case PHYLIB_HCUSHION:
        {
            if (obj2->type != PHYLIB_HCUSHION) {
                return false;
            }
            if ((obj1->obj.hcushion.y - obj2->obj.hcushion.y) < 0.1) {
                return true;
            } else {
                return false;
            }
        }
        case PHYLIB_VCUSHION:
        {
            if (obj2->type != PHYLIB_VCUSHION) {
                return false;
            }
            if (fabs(obj1->obj.vcushion.x - obj2->obj.vcushion.x) < 0.1) {
                return true;
            } else {
                return false;
            }
        }
        default: 
        {
            return false;
        }
    }
    return false;
}

void print_object( phylib_object *object )
{
  if (object == NULL)
  {
    printf( "NULL;\n" );
    return;
  }

  switch (object->type)
  {
    case PHYLIB_STILL_BALL:
      printf( "STILL_BALL (%d,%6.1lf,%6.1lf)\n",
	      object->obj.still_ball.number,
	      object->obj.still_ball.pos.x,
	      object->obj.still_ball.pos.y );
      break;

    case PHYLIB_ROLLING_BALL:
      printf( "ROLLING_BALL (%d,%6.1lf,%6.1lf,%6.1lf,%6.1lf,%6.1lf,%6.1lf)\n",
              object->obj.rolling_ball.number,
              object->obj.rolling_ball.pos.x,
              object->obj.rolling_ball.pos.y,
              object->obj.rolling_ball.vel.x,
              object->obj.rolling_ball.vel.y,
              object->obj.rolling_ball.acc.x,
              object->obj.rolling_ball.acc.y );
      break;

    case PHYLIB_HOLE:
      printf( "HOLE (%6.1lf,%6.1lf)\n",
	      object->obj.hole.pos.x,
	      object->obj.hole.pos.y );
      break;

    case PHYLIB_HCUSHION:
      printf( "HCUSHION (%6.1lf)\n",
	      object->obj.hcushion.y );
      break;

    case PHYLIB_VCUSHION:
      printf( "VCUSHION (%6.1lf)\n",
	      object->obj.vcushion.x );
      break;
  }
}

void print_table( phylib_table *table )
{
  if (!table)
  {
    printf( "NULL\n" );
    return ;
  }
  printf( "time = %6.1lf;\n", table->time );
  for ( int i=0; i<PHYLIB_MAX_OBJECTS; i++ )
  {
    printf( "  [%02d] = ", i );
    print_object( table->object[i] );
  }

}
