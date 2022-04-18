#include<bits/stdc++.h>
using namespace std;
int main(){
 int n;
 cin>>n;
 int val=1;
 int i=1;
 while(i<=n){
     int j=1;
     while(j<=i){
         cout<<val<<" ";
         j++;
         val++;
     }
     cout<<endl;
     i++;
 }   
}