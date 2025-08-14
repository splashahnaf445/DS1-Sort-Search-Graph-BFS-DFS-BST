#include<iostream>

using namespace std;

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

/* You are given a list of tasks, where each task is represented as
(StartTime, FinishTime). The goal is to sort the tasks based on their
durations (calculated as FinishTime - StartTime) in ascending
order.
Input Output
[(2, 5), (1, 2), (4, 6)]

*/


int main(){

int input[]={2,5,1,2,4,6};

int duration[3];

for(int i=0;i<6;i++){
    for(int j=i+1;j<5;j++){
        duration[i]=input[j]-input[i];

    }
}

selection(duration,3);

for(int k=0;k<3;k++){
    cout<<duration[k]<<" ";h
}

}
