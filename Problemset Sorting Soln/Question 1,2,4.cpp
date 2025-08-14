#include<iostream>

using namespace std;

//QUESTION 1 : Find the kth smallest element from an array.
                // a = [6,5,1,3,4], k = 2 ;        output:  3
                //b = [7,9,1,8,2] , k = 4 ;       output:   8


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


int main(){

//QUESTION 1

int a[] = {6,5,1,3,4};

int b[] = {7,9,1,8,2};

sorting(a,5);
cout<<a[1]<<endl;

sorting(b,5);

cout<<b[3]<<endl;



//QUESTION 2 : Find the median from an array :
                //c = [5,2,1,4,7] 4
                //d = [11,9,17,15] 13

int c[]={5,3,1,4,7};

int d[]= {11,9,17,15}; //?

sorting(c,5);

cout<<c[2]<<endl;



// QUESTION 4. : Sort an array by absolute value in ascending order.

                int e[]= {-10, 5, -3, 7, -2};

for(int k=0;k<5;k++){
    if(e[k]<0){
        e[k]=e[k]*(-1);
    }
}

sorting(e,5);
for(int i=0;i<5;i++){
    cout<<e[i]<<" ";
}


}
