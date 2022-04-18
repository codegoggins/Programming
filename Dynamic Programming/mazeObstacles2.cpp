#include<bits/stdc++.h>
using namespace std;

int mod=(int)(1e9+7);

int mazeObstacles(int m,int n,vector<vector<int>>&maze){
    
    int dp[m][n];

    for(int i=0;i<m;i++){
        
        for(int j=0;j<n;j++){
            if(maze[i][j]==-1)dp[i][j]=0;
            else if(i==0 && j==0)dp[i][j]=1;
            else{
            int up=0;
            int left=0;
            if(i>0){
                up=dp[i-1][j];
            }
            if(j>0){
                 left=dp[i][j-1];
            }
            dp[i][j]=(up+left)%mod;
            }
        }
    }
    return dp[m-1][n-1];
      
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