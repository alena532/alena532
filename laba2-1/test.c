#include "main.h"
#include <assert.h>
#include <stdio.h>

void test(){
    assert(countCars(60)==3);
    assert(countCars(61)==4);
    assert(countCars(80)==4);
}
#undef main
int main(){
    test();
    return 0;
}