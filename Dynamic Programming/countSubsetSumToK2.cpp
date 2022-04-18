#include<bits/stdc++.h>
using namespace std;

int countSubsetSumToK(int n,int target,vector<int>&arr){
    vector<vector<int>>dp(n,vector<int>(target+1,0));

    //base case
    for(int i=0;i<n;i++)dp[i][0]=1;
    if(arr[0]<=target)dp[0][arr[0]]=1;
    
    for(int indx=1;indx<n;indx++){
        
        for(int sum=0;sum<=target;sum++){
            
            int notTake=dp[indx-1][sum];
            int take=0;
            if(arr[indx]<=sum){
                take=dp[indx-1][sum-arr[indx-1]];
            }
            dp[indx][sum]=notTake+take;
        }
    }
    return dp[n-1][target];
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<endl;
    cout<<countSubsetSumToK(n,k,arr);
    return 0;
}