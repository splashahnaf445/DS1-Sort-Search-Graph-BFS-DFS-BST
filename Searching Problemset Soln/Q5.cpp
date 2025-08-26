/*
5: Binary Search in Descending Order Array
Problem: Perform binary search on a descending order sorted array to find a target value.
Example:
Input: arr = [9, 7, 5, 3, 1], target = 7

*/



#include<iostream>

using namespace std;

int main(){

int arr[5]={9,7,5,3,1};
int target=7;
int res=-1;

/*
for(int i=0;i<5;i++){
    for(int j=0;j<5-i-1;j++){
        if(arr[j]>arr[j+1]){
            int temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
        }
    }
}
*/
int l=0,h=4;

while(l<=h){
    int mid=(l+h)/2;

    if(arr[mid]==target){
        res=mid;
        break;
    }
    else if(arr[mid]<target){
        h=mid-1;
    }
    else if(arr[mid]>target){
        l=mid+1;
    }

}

cout<<res;
}
