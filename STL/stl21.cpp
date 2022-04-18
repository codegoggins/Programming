//STACKS AND QUEUES 
//Some questions such as balanced paranthesis and nest greater element questions can be done only using stacks
#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<string>q;
    q.push("abc");
    q.push("def");
    q.push("ghi");
    q.push("jkl");
    q.push("mnop");

    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    cout<<endl;
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

}