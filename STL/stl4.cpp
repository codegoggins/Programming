//CREATING AN ARRAY OF VECTORS
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
//ARRAY OF VECTORS
//Here we have an array of 10 vectors
//We have created an array which stores data of type vector
//Its just like a 2D array
/*In Array of vectors ,the number of rows is fixed but the number of columns is dynamic because we are specifying 
the number of rows i.e the number of vectors our array can store.But as vectors are dynamicao the number of columns
is not fixed.
If we want both rows and columns to be dynamic we need to use vector of vectors*/
int N;
cin>>N;
vector<int> v[N];
for(int i=0;i<N;i++){
    //taking size of each vector
    int a;
    cin>>a;
    for(int j=0;j<a;j++){
        int val;
        cin>>val;
        v[i].push_back(val);
    }
}
for(int i=0;i<N;i++){
    printVectorArray(v[i]);
}
//we can also print it like 2D arrays
for(int i=0;i<N;i++){
    for(int j=0;j<v[i].size();j++){
        cout<<v[i][j]<<" ";
    }
    cout<<endl;
}
cout<<endl;
}
