#include<bits/stdc++.h>
using namespace std;

int mod=(int)(1e9+7);

int f(int i,int j,vector<vector<int>>&maze,vector<vector<int>>&dp){
    
    if(i>=0 && j>=0 && maze[i][j]==-1){
        return 0;
    }

    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0)
    {
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int up=f(i-1,j,maze,dp);
    int left=f(i,j-1,maze,dp);
    return dp[i][j]=(up+left)%mod;
}

int mazeObstacles(int m,int n,vector<vector<int>>&maze){
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return f(m-1,n-1,maze,dp);
}

int main(){
   int m,n;
   cin>>m>>n;
   vector<vector<int>>maze;
   for(int i=0;i<n;i++){
       vector<int>temp;
       for(int j=0;j<3;j++){
           int val;
           cin>>val;
           temp.push_back(val);
       }
       maze.push_back(temp);
   }
   cout<<mazeObstacles(m,n,maze)<<endl;
}