#include <iostream>
#include<stdio.h>
#include<fstream>
#include<cstring>
#include"Header.h"
#include<vector>

using namespace std;
List::List()
{
    tail=head=NULL;
    size=0;
}

void List::Show()
{
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->flightNumber<<temp->planeType<<temp->country<<temp->interCountry<<temp->time;
        temp=temp->next;
    }
}

void ShowPlane(Node *temp)
{
    cout<<"Plane is found"<<endl;
    cout<<"Flight number "<<temp->flightNumber<<endl;
    cout<<"A type of plane "<<temp->planeType<<endl;
    cout<<"Destination is "<<temp->country<<endl;
    cout<<"Intermediate points ";
    for(int i=0;temp->interCountry[i]!='\0';i++){
        if(65<=(int)temp->interCountry[i]&&(int)temp->interCountry[i]<=90){
            cout<<" "<<temp->interCountry[i];
            continue;
        }
        cout<<temp->interCountry[i];
    }
    cout<<endl;
    cout<<"Departure time "<<temp->time<<endl;
    cout<<"Flight days ";
    for(int i=0;temp->days[i]!='\0';i++){
        if(65<=(int)temp->interCountry[i]&&(int)temp->interCountry[i]<=90){
            cout<<" "<<temp->interCountry[i];
            continue;
        }
    }
    cout<<endl;
}
 
void List::Push_back(FILE *file)
{
    Node *temp=new Node(NULL,NULL);
    for(int i=0;i<20;i++){
        temp->seats[i]=0;
    }
    fscanf(file,"%s%s%s%s%s%s%s",temp->flightNumber,temp->planeType,temp->country,temp->interCountry,temp->time,temp->days,temp->countSeats);
        
    for(int i=0;i<strlen(temp->countSeats);i++){
        temp->seats[temp->countSeats[i]-'0']=1;
    }
    if(head==NULL&& tail==NULL){
        head=tail=temp;
    }else{
        tail->next=temp;
        tail->next->previous=tail;
        tail=tail->next;
    }
    size++;
}

void List::Delete_list()
{
    FILE *file2;
    if ((file2= fopen("/Users/alenavorobej/Documents/c++/bgf/output2.txt","w")) == NULL){
        cout<<"Mistake";
        exit(0);
        }
    Node *deltemp=tail;
    tail=tail->previous;
  tail->next=NULL;
    delete deltemp;
    while(head!=NULL){
        Node *temp=head;
        int count=0;
        for(int i=0;i<20;i++){
            if(temp->seats[i]==1){
                count++;
            }
        }
        temp->aray=new int[count];
        int index=-1;
        for(int i=0;i<20;i++){
            if(temp->seats[i]==1){
                temp->aray[++index]=i;
            }
        }
        
        fprintf(file2,"%s %s %s %s %s %s ",temp->flightNumber,temp->planeType,temp->country,temp->interCountry,temp->time,temp->days);//,temp->outputSeats);
        for(int i=0;i<count;i++){
            fprintf(file2,"%d",temp->aray[i]);
        }
        if(temp)fprintf(file2, "\n");
            head=head->next;
            delete temp;
        }
    fclose(file2);
}
 
int List::Size()
{
    return size;
}

bool List::Empty()
{
    if(size==0){
        return true;
    }else return false;
}

List::~List()
{
    Node *temp=head;
    Node *del;
    while(temp!=NULL){
        del=temp;
        temp=temp->next;
        delete del;
    }
    delete temp;
}

Node* ByFlightNumber(List &a)
{
    char another[20];
    cout<<"Enter a flight number";
    cin>>another;
    Node *temp=a.head;
    bool check=false;
    while(temp!=NULL){
        if(!strcmp(another,temp->flightNumber)){
            ShowPlane(temp);
            check=true;
        }
        temp=temp->next;
    }
    if(check==false){
        cout<<"Plane is not found"<<endl;
        temp=NULL;
        return temp ;
    }
    return temp;
}

void ByCountry(List &a)
{
    char another[20];
    cout<<"Enter a country";
    cin>>another;
    bool check=false;
    Node *temp=a.head;
    while(temp!=NULL){
        if(!strcmp(another,temp->country)){
            ShowPlane(temp);
            check=true;
        }
        temp=temp->next;
    }
        if(check==false){
            cout<<"Plane is not found"<<endl;
        }
}

void ByTime(List &a)
{
    char another[20];
    cout<<"Enter a time";
    cin>>another;
    Node *temp=a.head;
    bool check=false;
    while(temp!=NULL){
        if(!strcmp(another,temp->time)){
            ShowPlane(temp);
            check=true;
        }
        temp=temp->next;
    }
    if(check==false){
        cout<<"Plane is not found"<<endl;
    }
}

void ByInterCountry(List &a)
{
    char another[20];
    cout<<"Enter a Intermediate country";
    cin>>another;
    int size=0;
    for(int i=0;another[i]!='\0';i++){
        size++;
    }
    Node *temp=a.head;
    bool flag =false;
    bool check=false;
    int index=0;
    int countSize=0;
    while(temp!=NULL){
        for(int i=0;temp->country[i]!='\0';i++){
            if(another[index]==temp->country[i]){
                flag=true;
                countSize++;
                index++;
                if(size==countSize){
                    check=true;
                    ShowPlane(temp);
                }
            }else{
                flag=false;
            }
        }
        temp=temp->next;
    }
    if(check==false){
        cout<<"Plane is not found"<<endl;
    }
}

