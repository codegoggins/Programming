//ORDER OF CONSTRUCTOR CALLS
#include<bits/stdc++.h>
using namespace std;

class Vehicle{

    private:
    //property cannot be inherited by child class
    int maxSpeed;
    //can be accessed only by child class
    protected:
    int numTyres=10;
    //can be accessed by all
    public:
    string color;

    //CONSTRUCTOR
    Vehicle(){
        cout<<"Vehicles Default Constructor"<<endl;
    }
    ~Vehicle(){
        cout<<"Vehicle Destructor"<<endl;
    }
};

//INHERITANCE SYNTAX
class Car:public Vehicle{
    public:
    int numGears;

    Car(){
        cout<<"Car Default Constructor"<<endl;
    }
    ~Car(){
        cout<<"Car Destructor"<<endl;
    }
};


int main(){
 Vehicle v;
 Car c;
}