//TABULATION HOUSE ROBBER PROBLEM
#include<bits/stdc++.h>
using namespace std;



int houseRobber(int n,int*arr){
    int dp[n];
    dp[0]=arr[0];
    
    for(int i=1;i<n;i++){

        int pick=arr[i];
        if(i > 1){
            pick+=dp[i-2];
        }
        int notPick=dp[i-1];

        dp[i]=max(pick,notPick);
    }
    return dp[n-1];     
}

int main(){
    int n;
    cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<houseRobber(n,arr)<<endl;
}