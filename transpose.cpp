#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter no. of rows and columns: ";
    cin>>n;
    int arr[n][n];
    cout<<"Enter elements:";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    } 
    cout<<"Matrix: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    } 
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(arr[i][j],arr[j][i]);
        }
    } 
    cout<<"Transpose matrix: "<<endl;
    // for(int j=0;j<c;j++){
    //     for(int i=0;i<r;i++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    //}
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    } 
    return 0;
}
