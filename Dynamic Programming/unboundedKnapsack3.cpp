#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(vector<int>&weight,vector<int>&value,int n,int maxWeight){
    vector<int>prev(maxWeight+1,0),curr(maxWeight+1,0);
    
    for(int W=0;W<=maxWeight;W++){
        prev[W]=((int)(W/weight[0]))*(value[0]);
    }

    for(int indx=1;indx<n;indx++){
 
        for(int W=0;W<=maxWeight;W++){
                    int notTake=prev[W];
                    int take=INT_MIN;
                    if(weight[indx]<=W){
                        take=value[indx]+curr[W-weight[indx]];
                    }
                    curr[W]=max(take,notTake); 
        }
        prev=curr;
    }
    return prev[maxWeight];
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