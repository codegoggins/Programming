//ORDER OF CONSTRUCTOR CALLS WHEN WE REMOVE DEFAULT CONSTRUCTOR FROM PARENT CLASS
#include<bits/stdc++.h>
using namespace std;

class Vehicle{

    private:
    //property cannot be inherited by child class
    int maxSpeed=30;
    //can be accessed only by child class
    protected:
    int numTyres=10;
    //can be accessed by all
    public:
    string color="Blue";

    //PARAMETERIZED CONSTRUCTOR
    Vehicle(int z){
        cout<<"Vehicles Parameterized Constructor"<<endl;
        maxSpeed=z;
        cout<<z<<endl;
    }
    ~Vehicle(){
        cout<<"Vehicle Destructor"<<endl;
    }
};

//INHERITANCE SYNTAX
class Car:public Vehicle{
    public:
    int numGears;

    Car(int x):Vehicle(x){
        cout<<"Car Default Constructor"<<endl;
        cout<<x<<endl;
    }
    Car(int x,int y):Vehicle(x){
        cout<<"Car Default Constructor 2 parameters"<<endl;
        cout<<x<<endl;
    }
    ~Car(){
        cout<<"Car Destructor"<<endl;
    }
};

class HondaCity:public Car{
     public:
     HondaCity(int x,int y):Car(x,y){
         cout<<"Honda City Constructor"<<endl;
        cout<<x<<" "<<y<<endl;
     }
    ~HondaCity(){
         cout<<"Honda City Destructor"<<endl;
    }
     

};


int main(){
 HondaCity h(4,5);
}