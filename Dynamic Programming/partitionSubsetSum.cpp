#include<bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n,int k,vector<int>&arr){
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
    return dp[n-1][k];
}

bool canPartition(vector<int>&arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2!=0)return false;
    return subsetSumToK(n,sum/2,arr);
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
    if(canPartition(arr,n)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}