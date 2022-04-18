#include<bits/stdc++.h>
using namespace std;


int minimumCoins(vector<int>&arr,int target){
      int n=arr.size();
      vector<vector<int>>dp(n,vector<int>(target+1,0));

      for(int T=0;T<=target;T++){
          if(T % arr[0] == 0)dp[0][T]=T/arr[0];
          else dp[0][T]=1e9;
      }
      for(int indx=1;indx<n;indx++){

          for(int T=0;T<=target;T++){
              
              int notTake=dp[indx-1][T];
              int take=1e9;
              if(arr[indx]<=T){
                 take=1+dp[indx][T-arr[indx]];
              }
              dp[indx][T]=min(take,notTake);
          }
      }
      int ans= dp[n-1][target];
      
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