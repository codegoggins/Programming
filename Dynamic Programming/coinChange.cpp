#include<bits/stdc++.h>
using namespace std;

long f(int indx,int T,vector<int>&arr){
      
     if(indx==0){
         if(T % arr[0]==0)return 1;
         else return 0;
     }

     long notTake=f(indx-1,T,arr);
     long take=0;
     if(arr[indx]<=T){
        take=f(indx,T-arr[indx],arr);
     }
     return notTake+take;
}

long countWaysToMakeChange(vector<int>&arr,int target){
      int n=arr.size();
      return f(n-1,target,arr);
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<countWaysToMakeChange(arr,target)<<endl;   
}