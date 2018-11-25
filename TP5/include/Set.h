/* Author: Lauren Sampaio
 * File: Obstacle.h
 */
#ifndef SET_H
#define SET_H

#include <iostream>
using namespace std;

template <typename T> class SetIter;
template  <typename T> class Set {
public:
  Set();
  inline Set(T x);
  ~Set();
  typedef SetIter<T> iterator;
  template  <typename U> friend class SetIter;
  iterator *createIterator( ) const;

  iterator begin()
  {
    iterator it;
    it.current = list;
    return it;
  }

  iterator end()
  {
      iterator it;
      it.current = last;
      return it;
  }

  inline bool isEmpty();
  std::ostream & flush(std::ostream & out) const;

  bool contains(T x) const;

  bool isSubsetOf(const Set<T> & other) const;

  void insert(T x);
  void remove(T x);
  void insertInto(Set<T> & other) const;
  void removeFrom(Set<T> & other) const;
  Set<T> & operator=(const Set & other);
  Set(const Set<T> & other);


private:
  class Node {
  public:
    Node(T value, Node * next = nullptr);
    ~Node();
    T getValue() const;
    Node * getNext() const;
    void setNext(Node * next);

  private:
    T value;
    Node * next;
  };

  Node * list;
  Node * last;
  static Node * remove(Node * list, T x);
};

template  <typename U>
class SetIter
{
public:
    template  <typename T> friend class Set;
private:
    typename Set<U>::Node *first;
    typename Set<U>::Node *current;
public:

    SetIter() { goFirst(); }
    void goFirst()
    {
        current = first;
    }
    SetIter & operator++()
    {
        current = current->getNext();
        return *this;
    }
    bool operator==( SetIter other)
    {
        return current == other.current;
    }
    bool operator!=( SetIter other)
    {
        return current != other.current;
    }
    bool isDone()
    {
        if( current->getNext())
        {
            return true;
        }
        return false;
    }
    const U operator*()
    {
        return current->getValue();
    }
};

template <typename T> class FunctionClass
{
public:
    FunctionClass() {}
    virtual T operator()( T x) = 0;
};

template <typename T> class Linear: public FunctionClass<T>
{
private:
    double _a;
    double _b;
public:
    Linear(double a, double b) { _a = a; _b = b;}
    T operator()( T x ) { return _a * x + _b; }
};

template <typename T>
Set<T> setImage(Set<T> & set, FunctionClass<T> & function)
{
    Set<T> result;
    typename Set<T>::iterator it;

    for(it = set.begin(); it != set.end(); ++it)
    {
        result.insert(function(*it));
    }
    return result;
}

template <typename U> SetIter<U> *Set<U>::createIterator() const
{
  return new SetIter<U>(this);
}

template <typename T> ostream & operator<<(ostream & out, const Set<T> & s)
{
    return s.flush(out);
}
template <typename T> Set<T> singleton(T x)
{
    Set<T> n(x);
    return n;
}
template <typename T> Set<T> emptySet()
{
    Set<T> n;
    return n;
}

template <typename T> bool equals(const Set<T> & a, const Set<T> & b)
{
    if(a.isSubsetOf(b) && b.isSubsetOf(a))
    {
            return true;
    }
    return false;
}
template <typename T> bool operator==(const Set<T> & a, const Set<T> & b)
{
    return equals(a, b);
}

template <typename T> bool operator<(const Set<T> & a, const Set<T> & b)
{
    if(a.isSubsetOf(b) && b.isSubsetOf(a)) {
            return false;
    }
    if(a.isSubsetOf(b)) {
            return true;
    }
    return false;
}
template <typename T> bool operator>(const Set<T> & a, const Set<T> & b)
{
    if(a.isSubsetOf(b) && b.isSubsetOf(a)) {
            return false;
    }
    if(b.isSubsetOf(a)) {
            return true;
    }
    return false;
}

template <typename T> Set<T> set_union(const Set<T> & a, const Set<T> & b)
{
    Set<T> result = a;
    b.insertInto(result);
    return result;
}
template <typename T> Set<T> operator+(const Set<T> & a, const Set<T> & b)
{
    return set_union(a, b);
}
template <typename T> Set<T> operator|(const Set<T> & a, const Set<T> & b)
{
    return set_union(a, b);
}

