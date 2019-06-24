//
//  main.cpp
//  4
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

int findmix(list* head){
    if (head->next==NULL) {
        return head->num;
    }
    int temp=findmix(head->next);
    if (head->num>temp) {
        return head->num;
    }else{
        return temp;
    }
}

int countnot(list * head){
    if (head==NULL) {
        return 0;
    }
    return 1+countnot(head->next);
}

float average(list * head,int n){
    if (head->next==NULL) {
        return (float)head->num;
    }else{
        n++;
        return (float)(head->num+average(head->next, n)*(n))/(n+1);
    }
    
}
int main() {
    list * head;
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
    cout<<"最大值为:"<<findmix(head);
    cout<<endl;
    cout<<"节点共："<<countnot(head);
    cout<<endl;
    cout<<"平均："<<average(head, 1);
    cout<<endl;
}
