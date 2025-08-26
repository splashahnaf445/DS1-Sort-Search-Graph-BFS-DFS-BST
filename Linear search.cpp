#include<iostream>

using namespace std;



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


cout<<endl;
cout<<"Enter the number you want to search:     ";

int s;

cin>>s;
int res=-1;

for(int k=0;k<n;k++){
    if(a[k]==s){
        res=k;
        cout<<"Found at index: ";
    }


}

return res;

}
