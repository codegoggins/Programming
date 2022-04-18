//Balanced Brackets Question using Stack
#include<bits/stdc++.h>
using namespace std;

//generally we write using if conditions
//if(s[i]=='[' || s[i]=='{' || s[i]=='(')//to check opening bracket
//if(s[i]==']' && st.top()=='[')
//But this code is tedious so we use unordered maps


//for opening bracket '(' we set value -1 and for closing ')' +1.So that their sum turns out to be 0;
//For each type bracket we select diff value
//sum of oening and closing pairs will be 0
unordered_map<char,int>symbols={{'[',-1},{'{',-2},{'(',-3},{']',1},{'}',2},{')',3}};
string isBalanced(string s){
    stack<char>st;
    for(char bracket:s){

       if(symbols[bracket] < 0){
           //means bracket is opening bracket,so we push it in the stack
          st.push(bracket);
       } 
       else{
        //bracket is closing so there needs to be an opening bracket in stack.
        //If stack is empty means not balanced
        if(st.empty())return "NO";
        char top=st.top();
        st.pop();
        //now we check if the top element and curr character are opening closing pair or not
         if(symbols[bracket]+symbols[top]!=0){
             return "NO";
         }
       }
    }
    if(st.empty()){
        return "YES";
    }
    return "NO";
}

int main(){
    string s;
    cout<<isBalanced(s)<<endl;
}