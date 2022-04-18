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

long countWaysToMakeChange(vector<long>&arr,int target){
      int n=arr.size();
      vector<vector<long>>dp(n,vector<long>(target+1,-1));
      
      for(int T=0;T<=target;T++)dp[0][T]=(T % arr[0] == 0);

      for(int indx=1;indx<n;indx++){
          
          for(int T=0;T<=target;T++){
                    long notTake=dp[indx-1][T];
                    long take=0;
                    if(arr[indx]<=T){
                        take=dp[indx][T-arr[indx]];
                    }
                    dp[indx][T]=notTake+take;
          }
      }
      return dp[n-1][target];
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<long>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<countWaysToMakeChange(arr,target)<<endl;   
}