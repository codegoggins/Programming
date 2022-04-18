#include<bits/stdc++.h>
using namespace std;

//APPROACH 1
//USING A TEMP ARRAY

//TIME COMPLEXITY:O(n)
//SPACE COMPLEXITY:O(d)

void rotateArray(int *arr,int n,int d){
  int*temp=new int[d];
  for(int i=0;i<d;i++){
      temp[i]=arr[i];
  }
  
  for(int i=0;i<n-d;i++){
      arr[i]=arr[i+d];
  }
  for(int i=0;i<d;i++){
      arr[n-d+i]=temp[i];
  }
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