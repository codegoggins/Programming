//EASY WAY TO IMPLEMENT ITERATORS WRITING SHORT CODE
#include<bits/stdc++.h>
using namespace std;
int main(){
   vector<int>v={1,2,3,4,5};
   for(int i=0;i<v.size();i++){
       cout<<v[i]<<" ";
   }
   cout<<endl;
   //Range Based Loops
   //We can iterate directly on the elements
   //one by one each value of vector is stored in the variable x and then printed until the vector is finished 
   for(int x:v){
       cout<<x<<" ";
   }
   cout<<endl;
   //But the values that are stored in variable x , are not the actual values of vector but just a copy,so any change in x 
   //won't affect the values of vector
   for(int x:v){
    x++;
   }
   //After printing ,no change is visible 
   for(int x:v){
       cout<<x<<" ";
   }
   cout<<endl;
   /*if we want to change the actual value,we can use reference operator.Then instead of copies actual values will
   be passed
   for(int &x : v){
       x++;
   }
   */ 
   //Printing pairs using Range based loop
   vector<pair<int,int>> v1={{1,2},{3,4},{5,6}};
   for(pair<int,int> &x : v1){
       cout<<x.first<<" "<<x.second<<endl;
   }
}