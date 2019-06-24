//
//  main.cpp
//  3.2
//
//  Created by Darnell on 2018/10/16.
//  Copyright © 2018年 Darnell. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

class Passenger{
public:
    char passengername[20];
    Passenger *next;
    Passenger(char *name){
        strcpy(passengername,name);
        next=0;
    }
};

class Filght{
public:
    char flightname[20];
    Passenger *head;
    Filght *next;
    Filght(char *name){
        strcpy(flightname,name);
        next=0;
        head=0;
    }
};

class FlightList{
private:
    Filght *head;
    Filght *tail;
    Filght *fptr1;
    Filght *fptr2;
    Passenger *pptr1;
    Passenger *pptr2;
public:
    void addflight(char *flight);
    bool reserve(char *flight,char *passenger);
    bool cancel(char *flight,char *passenger);
    bool Check(char *flight,char *passenger);
    void print();
    void print(char *s);
    FlightList();
    ~FlightList();
};

FlightList::FlightList()
{
    Filght *p=new Filght(" ");
    head=tail=p;
}

FlightList::~FlightList()
{
    fptr1=head->next;
    fptr2=fptr1->next;
    delete head;
    while(fptr1){
        pptr1=fptr1->head;
        pptr2=pptr1->next;
        while(pptr1){
            delete pptr1;
            pptr1=pptr2;
            if(pptr2)
                pptr2=pptr2->next;
        }
        delete fptr1;
        fptr1=fptr2;
        if(fptr2)
            fptr2=fptr2->next;
    }
}

void FlightList::addflight(char *flight)
{
    Filght *p=new Filght(flight);
    tail->next=p;
    tail=p;
}

void FlightList::print()
{
    for(fptr1=head->next;fptr1;fptr1=fptr1->next)
    {
        cout<<fptr1->flightname<<':'<<endl;
        for(pptr1=fptr1->head;pptr1;pptr1=pptr1->next)
            cout<<pptr1->passengername<<endl;
        cout<<endl;
    }
}

void FlightList::print(char *flight){
    fptr1=head->next;
    while(fptr1&&strcmp(fptr1->flightname,flight))
        fptr1=fptr1->next;
    if(fptr1){
        cout<<fptr1->flightname<<':'<<endl;
        for(pptr1=fptr1->head;pptr1;pptr1=pptr1->next)
            cout<<pptr1->passengername<<endl;
        cout<<endl;
    }
    else
        cout<<"don't have the flight"<<endl;
}

bool FlightList::reserve(char *flight,char *passenger){
    Passenger *p;
    p=new Passenger(passenger);
    for(fptr1=head->next;fptr1&&strcmp(fptr1->flightname,flight);fptr1=fptr1->next);
    if(!fptr1){
        cout<<"don't have the flight"<<endl;
        return 0;
    }
    if(!fptr1->head)
        fptr1->head=p;
    else{
        if(strcmp(fptr1->head->passengername,passenger)>0){
            p->next=fptr1->head;
            fptr1->head=p;
            return 0;
        }
        pptr2=fptr1->head;
        pptr1=pptr2->next;
        while(pptr1&&strcmp(pptr1->passengername,passenger)<=0){
            pptr2=pptr1;
            pptr1=pptr1->next;
        }
        pptr2->next=p;
        p->next=pptr1;
    }
    return true;
}

bool FlightList::cancel(char *flight,char *passenger)
{
    for(fptr1=head->next;fptr1&&strcmp(fptr1->flightname,flight);fptr1=fptr1->next);
    if(!fptr1){
        cout<<"don't have the flight"<<endl;
        return 0;
    }
    pptr1=fptr1->head;
    if(!strcmp(pptr1->passengername,passenger)){
        fptr1->head=pptr1->next;
        delete pptr1;
        return 1;
    }
    pptr2=pptr1;
    pptr1=pptr1->next;
    while(pptr1&&strcmp(pptr1->passengername,passenger)){
        pptr1=pptr1->next;
        pptr2=pptr2->next;
    }
    if(!pptr1){
        cout<<"no passenger"<<endl;
        return 0;
    }
    pptr2->next=pptr1->next;
    delete pptr1;
    return true;
}

bool FlightList::Check(char *flight,char *passenger){
    for(fptr1=head->next;fptr1&&strcmp(fptr1->flightname,flight);fptr1=fptr1->next);
    if(!fptr1){
        cout<<"no flight"<<endl;
        return 0;
    }
    for(pptr1=fptr1->head;pptr1&&strcmp(pptr1->passengername,passenger);pptr1=pptr1->next);
    if(!pptr1){
        cout<<passenger<<" no reservation"<<endl;
        return 0;
    }
    else{
        cout<<passenger<<" in reservation"<<endl;
        return 1;
    }
}

int main(){
    FlightList a;
    a.addflight("aaa");
    a.reserve("aaa","a1");
    a.reserve("aaa","a2");
    a.reserve("aaa","a3");
    
    a.addflight("bbb");
    a.reserve("bbb","b1");
    a.reserve("bbb","b2");
    a.reserve("bbb","b3");
    a.reserve("bbb","b4");
    a.print();
    
    a.cancel("bbb","b1");
    a.Check("bbb","b2");
    a.Check("aaa","a1");
    cout<<endl;
    a.print();
    return 0;
}
