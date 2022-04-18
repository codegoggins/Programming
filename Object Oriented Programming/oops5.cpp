//INITIALISATION LIST
#include<bits/stdc++.h>
using namespace std;
class Student{
public:
int age;
const int rollNumber;

Student(int r):rollNumber(r){

}
void display(){
    cout<<age<<" "<<rollNumber<<endl;
}
};

int main(){
    Student s1(101);
    s1.age=20;
    s1.display();
}