template <typename T> Set<T> difference(const Set<T> & a, const Set<T> & b)
{
    Set<T> result = a;
    b.removeFrom(result);
    return result;
}
template <typename T> Set<T> operator-(const Set<T> & a, const Set<T> & b)
{
    return difference(a, b);
}

template <typename T> Set<T> symmetricDifference(const Set<T> & a, const Set<T> & b)
{
    return (a - b) + (b - a);
}
template <typename T> Set<T> operator^(const Set<T> & a, const Set<T> & b)
{
    return symmetricDifference(a, b);
}

template <typename T> Set<T> intersection(const Set<T> & a, const Set<T> & b)
{
    return (a + b) - (a ^ b);
}
template <typename T> Set<T> operator&(const Set<T> & a, const Set<T> & b)
{
    return intersection(a, b);
}

template <typename T> Set<T>::Set()
{
      list = nullptr;
      last = nullptr;
}
template <typename T> Set<T>::Set(T x)
{
    list = new Set<T>::Node(x);
    last = list->getNext();
}
template <typename T> Set<T>::~Set()
{
    delete list;
}

template <typename T> bool Set<T>::isEmpty()
{
    if(list) {
      return true;
    }
    return false;
}
template <typename T> ostream & Set<T>::flush(std::ostream & out) const
{
    out << "{ ";
    for(Node * current = this->list; current; current = current->getNext())
    {
            out << current->getValue();
            if(current->getNext())
            {
                    out << ", ";
            }
    }
    out << " }\n";
    return out;
}

template <typename T> bool Set<T>::contains(T x) const
{
    Node * current = this->list;
    while(current)
    {
      if(current->getValue() == x)
      {
        return true;
      }
      current = current->getNext();
    };
    return false;
}

template <typename T> bool Set<T>::isSubsetOf(const Set<T> & other) const
{
    Node * current = this->list;
    while(current)
    {
      if(other.contains(current->getValue()))
      {
        current = current->getNext();
        if(!current)
        {
          return true;
        }
      }
      else {
          return false;
      }
    };
    return false;
}

template <typename T> void Set<T>::insert(T x)
{
    if(!this->list)
    {
            this->list = new Node(x, nullptr);
    }
    else
    {
        Node * new_head = new Node(x, this->list);
        this->list = new_head;
    }
}
template <typename T> void Set<T>::remove(T x)
{
    list = remove(list, x);
}
template <typename T> void Set<T>::insertInto(Set<T> & other) const
{
    Node * current = this->list;
    while(current)
    {
        if(other.contains(current->getValue()))
        {
           return;
        }
        other.insert(current->getValue());
        current = current->getNext();
    }
}
template <typename T> void Set<T>::removeFrom(Set<T> & other) const
{
    Node * current = this->list;
    while(current)
    {
        other.remove(current->getValue());
        current = current->getNext();
    }
}
template <typename T> Set<T> & Set<T>::operator=(const Set & other)
{
    if(this == &other)
    {
            return *this;
    }
    other.insertInto(*this);
    return *this;

}
template <typename T> Set<T>::Set(const Set<T> & other)
{
    if(other.list)
    {
        this->list = nullptr;
        other.insertInto(*this);
    } else {
        list = nullptr;
    }
}

template <typename T> typename Set<T>::Node * Set<T>::remove(Set<T>::Node * list, T x)
{
    if(!list)
    {
        return list;
    }
    Node * current = list;
    Node * before = nullptr;
    while(current)
    {
        if(current->getValue() == x)
        {
            if(before)
            {
                before->setNext(current->getNext());
            } else {
                list = current->getNext();
            }
            current->setNext(nullptr);
            delete current;
            return list;
        }
        before = current;
        current = current->getNext();
    }
    return list;
}

template <typename T> Set<T>::Node::Node(T value, Set<T>::Node * next)
{
        this->value = value;
        this->next = next;
}
template <typename T> Set<T>::Node::~Node()
{
        delete next;
}
template <typename T> T Set<T>::Node::getValue() const
{
        return this->value;
}
template <typename T> typename Set<T>::Node * Set<T>::Node::getNext() const
{
        return this->next;
}
template <typename T> void Set<T>::Node::setNext(Node * next)
{
        this->next = next;
}


#endif
