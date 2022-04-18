//AUTO KEYWORD
#include<bits/stdc++.h>
using namespace std;
int main(){
//Auto keyword automatically determines what the data type of a will be
auto a=1;
cout<<a<<endl;
vector<int> v={1,2,3,4};
//Instead of declaring the complete iterator we can use auto
//auto automatically determines what type of variable it is
//if we keep declaring iterators using scope resoltion and iterator keyword ,the code looks untidy
for(auto it=v.begin();it!=v.end();it++){
      cout<<(*it)<<" ";
}
cout<<endl;
vector<pair<int,int>> v1={{1,2},{3,4},{5,6}};
   for(auto &x : v1){
       cout<<x.first<<" "<<x.second<<endl;
   }
}