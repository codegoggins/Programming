//FROG JUMP TABULATION(BOTTOM UP APPROACH)
#include<bits/stdc++.h>
using namespace std;

int f(int n,vector<int>&heights){
    vector<int>dp(n,0);
    dp[0]=0;
    
    for(int i=1;i<n;i++){
    int fs=dp[i-1]+abs(heights[i]-heights[i-1]);

    int ss=INT_MAX;
    if(i >1){
        ss=dp[i-2]+abs(heights[i]-heights[i-2]);
    }
    dp[i]=min(fs,ss);
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
    cout<<f(n,vec)<<endl;;
}