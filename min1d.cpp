#include<iostream>
#include<climits>
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
    int mn=INT_MAX;
    for(int i=0;i<n;i++){
        mn=min(mn,arr[i]);
    }
    cout<<"Minimum number:"<<mn;
    return 0;
}
