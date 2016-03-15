#include "Node.hpp"

template <class TDATO>
class Stack {
private:
   Node<TDATO>* first_;                         //Pointer to the first element
public:
   Stack(void);                                 //Constructor
   ~Stack(void);                                //Destructor
   bool empty(void);                            //Check if empty stack
   void setFirst(Node<TDATO>* first);           //Set pointer to the first node
   Node<TDATO>* getFirst(void);                 //Get pointer to the first element
   void setHead(TDATO element);                 //Set element from head
   void deleteHead(void);                       //Delete node from head
   void printItems(void);                       //Print the stack of elements
};

////////////////////////////Methods////////////////////////////

template <class TDATO>
Stack<TDATO>::Stack(void) {
   setFirst(NULL);
}

template <class TDATO>
Stack<TDATO>::~Stack(void) {

}

template <class TDATO>
bool Stack<TDATO>::empty(void) {
   return (first_ == NULL);
}

template <class TDATO>
void Stack<TDATO>::setFirst(Node<TDATO>* first) {
   first_ = first;
}

template <class TDATO>
Node<TDATO>* Stack<TDATO>::getFirst(void) {
   return first_;
}

template <class TDATO>
void Stack<TDATO>::setHead(TDATO element) {
   Node<TDATO>* aux = new Node<TDATO>(element); //Creating Node with data
   if (empty()) {                               //If stack is empty
      setFirst(aux);                            //First node = aux
   }
   else {                                       //If stack is not empty
      aux->setNext(getFirst());                 //Set next of aux to 1st element
      setFirst(aux);                            // and change 1st element to aux
   }
}

template <class TDATO>
void Stack<TDATO>::deleteHead(void) {
   if (empty())
      std::cout << "Empty stack, nothing deleted" << std::endl;
   else {
      if (getFirst()->getNext() == NULL) {      //If only one element
         Node<TDATO>* aux = getFirst();         //Create aux pointer to first
         setFirst(NULL);                        //Set first = null
         delete aux;                            //Delete node
      }
      else {                                    //If more than one element
         Node<TDATO>* aux = getFirst();         //Create aux pointer to first
         setFirst(aux->getNext());              //Set first = 2nd element
         delete aux;                            //Delete node (old first)
      }
   }
}

template <class TDATO>
void Stack<TDATO>::printItems(void) {
   if (empty())
      std::cout << "The stack is empty" << std::endl;
   else {
      Node<TDATO>* aux = getFirst();            //Create aux pointer to first
      do{
         std::cout << aux->getElement() << " "; //Print item of stack
         aux = aux->getNext();                  //Iterate to the next
      } while (aux != NULL);                    //While no end of stack
      std::cout << "\n";
   }
}
