#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>

namespace Ft {

// iterator trait

// iterator tag  trait
//
struct random_access_iterator_tag {};
struct forward_iterator_tag {};
struct bidirectional_iterator_tag {};
struct input_iterator_tag {};

template <class Iterator>
class iterator_traits {
public:

  typedef typename Iterator::value_type value_type;
  typedef typename Iterator::difference_type difference_type;
  typedef typename Iterator::pointer pointer;
  typedef typename Iterator::reference reference;
  typedef typename Ft::random_access_iterator_tag  iterator_category;
};
template <class T> class iterator_traits<T *> {};
template <class T> class iterator_traits<const T *> {};

// iterator class
template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
class iterator {
  typedef T value_type;
  typedef Distance difference_type;
  typedef Pointer pointer;
  typedef Reference reference;
  typedef Category iterator_category;
  pointer _ptr;
  iterator(const iterator &other) { return other; }
  iterator( iterator &other){return other;}
  iterator &operator=(const iterator &other) { (void)other ;return *this;  }
  reference operator*() { return *_ptr; }
};

}; // namespace Ft
#endif
