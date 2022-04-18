//OPERATOR OVERLOADING
// NOW INSTEAD OF USING add we use the operator '+'
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
const Fraction operator + (Fraction const &f2){
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
//multiply two fractions
const Fraction operator *(Fraction const &f2){
    int n=numerator*f2.numerator;
    int d=denominator*f2.denominator;
    Fraction fNew(n,d);
    return fNew;
}

const bool operator == (Fraction f2){
    return (numerator==f2.numerator && denominator==f2.denominator);
}

};

int main(){
Fraction f1(10,2);
Fraction f2(15,4);
Fraction f3=f1+f2;
Fraction f4=f1*f2;
if(f1==f2){
    cout<<"Equal fractions"<<endl;
}else{
    cout<<"Not equal fractions"<<endl;
}
f1.display();
f2.display();
f3.display();
f4.display();
}