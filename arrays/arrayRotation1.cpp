#include<bits/stdc++.h>
using namespace std;

//APPROACH 2
//ROTATE THE ARRAY BY ONE POSITION TO TTHE LEFT USING A FUNCTIONA AND RUN THAT FUNCTION D TIMES

//TIME COMPLEXITY:O(n*d)
//SPACE COMPLEXITY:O(1)

void rotateArraybyOne(int *arr,int n){
      
      int temp=arr[0];

      for(int i=0;i<n-1;i++){
          arr[i]=arr[i+1];
      }
      arr[n-1]=temp;
}

void rotateArray(int*arr,int n,int d){
    
    for(int i=0;i<d;i++){
        rotateArraybyOne(arr,n);
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