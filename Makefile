all: clean build_Main build_Test run_Test

build_Main: 1lab.c
    mkdir -p FIRST/main
    gcc -o FIRST/main/number 1lab.c -lm

build_Test: test.c 1lab.c
    mkdir -p FIRST/run_Test
    gcc -o FIRST/test/number_test -Dmain=_1lab 1lab.c test.c -lm

run_Test:
    ./FIRST/test/number_test

clean:
    rm -rf FIRST