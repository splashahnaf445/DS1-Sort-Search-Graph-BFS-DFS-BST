#include<iostream>

using namespace std;

void bubble(int arr[], int n){

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }



}

int main(){

// QUESTION 7. Find the Longest Consecutive Subsequence after sorting an array.

int a[]={1,9,3,10,4,20,2};


bubble(a,7);


cout<<"using bubble sort:    ";

for(int i=0;i<7;i++){
    cout<<a[i]<<" ";
}

int counter=0;


    for(int j=0;j<6;j++){
        if(a[j+1]=a[j]+1){
            counter++;

        }

        // 1,2,3,4,9,10,12
}

cout<<endl<<counter;
}
