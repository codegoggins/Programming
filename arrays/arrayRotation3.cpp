#include<bits/stdc++.h>
using namespace std;


//Given an array, cyclically rotate the array clockwise by one. 

//TIME COMPLEXITY:O(n)
//SPACE COMPLEXITY:O(1)



void rotateArray(int*arr,int n){
    
  int temp=arr[n-1];

  for(int i=n-1;i>0;i--){
      arr[i]=arr[i-1];
  }
  arr[0]=temp;
    
}

int main(){
    int n;
    cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    rotateArray(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}