//
//  main.cpp
//  6
//
//  Created by Darnell on 2018/11/2.
//  Copyright © 2018年 Darnell. All rights reserved.
//
//  迷宫求解

#include <iostream>
using namespace std;

#define SIZE 6

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


int main() {
    int map[SIZE][SIZE]={   {0,1,1,1,1,1},
                            {0,0,1,1,1,1},
                            {1,0,0,1,1,1},
                            {1,0,0,0,1,1},
                            {1,0,1,0,0,0},
                            {1,1,1,1,1,0}
                        };
    Stack<int> Xstack(100);
    Stack<int> Ystack(100);
    int i=0;
    int j=0;
    bool flag=false;
    
    Xstack.Push(0);
    Ystack.Push(0);
    while (i!=SIZE-1&&j!=SIZE-1) {
        flag=false;
        if ( i+1<SIZE && j<SIZE && i>=0 && j>=0 && map[i+1][j]==0 ) {       //下移
            map[i][j]=3;
            i++;
            flag=true;
            Xstack.Push(i);
            Ystack.Push(j);
        
        }
        if ( i<SIZE && j+1<SIZE && i>=0 && j>=0 && flag==false && map[i][j+1]==0 ) {       //右移
            map[i][j]=3;
            j++;
            flag=true;
            Xstack.Push(i);
            Ystack.Push(j);
        }
        if ( i<SIZE && j<SIZE && i>=0 && j-1>=0&& flag==false && map[i][j-1]==0 ) {       //左移
            map[i][j]=3;
            j--;
            flag=true;
            Xstack.Push(i);
            Ystack.Push(j);
        }
        if ( i<SIZE && j<SIZE && i-1>=0 && j>=0&& flag==false && map[i-1][j]==0 ) {       //上移
            map[i][j]=3;
            i--;
            flag=true;
            Xstack.Push(i);
            Ystack.Push(j);
        }
        if (flag==false) {
            map[i][j]=2;
            Xstack.Pub(i);
            Ystack.Pub(j);
        }
    }
    Stack<int> X(100);
    Stack<int> Y(100);
    while (!Xstack.empty()) {
        Xstack.Pub(i);
        Ystack.Pub(j);
        X.Push(i);
        Y.Push(j);
    }
    while (!X.empty()) {
        X.Pub(i);
        Y.Pub(j);
        cout<<i+1<<" "<<j+1<<endl;
    }
    cout<<6<<" "<<6<<endl;
    
}


















