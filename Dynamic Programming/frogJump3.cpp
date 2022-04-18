//FROG JUMP TABULATION(BOTTOM UP APPROACH)
//SPACE OPTIMIZED CODE

#include<bits/stdc++.h>
using namespace std;

int f(int n,vector<int>&heights){
    int prev=0;
    int curr=0;
    int prev2=0;
    
    for(int i=1;i<n;i++){
    int fs=prev+abs(heights[i]-heights[i-1]);

    int ss=INT_MAX;
    if(i >1){
        ss=prev2+abs(heights[i]-heights[i-2]);
    }
    curr=min(fs,ss);
    prev=prev;
    prev=curr;
    }
    return prev;
}


int main(){
    int n,x;
    cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++){
        cin>>x;
        vec.push_back(x);
    }
    cout<<f(n,vec)<<endl;;
}