//
//  main.cpp
//  6
//
//  Created by Darnell on 2018/9/25.
//  Copyright © 2018年 Darnell. All rights reserved.
//

#include <iostream>
using namespace std;

class list{
public:
    int num;
    list * next;
};


void link(list* p,list *q){
    list* head=p;
    list* pa = p->next;
    list* qa = q->next;
    while (pa&&qa){
        if (pa->num <= qa->num)
        {
            p->next = pa;
            p = pa;
            pa = pa->next;
        }
        else
        {
            p->next = qa;
            p = qa;
            qa = qa->next;
        }
    }
    
    p->next = pa ? pa : qa;
    
}

int main(int argc, const char * argv[]) {
    list * p;
    list * q;
    list * temp;
    list * k;
    p=new list;
    q=new list;
    p->next=NULL;
    q->next=NULL;
   
    temp=p;
    for (int i=1; i<10;i++) {
        k=new list;
        k->num=i*2+1;
        temp->next=k;
        temp=temp->next;
    }
    temp=q;
    for (int i=2; i<11;i++) {
        k=new list;
        k->num=i*2;
        temp->next=k;
        temp=temp->next;
    }
    link(p, q);
    p=p->next;
    while (p) {
        cout<<p->num<<" ";
        p=p->next;
    }
    cout<<endl;
}
