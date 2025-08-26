
/*
7: Find the Insert Position
Problem: Given a sorted array, return the index where a target value should be inserted to
maintain the order. Use binary search.
Example:
Input: arr = [1, 3, 5, 6], target = 4
Output: 2

*/

/*
8: Count Occurrences of Target with Binary Search
Problem: In a sorted array, count the occurrences of a target value using binary search.
Example:Input: arr = [2, 4, 4, 4, 6, 7], target = 4
Output: 3

*/

#include<iostream>

using namespace std;

int main(){

int arr[6] ={2,4,4,4,6,7};
int t=4;

int counter=0;

int l=0,h=5;

while(l<=h){
    int mid=(l+h)/2;
    if(arr[mid]==t){
        counter++;
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
        counter++;
        l=mid+1;
    }

    else if(arr[mid]<t){
        l=mid+1;
    }
    else if(arr[mid]>t){
        h=mid-1;
    }
}
cout<<counter;

}
