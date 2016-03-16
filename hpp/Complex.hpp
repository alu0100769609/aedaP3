#include <iostream>
using namespace std;

class Complex {
   friend class RPN<Complex>;               //Allow class RPN to access method operator -
public:                       //Attributes
   double realPart;
   double imaginaryPart;

public:                       //Default constructor & destructor
   Complex();                               //Default constructor
   Complex(double, double);                 //Overloaded constructor
   ~Complex();                              //Destructor

public:                       //Public access methods
   void setRealPart(double);
   double getRealPart() const;
   void setImaginaryPart(double);
   double getImaginaryPart() const;

private:                      //Methods that can't be called from outside the class
   Complex operator +(const Complex) const;
   Complex operator -(const Complex) const;
   Complex operator *(const Complex) const;
   Complex operator /(const Complex) const;
   Complex operator -() const;
};

////////////////////////////Methods////////////////////////////

Complex::Complex() {
   //By default
}

Complex::Complex(double realPart, double imaginaryPart) {
   setRealPart(realPart);
   setImaginaryPart(imaginaryPart);
}

Complex::~Complex() {
   //By default
}

void Complex::setRealPart(double realPart) {
   this->realPart = realPart;
}

double Complex::getRealPart() const {
   return realPart;
}

void Complex::setImaginaryPart(double imaginaryPart) {
   this->imaginaryPart = imaginaryPart;

}

double Complex::getImaginaryPart() const {
   return imaginaryPart;
}

Complex Complex::operator +(const Complex c2) const {
   return (Complex(getRealPart() + c2.getRealPart(), getImaginaryPart() + c2.getImaginaryPart()));
}

Complex Complex::operator -(const Complex c2) const {
   return (Complex(getRealPart() - c2.getRealPart(), getImaginaryPart() - c2.getImaginaryPart()));
}

Complex Complex::operator -() const {
   return (Complex(-getRealPart(), -getImaginaryPart()));
}

Complex Complex::operator *(const Complex c2) const {
   return (Complex(getRealPart() * c2.getRealPart(), getImaginaryPart() * c2.getImaginaryPart()));
}

Complex Complex::operator /(const Complex c2) const {
   return (Complex(getRealPart() / c2.getRealPart(), getImaginaryPart() / c2.getImaginaryPart()));
}

ostream& operator << (ostream& os, const Complex& complejo) {
   os << "(" << complejo.getRealPart() << "+" << complejo.getImaginaryPart() << "i)";
   return os;
}

istream& operator >>(istream& is, Complex& complejo) {
   is >> ws;                                 //Eat up any leading white spaces
                                             //Start of parse input
   int c = is.peek();                        //See next character
   if (c == '('){
      char discard;                          //Create discard variable
      is >> discard;                         //Discard "("
      c = is.peek();                         //See next char
      if (isdigit(c)){                       //If isDigit save into realPart
         double num;
         is >> num;
         complejo.setRealPart(num);
         c = is.peek();                      //See next char
         if (c == ','){
            is >> discard;                   //Discard ","
            c = is.peek();                   //Get next char
            if (isdigit(c)) {                //If isDigit save into imaginaryPart
               is >> num;
               complejo.setImaginaryPart(num);
               c = is.peek();                //See next char
               if (c == ')') {
                  is >> discard;             //Discard ")"
                  return is;                 //All successfully, return istream
               }
            }
         }
      }
   }                                         //If here, complex input was wrong
   cout <<"Oops... Something is wrong here" << endl;
}
