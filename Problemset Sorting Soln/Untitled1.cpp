#include<iostream>

using namespace std;

void insertionsort(int arr[],int n){

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


void selection(int arr[], int n){

    for(int i=0;i<n-1;i++){
        int minind=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minind]){
                minind=j;
            }
            int temp=arr[i];
            arr[i]=arr[minind];
            arr[minind]=temp;
        }
    }


}



int main(){

int a[]={7,4,5,9,1,3};
int b[]={8,5,6,2,3,1};

insertionsort(a,6);

for(int i=0;i<6;i++){
    cout<<a[i]<<" ";
}

cout<<endl;

bubble(b,6);

for(int i=0;i<6;i++){
    cout<<b[i]<<" ";
}

cout<<endl;

selection(a,6);

for(int i=0;i<6;i++){
    cout<<a[i]<<" ";
}

}
