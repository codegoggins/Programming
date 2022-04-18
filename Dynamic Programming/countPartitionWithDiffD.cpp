int mod=1e9+7;
#include<bits/stdc++.h>
using namespace std;

int f(int indx,int sum,vector<int>&arr,vector<vector<int>>&dp){

if(sum==0)return 1;
if(indx==0)return (arr[0]==sum);

int notTake=f(indx-1,sum,arr,dp);
int take=0;
if(sum >= arr[indx]){
    take=f(indx-1,sum-arr[indx],arr,dp);
}

return dp[indx-1][sum]=(take +notTake)%mod;

}

int countSubsetSumToK(int n,int k,vector<int>&arr){
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}

int countPartitions(vector<int>&arr,int n,int d){
    int totSum=0;
    for(auto &it:arr)totSum+=it;
    if(totSum - d <0 || (totSum-d)%2!=0)return -1;

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