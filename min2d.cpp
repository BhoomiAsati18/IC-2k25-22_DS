#include<iostream>
#include<climits>
using namespace std;
int main(){
    int r,c;
    cout<<"Enter no. of rows and columns: ";
    cin>>r>>c;
    cout<<"Enter elements: ";
    int arr[r][c];

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }
    int mn=INT_MAX;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            mn=min(mn,arr[i][j]);
        }
    }
    cout<<"Minimun element:"<<mn;
    return 0;
}
