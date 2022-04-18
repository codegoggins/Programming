//Practice nesting Question
/*
Problem
Monk is a multi-talented person, and prepares results for his college in his free time. 
(Yes, he is still in love with his old college!) He gets a list of students with their marks. 
The maximum marks which can be obtained in the exam is 100.
The Monk is supposed to arrange the list in such a manner that the list is sorted in decreasing order of marks.
And if two students have the same marks, they should be arranged in lexicographical manner.
Help Monk prepare the same!

Link:
https://www.hackerearth.com/problem/algorithm/the-monk-and-class-marks/

*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    //But if we use sets people with same name and marks will be printed only once
     //map<int,set<string>>marks_map;
     //So to avoid that we use multi sets
     map<int,multiset<string>>marks_map;
     int n;
     cin>>n;
     for(int i=0;i<n;i++){
         int marks;
         string name;
         cin>>name>>marks;
         marks_map[marks].insert(name);
     }
     //marks_map>end() points next to last iterator.We decrement and point to last iterator which has the 
     //highest marks.We take this till marks_map.begin()
     auto curr_it=--marks_map.end();
     while(true){
         auto &students=(*curr_it).second;
         int marks=(*curr_it).first;
         for(auto student:students){
             cout<<student<<" "<<marks<<endl;
         }
         //this loop is an infinite loop ,so we need to break it also
         if(curr_it==marks_map.begin()){
             //means map pura cover ho chuka h
             break;
         }
         curr_it--;
     }
}