//
//  main.cpp
//  3
//
//  Created by Darnell on 2018/10/16.
//  Copyright © 2018年 Darnell. All rights reserved.
//

#include <iostream>
using namespace std;

template<class T>
class Stack{
private:
    int maxsize;
    int top;
    T * st;
public:
    Stack(int size){
        maxsize=size;
        top=-1;
        st=new T[size];
    }
    Stack(){
        top=-1;
    }
    ~Stack(){
        delete [] st;
    }
    void Clear(){
        top=-1;
    }
    bool Push(const T item){
        if (top==maxsize-1) {
            cout<<"已满"<<endl;
            return false;
        }else{
            st[++top]=item;
            return true;
        }
    }
    bool Pub(T & item){
        if (top==-1) {
            cout<<"已空"<<endl;
            return false;
        }else{
            item=st[top--];
            return true;
        }
    }
    bool Top(T & item){
        if (!Pub(item)) {
            return false;
        }
        Push(item);
        return true;
    }
    void print(){
        for (int i=-1; i<top; i++) {
            cout<<st[i+1]<<" ";
        }
        cout<<endl;
    }
};



int main(){
    Stack<int> a(5);
    a.Push(2);
    a.Push(3);
    a.print();
    
}

