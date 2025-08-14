#include<iostream>

using namespace std;

void sorted(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }



}

int smallestdif(int arr[],int n){

int temp=arr[n-1]-arr[n-2];

for(int i=n-1;i>0;i--){
    for(int j=i-1;j>=0;j--){
        if((arr[i]-arr[j])<temp){
            temp=arr[i]-arr[j];
        }
    }
}
return temp;

}


// QUESTION 3 :  Find the smallest difference of elements from an array.

int main(){


int a[]={15,7,2,12,13};

int b[] = {2,13,11,19,5};

sorted(a,5);
sorted(b,5);


for(int i=0;i<5;i++){
    cout<<a[i]<<" ";
}
cout<<endl<<endl;

for(int i=0;i<5;i++){
    cout<<b[i]<<" ";
}

int res=smallestdif(a,5);

int res2=smallestdif(b,5);

cout<<endl<<res;
cout<<endl<<res2;



}
