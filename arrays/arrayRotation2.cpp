#include<bits/stdc++.h>
using namespace std;

//APPROACH 3
//REVERSAL ALGORITHM FOR ARRAY ROTATION
//Reverse the first d elements in array
//Then reverse the n-d elements in array after the first d elements
//Then reverse the whole array and we thus obtain the array rotated by d positions

//TIME COMPLEXITY:O(n)
//SPACE COMPLEXITY:O(1)

void reverseArray(int *arr,int si,int ei){
      
      while(si < ei){
        int temp=arr[si];
        arr[si]=arr[ei];
        arr[ei]=temp;
        si++;
        ei--;
      }
    
}

void rotateArray(int*arr,int n,int d){
    
    if(d==0){
        return;
    }
    reverseArray(arr,0,d-1);
    reverseArray(arr,d,n-1);
    reverseArray(arr,0,n-1);
    
}

int main(){
    int n,d;
    cin>>n>>d;
    int*arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    rotateArray(arr,n,d);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}