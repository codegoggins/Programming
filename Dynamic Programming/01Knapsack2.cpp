#include<bits/stdc++.h>
using namespace std;



int knapsack(vector<int>&wt,vector<int>&val,int n,int maxWeight){
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));

        for(int i=wt[0];i<=maxWeight;i++){
           dp[0][i]=val[0];    
        }
        for(int indx=1;indx<n;indx++){

            for(int W=0;W<=maxWeight;W++){
                    int notTake=dp[indx-1][W];
                    int take=INT_MIN;
                    if(wt[indx]<=W){
                        take=val[indx]+dp[indx-1][W-wt[indx]];
                    }
                    dp[indx][W]=max(take,notTake);
            }
        }
        return dp[n-1][maxWeight];
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

    cout<<knapsack(weight,value,n,maxWeight)<<endl;
}