#include<bits/stdc++.h>
using namespace std;

int f(int indx,vector<int>&price,int N){
    if(indx==0){
        return N*price[0];
    }
    int notTake=f(indx-1,price,N);
    int take=INT_MIN;
    int rodLength=indx+1;
    if(rodLength<=N){
        take=price[indx]+f(indx,price,N-rodLength);
    }

    return max(take,notTake);
}

int cutRod(vector<int>&price,int n){
    return f(n-1,price,n);
}

int main(){
    int n;
    cin>>n;
    vector<int>price;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        price.push_back(x);
    }
    cout<<cutRod(price,n);
}