//MULTIPLE INHERITANCE
#include<bits/stdc++.h>
using namespace std;

class Teacher{
  public:
  string name;
  int age;

  Teacher(){
      cout<<"Teachers Constructor"<<endl;
  }
  ~Teacher(){
      cout<<"Teachers Destructor"<<endl;
  }

  void print(){
      cout<<"Teacher"<<endl;
  }
};

class Student{
    public:

    void print(){
        cout<<"Student"<<endl;
    }
    Student(){
      cout<<"Students Constructor"<<endl;
    }
    ~Student(){
      cout<<"Students Destructor"<<endl;
    }
};

//TA inherits properties of both teacher and student
//As Teacher class is wriiten first in multiple inheritance its constructor will be called first
class TA:public Teacher,public Student{
    public:

    TA(){
        cout<<"TA constructor"<<endl;
    }
    ~TA(){
        cout<<"TA Destructor"<<endl;
    }
    void print(){
        cout<<"TA"<<endl;
    }
};

//When we have a print function in TA class ,we create a TA object and call print.
//The print function of TA class is called
//But if we remove the print function in TA class we get an error because ambiguiy is created 
//because of print functions in both Teacher and Student constructor
//object a is confused as to which function to call as it inherits both
int main(){
   TA a;
   a.print();
}
