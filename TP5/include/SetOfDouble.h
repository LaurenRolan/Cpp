/** -*- mode: c++ -*-
 * @file   SetOfDouble.h
 * @author Sebastien Fourey
 *
 * @brief Declaration of the class SetOfDouble
 *
 */
#ifndef SETOFDOUBLE_H
#define SETOFDOUBLE_H

#include <iostream>
#include <ostream>
using namespace std;

class SetOfDouble {

public:
  SetOfDouble();
  inline SetOfDouble(double x);
  ~SetOfDouble();

  inline bool isEmpty();

  std::ostream & flush(std::ostream & out) const;

  bool contains(double x) const;

  bool isSubsetOf(const SetOfDouble & other) const;

  void insert(double x);

  void remove(double x);

  void insertInto(SetOfDouble & other) const;

  void removeFrom(SetOfDouble & other) const;

  SetOfDouble & operator=(const SetOfDouble & other);

  SetOfDouble(const SetOfDouble & other);

private:
  class Node {
  public:
    Node(double value, Node * next = nullptr);
    ~Node();
    double getValue() const;
    Node * getNext() const;
    void setNext(Node * next);

  private:
    double value;
    Node * next;
  };

  Node * list;

  static Node * remove(Node * list, double x);
};

std::ostream & operator<<(std::ostream & out, const SetOfDouble & s);

SetOfDouble singleton(double x)
{
  SetOfDouble n(x);
  return n;
}

SetOfDouble emptySet()
{
  SetOfDouble n;
  return n;
}

//Outsiders functions
bool equals(const SetOfDouble & a, const SetOfDouble & b)
{
	if(a.isSubsetOf(b) && b.isSubsetOf(a))
	{
		return true;
	}
	return false;
}
bool operator==(const SetOfDouble & a, const SetOfDouble & b)
{
	if(a.isSubsetOf(b) && b.isSubsetOf(a))
	{
		return true;
	}
	return false;
}
bool operator<(const SetOfDouble & a, const SetOfDouble & b)
{
	if(a.isSubsetOf(b) && b.isSubsetOf(a)) {
		return false;
	} 
	if(b.isSubsetOf(a)) {
		return true;
	} 
	return false;
}
bool operator>(const SetOfDouble & a, const SetOfDouble & b)
{
	if(a.isSubsetOf(b) && b.isSubsetOf(a)) {
		return false;
	} 
	if(a.isSubsetOf(b)) {
		return true;
	} 
	return false;
}

SetOfDouble set_union(const SetOfDouble & a, const SetOfDouble & b);
SetOfDouble operator+(const SetOfDouble & a, const SetOfDouble & b);
SetOfDouble operator|(const SetOfDouble & a, const SetOfDouble & b);

SetOfDouble difference(const SetOfDouble & a, const SetOfDouble & b);
SetOfDouble operator-(const SetOfDouble & a, const SetOfDouble & b);

SetOfDouble symmetricDifference(const SetOfDouble & a, const SetOfDouble & b);
SetOfDouble operator^(const SetOfDouble & a, const SetOfDouble & b);

SetOfDouble intersection(const SetOfDouble & a, const SetOfDouble & b);
SetOfDouble operator&(const SetOfDouble & a, const SetOfDouble & b);


//Node functions
SetOfDouble::Node::Node(double value, Node * next)
{
	this->value = value;
	this->next = next;
}
SetOfDouble::Node::~Node()
{
	delete next;
}
double SetOfDouble::Node::getValue() const
{
	return this->value;
}
SetOfDouble::Node * SetOfDouble::Node::getNext() const
{
	return this->next;
}
void SetOfDouble::Node::setNext(Node * next)
{
	this->next = next;
}

//SetOfDouble functions
SetOfDouble::SetOfDouble()
{
  list = nullptr;
}

SetOfDouble::SetOfDouble(double x)
{
  list = new SetOfDouble::Node(x);
}

SetOfDouble::SetOfDouble(const SetOfDouble & other)
{
  this->list = other.list;
}

SetOfDouble::~SetOfDouble()
{
  delete list;
}

bool SetOfDouble::isEmpty()
{
  if(list) {  
    return true;
  }
  return false;

}

bool SetOfDouble::contains(double x) const
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

bool SetOfDouble::isSubsetOf(const SetOfDouble & other) const
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

void SetOfDouble::insert(double x)
{
	if(!this->list)
	{
		this->list = new Node(x, nullptr);
	}
	Node * current = this->list;
	Node * before = nullptr;
	while(current)
	{
		if(current->getValue() > x)
		{
			Node * temp = new Node(x, current);
			if(before)
			{
				before->setNext(temp);
			} else {
				this->list = temp;
			}
			return;
		}
		before = current;
		current = current->getNext();
	}
	before->setNext(new Node(x, nullptr));
}

void SetOfDouble::remove(double x)
{
	if(!this->list)
	{
		cout << "!!!No objects in list.\n";
		return;
	}
	Node * current = this->list;
	Node * before = nullptr;
	while(current)
	{
		if(current->getValue() == x)
		{
			if(before)
			{
				before->setNext(current->getNext());
			} else {
				this->list = current->getNext();
			}
			current->setNext(nullptr);
			delete current;
			return;
		}
		before = current;
		current = current->getNext();
	}
	cout << "!!!No match in list.\n";
}


void SetOfDouble::insertInto(SetOfDouble & other) const
{
	Node * current = this->list;
	while(current)
	{
		other.insert(current->getValue());
		current = current->getNext();
	}
}

void SetOfDouble::removeFrom(SetOfDouble & other) const
{
	Node * current = this->list;
	while(current)
	{
		other.remove(current->getValue());
		current = current->getNext();
	}
}

SetOfDouble & SetOfDouble::operator=(const SetOfDouble & other)
{
	if(this == &other)
	{
		return *this;
	}
	this->list = other.list;
	return *this;
}

std::ostream & SetOfDouble::flush(std::ostream & out) const
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

#endif // SETOFDOUBLE_H
