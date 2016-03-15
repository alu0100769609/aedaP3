#include <iostream>
using namespace std;

class Complejo {
   friend class RPN<Complejo>;               //Allow class RPN to access method operator -
public:                       //Attributes
   double realPart;
   double imaginaryPart;

public:                       //Default constructor & destructor
   Complejo();                               //Default constructor
   Complejo(double, double);                 //Overloaded constructor
   ~Complejo();                              //Destructor

public:                       //Public access methods
   void setRealPart(double);
   double getRealPart() const;
   void setImaginaryPart(double);
   double getImaginaryPart() const;

private:                      //Methods that can't be called from outside the class
   Complejo operator +(const Complejo) const;
   Complejo operator -(const Complejo) const;
   Complejo operator *(const Complejo) const;
   Complejo operator /(const Complejo) const;
   Complejo operator -() const;
};

////////////////////////////Methods////////////////////////////

Complejo::Complejo() {
   //By default
}

Complejo::Complejo(double realPart, double imaginaryPart) {
   setRealPart(realPart);
   setImaginaryPart(imaginaryPart);
}

Complejo::~Complejo() {
   //By default
}

void Complejo::setRealPart(double realPart) {
   this->realPart = realPart;
}

double Complejo::getRealPart() const {
   return realPart;
}

void Complejo::setImaginaryPart(double imaginaryPart) {
   this->imaginaryPart = imaginaryPart;

}

double Complejo::getImaginaryPart() const {
   return imaginaryPart;
}

Complejo Complejo::operator +(const Complejo c2) const {
   return (Complejo(getRealPart() + c2.getRealPart(), getImaginaryPart() + c2.getImaginaryPart()));
}

Complejo Complejo::operator -(const Complejo c2) const {
   return (Complejo(getRealPart() - c2.getRealPart(), getImaginaryPart() - c2.getImaginaryPart()));
}

Complejo Complejo::operator -() const {
   return (Complejo(-getRealPart(), -getImaginaryPart()));
}

Complejo Complejo::operator *(const Complejo c2) const {
   return (Complejo(getRealPart() * c2.getRealPart(), getImaginaryPart() * c2.getImaginaryPart()));
}

Complejo Complejo::operator /(const Complejo c2) const {
   return (Complejo(getRealPart() / c2.getRealPart(), getImaginaryPart() / c2.getImaginaryPart()));
}

ostream& operator << (ostream& os, const Complejo& complejo) {
   os << "(" << complejo.getRealPart() << "+" << complejo.getImaginaryPart() << "i)";
   return os;
}

istream& operator >>(istream& is, Complejo& complejo) {
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
