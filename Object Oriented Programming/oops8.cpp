//INHERITANCE
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
};

//INHERITANCE SYNTAX
class Car:public Vehicle{
    public:
    int numGears;

    void print(){
        cout<<"Number of tyres :"<<numTyres<<endl;
        cout<<"Colour :"<<color<<endl;
        cout<<"Number of gears :"<<numGears<<endl;
    }
};


int main(){
Vehicle v;
v.color="Blue";
//v.maxSpeed=100;//error bcoz its private
//v.numTyres=4;//error bcoz numTyres is protected and can be accesssed only by child class


Car c;
c.color="Black";
//c.numTyres=4;//error bcoz numTyres is a protected member of vehicle class and even though this is the child class object,it cannot 
//access the protected property.Only the child class can access th protected property
c.numGears=5;
c.print();//this prints numTyres which is a protected property as this is a method of the child class 
}