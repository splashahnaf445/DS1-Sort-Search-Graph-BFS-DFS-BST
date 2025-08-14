#include<iostream>

using namespace std;

void sorting(int arr[],int n){

for(int i=1;i<n;i++){
    int key=arr[i];
    int j=i-1;

    while(j>=0 && arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
}

}

// QUESTION 9 : You are given two arrays a and b. Merge a and b into a single array sorted in non-decreasing order.

int main(){

int a[]={1,16,13,14,4};
int b[]={15,12,5,3,7};

int c[10];

for(int i=0;i<5;i++){
    c[i]=a[i];
}

for(int j=0;j<5;j++){
    c[j+5]=b[j];
}

sorting(c,10);

for(int i=0;i<10;i++){
    cout<<c[i]<<" ";
}

}
