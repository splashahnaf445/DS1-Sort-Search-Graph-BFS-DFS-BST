#include<iostream>

using namespace std;

void ascendsort(int arr[], int n){

for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}



}

int main(){
int n;

cout<<"Enter array size:    ";
cin>>n;

cout<<endl;

int a[n];

cout<<"Enter "<<n<<" integar numbers:     ";

for(int i=0;i<n;i++){
    cin>>a[i];
}

cout<<endl;

ascendsort(a,n);

cout<<"The array is sorted in ascending order:     ";

for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}

cout<<endl;
cout<<"Enter the number you want to search:     ";

int key;

cin>>key;

int l=0;
int h=n-1;

while(l<=h){
    int mid=(l+h)/2;
    if(a[mid]==key){
        return mid;
    }
    else if(a[mid]<key){
        l=mid+1;
    }
    else if(a[mid]>key){
        h=mid-1;
    }
}


}
