#include "1lab.h"
#include <assert.h>
#include<stdio.h>
//hello
void test(){
    assert (Sum(5250)==7);
    assert (Sum(528)==15);
    assert (Sum(828)==18);
    
}

#undef main
int main(){
    test();
}


