#include<bits/stdc++.h>
using namespace std;
//A class is a template that defines the properties and functions of a specific object
//By default all the properties of a class are private
class Student{
//the age property is private here
int age;

public:

int roll;
char name[100];

//getters
int getAge(){
    return age;
}
//setters
void setAge(int a){
    age=a;
}

void display(){
    //age is private but as we are inside the class we can use it
    cout<<age<<" "<<roll<<endl;
}


};

int main(){
    //an objet s1 is created with properties of Student class.Its like a copy of student class is created
    //These properties in this object are initialised with garbage value when the object is created
    //creating an object statically
    Student s1;
    s1.roll=1000;
    s1.setAge(24);
    s1.display();
    //creating an object dynamically
    Student *s2=new Student;
    s2->roll=1001;
    s2->setAge(25);
    s2->display();
    //we can also  write (*s2).roll

}