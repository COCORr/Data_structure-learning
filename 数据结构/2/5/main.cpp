//
//  main.cpp
//  5
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

list * reverse(list *head)
{
    list *p, *temp;
    
    p = head->next;
    temp = p->next;
    p->next = NULL;
    head->next = p;
    p = temp;
    while (p) {
        temp = p->next;
        p->next = head->next;
        head->next = p;
        p = temp;
    }
    return head;
}


list *link(list *p, list *q)
{
    list *h, *r;
    h = new list;
    h->next = NULL;
    r = h;
    while (p!= NULL && q!= NULL)
    {
        if (p->num<= q->num)
        {
            r->next = p;
            r = p;
            p = p->next;
        }
        else
        {
            r->next = q;
            r = q;
            q = q->next;
        }
    }
    
    return h;
    
}
int main() {
    list * p;
    list * q;
    list * temp;
    list * k;
    p=new list;
    q=new list;
    p->next=NULL;
    q->next=NULL;
    p->num=1;
    q->num=2;
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
    list* head=reverse(link(p, q))->next;
    
    for (int i=0; i<19; i++) {
        cout<<head->num<<" ";
        head=head->next;
    }
    cout<<endl;
}
