#include<bits/stdc++.h>
using namespace std;

bool f(int indx,int target,vector<int>&arr){

if(target==0)return true;
if(indx==0)return (arr[0]==target);

bool notTake=f(indx-1,target,arr);
bool take=false;
if(target >= arr[indx]){
    take=f(indx-1,target-arr[indx],arr);
}

return take | notTake;

}

bool subsetSumToK(int n,int k,vector<int>&arr){
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
    if(subsetSumToK(n,k,arr)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}