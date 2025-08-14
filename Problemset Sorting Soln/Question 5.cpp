
#include<iostream>
#include<string>

using namespace std;

//QUESTION 5 : Sort an Array of Strings according to length : a = ["apple", "bat", "carrot", "dog"]


void sorting(string arr[],int n){

for(int i=1;i<n;i++){
    string key=arr[i];
    int j=i-1;

    while(j>=0 && arr[j].length()>key.length()){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
}

}

int main(){

string a[] = {"apple", "bat", "carrot", "dog"};
sorting(a,4);

for(int i=0;i<4;i++){
    cout<<a[i]<<" ";
}


}
