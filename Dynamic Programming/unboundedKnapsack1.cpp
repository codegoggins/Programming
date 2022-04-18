#include<bits/stdc++.h>
using namespace std;

int f(int indx,int W,vector<int>&wt,vector<int>&val,vector<vector<int>>&dp){
    if(indx==0){
        if(wt[0]<=W){
            return ((int)(W/wt[0]))*(val[0]);
        }else{
            return 0;
        }
    }
    if(dp[indx][W]!=-1){
        return dp[indx][W];
    }
    int notTake=f(indx-1,W,wt,val,dp);
    int take=INT_MIN;
    if(wt[indx]<=W){
        take=val[indx]+f(indx,W-wt[indx],wt,val,dp);
    }
    return dp[indx][W]=max(take,notTake);
}

int unboundedKnapsack(vector<int>&weight,vector<int>&value,int n,int maxWeight){
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
    return f(n-1,maxWeight,weight,value,dp);
}

int main(){
     int n;
     cin>>n;
     vector<int>weight;
    cout<<"Enter weight array :"<<endl;    
     for(int i=0;i<n;i++){
         int x;
         cin>>x;
         weight.push_back(x);
     }
    vector<int>value;
    cout<<"Enter value array :"<<endl;
    for(int i=0;i<n;i++){
         int x;
         cin>>x;
         value.push_back(x);
    }
    int maxWeight;
    cout<<"Enter max weight of the knapsack :"<<endl;
    cin>>maxWeight;

    cout<<unboundedKnapsack(weight,value,n,maxWeight)<<endl;
}