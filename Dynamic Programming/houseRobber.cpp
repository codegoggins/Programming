//HOUSE ROBBER RECURSIVE CODE
#include<bits/stdc++.h>
using namespace std;

int houseRobber_helper(int n,int*arr){
    
    if(n==0)return arr[n];

    if(n<0)return 0;

    int pick=arr[n]+houseRobber_helper(n-2,arr);
    int notPick=houseRobber_helper(n-1,arr);

    return max(pick,notPick);
}

int houseRobber(int n,int*arr){
     return houseRobber_helper(n-1,arr);
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