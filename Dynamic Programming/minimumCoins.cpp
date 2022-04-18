#include<bits/stdc++.h>
using namespace std;

int f(int indx,int T,vector<int>&arr){
      
     if(indx==0){
         if(T % arr[0]==0)return T/arr[0];
         else return 1e9;
     }

     int notTake=f(indx-1,T,arr);
     int take=1e9;
     if(arr[indx]<=T){
        take=1+f(indx,T-arr[indx],arr);
     }
     return min(notTake,take);
}

int minimumCoins(vector<int>&arr,int target){
      int n=arr.size();
      int ans= f(n-1,target,arr);
      //The constraint is if ans is not possible we return -1.
      //When ans is not possible it will be equal to 1e9 or go beyond that
      if(ans>=1e9)return -1;

      return ans;
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
    cout<<minimumCoins(arr,target)<<endl;
    
}