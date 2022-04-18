//NESTING IN STL MAPS AND SETS
#include<bits/stdc++.h>
using namespace std;
int main(){
    map<pair<int,int>,int>m;
    pair<int,int>p1,p2;
    //
    p1={1,2};
    p2={2,3};
    //while comparing the first element in pair is checked
    cout<<(p1 > p2)<<endl;
    //if the first elements are same in both ,then second element is compared
    p1={2,2};
    p2={2,3};
    cout<<(p1 < p2)<<endl;
    //So in maps ,this way keys are also stored in sorted order


    //SETs
    map<set<int>,int> m1;
    set<int>s1={1,2,3};
    set<int>s2={2,3}; 
    //Just like pairs these can also be compared.Those things which can be compared are inserted in maps as keys
    cout<< (s1 < s2)<<endl;
}//But we cannot do these type of nestings in unordered sets or maps because they need hash functions.
//Hash functions for these complicated data types is not available.