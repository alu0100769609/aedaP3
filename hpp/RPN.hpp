#include "Stack.hpp"
#include <string>                            //string
#include <cctype>                            //isdigit()

#include <iostream>

template <class TDATO>
class RPN {
private:                      //Attributes
   Stack<TDATO> stack;                       //Stack
   TDATO value1;                             //Frist item
   TDATO value2;                             //Second item

public:                       //Default constructor & destructor
   RPN(void);                                //Constructor
   ~RPN(void);                               //Destructor

public:                       //Public access methods
   void setValue1(TDATO);                    //Set item into value1
   TDATO getValue1(void);                    //Get item from value1
   void setValue2(TDATO);                    //Set item into value2
   TDATO getValue2(void);                    //Get item from value2
   void pushItem(Stack<TDATO>*, TDATO);      //Push into stack
   TDATO popItem(Stack<TDATO>*);             //Pop from stack

private:                      //Methods that can't be called from outside the class
   void addition(Stack<TDATO>*);             //Add two numbers and push result into stack
   void substract(Stack<TDATO>*);            //Substract two numbers and push result into stack
   void multiply(Stack<TDATO>*);             //Multiply two numbers and push result into stack
   void divide(Stack<TDATO>*);               //Divide two numbers and push result into stack

public:                       //Public Methods
   void printItems(Stack<TDATO>*);           //Print stack items
   void popItems(Stack<TDATO>*);             //Pop 2 items and set them into value1 & value2
   void run(void);                           //Run RPN calculator
};

////////////////////////////Methods////////////////////////////

template <class TDATO>
RPN<TDATO>::RPN(void){
   //Default constructor
}

template <class TDATO>
RPN<TDATO>::~RPN(void){
   //Default destructor
}

template <class TDATO>
void RPN<TDATO>::setValue1(TDATO value1){
   this->value1 = value1;
}

template <class TDATO>
TDATO RPN<TDATO>::getValue1(void) {
   return value1;
}

template <class TDATO>
void RPN<TDATO>::setValue2(TDATO value2) {
   this->value2 = value2;
}

template <class TDATO>
TDATO RPN<TDATO>::getValue2(void) {
   return value2;
}

template <class TDATO>
void RPN<TDATO>::pushItem(Stack<TDATO>* stack, TDATO item) {
   stack->setHead(item);
}

template <class TDATO>
TDATO RPN<TDATO>::popItem(Stack<TDATO>* stack) {
   return stack->getFirst()->getElement();
}

template <class TDATO>
void RPN<TDATO>::addition(Stack<TDATO>* stack) {
   stack->setHead(getValue2() + getValue1());
}

template <class TDATO>
void RPN<TDATO>::substract(Stack<TDATO>* stack) {
   stack->setHead(getValue2() - getValue1());
}

template <class TDATO>
void RPN<TDATO>::multiply(Stack<TDATO>* stack) {
   stack->setHead(getValue2() * getValue1());
}

template <class TDATO>
void RPN<TDATO>::divide(Stack<TDATO>* stack) {
   stack->setHead(getValue2() / getValue1());
}

template <class TDATO>
void RPN<TDATO>::printItems(Stack<TDATO>* stack) {
   stack->printItems();
}

template <class TDATO>
void RPN<TDATO>::popItems(Stack<TDATO>* stack) {
   setValue1(popItem(stack));
   stack->deleteHead();             //remove element from stack
   setValue2(popItem(stack));
   stack->deleteHead();             //remove element from stack
}

template <class TDATO>
void RPN<TDATO>::run(void) {
   using namespace std;
   Stack<TDATO>* stack = new Stack<TDATO>();   //Creating our stack
   bool finCadena = false;

   cin.ignore();                    //skip the enter buffered from call
   cout << "Please, enter your expression: ";
   do{
      cout.flush();                 // ensure output is written
      int a = cin.peek();           // first peek just to catch \n
      if (a != '\n'){
         cin >> ws;                 // eat up any leading white spaces (except eof by if)
      }
      int c = cin.peek();           // peek character
      if (c == '\n') {
         finCadena = true;
         cout << "Resultado: ";
         printItems(stack);
         cout << endl;
      }
      else if (isdigit(c) || c == '(' || c == '{'){
         TDATO item;
         cin >> item;
//         cout << "El item es: " << item << endl;
//         cout << "Real de item: " << item.getRealPart() << endl;
//         cout << "Imag de item: " << item.getImaginaryPart() << endl;
         pushItem(stack, item);

//         cout << "Esto hay en la pila" << endl;
//         printItems(stack);
//         cout << "Sacamos el item" << endl;
//         popItem(stack);
//         cout << "Lo nuevo de la pila" << endl;
//         printItems(stack);
//         cout << "por aqui no pasa" << endl;
      }
      else {
         char op;
         cin >> op;
         if ((op == '-') && isdigit(cin.peek())) {   //If -3 || +4
            TDATO item;
            cin >> item;
            pushItem(stack, -item);
//            pushItem(stack, item);
         }
         else if ((op == '+') && isdigit(cin.peek())) {
            TDATO item;
            cin >> item;
            pushItem(stack, item);
         }
         else {
            popItems(stack);
            switch (op) {
               case '+':
                  addition(stack);
                  break;
               case '-':
                  substract(stack);
                  break;
               case '*':
                  multiply(stack);
                  break;
               case '/':
                  divide(stack);
                  break;
            }
         }
      }
   }while (!finCadena);
}
