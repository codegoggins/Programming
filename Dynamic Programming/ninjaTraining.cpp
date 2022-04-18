#include<bits/stdc++.h>
using namespace std;

int f(int day,int last,vector<vector<int>>&points){
      if(day==0){
          int maxi=0;
          for(int task=0;task<3;task++){
          if(task!=last){
             maxi=max(maxi,points[0][task]);
          }

        }
        return maxi;
      }
      int maxi=0;

      for(int task=0;task <3;task++){
          
          if(task!=last){
              int point=points[day][task]+f(day-1,task,points);
              maxi=max(maxi,point);
          }
      }
      return maxi;
}


int ninjaTraining(int n,vector<vector<int>>&points){
      
      return f(n-1,3,points);
}

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