/*Given N strings ,print unique strings in lexiographical order
N<=10^5
|S| <= 100000
*/

//In this question we can use both maps and sets.But there is no sense in using maps as we just want to print unique 
//in lexiographical order
#include<bits/stdc++.h>
using namespace std;
int main(){
    set <string> s;
    int n;
    cin>> n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        s.insert(str);
    }
    for(auto value : s){
           cout<< value<<endl;
    }
}