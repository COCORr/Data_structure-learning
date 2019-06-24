//
//  main.cpp
//  2
//
//  Created by Darnell on 2018/9/18.
//  Copyright © 2018年 Darnell. All rights reserved.
//

#include <iostream>
using namespace std;

void change(int * a,int i,int j){
    int x=0;
    int temp;
    while (i<=j) {
        for (; j>=i; j--) {
            if (a[x]>a[j]) {
                temp=a[j];
                a[j]=a[x];
                a[x]=temp;
                x=j;
                break;
            }
        }
        for (; i<=j; i++) {
            if (a[x]<a[i]) {
                temp=a[i];
                a[i]=a[x];
                a[x]=temp;
                x=i;
                break;
            }
        }
    }
}

int main() {
    int a[10]={29,9,8,7,6,51,41,31,21,11};
    change(a, 0, 9);
    for (int i=0; i<10; i++) {
        cout<<a[i]<<" ";
        
    }
}
