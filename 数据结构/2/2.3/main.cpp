//
//  main.cpp
//  2.3
//
//  Created by Darnell on 2018/9/25.
//  Copyright © 2018年 Darnell. All rights reserved.
//

#include <iostream>
using namespace std;

void moveforward(int a[],int num,int size){
    for (int i=num; i<size-1; i++) {
        a[i]=a[i+1];
    }
}

int delete_somenum(int a[],int down,int top,int size){
    for (int i = 0; i<size; i++) {
        if (a[i]>=down&&a[i]<=top) {
            moveforward(a, i, size);
            size--;
            i--;
        }
    }
    return size;
}
int main() {
    int a[10]={2,3,23,2,3,4,5,6,7,7};
    int top,down;
    cout<<"输入删除数下上标：";
    cin>>down;
    cin>>top;
    int i=delete_somenum(a, down,top, 10);
    for (int j=0; j<i; j++) {
        cout<<a[j]<<" ";
    }
    
}
