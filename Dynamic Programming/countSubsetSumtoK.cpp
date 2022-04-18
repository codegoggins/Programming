#include<bits/stdc++.h>
using namespace std;

int f(int indx,int sum,vector<int>&arr){

if(sum==0)return 1;
if(indx==0)return (arr[0]==sum);

int notTake=f(indx-1,sum,arr);
int take=0;
if(sum >= arr[indx]){
    take=f(indx-1,sum-arr[indx],arr);
}

return take +notTake;

}

int countSubsetSumToK(int n,int k,vector<int>&arr){
    return f(n-1,k,arr);
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<endl;
    cout<<countSubsetSumToK(n,k,arr);
    return 0;
}