//
//  main.cpp
//  8
//
//  Created by Darnell on 2018/10/9.
//  Copyright © 2018年 Darnell. All rights reserved.
//


#include <iostream>
using namespace std;

class node{
public:
    node * prev=NULL;
    node * next=NULL;
    int data;
};

void deletenode(node* p,node* head, node* tail)
{
    node *p1,*p2;
    p1=p->prev;
    p2=p->next;
    p1->next=p2;
    p2->prev=p1;
    if(head==p)
        head=p2;
        else if(tail==p)
            tail=p1;
            delete p;
}

int main(){
    node* p1=new node;
    node* head=p1;
    p1->data=0;
    node* p2;
    node* p3;
    p2=p1;
    for (int i=1; i<10; i++) {
        p3=new node;
        p3->data=i;
        p2->next=p3;
        p3->prev=p2;
        p2=p3;
    }
    p1->prev=p2;
    p2->next=p1;
    node* tail=p2;
    
    
    deletenode(p1->prev,head,tail);
    for (int i=0; i<9; i++) {
        cout<<p1->data<<" ";
        p1=p1->next;
    }
    cout<<endl;
    
}
