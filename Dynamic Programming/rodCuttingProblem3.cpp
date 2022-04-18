#include<bits/stdc++.h>
using namespace std;

int cutRod(vector<int>&price,int n){
    vector<int>prev(n+1,0),curr(n+1,0);    
    
    for(int N=0;N<=n;N++){
        prev[N]=N*price[0];
    }

    for(int indx =1;indx<n;indx++){

       for(int N=0;N<=n;N++){
            int notTake=prev[N];
            int take=INT_MIN;
            int rodLength=indx+1;
            if(rodLength<=N){
                take=price[indx]+curr[N-rodLength];
            }
            curr[N]=max(take,notTake);
       }
       prev=curr;
    }
    return prev[n];
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