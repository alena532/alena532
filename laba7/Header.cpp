#include "Header.h"
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
    if ((file2= fopen("output2.txt","w")) == NULL){
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

Node* ByFlightNumber(List &a,char another[])
{
    Node *temp=a.head;
    bool check=false;
    while(temp!=NULL){
        if(!strcmp(another,temp->flightNumber)){
            ShowPlane(temp);
            check=true;
            return temp ;
        }
        temp=temp->next;
    }
        cout<<"Plane is not found"<<endl;
        temp=NULL;
    return temp;
}

Node* ByCountry(List &a,char another[])
{
    bool check=false;
    Node *temp=a.head;
    while(temp!=NULL){
        if(!strcmp(another,temp->country)){
            ShowPlane(temp);
            check=true;
            return temp;
        }
        temp=temp->next;
    }
        if(check==false){
            cout<<"Plane is not found"<<endl;
        }
        return temp;
}

Node* ByTime(List &a,char another[])
{
    
    Node *temp=a.head;
    bool check=false;
    while(temp!=NULL){
        if(!strcmp(another,temp->time)){
            ShowPlane(temp);
            check=true;
            return temp;
        }
        temp=temp->next;
    }
    if(check==false){
        cout<<"Plane is not found"<<endl;
    }
    return temp;
}

Node* ByPlaneType(List &a,char another[])
{
    Node *temp=a.head;
    bool check=false;
    while(temp!=NULL){
        if(!strcmp(another,temp->planeType)){
            ShowPlane(temp);
            check=true;
            return temp;
        }
        temp=temp->next;
    }
    if(check==false){
        cout<<"Plane is not found"<<endl;
    }
    return temp;

}

Node* ByInterCountry(List &a,char another[])
{
    Node *temp=a.head;
    while(temp!=NULL){
        if(strstr(temp->interCountry,another)!=NULL){
            ShowPlane(temp);
            return temp;
        }
        temp=temp->next;
    }
    cout<<"Plane is not found"<<endl;
    return temp;
}

Node* ByDays(List &a,char another[])
{
    Node *temp=a.head;
    while(temp!=NULL){
        if(strstr(temp->days,another)!=NULL){
            ShowPlane(temp);
            return temp;
        }
        temp=temp->next;
    }
    cout<<"Plane is not found"<<endl;
    return temp;
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

Node *planeNumber(List&a,char another[])
{
    
    Node *temp=a.head;
    while(temp!=NULL){
        if(!strcmp(another,temp->flightNumber))
            return temp;
        temp=temp->next;
    }
    return temp;
}
    
bool Booking(List &a,char another[])
{

    bool check=false;
    Node *temp=planeNumber(a,another);
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
        return false;
    }
    if(check==true){
        cout<<"Plane is full"<<endl;
        return false;
    }
    cout<<"You book a ticket!"<<endl;
    return true;
}

bool Returning(List &a,char another[])
{
    bool check=false;
    Node *temp=planeNumber(a,another);
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
            return false;
        }
    if(check==true){
        cout<<"No booking places in this raise"<<endl;
        return false;
    }
    cout<<"Your ticket is successfully returned!"<<endl;
    return true;
}

int FreePlaces(List &a,char another[])
{
    Node *temp=planeNumber(a,another);
    int count=0;
    if(temp!=NULL){
        for(int i=0;i<20;i++){
            if(temp->seats[i]==0){
                count+=1;
            }
        }
    }
    cout<<"Free places :"<<count;
    return count;
}

void ShowTicket(List &a,char another[])
{
    Node *temp=planeNumber(a,another);
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
