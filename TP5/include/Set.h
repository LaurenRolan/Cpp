/* Author: Lauren Sampaio
 * File: Obstacle.h
 */
#ifndef SET_H
#define SET_H

#include <iostream>
using namespace std;

template  <typename T> 
class Set {
public:
  Set();
  inline Set(T x);
  ~Set();

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

  static Node * remove(Node * list, T x);
};

template <typename T> std::ostream & operator<<(std::ostream & out, const Set<T> & s);
template <typename T> Set<T> singleton(T x);
template <typename T> Set<T> emptySet();

template <typename T> bool equals(const Set<T> & a, const Set<T> & b);
template <typename T> bool operator==(const Set<T> & a, const Set<T> & b);
template <typename T> bool operator<(const Set<T> & a, const Set<T> & b);
template <typename T> bool operator>(const Set<T> & a, const Set<T> & b);

template <typename T> Set<T> set_union(const Set<T> & a, const Set<T> & b);
template <typename T> Set<T> operator+(const Set<T> & a, const Set<T> & b);
template <typename T> Set<T> operator|(const Set<T> & a, const Set<T> & b);


template <typename T> Set<T> difference(const Set<T> & a, const Set<T> & b);
template <typename T> Set<T> operator-(const Set<T> & a, const Set<T> & b);


template <typename T> Set<T> symmetricDifference(const Set<T> & a, const Set<T> & b);
template <typename T> Set<T> operator^(const Set<T> & a, const Set<T> & b);

template <typename T> Set<T> intersection(const Set<T> & a, const Set<T> & b);
template <typename T> Set<T> operator&(const Set<T> & a, const Set<T> & b);


template <typename T> Set<T>::Set()
{
      list = nullptr;
}
template <typename T> Set<T>::Set(T x)
{
    list = new Set<T>::Node(x);
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
template <typename T> std::ostream & Set<T>::flush(std::ostream & out) const
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
    Node * comparison = other.list;
    while(comparison)
    {
      if(current->getValue() == comparison->getValue())
      {
        current = current->getNext();
        if(!current)
        {
          return true;
        }
      }
      comparison = comparison->getNext();
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

}

#endif
