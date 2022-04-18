/*Given N strings and Q queries.In each query you are given a string.Print yes if string is present else print no
N<=10^6
|S| <= 100
Q <= 10^6
*/

//In this question we can use both maps and sets.But there is no sense in using maps as we just want to print unique 
//in lexiographical order
#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_set <string> s;
    int n;
    cin>> n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        s.insert(str);
    }
    int q;
    cin>>q;
    while(q--){
        string str;
        cin>>str;
        if(s.find(str)==s.end()){
          cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
    }
}