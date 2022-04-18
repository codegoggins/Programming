//FROG JUMP RECURSIVE CODE
#include<bits/stdc++.h>
using namespace std;

int f(int indx,vector<int>&heights){
    
    if(indx==0)return 0;

    int left=f(indx-1,heights) + abs(heights[indx]-heights[indx-1]);

    int right=INT_MAX;
    if(indx >1){
        right=f(indx-2,heights)+abs(heights[indx]-heights[indx-2]);
    }
    return min(left,right);


}


int frogJump(int n,vector<int>&vec){
    return f(n-1,vec);
}

int main(){
    int n,x;
    cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++){
        cin>>x;
        vec.push_back(x);
    }
    cout<<frogJump(n,vec)<<endl;;
}