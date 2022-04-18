#include<bits/stdc++.h>
using namespace std;

bool f(int indx,int target,vector<int>&arr,vector<vector<int>>&dp){

if(target==0)return true;
if(indx==0)return (arr[0]==target);

if(dp[indx][target]!=-1){
   return dp[indx][target];
}

bool notTake=f(indx-1,target,arr,dp);
bool take=false;
if(target >= arr[indx]){
    take=f(indx-1,target-arr[indx],arr,dp);
}

return dp[indx][target]=take | notTake;

}

bool subsetSumToK(int n,int k,vector<int>&arr){
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
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
    if(subsetSumToK(n,k,arr)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}