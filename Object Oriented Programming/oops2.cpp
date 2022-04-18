//fraction class
#include<bits/stdc++.h>
using namespace std;
class Fraction{
    private:
    int numerator;
    int denominator;

    public:

    //parameterized constructor
    Fraction(int numerator,int denominator){
        this->numerator=numerator;
        this->denominator=denominator;
    }

    void print(){
        cout<<numerator<<"/"<<denominator<<endl;
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

    //function to add two fractions
    void add(Fraction const &f2){
        int lcm=denominator * f2.denominator;
        int x=lcm/denominator;
        int y=lcm/f2.denominator;

        int num=x*numerator + (y*f2.numerator);

        numerator=num;
        denominator=lcm;
        //simply() function will simplify the fraction
        simplify();
    }
    //multiply two fractions
    void multiply(Fraction const &f2){
        numerator=numerator*f2.numerator;
        denominator=denominator*f2.denominator;
        simplify();
    }
};

int main(){
    Fraction f1(10,2);
    Fraction f2(15,4);
    //we update the values in f1
    f1.add(f2);
    f1.print();
    f2.print();
    f1.multiply(f2);
    f1.print();
    f2.print();

}