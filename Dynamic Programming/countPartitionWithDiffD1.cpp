int mod=1e9+7;
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
            dp[indx][sum]=(notTake+take)%mod;
        }
    }
    return dp[n-1][target];
}

int countPartitions(vector<int>&arr,int n,int d){
    int totSum=0;
    for(auto &it:arr)totSum+=it;
    if(totSum - d <0 || (totSum-d)%2!=0)return 0;

    return countSubsetSumToK(n,(totSum-d)/2,arr);

}

int main(){
    int n,d;
    cin>>n>>d;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<endl;
    cout<<countPartitions(arr,n,d);
    return 0;
}