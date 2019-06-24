//
//  main.cpp
//  2.2
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

int delete_somenum(int a[],int num,int size){
    for (int i = 0; i<size; i++) {
        if (a[i]==num) {
            moveforward(a, i, size);
            size--;
            i--;
        }
    }
    return size;
}
int main() {
    int a[10]={2,3,23,2,3,4,5,6,7,7};
    int num;
    cout<<"输入删除数：";
    cin>>num;
    int i=delete_somenum(a, num, 10);
    for (int j=0; j<i; j++) {
        cout<<a[j]<<" ";
    }
    
}
