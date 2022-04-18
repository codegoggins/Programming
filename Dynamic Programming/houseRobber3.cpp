//SPACE OPTIMIZED HOUSE ROBBER PROBLEM
#include<bits/stdc++.h>
using namespace std;



int houseRobber(int n,int*arr){

    int prev=arr[0];
    int prev2=0;
    for(int i=1;i<n;i++){

        int pick=arr[i];
        if(i > 1){
            pick+=prev2;
        }
        int notPick=prev;

        int curr=max(pick,notPick);
        prev2=prev;
        prev=curr;
    }
    return prev;     
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