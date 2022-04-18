#include<bits/stdc++.h>
using namespace std;

int f(int indx,vector<int>&price,int N,vector<vector<int>>&dp){
    if(indx==0){
        return N*price[0];
    }

    if(dp[indx][N]!=-1){
        return dp[indx][N];
    }

    int notTake=f(indx-1,price,N,dp);
    int take=INT_MIN;
    int rodLength=indx+1;
    if(rodLength<=N){
        take=price[indx]+f(indx,price,N-rodLength,dp);
    }

    return max(take,notTake);
}

int cutRod(vector<int>&price,int n){
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return f(n-1,price,n,dp);
}

int main(){
    int n;
    cin>>n;
    vector<int>price;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        price.push_back(x);
    }
    cout<<cutRod(price,n);
}