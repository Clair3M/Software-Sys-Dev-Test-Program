# Software Systems Test Program
This is a testing program built for the course at University of Guelph Software Systems Development and Integration (CIS*2750). The tests are all build using C.

## Coverage
The current test coverage is quite low. Only a few functions have test cases and those functions are not thoroughly tested.

## Compiling
Add the following to your A1 makefile

```
TESTSRC = testingMain.c testUtil.c copyObject.c copyTableTest.c distanceTest.c
vpath %.c ../Software-Sys-Dev-Test-Program:../Software-Sys-Dev-Test-Program/testCases

phylib_test: phylib.c $(TESTSRC)
	$(CC) $(CFLAGS) -lm $^ -o $@
	./phylib_test
```
* To run the tests simple type the command "make phylib_test" into your command line

## Contributors
* <a href="github.com/Clair3M">Claire Mather</a>
