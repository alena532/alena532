#include <stdio.h>
#include<stdlib.h>
#include"main.h"
struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};
 struct myNumber {
    Node* head;
    Node* tail;
    int size;
};
void Add(myNumber *number,int str)
{
    Node* temp=(Node *)malloc(sizeof(Node));
    temp->data=str;
    temp->prev=NULL;
    temp->next=NULL;
    if(number->head==NULL){
        number->tail= number-> head=temp;
    }else{
        temp->prev=number->tail;
        number->tail->next=temp;
        number->tail=temp;
    }
    number->size++;
}
 myNumber Create(char* str)
{
    myNumber number={NULL,NULL,0};
    for(int i=0;str[i]!='\0';i++){
        Add(&number,str[i]-'0');
    }
    return number;
}
int Equal(myNumber *number1,myNumber *number2)
{
    myNumber *first=number1;
    myNumber *second=number2;
    if(first->size>second->size){
        return 1;
    }else if(first->size<second->size){
        return -1;
    }else{
        Node* temp1=number1->head;
        Node* temp2=number2->head;
        while(1){
            if(temp1->data>temp2->data){
                return 1;
            }else if(temp1->data<temp2->data){
                return -1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp1==NULL && temp2==NULL){
                return 0;
            }
        }
    }
}
int BigNumber(myNumber *number1)
{
    int amountRank=number1->size;
    int current;
    long int number=0;
    Node* temp=number1->head;
    int nodeNumber=temp->data;
    long int sumNode;
    if(amountRank==1){
        return nodeNumber;
    }
    while(amountRank!=1){
        current =amountRank;
        sumNode=nodeNumber;
        for(int i=0;i<current-1;i++){
            sumNode*=10;
        }
        number+=sumNode;
        amountRank--;
       temp=temp->next;
        nodeNumber=temp->data;
        if(amountRank==1){
            sumNode=nodeNumber;
            number+=sumNode;
            break;
        }
    }
    return number;
}
int LongDivShort(myNumber *number1,int yourNumber)
{
    int number=BigNumber(number1);
    number=number/yourNumber;
    return number;
}
int LongModShort(myNumber *number1,int yourNumber)
{
    int number=BigNumber(number1);
    number=number%yourNumber;
    return number;
    
}
int LongMulShort(myNumber *number1,int yourNumber)
{
    int number=BigNumber(number1);
    number=number*yourNumber;
    return number;
}
void Show(myNumber *number)
{
    Node *temp=number->head;
    while(temp){
        printf("%d",temp->data);
        temp=temp->next;
    }
}
int main(int argc, const char * argv[]) {
    myNumber a = Create("17562138");
    myNumber b = Create("12345678918923456789");
    printf("%d",LongDivShort(&a, 2));
    return 0;
}
