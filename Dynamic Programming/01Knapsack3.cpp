#include<bits/stdc++.h>
using namespace std;

//SPACE OPTIMISED 01 KNAPSACK CODE

int knapsack(vector<int>&wt,vector<int>&val,int n,int maxWeight){
    
        //WE CREATE A PREV ARRAY AND A CURR ARRAY 
        //PREV ARRAY IS THE PREV ARRAY WE FILLED
        //CURR ARRAY IS THE CURRENT ARRAY THAT WE ARE GOING TO FILL USING PREV
    
        vector<int>prev(maxWeight+1,0),curr(maxWeight+1,0);
        
        for(int W=wt[0];W<=maxWeight;W++){
           prev[W]=val[0];    
        }
        for(int indx=1;indx<n;indx++){

            for(int W=0;W<=maxWeight;W++){
                    int notTake=prev[W];
                    int take=INT_MIN;
                    if(wt[indx]<=W){
                        take=val[indx]+prev[W-wt[indx]];
                    }
                    curr[W]=max(take,notTake);
            }
            prev=curr;
        }
        return prev[maxWeight];
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