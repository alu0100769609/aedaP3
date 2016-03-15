#include <iostream>

template <class TDATO>
class Node {
private:
   TDATO element_;                     //Item
   Node* next_;                        //Pointer

public:
   Node(TDATO element);                //Constructor with element
   ~Node();                            //Destructor
   void setNext(Node* next);           //Set pointer to the next
   Node* getNext(void);                //Get pointer of the next
   void setElement(TDATO element);     //Set node item
   TDATO getElement(void);             //Get node item
};

////////////////////////////Methods////////////////////////////

template <class TDATO>
Node<TDATO>::Node(TDATO element) {
   setElement(element);
   setNext(NULL);
}

template <class TDATO>
Node<TDATO>::~Node() {

}

template <class TDATO>
void Node<TDATO>::setNext(Node* next) {
   next_= next;
}

template <class TDATO>
Node<TDATO>* Node<TDATO>::getNext(void) {
   return next_;
}

template <class TDATO>
void Node<TDATO>::setElement(TDATO element) {
   element_ = element;
}

template <class TDATO>
TDATO Node<TDATO>::getElement(void) {
   return element_;
}
