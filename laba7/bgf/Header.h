//
//  Header.h
//  bgf
//
//  Created by Алена Воробей on 4/27/21.
//

#ifndef Header_h
#define Header_h
#include<string>
#include<vector>
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
    //void Insert(int index,int data);
   // void Pop_back();
   
    int Size();
    bool Empty();
    ~List();
};

#endif /* Header_h */
