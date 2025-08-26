/*

6: Binary Search for First and Last Occurrence
Problem: Given a sorted array, find the first and last positions of a target value. If the target
is not found, return (-1, -1).
Example:
Input: arr = [1, 2, 2, 2, 3, 4], target = 2
Output: (1, 3)

*/


#include<iostream>

using namespace std;

int main(){

int arr[6] ={1,2,2,2,3,4};
int t=2;

int res1=-1;
int res2=-1;

int l=0,h=5;

while(l<=h){
    int mid=(l+h)/2;
    if(arr[mid]==t){
        res1=mid;
        h=mid-1;
    }
    else if(arr[mid]<t){
        l=mid+1;
    }
    else if(arr[mid]>t){
        h=mid-1;
    }
}
l=0,h=5;

while(l<=h){
    int mid=(l+h)/2;
    if(arr[mid]==t){
        res2=mid;
        l=mid+1;
    }
    else if(arr[mid]<t){
        l=mid+1;
    }
    else if(arr[mid]>t){
        h=mid-1;
    }
}

cout<<res1;
cout<<endl;
cout<<res2;
}
