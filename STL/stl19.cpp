#include<bits/stdc++.h>
using namespace std;
int main(){
    map<pair<string,string>,vector<int>>m;
    //this map will have key as a pair of strings like first name last name
    //and the value will be a vector of marks
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string fn,ln;
        int ct;//count of subject marks
        cin>>fn>>ln>>ct;
        for(int i=0;i<ct;i++){
            int x;
            cin>>x;
            //as the value is a vector,so m[key] becomes a vector and we can use push_back on it
            m[{fn,ln}].push_back(x);
        }

        //we use & to avoid creation of copy
        for(auto &pr:m){
            auto &full_name=pr.first;
            auto &list=pr.second;
            cout<<full_name.first<<" "<<full_name.second<<endl;
            cout<<list.size()<<endl;
            for(auto &element :list){
               cout<<element<<" ";
            }
            cout<<endl;
        }
    }
}