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


<template T> Set<T>::Set() 
{

}
<template T> Set<T>::Set(T x)
{

}
<template T> Set<T>::~Set()
{

}

<template T> bool Set<T>::isEmpty()
{

}
<template T> std::ostream & Set<T>::flush(std::ostream & out) const
{

}

<template T> bool Set<T>::contains(T x) const
{

}

<template T> bool Set<T>::isSubsetOf(const Set<T> & other) const
{

}

<template T> void Set<T>::insert(T x)
{

}
<template T> void Set<T>::remove(T x)
{

}
<template T> void Set<T>::insertInto(Set<T> & other) const
{

}
<template T> void Set<T>::removeFrom(Set<T> & other) const
{

}
<template T> Set<T> & Set<T>::operator=(const Set & other)
{

}
<template T> Set<T>::Set(const Set<T> & other)
{

}

<template T> Set<T>::Node * Set<T>::remove(Set<T>::Node * list, T x)
{

}
#endif