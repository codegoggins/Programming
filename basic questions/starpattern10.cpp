//check if  a number is prime
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int d=2;
    bool flag=true;;
    for(int i=d;d<=n;d++){
        if(i % d==0){
             flag=false;
        }
    }
    cout<<flag<<endl;
}