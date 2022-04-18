#include<bits/stdc++.h>
using namespace std;

long f(int indx,int T,vector<int>&arr,vector<vector<long>>&dp){
      
     if(indx==0){
         if(T % arr[0]==0)return 1;
         else return 0;
     }
      if(dp[indx][T]!=-1){
          return dp[indx][T];
      }
     long notTake=f(indx-1,T,arr,dp);
     long take=0;
     if(arr[indx]<=T){
        take=f(indx,T-arr[indx],arr,dp);
     }
     return dp[indx][T]=notTake+take;
}

long countWaysToMakeChange(vector<int>&arr,int target){
      int n=arr.size();
      vector<vector<long>>dp(n,vector<long>(target+1,-1));
      return f(n-1,target,arr,dp);
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