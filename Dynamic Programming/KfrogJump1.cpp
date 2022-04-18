//K FROG JUMP MEMOIZATION CODE
#include<bits/stdc++.h>
using namespace std;

int f(int indx,vector<int>&heights,int k,vector<int>dp){
    
    if(indx==0)return 0;
    if(dp[indx]!=-1){
        return dp[indx];
    }
    int minSteps=INT_MAX;
    for(int j=1;j<=k;j++){
     
    if(indx-j >= 0){
        int jumpEnergy=f(indx-j,heights,k,dp)+abs(heights[indx]-heights[indx-j]);
        minSteps=min(minSteps,jumpEnergy);
    }
    }

    dp[indx]=minSteps;
    return dp[indx];
}


int frogJump(int n,vector<int>&vec,int k){
    vector<int>dp(n+1,-1);
    return f(n-1,vec,k,dp);
}

int main(){
    int n,x;
    cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++){
        cin>>x;
        vec.push_back(x);
    }
    int k;
    cin>>k;
    cout<<frogJump(n,vec,k)<<endl;;
}