void ByDays(List &a)
{
    char another[20];
    cout<<"Enter a Day";
    cin>>another;
    int size=0;
    for(int i=0;another[i]!='\0';i++){
        size++;
    }
    Node *temp=a.head;
    bool flag =false;
    bool check=false;
    int index=0;
    int countSize=0;
    while(temp!=NULL){
        for(int i=0;temp->days[i]!='\0';i++){
            if(another[index]==temp->days[i]){
                flag=true;
                countSize++;
                index++;
                if(size==countSize){
                    check=true;
                    ShowPlane(temp);
                }
            }else{
                flag=false;
            }
        }
        temp=temp->next;
}
        if(check==false){
            cout<<"Plane is not found"<<endl;
        }
    }

void Searching(List &a)
{
    cout<<"1.Searching by flight number"<<endl;
    cout<<"2.Searching by country"<<endl;
    cout<<"3.Searching by inter country"<<endl;
    cout<<"4.Searching by time"<<endl;
    cout<<"Enter a number"<<endl;
    int num;
    while(scanf("%d",&num)!=1||num<1||num>4){
        printf("Mistake!Try again");
        while(getchar()!='\n');
    }
    switch(num){
        case 1:
            ByFlightNumber(a);
            break;
        case 2:
            ByCountry(a);
            break;
        case 3:
            ByInterCountry(a);
            break;
        case 4:
            ByTime(a);
            break;
    }
}

bool ClosestDay(int indxDay,Node *temp)
{
    char daysOfWeek[7][10]={"Monday","Tuesday","Wednesday","Thirsday","Friday","Saturday","Sunday"};
    char str[12];
    if(indxDay==6){
        indxDay=0;
    }else{
        ++indxDay;
    }
    strcpy(str,daysOfWeek[indxDay]);
    if( strstr (temp->days,str)==NULL){
        return false;
    }
    return true;
}
    
void Closest(List &a)
{
    char daysOfWeek[7][10]={"Monday","Tuesday","Wednesday","Thirsday","Friday","Saturday","Sunday"};
    char currentDay[10];
    int indxDay=0;
    cout<<"Enter current day of week"<<endl;
    cin>>currentDay;
    for(int i=0;i<7;i++){
        if(!strcmp(daysOfWeek[i],currentDay)){
            indxDay=i;
        }
    }
    char country[20];
    cout<<"Enter a country";
    cin>>country;
        
        Node *temp=a.head;
        while(temp!=NULL){
            if(!strcmp(country,temp->country)){
               if( ClosestDay(indxDay,temp))
                ShowPlane(temp);
            }
            temp=temp->next;
        }
    cout<<"No suitables planes";
}

Node *planeNumber(List&a)
{
    char another[20];
    cout<<"Enter a flight number";
    cin>>another;
    Node *temp=a.head;
    while(temp!=NULL){
        if(!strcmp(another,temp->flightNumber))
            return temp;
        temp=temp->next;
    }
    return temp;
}
    
void Booking(List &a)
{
    bool check=false;
    Node *temp=planeNumber(a);
    if(temp!=NULL){
        for(int i=0;i<20;i++){
            if(temp->seats[i]==0){
                temp->seats[i]=1;
                break;
            }
            if(i==19){
                check=true;
            }
        }
    }else{
        cout<<"Plane is not found"<<endl;
        return;
    }
    if(check==true){
        cout<<"Plane is full"<<endl;
        return;
    }
    cout<<"You book a ticket!"<<endl;
}

void Returning(List &a)
{
    bool check=false;
    Node *temp=planeNumber(a);
        if(temp!=NULL){
            for(int i=0;i<20;i++){
                if(temp->seats[i]==1){
                    temp->seats[i]=0;
                    break;
                }
                if(i==19){
                    check=true;
                }
            }
        }else{
            cout<<"Plane is not found "<<endl;
            return;
        }
    if(check==true){
        cout<<"No booking places in this raise"<<endl;
        return;
    }
    cout<<"Your ticket is successfully returned!"<<endl;
}

void FreePlaces(List &a)
{
    Node *temp=planeNumber(a);
    int count=0;
    if(temp!=NULL){
        for(int i=0;i<20;i++){
            if(temp->seats[i]==0){
                count+=1;
            }
        }
    }
    cout<<"Free places :"<<count;
}

void ShowTicket(List &a)
{
   
    Node *temp=planeNumber(a);
    if(temp!=NULL){
        cout<<temp->planeType<<endl;
        cout<<temp->country<<endl;
        cout<<temp->interCountry<<endl;
        cout<<temp->time<<endl;
        cout<<temp->days<<endl;
    }else{
        cout<<"Plane is not found"<<endl;
        return;
    }
}
 
int main(int argc, const char * argv[]) {
    setlocale(0, "");
    
      List a;
    FILE *file;
    if ((file= fopen("/Users/alenavorobej/Documents/c++/bgf/output2.txt","r")) == NULL){
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
                    Searching(a);
                    break;
                case 2:
                    Closest(a);
                    break;
                case 3:
                    Booking(a);
                    break;
                case 4:
                    Returning(a);
                    break;
                case 5:
                    FreePlaces(a);
                    break;
                case 6:
                    ShowTicket(a);
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
