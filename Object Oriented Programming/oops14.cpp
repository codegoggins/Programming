//HYBRID INHERITANCE
#include<bits/stdc++.h>
using namespace std;

class Vehicle{
   public:
   Vehicle(){
       cout<<"Vehicles Constructor"<<endl;
   }
   ~Vehicle(){
       cout<<"Vehicles Destructor"<<endl;
   }
   void print(){
       cout<<"Car"<<endl;
   }
};

//HEIRARICHAL INHERITANCE
class Car:public Vehicle{
   public:
   Car(){
       cout<<"Cars Constructor"<<endl;
   }
   ~Car(){
       cout<<"Car Destructor"<<endl;
   }
   
   void print(){
       cout<<"Car"<<endl;
   }
};

//HEIRARICHAL INHERITANCE
class Truck:public Vehicle{
   public:
   Truck(){
       cout<<"Trucks Constructor"<<endl;
   }
   ~Truck(){
       cout<<"Trucks Destructor"<<endl;
   }

   void print(){
       cout<<"Truck"<<endl;
   }
};

//MULTIPLE INHERITANCE
class Bus:public Car,public Truck{
   public:
   Bus(){
       cout<<"Bus Constructor"<<endl;
   }
   ~Bus(){
       cout<<"Bus Destructor"<<endl;
   }
};

int main(){
    Bus b;
   // b.print();We will get error
}