#include <iostream>

template <class T>
class Node {
public:
  Node(T invalue)
    : m_Value(invalue), m_Next(0) { }
  ~Node();
  T getValue() const { return m_Value; }
  void setValue(T value) { m_Value = value; }
  Node<T>* getNext() const { return m_Next; } 
  void setNext(Node<T>* next) { m_Next = next; }
private:
  T m_Value;
  Node<T>* m_Next;
};

template <class T>
Node<T>::~Node() {
  //cout << m_Value.toSring() << " deleted" << endl;
  if (m_Next) {
    delete m_Next; // put links to 0
  }
}

template <class T>
class Stack {
public:
  Stack()
    : m_Head(0), m_Count(0) { }
  ~Stack() { delete m_Head; }
  void push(const T& t);
  T pop();
  T pop() const;
  int count() const;
private:
  Node<T>* m_Head;
  int m_Count;
};

template <class T>
void Stack<T>::push(const T& value) {
  Node<T>* newNode = new Node<T>(value);
  newNode->setNext(m_Head);
  m_Head = newNode;
  ++m_Count;
}

template <class T>
T Stack<T>::pop() {
  Node<T>* popped = m_Head;
  if (m_Head != 0) {
    m_Head = m_Head->getNext();
    T retval = popped->getValue();
    popped->setNext(0);
    delete popped;
    --m_Count;
    return retval;
  }
  return 0;
}

template <class T>
int Stack<T>::count() const {
  return m_Count;
}

