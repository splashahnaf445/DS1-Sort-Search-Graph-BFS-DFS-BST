/*
3: Linear Search with Condition
Problem: Find the first element in an array of integers that is greater than a given target. If
no such element exists, return -1.

Input: arr = [3, 5, 7, 2, 8, 10], target = 6

*/

#include<iostream>

using namespace std;

int main(){

    int arr[6]={3,5,7,2,8,10};

    int t=6;
    int res=-1;



    for(int i=0;i<6;i++){
        if(arr[i]>t){
            res=arr[i];
            break;
        }
    }
    cout<<res;



}
