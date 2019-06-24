//
//  main.cpp
//  1
//
//  Created by Darnell on 2018/9/18.
//  Copyright © 2018年 Darnell. All rights reserved.
//

#include <iostream>
using namespace std;


void finddata(int *a,int len,int b){
    bool flag=false;
    int num=0;
    for (int i=0; i<len; i++) {
        if (a[i]==b) {
            flag=true;
            num++;
            break;
        }
        num++;
    }
    if (flag==true) {
            cout<<"查找成功 比较次数为:"<<num<<endl;
        }else{
            cout<<"查找失败 比较次数为:"<<num<<endl;
        }
}

int main() {
    int a[10]={1,2,2,2,5,6,7,8,9,10};
    int b;
    cin>>b;
    finddata(a,10,b);
    
}
