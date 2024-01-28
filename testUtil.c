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

bool assert_tables_equal(phylib_table *table1, phylib_table *table2) {
    bool equal = true;
    if (table1->time != table2->time) {
        printf("The time variable is not equal\n");
        equal = false;
    }
    for (int i = 0; i < PHYLIB_MAX_OBJECTS; i++) {
        if (!assert_objects_equal(table1->object[i], table2->object[i])) {
            printf("Objects at index %d are not equal\n", i);
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
        printf("Objects are not equal\n");
        return false;
    }
    switch(obj1->type) {
        case PHYLIB_STILL_BALL:
        {
            if (obj2->type != PHYLIB_STILL_BALL) {
                printf("Objects are not the same type | %d vs %d\n", obj1->type, obj2->type);
                return false;
            }
            if (
                obj1->obj.still_ball.number == obj2->obj.still_ball.number
                && obj1->obj.still_ball.pos.x == obj2->obj.still_ball.pos.x
                && obj1->obj.still_ball.pos.y == obj2->obj.still_ball.pos.y
            ) {
                return true;
            } else {
                printf("Objects are not equal\n");
                return false;
            }
        }
        case PHYLIB_ROLLING_BALL:
        {
            if (obj2->type != PHYLIB_ROLLING_BALL) {
                printf("Objects are not the same type | %d vs %d\n", obj1->type, obj2->type);
                return false;
            }
            if (
                obj1->obj.rolling_ball.number == obj2->obj.rolling_ball.number
                && obj1->obj.rolling_ball.pos.x == obj2->obj.rolling_ball.pos.x
                && obj1->obj.rolling_ball.pos.y == obj2->obj.rolling_ball.pos.y
                && obj1->obj.rolling_ball.vel.x == obj2->obj.rolling_ball.vel.x
                && obj1->obj.rolling_ball.vel.y == obj2->obj.rolling_ball.vel.y
                && obj1->obj.rolling_ball.acc.x == obj2->obj.rolling_ball.acc.x
                && obj1->obj.rolling_ball.acc.y == obj2->obj.rolling_ball.acc.y
            ) {
                return true;
            } else {
                 printf("Objects are not equal\n");
                return false;
            }
        }
        case PHYLIB_HOLE:
        {
            if (obj2->type != PHYLIB_HOLE) {
                printf("Objects are not the same type | %d vs %d\n", obj1->type, obj2->type);
                return false;
            }
            if (
                obj1->obj.hole.pos.x == obj2->obj.hole.pos.x
                && obj1->obj.hole.pos.y == obj2->obj.hole.pos.y
            ) {
                return true;
            } else {
                 printf("Objects are not equal\n");
                return false;
            }
        }
        case PHYLIB_HCUSHION:
        {
            if (obj2->type != PHYLIB_HCUSHION) {
                printf("Objects are not the same type | %d vs %d\n", obj1->type, obj2->type);
                return false;
            }
            if (
                obj1->obj.hcushion.y == obj2->obj.hcushion.y
            ) {
                return true;
            } else {
                printf("Objects are not equal | %f vs %f\n", obj1->obj.hcushion.y, obj2->obj.hcushion.y);
                return false;
            }
        }
        case PHYLIB_VCUSHION:
        {
            if (obj2->type != PHYLIB_VCUSHION) {
                printf("Objects are not the same type | %d vs %d\n", obj1->type, obj2->type);
                return false;
            }
            if (
                obj1->obj.vcushion.x == obj2->obj.vcushion.x
            ) {
                return true;
            } else {
                 printf("Objects are not equal | %f vs %f\n", obj1->obj.vcushion.x, obj2->obj.vcushion.x);
                return false;
            }
        }
        default: 
        {
            printf("Object 1 is an invalid type | %d\n", obj1->type);
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
