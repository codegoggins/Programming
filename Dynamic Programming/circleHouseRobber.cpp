//SPACE OPTIMIZED CIRCLE HOUSE ROBBER PROBLEM
#include<bits/stdc++.h>
using namespace std;



int houseRobber(vector<int>&arr){
    int n=arr.size();
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

long long int circularHouse(vector<int> &house)
{
   vector<int> temp1,temp2;
   int n=house.size();

   if(n==1){
       return house[0];
   }
   for(int i=0;i<n;i++){
         if(i!=0){
             temp1.push_back(house[i]);
         }
         if(i!=n-1){
             temp2.push_back(house[i]);
         }
   }
   return max(houseRobber(temp1),houseRobber(temp2));
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<circularHouse(arr)<<endl;
}