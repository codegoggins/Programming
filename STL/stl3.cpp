//CREATING A VECTOR OF PAIRS
#include<bits/stdc++.h>
using namespace std;

void printVectorArray(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"";
    }
}

void printVector(vector<pair<int,int>> &v){
for(int i=0;i<v.size();i++){
    cout<<v[i].first<<" "<<v[i].second<<endl;
}
cout<<endl;
}

int main(){
vector<pair<int,int>> v1={{1,2},{3,4},{5,6}};
printVector(v1);


//taking input
vector<pair<int,int>> v2;
int n;
cin>>n;
for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    //we can pair using curly brackets ,using make_pair or by creating pair and then passing it 
    v2.push_back({x,y});
}
printVector(v2);
}