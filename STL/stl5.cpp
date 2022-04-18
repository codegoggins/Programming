//CREATING A VECTOR OF VECTORS
#include<bits/stdc++.h>
using namespace std;

void printVectorArray(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
/*
3
2
1 2
3
4 5 6
5
7 8 9 0 1
*/
int main(){
//VECTOR OF VECTORS
//Here we have an vector of 10 vectors
int N;
cin>>N;
vector<vector<int>> v;
for(int i=0;i<N;i++){
    //taking size of each vector
    int x;
    cin>>x;
    /*
    we create a temporary vector,first we store values in temp vector and then push back temp to main vector v
    beacuse main vector is a collection of vectors ,so we can only push a vector inside it.
    */
    vector<int>temp;
    for(int j=0;j<x;j++){
        int val;
        cin>>val;
        temp.push_back(val);
    }
    v.push_back(temp);
}
for(int i=0;i<v.size();i++){
    printVectorArray(v[i]);
}
cout<<endl;

//we can add elements,
//Suppose we add elements in first vector
v[0].push_back(15);
v[1].push_back(29);
//we can add a row
//suppose we have pushed an empty vector,the size of this vector will be printed 0
v.push_back(vector<int> ());

for(int i=0;i<v.size();i++){
       cout<<v[i].size()<<endl;
    for(int j=0;j<v[i].size();j++){
        cout<<v[i][j]<<" ";
    }
    cout<<endl;
}

}
