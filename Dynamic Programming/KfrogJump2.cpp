//K FROG JUMP TABULATION CODE
#include<bits/stdc++.h>
using namespace std;


int frogJump(int n,vector<int>&heights,int k){
    int dp[n];
    dp[0]=0;
    for(int i=1;i<n;i++){

    int minSteps=INT_MAX;
    for(int j=1;j<=k;j++){
     
        if(i-j >= 0){
        int jumpEnergy=dp[i-j]+abs(heights[i]-heights[i-j]);
        minSteps=min(minSteps,jumpEnergy);
       }
     }
    dp[i]=minSteps;
    }

    return dp[n-1];
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