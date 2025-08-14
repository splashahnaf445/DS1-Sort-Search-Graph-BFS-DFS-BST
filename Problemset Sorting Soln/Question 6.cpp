#include<iostream>

using namespace std;

void ascendsorting(int arr[],int n){

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

void descendsorting(int arr[],int n){

for(int i=1;i<n;i++){
    int key=arr[i];
    int j=i-1;

    while(j>=0 && arr[j]<key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
}

}

//QUESTION 6. Sort odd indexed elements of an array in descending order and even indexed elements in ascending order.

int main(){

int a[]={16,17,4,18,1,20,5,12};


int ev[8];
int odd[8];

for(int k=0;k<8;k++){
    if(k%2==0){
        ev[k]=a[k];
    }else{
        odd[k]=a[k];
    }
}

ascendsorting(ev,7);
descendsorting(odd,8);

for(int i=1;i<8;i+=2){
    ev[i]=odd[i];
}


for(int j=0;j<8;j++){
    cout<<ev[j]<<" ";
}

}
