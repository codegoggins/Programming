//ORDER OF CONSTRUCTOR CALLS WHEN WE REMOVE DEFAULT CONSTRUCTOR FROM PARENT CLASS
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

    //PARAMETERIZED CONSTRUCTOR
    Vehicle(int z){
        cout<<"Vehicles Parameterized Constructor"<<endl;
        maxSpeed=z;
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
    }
    ~Car(){
        cout<<"Car Destructor"<<endl;
    }
};


int main(){
 Car c(50);
}