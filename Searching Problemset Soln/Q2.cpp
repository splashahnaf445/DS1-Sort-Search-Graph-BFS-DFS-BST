/*
2: Linear Search with Multiple Occurrences
Problem: Given an array, find all the indices where a target integer appears. Return an array
of indices. If the target does not appear, return an empty array
*/


#include<iostream>

using namespace std;

int main(){

    int arr[6] ={4,2,3,2,4,2}; //target = 2
    int target[6];
    int t=2;
    int k=0;

    for(int i=0;i<6;i++){
        if(arr[i]==t){
            target[k]=i;
            target[k++];
        }
    }


    for(int i=0;i<k;i++){
        cout<<target[i]<<" ";
    }
}
