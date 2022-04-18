//MAPS STL
//In Maps each element is a pair
//Maps store key value pairs
//The keys stored in maps are unique and we cannot insert the same key again i.e.If we cannot have a duplicate
//do duplicate is not create.The old value
//corresponding to the key is updated with the new value
#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,string> m;
    //if we have not initialed with any value then by default empty string in stored at that key
    //if value is of type int then it is initialised with 0 by default if we not stored any value at that key
    //insert values in maps using square brackets
    //Insertion using square brackets or using insert function takes O(logn) time in maps
    //TIme complexity to access values is also O(logn)
    //where n is the size of the map
    m[1]="abc";
    m[2]="def";
    m[3]="ghi";
    //using insert
    m.insert({4,"jkl"});
    //printing map
    map<int,string>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
        //or cout<<it->first<<" "<<it->second<<endl;
    }
    //using auto
    for(auto &p : m){
        cout<<p.first<<" "<<p.second<<endl;
        //cout<<p->first<<" "<<p->second<<endl;
    }

}