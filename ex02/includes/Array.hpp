#pragma once

#include <cstddef>
#include <exception>
#include <iostream>
#include <ostream>
#include <sstream>
template<typename T>
class Array
{
  private:
    T *_array;
    unsigned int _size;

  public:
    Array();
    ~Array();
    Array(unsigned int n);
    Array(const Array &other);

    Array &operator=(const Array &other);
    T &operator[](unsigned int size) const;
    unsigned int size() const;

    // Custom exception

    class OutOfBoundsException: public std::exception
    {
      public:
        // Exception constructor
        OutOfBoundsException(int idx)
        {
          std::ostringstream oss;
          oss << "OutOfBoundException:: You tried to acces out of bound index: " << idx;
          _message = oss.str();
        }

        // Method to override
        virtual const char *what()const  throw();

        // Virtual destructor
        // We must declare this with the throw() at the end, because the std::exception destructor
        // has this syntax
        //  virtual ~exception() throw();
        //  The throw() at the end of a func declearation basically means the function won't throw
        //  any exception

        virtual ~OutOfBoundsException() throw() {}

      private:
        std::string _message;

    };
};

// The reason why we need Array<T> its because we're defining
// the class constructor outside of the class.

// Constructors

template<typename T>inline Array<T>::Array():_array(NULL),_size(0)
{

}

template<typename T>Array<T>::Array(unsigned int n):_array(new T[n]()),_size(n)
{

}

template<typename T>Array<T>::Array(const Array &other):_array(new T[other._size]),_size(other._size)
{
  for (unsigned int i = 0; i < other._size; i++)
    this->_array[i] = other._array[i];
}

 // Operators
 // Since We're defining the operator= overload outside of the class we need the Array<T> scope::
 // Steps are template<typename T>
 // Array<T>& since we're returning a reference
 // Array<T>:: Since we're outside of the class
 // then standard copy assignment operator syntax
 // first template-> return type -> Tclass name -> method/operator.

template<typename T>
Array<T>& Array<T>::operator=(const Array<T> &other)
{
  delete[] this->_array;
  this->_size = other._size;
  this->_array = new T[_size];

  for (unsigned int i = 0; i < _size; i++)
    this->_array[i] = other._array[i];
  return *this;
}

template <typename T> T& Array<T>::operator[](unsigned int idx) const
{
  if (idx >= this->_size)
    throw OutOfBoundsException(idx);
  else
    return *(this->_array + idx);
}

// Size method

template<typename T>unsigned int Array<T>::size() const
{
  return this->_size;
}

template<typename  T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
  return _message.c_str();
}


// Destructor

template<typename T>inline Array<T>::~Array()
{
  delete[] this->_array;
}
