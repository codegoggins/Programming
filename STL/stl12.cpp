//SETS ,UNORDERED SETS AND MULTISETS
//In maps we store key value pairs,if we remove the value part from maps then we only have a container that stores keys.
//Set is container that stores keys i.e a collection of elements
#include<bits/stdc++.h>
using namespace std;
int main(){
    //stores unique elements in sorted order
    set<string> s;
    //insert-O(logn)
    s.insert("abc");
    s.insert("zxy");
    s.insert("gfh");
    //to access we don't have any brackets in sets,we only have find()
    //s.find() returns the iterator of that element
    //if the element does not exists then we get the end iterator
    auto it=s.find("abc");
    //print
    //the elements are printed in sorted order
    
    for(string  value : s){
           cout<<value<<endl;
    }
    /*
    for(auto it=s.begin();it!=s.end();it++){
        cout<<(*it)<<endl;
    }
    */
    //if we insert abc again and print,abc will be printed only once because a set only stores unique elements
    //Internal implementation of sets is using red black trees i.e self balancing trees

}