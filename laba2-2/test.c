#include "main.h"
#include <assert.h>
#include <stdio.h>

void test(){
    assert(fact(5)==120);
    assert(fact(4)==24);
    assert(fact(6)==720);
}
#undef main
int main(){
    test();
    return 0;
}
