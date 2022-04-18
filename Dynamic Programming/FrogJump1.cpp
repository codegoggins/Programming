//FROG JUMP MEMOIZATION CODE
#include<bits/stdc++.h>
using namespace std;

int f(int indx,vector<int>&heights,vector<int>dp){
    
    if(indx==0)return 0;
    
    if(dp[indx]!=-1){
        return dp[indx];
    }

    int left=f(indx-1,heights,dp) + abs(heights[indx]-heights[indx-1]);

    int right=INT_MAX;
    if(indx >1){
        right=f(indx-2,heights,dp)+abs(heights[indx]-heights[indx-2]);
    }
    dp[indx]=min(left,right);
    return dp[indx];

}


int frogJump(int n,vector<int>&vec){
    vector<int>dp(n,-1);
    return f(n-1,vec,dp);
}

int main(){
    int n,x;
    cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++){
        cin>>x;
        vec.push_back(x);
    }
    cout<<frogJump(n,vec)<<endl;;
}