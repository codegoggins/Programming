#include<bits/stdc++.h>
using namespace std;

int maxPower(int n){
   int i=1;
   while(i*2<=n){
       i*=2;
   }
   return i;
}


int main(){
    int n;
    cin>>n;
    int hp=maxPower(n);
    int l=n-hp;
    cout<<(2*l)+1<<endl;
}
