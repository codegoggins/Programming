/*
Problem
Our Monk loves candy!
While taking a stroll in the park, he stumbled upon N Bags with candies. 
The i'th of these bags contains Ai candies.
He picks up a bag, eats all the candies in it and drops it on the ground. 
But as soon as he drops the bag, the number of candies in the bag increases magically! 
Say the bag that used to contain X candies (before eating), now contains [X/2] candies! ,
where [x] is the greatest integer less than x (Greatest Integer Function).
Amazed by the magical spell, Monk can now have a lot more candies! 
But he has to return home in K minutes. 
In a single minute,Monk can consume all the candies in a single bag, regardless of the number of candies in it.
Find the maximum number of candies that Monk can consume.

Input:
First line contains an integer T. T test cases follow.
First line of each test case contains two space-separated integers N and K.
Second line of each test case contains N space-separated integers,the number of candies in the bags.

link:
https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/

*/

//We do not use sets here because if bags have similar no. of candies they will be considered the same
//In each minute we can consume only one bag.So in each min we need to choose bag with max candy
//We have k min ,so we can consume candy from only k bags 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        //we have written long long because of the constraints given
        multiset<long long>bags;
        for(int i=0;i<n;i++){
            long long candy_ct;
            cin>>candy_ct;
            bags.insert(candy_ct);
        }
        //to keep count of candies we eat
        long long totalCandies=0;
        for(int i=0;i<k;i++){
            //to get the bag with the max candy we need to get the last iterator,because it is ordered
            //this points next to last iterator,so we need to decrement by 1
            //we cannot do this- auto last_it=(bags.end()--),because woh pehle assign hoga phir decrement hoga
            //we can do this- auto last_it=(--bags.end());
            //or
            auto last_it=bags.end();
            last_it--;
            long long candy_ct=*(last_it);
            totalCandies+=candy_ct;
            //now we will erase & we avoid using bags.erase(candy_ct) as it will delete duplicates too
            //we use iterator
            bags.erase(last_it);//O(1) when iterator provided and O(logn) when value provided
            bags.insert(candy_ct/2);//log(n)//multiset always stores in sorted order
        }
        cout<<totalCandies<<endl;
    }
}