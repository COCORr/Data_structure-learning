//
//  main.cpp
//  exam
//
//  Created by Darnell on 2018/11/6.
//  Copyright © 2018年 Darnell. All rights reserved.
//
//  第三题


#include <iostream>
using namespace std;

void Move(int a[],int n){
    int temp;
    bool flag;

    
    for (int i=1; i<n; i++) {
        flag=false;
        if (a[i]>a[0]) {
            for (int j=i; j<n; j++) {
                if (a[j]<a[0]) {
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                    flag=true;
                    
                }
            }
            if (flag==false) {
                break;
            }
        }
    }
}
int main(){
    int a[10]={20,2,30,4,50,5,6,7,8,9};
    Move(a, 10);
    for (int i=0; i<10; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
}
