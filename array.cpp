#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter array size:";
    cin>>n;
    int arr[n];
    cout<<"Enter element:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Elements are:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
