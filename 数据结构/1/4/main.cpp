//
//  main.cpp
//  4
//
//  Created by Darnell on 2018/9/18.
//  Copyright © 2018年 Darnell. All rights reserved.
//

#include <iostream>
using namespace std;

int *addition(int *a,int *b,int anum,int bnum){
    int *temp=new int(anum+bnum);
    int aa=0;
    int bb=0;
    int len=0;
    while (aa<anum &&bb<bnum) {
        if (a[aa]>b[bb]) {
            temp[len]=b[bb];
            bb++;
        }else{
            temp[len]=a[aa];
            aa++;
        }
        len++;
    }
    while (aa<anum) {
        temp[len]=a[aa];
        aa++;
        len++;
    }
    while (bb<bnum) {
        temp[len]=b[bb];
        bb++;
        len++;
    }
    return temp;
}

int main() {
    int a[5]={2,3,5,7,8};
    int b[2]={1,10};
    int * c=addition(a, b, 5, 2);
    for (int i=0; i<7; i++) {
        cout<<c[i]<<" ";
    }
    cout<<endl;
    free(c);
}
