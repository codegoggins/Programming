//ITERATORS
//We can access data in vectors just like array Eg:v[i]
//But as we move further i STL,containers like maps and sets dont have indexing and we cannot access ith value
//So we use iterators
#include<bits/stdc++.h>
using namespace std;
int main(){
   vector<int>v={1,2,3,4,5};
   for(int i=0;i<v.size();i++){
       cout<<v[i]<<" ";
   }
   cout<<endl;
   //declaring an iterator that points at first element of the vector
   vector<int> :: iterator it =v.begin();
   cout<<(*it)<<endl;
   cout<<(*(it+1))<<endl;
   cout<<(*(it+2))<<endl;
   cout<<(*(it+3))<<endl;
   cout<<(*(it+4))<<endl;

   for(it=v.begin();it!=v.end();it++){
       cout<<(*it)<<" ";
   }
   cout<<endl;

   //iterators pointing to pairs
   vector<pair<int,int>> v1={{1,2},{3,4},{5,6}};
   vector<pair<int,int>> :: iterator it2;
   for(it2=v1.begin();it2!=v1.end();it2++){
       cout<<(*it2).first<<" "<<(*it2).second<<endl;
   }
   //Another way to print first and second in pair
   for(it2=v1.begin();it2!=v1.end();it2++){
       cout<<it2->first<<" "<<it2->second<<endl;
   }
}