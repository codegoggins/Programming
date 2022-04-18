//MEMOIZED HOUSE ROBBER PROBLEM
#include<bits/stdc++.h>
using namespace std;

int houseRobber_helper(int n,int*arr,int*dp){
    
    if(n==0)return arr[n];

    if(n<0)return 0;

    if(dp[n]!=-1){
        return dp[n];
    }

    int pick=arr[n]+houseRobber_helper(n-2,arr,dp);
    int notPick=houseRobber_helper(n-1,arr,dp);

    dp[n]=max(pick,notPick);
    return dp[n];
}

int houseRobber(int n,int*arr){
     int*dp=new int[n];
     for(int i=0;i<n;i++){
         dp[i]=-1;
     }
     return houseRobber_helper(n-1,arr,dp);
}

int main(){
    int n;
    cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<houseRobber(n,arr)<<endl;
}