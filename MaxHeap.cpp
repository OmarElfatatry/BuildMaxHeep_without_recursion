/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: OmarTarek
 *
 * Created on May 12, 2022, 6:44 AM
 */
#include <cstdlib>
#include<iostream>
int *mainArray,*tempArray,t,size,l,d;
using namespace std;
void fill(int []);
void build(int [],int);
void out(int []);
void reheep();
void x(int [],int);
int main()
{
    cout<<"Please Enter The No. Of Elements"<<endl;
    cin>>size;
    if((size>0))
    {
        mainArray=new int [size];
        cout<<"Please Enter "<<size<<" Elements"<<endl;
        fill(mainArray);
        reheep();
        cout<<"After Reheepify: "<<endl;
        out(mainArray);
    }
    else
    {
        cout<<"Wrong Input"<<endl;
    }
}
void fill(int mainArray[])
{
    for(int i=0;i<size;i++)
    {
        cin>>mainArray[i];
    }
}
void reheep()
{
    for(int i=0;i<size;i++)
    {
        tempArray=new int[size-i];
        for(int j=0;j<size-i;j++)
        {
            tempArray[j]=mainArray[j+i];
        }
        for(int k=0;k<size-i;k++)
        {
            build(tempArray,k);
        }
        for(int l=0;l<size-i;l++)
        {
            mainArray[l+i]=tempArray[l];
        }
    }
}
void build(int a[],int i)
{
    if(i==0)
    {
        i=0;
    }
    else if(i==1)
    {
        if(a[1]>a[0])
        {
            t=a[0];
            a[0]=a[1];
            a[1]=t;
        }
    }
    else if(i%2==0)
    {
        l=(i/2)-1;
        d=i;
        if(a[l]<a[d])
        {
            while((a[l]<a[d])&&(l>=0)&&(d>=0))
            {
                t=a[d];
                a[d]=a[l];
                a[l]=t;
                d=l;
                if((l==1)||(l==2))
                {
                    l=0;
                }
                else
                {
                    l=(l/2)-1;
                }

            }	
        }	
    }
    else
    {
        l=(i/2);
        d=i;
        if(a[l]<a[d])
        {
            while((a[l]<a[d])&&(l>=0))
            {
                t=a[d];
                a[d]=a[l];
                a[l]=t;
                d=l;
                if((l==1)||(l==2))
                {
                    l=0;
                }
                else
                {
                    l=(l/2);
                }

            }	
        }
        }
}
void out(int array[])
{
    for(int j=0;j<size;j++)
    cout<<"a["<<j<<"]= "<<array[j]<<endl;
    cout<<endl;
}