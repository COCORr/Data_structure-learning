//
//  main.cpp
//  7
//
//  Created by Darnell on 2018/10/9.
//  Copyright © 2018年 Darnell. All rights reserved.
//

#include <iostream>
using namespace std;



template <class T>
class Node{
private:
    T data;
    Node *prev=NULL;
    Node *next=NULL;
    
public:
    Node(T d):data(d){}
    void linkprev(Node *p){prev=p;}
    void linknext(Node *p){next=p;}
    Node* getprev(){return prev;}
    Node* getnext(){return next;}
    T getdata(){return data;}
};



template <class T>
class NodeList{
private:
    Node<T> *head=NULL;
    Node<T> *tail=NULL;
    int len=0;
public:
    void addNode(T d);
    void changeList();
    void print();
    ~NodeList();
};

template <class T>
NodeList<T>::~NodeList(){
    Node<T> *p;
    p=head->getnext();
    while(head!=tail)
    {
        delete head;
        head=p;
        p=p->getnext();
    }
    delete head;
}

template <class T>
void NodeList<T>::print(){
    int i;
    Node<T> *p=head;
    for(i=0;i<len;i++){
        cout<<p->getdata()<<' ';
        p=p->getnext();
    }
}

template <class T>
void NodeList<T>::addNode(T d){
    Node<T> *p;
    p=new Node<T>(d);
    if(head){
        tail->linknext(p);
        p->linkprev(tail);
        tail=p;
    }
    else{
        head=tail=p;
    }
    len++;
}

template <class T>
void NodeList<T>::changeList()
{
    Node<T> *p1,*p2,*p3;
    if(len%2==0){
        p2=tail->getprev();
        p2=p2->getprev();
        p3=p2->getnext();
        p1=p2->getprev();
    }
    else{
        p2=tail->getprev();
        p3=p2->getnext();
        p1=p2->getprev();
    }
    while(p2!=NULL){
        p1=p2->getprev();
        p1->linknext(p3);
        p3->linkprev(p1);
        tail->linknext(p2);
        p2->linkprev(tail);
        tail=p2;
        p3=p1;
        p1=p1->getprev();
        p2=p1;
    }
}



int main(){
    NodeList<int> a;
    int i;
    for(i=1;i<11;i++)
        a.addNode(i);
    a.changeList();
    a.print();
}
