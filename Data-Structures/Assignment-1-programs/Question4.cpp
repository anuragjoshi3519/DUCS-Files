#include<iostream>
using namespace std;

void rearrange(int* arr,int start, int end){
    if(start==end) return;

    if(arr[start]%2!=0){
        arr[start] = arr[start]^arr[end];
        arr[end] = arr[start]^arr[end];
        arr[start] = arr[start]^arr[end];
        rearrange(arr,start,end-1);
    }
    else{
        rearrange(arr,start+1,end);
    }
}

int main(){
    int n,i;
    cout<<"\nEnter Size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the elements of the array: ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }

    rearrange(arr,0,n-1);

    cout<<"\nRearranged array: ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}