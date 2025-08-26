/*
4: Binary Search in a Sorted Array
Problem: Implement binary search in a sorted array to locate a target value. Return the
index of the target if found; otherwise, return -1.
Example:
Input: arr = [1, 3, 5, 7, 9], target = 5

*/


#include<iostream>

using namespace std;

int main(){


int arr[5]={1,3,5,7,9};

int target=5;
int res=-1;

int l=0;
int h=4;

while(l<=h){

int mid=(l+h)/2;

if(arr[mid]==target){
    res=mid;
    break;
    }
else if(arr[mid]<target){
    l=mid+1;
    }
else if(arr[mid]>target){
    h=mid-1;
    }

}

cout<<res;
}
