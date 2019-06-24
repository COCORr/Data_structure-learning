//
//  main.cpp
//  4
//
//  Created by Darnell on 2018/10/22.
//  Copyright © 2018年 Darnell. All rights reserved.
//

#include <iostream>
#include <string>
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


int priority(char a){
    if (a=='(') {
        return 1;
    }else if (a=='+'||a=='-'){
        return 2;
    }else if (a=='*'||a=='/'){
        return 3;
    }else{
        return 4;
    }
}

char * change(char * str){              //中转后
    Stack<char> stack(100);
    unsigned long size=strlen(str);                //获取字符串长度
    int i=0;
    char f[100];
    int fnum=0;
    char temp;
    while (i<size) {
        if (str[i]>='0'&&str[i]<='9') {
            f[fnum]=str[i];
            fnum++;
        }else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            if (stack.empty()) {
                stack.Push(str[i]);
            }else{
                while (!stack.empty()) {
                    stack.Top(temp);
                    if (priority(temp)>=priority(str[i])) {
                        f[fnum]=temp;
                        fnum++;
                        stack.Pub(temp);
                    }else{
                        break;              //退出循环
                    }
                }
                stack.Push(str[i]);
            }
        }else{
            if (str[i]=='(') {
                stack.Push(str[i]);
            }else{
                while (stack.Top(temp)&&temp!='(') {
                    f[fnum]=temp;
                    fnum++;
                    stack.Pub(temp);
                }
                stack.Pub(temp);
            }
        }
        i++;
    }
    
                    //弹出元素
    while (!stack.empty()) {
        stack.Pub(temp);
        f[fnum]=temp;
        fnum++;
    }
    return f;
    
}


int calculate(char * str){
    Stack<int> stack(100);
    unsigned long size = strlen(str);
    int num1,num2,num3;
    for (int i=0; i<size; i++) {
        if (str[i]>='0' && str[i]<='9') {
            stack.Push(str[i]-'0');
        }else{
            stack.Pub(num2);
            stack.Pub(num1);
            if (str[i] == '+') {
                num3 = num1 + num2;
                
            }else if (str[i] == '-') {
                num3 = num1 - num2;
                
            }else if (str[i] == '*') {
                num3 = num1 * num2;
                
            }else if(str[i] == '/'){
                num3 = num1 / num2;
                
            }
            stack.Push(num3);
        }
    }
    stack.Top(num1);
    return num1;
}

void calculatemiddle(char * str){
    strcpy(str, change(str));
    cout<<calculate(str)<<endl;
}
int main(){
    char str[100];
    cin>>str;
    cout<<change(str)<<endl;
//    strcpy(str, change(str));
//    cout<<calculate(str)<<endl;
}





















