//UNORDERED SETs
//Just like maps the operations take O(1)
//We use when order in which elements are stored doesnt matters
//only presence of elements matters
//In maps we store key value pairs,if we remove the value part from maps then we only have a container that stores keys.
//Set is container that stores keys i.e a collection of elements
//Internal implementation uses hashtables
//We cannot store complex data types as keys like sets ,pairs etc because their hash 
//functions are not defines in external libraries
#include<bits/stdc++.h>
using namespace std;
int main(){
    //stores unique elements in unsorted order
    unordered_set<string> s;
    //insert-O(1)
    s.insert("abc");
    s.insert("zxy");
    s.insert("gfh");
    //to access we don't have any brackets in sets,we only have find()
    //s.find() O(1) returns the iterator of that element
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


}