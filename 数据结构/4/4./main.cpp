//
//  main.cpp
//  4.
//
//  Created by Darnell on 2018/10/29.
//  Copyright © 2018年 Darnell. All rights reserved.
//
//  括号匹配

#include <iostream>

using namespace std;

class Stack {
public:
    void Clear();
    bool Push(const int item);
    bool Pop(int &item);
    bool Top(int &item);
    bool  IsEmpty();
    bool  IsFull();
};

class ArrayStack:public Stack {
private:
    int maxSize;
    int top;
    char *st;
    
public:
    ArrayStack(int size)
    {
        maxSize = size;
        top = -1;
        st = new char(maxSize);
    }
    ArrayStack()
    {
        top = -1;
        
    }
    ~ArrayStack()
    {
        delete []st;
    }
    int gettop();
    void Clear()
    {
        top = -1;
    }
    bool Push(const char item)//进栈
    {
        if(top == maxSize-1)
        {
            cout<<"栈满溢出"<<endl;
            return false;
        }
        else
        {
            st[++top] = item;
            return true;
        }
    }
    bool Pop(char &item)//出栈
    {
        if(top == -1)
        {
            cout<<"栈空，不能进行删除操作！！"<<endl;
            return false;
        }
        else
        {
            item  = st[top--];
            
            return true;
            
        }
    }
    bool Top(char & item)//读取栈顶元素
    {
        if(top == -1)
        {
            
            cout<<"栈空，不能进行删除操作！！"<<endl;
            return false;
        }
        else
            
        {
            item  = st[top];
            return true;
            
        }
    }
};
int ArrayStack::gettop()
{
    return top;
}


bool check(char * n)
{
    ArrayStack a = ArrayStack(20);
    ArrayStack b = ArrayStack(20);
    int i =0 ;
    char item1,item2;
    while(n[i])
    {
        if(n[i]=='['||n[i]=='('||n[i]=='{')
        {
            a.Push(n[i]);
        }
        if(n[i]==']'||n[i]==')'||n[i]=='}')
        {
            
            if(n[0]==']'||n[0]==')'||n[0]=='}')
            {
                return false;
               
            }
            item2=n[i];
            a.Pop(item1);
            if((item2-item1)>2)
            {
                return false;
              
            }
            
        }
        i++;
        
    }
    if(a.gettop()!=-1)
    {
        cout<<"匹配错误"<<endl;
        exit(1);
    }
    cout<<"匹配正确"<<endl;
    return true;
    
};
int main()
{
    char *a = "{{{{";
    check(a);
    return 0;
}
