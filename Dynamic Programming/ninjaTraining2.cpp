//TABULATION CODE
#include<bits/stdc++.h>
using namespace std;


int ninjaTraining(int n,vector<vector<int>>&points){
      
      vector<vector<int>>dp(n,vector<int>(4,0));
      
      dp[0][0]=max(points[0][1],points[0][2]);
      dp[0][1]=max(points[0][0],points[0][2]);
      dp[0][2]=max(points[0][0],points[0][1]);
      dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));

      for(int day=1;day <n;day++){

         for(int last=0;last<4;last++){
             dp[day][last]=0;
             for(int task=0;task<3;task++){
                 if(task!=last){
                     int point=points[day][task]+dp[day-1][task];
                     dp[day][last]=max(dp[day][last],point);
                     /*or we can simply write
                     dp[day][last]=max(dp[day][last],points[day][task]+dp[day-1][task]);
                     instead of using point variable
                     */
                 }
             }
         }

      }
      return dp[n-1][3];
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