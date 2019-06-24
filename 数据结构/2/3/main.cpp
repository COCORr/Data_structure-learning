//
//  main.cpp
//  3
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


int main() {
    list * head;
    list * prohead;
    list * p;
    list * temp;
    head=new list;
    head->num=2;
    head->next= NULL;
    p=head;
    for (int i=1; i<10; i++) {
        temp=new list;
        temp->num=i;
        p->next=temp;
        p=p->next;
        p->next=NULL;
    }
    prohead=head;
    p=reverse(prohead);
    
    for (int i=0; i<10; i++) {
        cout<<p->num<<" ";
        p=p->next;
    }
}
