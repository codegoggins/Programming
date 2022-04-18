#include<bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>&arr,int n){
    int totalSum=0;
    for(int i=0;i<n;i++)totalSum+=arr[i];
        
        int k=totalSum;
    
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    dp[0][arr[0]]=true;

    for(int indx=1;indx<n;indx++){

        for(int target=1;target<=k;target++){

            bool notTake=dp[indx-1][target];
            bool take=false;
            if(target >= arr[indx]){
                take=dp[indx-1][target-arr[indx]];
            }
            dp[indx][target]=take | notTake;
        }
    }
    //dp[n-1][col-> 0......totalSum]
    int mini=1e9;
    for(int s1=0;s1<=totalSum/2;s1++){
        if(dp[n-1][s1]==true){
            mini=min(mini,abs((totalSum-s1)-s1));
        }
    }
    return mini;
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
    cout<<minSubsetSumDifference(arr,n)<<endl;
    return 0;
}