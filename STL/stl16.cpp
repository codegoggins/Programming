//MULTISET ALLOWS TO INSERT MULTIPLE VALUES
//It uses red black trees,so T.C for operations becomes O(logn)
//We can insert duplicate values in multiset

#include<bits/stdc++.h>
using namespace std;
int main(){
    multiset <string> s;
    s.insert("abc");
    s.insert("lmn");
    s.insert("abc");
    s.insert("ghi");
    s.insert("abc");
    //returns iterator pointng to the first abc
    auto it=s.find("abc");
    if(it!=s.end()){
        s.erase(it);
    }
    for( string x : s){
        cout<<x<<endl;
    }
    cout<<endl;
    //Or we can give value in erase function s.erase("abc")
    //But when we do this ,it does not points the first abc but instead deletes all abc values
    //So we should use the above way to delete and not this
      s.erase("abc");
      for( string x : s){
        cout<<x<<endl;
    }
}