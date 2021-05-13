#include <iostream>
#include<stdio.h>
#include<fstream>
#include<cstring>
#include"Header.h"
#include<vector>

using namespace std;

 
int main(int argc, const char * argv[]) {
    setlocale(0, "");
    
      List a;
    FILE *file;
    if ((file= fopen("output2.txt","r")) == NULL){
        cout<<"Mistake";
        exit(0);
        }

    while(!feof(file)){
        a.Push_back(file);
        }
    fclose(file);
    while(1){
        cout<<"Menu:"<<endl;
        cout<<"1.Search plane"<<endl;
        cout<<"2.The most closest rase"<<endl;
        cout<<"3.Book ticket"<<endl;
        cout<<"4.Return ticket"<<endl;
        cout<<"5.Free seats"<<endl;
        cout<<"6.Show a ticket"<<endl;
        cout<<"7.Exit"<<endl;
        cout<<"Enter a number"<<endl;
        int num;
            while(scanf("%d",&num)!=1||num<1||num>8){
                printf("Mistake!Try again");
                while(getchar()!='\n');
            }
            switch(num){
                case 1:
                cout<<"1.Searching by flight number"<<endl;
                cout<<"2.Searching by country"<<endl;
                cout<<"3.Searching by inter country"<<endl;
                cout<<"4.Searching by time"<<endl;
                cout<<"5.Searching by plane type"<<endl;
                cout<<"6.Searching by days"<<endl;
                cout<<"Enter a number"<<endl;
                int num2;
                while(scanf("%d",&num2)!=1||num2<1||num2>7){
                 printf("Mistake!Try again");
                while(getchar()!='\n');
                }
                switch(num2){
                    case 1:
                        cout<<"Please enter flight number";
                        char Another1[20];
                        cin>>Another1;
                        ByFlightNumber(a,Another1);
                        break;
                    case 2:
                        cout<<"Please enter country number";
                        char Another2[20];
                        cin>>Another2;
                        ByCountry(a,Another2);
                        break;
                    case 3:
                        char Another3[20];
                        cout<<"Enter a Intermediate country";
                        cin>>Another3;
                        ByInterCountry(a,Another3);
                        break;
                    case 4:
                        cout<<"Please enter flight time";
                        char Another4[20];
                        cin>>Another4;
                        ByTime(a,Another4);
                        break;
                    case 5:
                        cout<<"Please enter plane type";
                        char Another5[20];
                        cin>>Another5;
                        ByPlaneType(a,Another5);
                        break;
                    case 6:
                        cout<<"Please enter inter country";
                        char Another6[20];
                        cin>>Another6;
                        ByDays(a,Another5);
                        break;
                }
                    break;
                case 2:
                    Closest(a);
                    break;
                case 3:
                    char another7[20];
                    cout<<"Enter a flight number";
                    cin>>another7;
                    Booking(a,another7);
                    break;
                case 4:
                    char another8[20];
                    cout<<"Enter a flight number";
                    cin>>another8;
                    Returning(a,another8);
                    break;
                case 5:
                    char another9[20];
                    cout<<"Enter a flight number";
                    cin>>another9;
                    FreePlaces(a,another9);
                    break;
                case 6:
                    char another10[20];
                    cout<<"Enter a flight number";
                    cin>>another10;
                    ShowTicket(a,another10);
                    break;
                case 7:
                    a.Delete_list();
                    cout<<"Finish";
                    exit(0);
                    break;
            }
    }
    
    return 0;
}
