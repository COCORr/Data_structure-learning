//
//  main.cpp
//  try
//
//  Created by Darnell on 2018/10/30.
//  Copyright © 2018年 Darnell. All rights reserved.
//

#include<iostream>
#include<fstream>
#include<string>
#define SIZE 57
using namespace std;

int main()
{
    string str[53];
    string result[1000];
    int amount=0;
    int i=0;
    char str1[1000];
    char *filename="strings.txt";
    ifstream inFile(filename);
    if(!inFile)
    {
        cout<<endl<<"Failed to open file";
        return 1;
    }
    while(!inFile.eof())
    {
        inFile.getline(str1,100);
        if(strlen(str1)==0)
        {
            break;
        }
        str[i]=str1;
        i++;
    }
//    for (int i=0; i<53; i++) {
//        cout<<str[i];
//        cout<<endl;
//    }
    float rate1;
    cout<<" 输入豫之";
    cin>>rate1;
    for(int strnum=0;strnum<53;strnum++)
    {
        for(int istrlength=1;istrlength<=SIZE;istrlength++)
        {
            for(int istrnum=0;istrnum<=SIZE-istrlength;istrnum++)
            {
                char * temp;
                temp=new char[200];
                for(int i=istrnum;i<istrlength;i++)
                {
                    temp[i-istrnum]=str[strnum][i];
                }
                int p=0;
                int t=0;
                int num=0;
                float rate;
                int flag=0;
                int plen=strlen(temp);
                for(int strnum=0;strnum<53;strnum++)
                {
                    int tlen=str[strnum].length();
                    
                    while(t<=tlen&&p<=plen)
                    {
                        if(str[strnum][t]==temp[p])
                        {
                            p++;
                            t++;
                        }
                        else
                        {
                            t=t-p+1;
                            p=0;
                        }
                    }
                    if(p>=plen)
                    {
                        num=num+1;
                    }
                }
                rate=(float)num/53;
                if(rate>rate1)
                {
                    flag=0;
                    for(int j=0;j<=amount-1;j++)
                    {
                        if(result[j]==temp)
                        {
                            flag=1;
                        }
                        else
                        {
                            flag=0;
                        }
                    }
                    if(flag==0)
                    {
                       // result[amount]=temp;
                        strcpy(result[amount], temp);
                        
                        amount=amount+1;
                    }
                    delete []temp;
                }
                
                
            }
        }
    }
    cout<<"为";
    for(int m=0;m<amount;m++)
    {
        cout<<result[m]<<"  ";
    }
    cout<<endl;
    return 0;
}
