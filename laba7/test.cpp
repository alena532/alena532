#include "Header.h"
#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstring>
void test(){
    FILE *file;
    if ((file= fopen("output1.txt","r")) == NULL){
        std::cout<<"Mistake";
        exit(0);
        }
    List a;
    while(!feof(file)){
        a.Push_back(file);
        } 
    assert(a.Size()==3);
    assert(a.Empty()==false);

    Node* temp=a.head;

    char another1[20]="AA12345";
    assert(ByFlightNumber(a,another1)==NULL);
    char another2[20]="AA123";
    assert(ByFlightNumber(a,another2)==temp);

    char country1[20]="Minsk";
    assert(ByCountry(a,country1)==NULL);
    char country2[20]="Moscow";
    assert(ByCountry(a,country2)==temp);

    char time1[20]="14:43";
    assert(ByTime(a,time1)==NULL);
    char time2[20]="14:45";
    assert(ByTime(a,time2)==temp);

    char type1[20]="buinf";
    assert(ByPlaneType(a,type1)==NULL);
    char type2[20]="boing";
    assert(ByPlaneType(a,type2)==temp);

    char inter1[20]="buinf";
    assert(ByInterCountry(a,inter1)==NULL);
    char inter2[20]="Rostov";
    assert(ByInterCountry(a,inter2)==temp);

    assert(Booking(a,another2)==true);
    assert(Booking(a,another1)==false);

    assert(Returning(a,another2)==true);
    assert(Returning(a,another1)==false);

    assert(FreePlaces(a,another1)==0);






    
    
    
    
    
}
#undef main
int main(){
    test();
    return 0;
}
