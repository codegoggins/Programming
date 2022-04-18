#include<bits/stdc++.h>
using namespace std;

int cutRod(vector<int>&price,int n){
    vector<vector<int>>dp(n,vector<int>(n+1,0));
    
    for(int N=0;N<=n;N++){
        dp[0][N]=N*price[0];
    }

    for(int indx =1;indx<n;indx++){

       for(int N=0;N<=n;N++){
            int notTake=dp[indx-1][N];
            int take=INT_MIN;
            int rodLength=indx+1;
            if(rodLength<=N){
                take=price[indx]+dp[indx][N-rodLength];
            }
            dp[indx][N]=max(take,notTake);
       }
    }
    return dp[n-1][n];
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