#include <iostream>
using namespace std;

template <class X>
class GenStack {
  public:
    GenStack();//default
    GenStack(int maxSize); //overload
    ~GenStack(); //destructor

    void push(char data);
    char pop();
    char peek();

    bool isFull();
    bool isEmpty();
    int getSize();
    
    void printStack(GenStack<char> stack);

    int top;
    int mSize;

    char *myArray;
};
// Template class for GenStack
template <class X>
GenStack<X>::GenStack(){
  myArray = new char[128]; //When you allocate memory dynamically, you have to do your own garbage collection.
  mSize = 128;
  top = -1;
}

template <class X>
GenStack<X>::GenStack(int maxSize) {
  myArray = new char[maxSize];
  mSize = maxSize;
  top = -1;
}
template <class X>
GenStack<X>::~GenStack(){
  delete myArray;
}
template <class X>
void GenStack<X>::push(char data) {
  //check if full before proceeding
  myArray[++top] = data;
}
template <class X>
char GenStack<X>::pop() {
  //check if empty before proceeding
  if(isEmpty()) {
    cout << "Error: Stack is empty and cannot perform pop() function." << endl;
    return '\0';
  }
  return myArray[top--];
}
template <class X>
char GenStack<X>::peek() {
  //check if empty before proceeding
  return myArray[top];
}
template <class X>
bool GenStack<X>::isFull() {
  return (top == mSize-1);
}
template <class X>
bool GenStack<X>::isEmpty() {
  return (top == -1);
}
template <class X>
int GenStack<X>::getSize() {
  return top + 1;
}
