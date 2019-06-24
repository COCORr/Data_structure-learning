//
//  main.cpp
//  3
//
//  Created by Darnell on 2018/9/18.
//  Copyright © 2018年 Darnell. All rights reserved.
//

#include <iostream>
using namespace std;


int findmin(int a[],int begin,int end){
    static int min=a[0];
    if (begin!=end) {
        if (a[begin]<min) {
            min=a[begin];
        }
        findmin(a, begin+1, end);
    }
    return min;
}

int main(int argc, const char * argv[]) {
    int a[10]={22,2,3,4,5,6,7,8,9,10};
    cout<<"最小值为："<<findmin(a, 0, 9)<<endl;
    
}
