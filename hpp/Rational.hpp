#include <iostream>
using namespace std;

class Rational {
   friend class RPN<Rational>;               //Allow class RPN to access method operator -
public:                       //Attributes
   int numerator;
   int denominator;

public:                       //Default constructor & destructor
   Rational();                               //Default constructor
   Rational(int, int);                       //Overloaded constructor
   ~Rational();                              //Destructor

public:                       //Public access methods
   void setNumerator(int);
   int getNumerator() const;
   void setDenominator(int);
   int getDenominator() const;

private:                      //Methods that can't be called from outside the class
   void gcd ();
   Rational operator +(const Rational) const;
   Rational operator -(const Rational) const;
   Rational operator *(const Rational) const;
   Rational operator /(const Rational) const;
   Rational operator -() const;
};

////////////////////////////Methods////////////////////////////

Rational::Rational() {
   //By default
}

Rational::Rational(int numerator, int denominator) {
   setNumerator(numerator);
   setDenominator(denominator);
}

Rational::~Rational() {
   //By default
}

void Rational::setNumerator(int numerator) {
   this->numerator = numerator;
}

int Rational::getNumerator() const {
   return numerator;
}

void Rational::setDenominator(int denominator) {
   this->denominator = denominator;

}

int Rational::getDenominator() const {
   return denominator;
}

void Rational::gcd () {
   int  gcd;
   for(int i = 1; i <= getNumerator() && i <= getDenominator(); i++)
      if(getNumerator() % i == 0 && getDenominator() % i == 0 )
         gcd = i;
   setNumerator(getNumerator() / gcd);
   setDenominator(getDenominator() / gcd);
}

Rational Rational::operator +(const Rational r2) const {
   Rational result = (Rational((getNumerator() * r2.getDenominator()) +
                               (r2.getNumerator() * getDenominator()),
                              getDenominator() * r2.getDenominator()));
   result.gcd();
   return result;
}

Rational Rational::operator -(const Rational r2) const {
   Rational result = (Rational((getNumerator() * r2.getDenominator()) -
                               (r2.getNumerator() * getDenominator()),
                              getDenominator() * r2.getDenominator()));
   result.gcd();
   return result;
}

Rational Rational::operator -() const {
   return (Rational(-getNumerator(), getDenominator()));
}

Rational Rational::operator *(const Rational r2) const {
   Rational result = (Rational(getNumerator() * r2.getNumerator(),
                              getDenominator() * r2.getDenominator()));
   result.gcd();
   return result;
}

Rational Rational::operator /(const Rational r2) const {
   Rational result = (Rational(getNumerator() * r2.getDenominator(),
                              getDenominator() * r2.getNumerator()));
   result.gcd();
   return result;
}

ostream& operator << (ostream& os, const Rational& rational) {
   os << rational.getNumerator() << "/" << rational.getDenominator();
   return os;
}

istream& operator >>(istream& is, Rational& rational) {
   is >> ws;                                 //Eat up any leading white spaces
                                             //Start of parse input
   int c = is.peek();                        //See next character
   if (c == '{'){
      char discard;                          //Create discard variable
      is >> discard;                         //Discard "("
      c = is.peek();                         //See next char
      if (isdigit(c)){                       //If isDigit save into numerator
         double num;
         is >> num;
         rational.setNumerator(num);
         c = is.peek();                      //See next char
         if (c == '/'){
            is >> discard;                   //Discard "/"
            c = is.peek();                   //Get next char
            if (isdigit(c)) {                //If isDigit save into denominator
               is >> num;
               rational.setDenominator(num);
               c = is.peek();                //See next char
               if (c == '}') {
                  is >> discard;             //Discard ")"
                  return is;                 //All successfully, return istream
               }
            }
         }
      }
   }                                         //If here, rational input was wrong
   cout <<"Oops... Something is wrong here" << endl;
}
