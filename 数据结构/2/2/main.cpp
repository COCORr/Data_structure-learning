//
//  main.cpp
//  2
//
//  Created by Darnell on 2018/9/25.
//  Copyright © 2018年 Darnell. All rights reserved.
//

#include <iostream>
using namespace std;

int delete_min(int a[],int num){
    int temp=0;
    for (int i=0; i<num; i++) {
        if (a[temp]>a[i]) {
            temp=i;
        }
    }
    int t=temp;
    a[temp]=a[num-1];
    return t;
}
int main() {
    int a[10]={5,6,7,8,9,1,2,3,4,5};
    cout<<"被删除的元素为："<<delete_min(a, 10)<<endl;
    for (int i=0; i<10-1; i++) {
        cout<<a[i]<<" ";
    }
}
