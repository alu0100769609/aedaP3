#include <iostream>

using namespace std;

class Number {
public:  //why public? --> That's how it is specified in the exercise
//protected:  //why protected? --> To be like public but restricting calls from outside the class
//private:    //why private? --> Guideline #2 --> http://www.gotw.ca/publications/mill18.htm
   virtual const Integer toInteger() const = 0;       // Return Number converted in Integer
   virtual const Rational toRational() const = 0;     // Return Number converted in Rational
   virtual const Real toReal() const = 0;             // Return Number converted in Real
   virtual const Complex toComplex() const = 0;       // Return Number converted in Complex
   virtual ostream& toStream(ostream& sout) const = 0;// Write Number in ostream
   virtual istream& fromStream(istream& sin) = 0;     // Read Number from istream

};
