//
//  main.cpp
//  8
//
//  Created by Darnell on 2018/12/3.
//  Copyright © 2018 Darnell. All rights reserved.
//
//  最大堆的实现


#include <iostream>
using namespace std;

template<class T>
class Maxheap{
private:
    T * heapArrey;
    int CurrentSize;
    int Maxsize;
public:
    Maxheap(T * arrey,int num,int max){
        heapArrey=arrey;
        CurrentSize=num;
        Maxsize=max;
    }
    ~Maxheap(){
        CurrentSize=0;
        Maxsize=0;
    };
    int parnent(int i){
        if (i%2==0) {
            return (i-2)/2;
        }else{
            return i/2;
        }
    }
    void SiftUp(int left){
        int i=left;
        int j=parnent(i);
        T temp=heapArrey[i];
        
        while (j>=0) {
            if (heapArrey[j]>temp) {
                heapArrey[i]=heapArrey[j];
                i=j;
                j=parnent(j);
            }else{
                break;
            }
        }
        heapArrey[i]=temp;
    }
    void SiftDown(int left){
        int i=left;                 //父节点
        int j=2*i+1;                //左结点
        T temp=heapArrey[i];
        
        while (j<CurrentSize) {
            if (j<CurrentSize-1&&heapArrey[j]>heapArrey[j+1]) {
                j++;
            }
            
            if (temp>heapArrey[j]) {
                heapArrey[i]=heapArrey[j];
                i=j;
                j=2*j+1;
            }else{
                break;
            }
        }
        heapArrey[i]=temp;
    }
    void BuildHeap(){
        for (int i=CurrentSize/2-1; i>=0; i--) {
            SiftDown(i);
        }
    }
    T & RemoveMax(){
        if (CurrentSize==0) {
            cout<<"no";
        }
        T temp;
        temp=heapArrey[0];
        heapArrey[0]=heapArrey[CurrentSize-1];
        CurrentSize--;
        if (CurrentSize>1) {
            SiftDown(0);
        
        }
        return temp;
    }
    bool Insert(T temp){
        if (CurrentSize==Maxsize) {
            return false;
        }else{
            CurrentSize++;
            heapArrey[CurrentSize-1]=temp;
          BuildHeap();
          //  SiftUp(CurrentSize-1);
        }
        return true;
    }
    void Print(){
        for (int i=0; i<CurrentSize; i++) {
            cout<<heapArrey[i]<<" ";
        }
        cout<<endl;
    }
};



int main() {
    int a[10]={20,12,35,15,10,80,30,17,2,1};
    Maxheap<int> h(a,10,10);
    h.BuildHeap();
    h.Print();
    h.RemoveMax();
    h.Print();
    h.Insert(1);
    h.Print();
}
