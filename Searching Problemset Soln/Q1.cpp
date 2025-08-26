
/*
Problem: Given an array of integers, find the first occurrence of a target integer. If the target
is not in the array, return -1.

*/

#include<iostream>

using namespace std;

int main(){

int arr[5]={5,3,8,1,9};
int s=8;

int res=-1;

 for(int i=0;i<5;i++){
        if(arr[i]==s){
            res=i;
        }

    }

cout<<res;

}
