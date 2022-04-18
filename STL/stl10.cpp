//MAPS
#include<bits/stdc++.h>
using namespace std;
int main(){
     map<int,string> m;
    m[1]="abc";
    m[2]="def";
    m[3]="ghi";
    //If we want to find a value in maps we use map.find() function.
    //map.find() returns an iterators pointing to that key value pair
    //If 3 is present in the map it returns the iterator of value 3
    //If 3 is not present in the map then it return iterator pointing to m.end();
    auto it=m.find(3);
    if(it==m.end()){
        cout<<"No value"<<endl;
    }else{
        cout<<it->first<<" "<<it->second<<endl;
    }
    //Using erase function
    //Erase function can take two types of inputs either a value or an iterator
    m.erase(2);//O(logn) n=size of map
    if(it!= m.end()){
        m.erase(it);//erases the pair to which the iterator is pointing to
    }
    //we cannot pass an iterator to erase which does not exists
    /*Suppose 
    auto it=m.find(15);
    this it will point to m.end()
    Now when we pass this it to erase we get a segmentation fault because it does not exists
    So we always use m.erase with safety check
    */
   for(auto &x:m){
        cout<<x.first<<" "<<x.second<<endl;
   }
   m.clear();//clears the map
}