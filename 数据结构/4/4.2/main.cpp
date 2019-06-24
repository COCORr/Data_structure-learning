//
//  main.cpp
//  4.2
//
//  Created by Darnell on 2018/10/29.
//  Copyright © 2018年 Darnell. All rights reserved.
//
//  回文串匹配

#include <string>
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
            //  cout<<"已满"<<endl;
            return false;
        }else{
            st[++top]=item;
            return true;
        }
    }
    bool Pub(T & item){
        if (top==-1) {
            //  cout<<"已空"<<endl;
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
    bool empty(){
        if (top==-1) {
            return true;
        }
        return false;
    }
};



int main(){
    Stack<char> s(100);
    char * st="abcdcba";
    unsigned long len=strlen(st);
    char temp;
    
    
    for (int i=0; i<len/2; i++) {
        s.Push(st[i]);
    }
    int k;
    if (len%2==1) {
        k=1;
    }else{
        k=0;
    }
    for (int i=int(len)/2+k; i<len; i++) {
        s.Top(temp);
        if (temp==st[i]) {
            s.Pub(temp);
        }else{
            cout<<"不是回文"<<endl;
            break;
        }
    }
    if (s.empty()) {
        cout<<"是回文"<<endl;
    }
}
