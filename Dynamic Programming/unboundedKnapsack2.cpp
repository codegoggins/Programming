#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(vector<int>&weight,vector<int>&value,int n,int maxWeight){
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
    
    for(int W=0;W<=maxWeight;W++){
        dp[0][W]=((int)(W/weight[0]))*(value[0]);
    }

    for(int indx=1;indx<n;indx++){
 
        for(int W=0;W<=maxWeight;W++){
                    int notTake=dp[indx-1][W];
                    int take=INT_MIN;
                    if(weight[indx]<=W){
                        take=value[indx]+dp[indx][W-weight[indx]];
                    }
                    dp[indx][W]=max(take,notTake); 
        }
    }
    return dp[n-1][maxWeight];
}

int main(){
     int n,maxWeight;
     cin>>n>>maxWeight;
    vector<int>value;
    cout<<"Enter value array :"<<endl;
    for(int i=0;i<n;i++){
         int x;
         cin>>x;
         value.push_back(x);
    }
    vector<int>weight;
    cout<<"Enter weight array :"<<endl;    
     for(int i=0;i<n;i++){
         int x;
         cin>>x;
         weight.push_back(x);
     }
    cout<<unboundedKnapsack(weight,value,n,maxWeight)<<endl;
}