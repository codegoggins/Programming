#include<bits/stdc++.h>
using namespace std;

int f(int indx,int W,vector<int>&wt,vector<int>&val){
    if(indx==0){
        if(wt[0]<=W){
            return val[0];
        }else{
            return 0;
        }
    }
    int notTake=f(indx-1,W,wt,val);
    int take=INT_MIN;
    if(wt[indx]<=W){
        take=val[indx]+f(indx-1,W-wt[indx],wt,val);
    }
    return max(take,notTake);
}

int knapsack(vector<int>&weight,vector<int>&value,int n,int maxWeight){
    
    return f(n-1,maxWeight,weight,value);
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