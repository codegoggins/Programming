//FRACTION CLASS
//Before we were updating value of add and multiply in f1
//now suppose we want to save it and return it in a new object
#include<bits/stdc++.h>
using namespace std;
class Fraction{
int numerator;
int denominator;

public:
void display(){
    cout<<numerator<<" / "<<denominator<<endl;
}

//constructor
Fraction(int numerator,int denominator){
    this->numerator=numerator;
    this->denominator=denominator;
}

void simplify(){

    int gcd=1;
    int j=min(numerator,denominator);
    for(int i=1;i<=j;i++){
        if(numerator%i==0 && denominator%i==0){
            gcd=i;
        }
    }
    numerator=numerator/gcd;
    denominator=denominator/gcd;
}

//add two fractions
Fraction add(Fraction const &f2){
    int lcm=denominator * f2.denominator;
    int x = lcm/denominator;
    int y = lcm/f2.denominator;
    int num = numerator*x + f2.numerator * y;
    
    //numerator=num;
    //denominator=lcm;
    Fraction fNew(num,lcm);
    fNew.simplify();    
    
    return fNew;
}
};

int main(){
Fraction f1(10,2);
Fraction f2(15,4);
Fraction f3=f1.add(f2);
f1.display();
f2.display();
f3.display();
}