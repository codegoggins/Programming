//TABULATION CODE SPACE OPTIMIZED
#include<bits/stdc++.h>
using namespace std;


int ninjaTraining(int n,vector<vector<int>>&points){
      
      vector<int>prev(4,0);
      
      prev[0]=max(points[0][1],points[0][2]);
      prev[1]=max(points[0][0],points[0][2]);
      prev[2]=max(points[0][0],points[0][1]);
      prev[3]=max(points[0][0],max(points[0][1],points[0][2]));

      for(int day=1;day <n;day++){
          vector<int>temp(4);
         for(int last=0;last<4;last++){
             temp[last]=0;
             for(int task=0;task<3;task++){
                 if(task!=last){
                   temp[last]=max(temp[last],points[day][task]+prev[task]);
                 }
             }
         }
         prev=temp;
      }
      return prev[3];
      
}
/*

4
2 1 3
3 4 6
10 1 6
8 3 7

*/


int main(){
   cout<<"Enter number of days :"<<endl;
   int n;
   cin>>n;
   vector<vector<int>>points;
   for(int i=0;i<n;i++){
       vector<int>temp;
       for(int j=0;j<3;j++){
           int val;
           cin>>val;
           temp.push_back(val);
       }
       points.push_back(temp);
   }
   cout<<ninjaTraining(n,points)<<endl;
}