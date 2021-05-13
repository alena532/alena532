#ifndef Header_h
#define Header_h
#include<string>
#include<vector>
#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;
struct Node
{
    Node*previous;
    Node*next;
    char flightNumber[15];
    char planeType[15];
    char country[15];
    char interCountry[50];
    char time[15];
    int seats[20];
    char days[50];
    char countSeats[20];
    int *aray;
    Node(Node *previous,Node*next){
        this->previous=previous;
        this->next=next;
    }
    
};
class List
{
public:
    Node *head;
    Node *tail;
    int size;
public:
    List();
    void Delete_list();
    void Show();
    void Push_back(FILE *file);
    
   
    int Size();
    bool Empty();
    ~List();
};

void ShowPlane(Node *temp);
Node* ByFlightNumber(List &a,char another[]);
Node* ByCountry(List &a,char another[]);
Node* ByTime(List &a,char another[]);
Node* ByPlaneType(List &a,char another[]);
Node* ByInterCountry(List &a,char another[]);
Node* ByDays(List &a,char another[]);
bool ClosestDay(int indxDay,Node *temp);
void Closest(List &a);
Node *planeNumber(List&a,char another[]);
bool Booking(List &a,char another[]);
bool Returning(List &a,char another[]);
int FreePlaces(List &a,char another[]);
void ShowTicket(List &a,char another[]);


 



 




#endif /* Header_h */
