#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>
#include <cstddef>

namespace Ft {

// iterator trait

// iterator tag  trait
//
class random_access_iterator_tag {};
class forward_iterator_tag {};
class bidirectional_iterator_tag {};
class output_iterator_tag {};
class input_iterator_tag {};


template <bool is_valid, typename T>
	struct valid_iterator_tag_res { typedef  T type;const static  bool value = is_valid;};
	

template <typename T>
	struct is_input_interator_tagged : public valid_iterator_tag_res< false , T>{ }; 

template <>
	struct is_input_interator_tagged<Ft::random_access_iterator_tag> :
		public valid_iterator_tag_res<true , Ft::random_access_iterator_tag >{ }; 

template <>
	struct is_input_interator_tagged<Ft::bidirectional_iterator_tag> :
		public valid_iterator_tag_res<true , Ft::bidirectional_iterator_tag >{ }; 

template <>
	struct is_input_interator_tagged<Ft::forward_iterator_tag> :
		public valid_iterator_tag_res<true , Ft::forward_iterator_tag>{ }; 

template <>
	struct is_input_interator_tagged<Ft::output_iterator_tag> :
		public valid_iterator_tag_res<true , Ft::output_iterator_tag>{ };

template <>
	struct is_input_interator_tagged<Ft::input_iterator_tag> :
		public valid_iterator_tag_res<true , Ft::input_iterator_tag>{ };





// iterator validation if its a ft one or not 
 template <typename T>
	struct  is_ft_iterator_tagged_res: public valid_iterator_tag_res< false , T>{ };

 template <>
	struct is_ft_iterator_tagged_res<Ft::random_access_iterator_tag> :
		public valid_iterator_tag_res<true , Ft::random_access_iterator_tag >{ };

	 template <>
	struct is_ft_iterator_tagged_res<Ft::bidirectional_iterator_tag> :
		public valid_iterator_tag_res<true , Ft::bidirectional_iterator_tag >{ };
	
	 template <>
	struct is_ft_iterator_tagged_res<Ft::forward_iterator_tag> :
		public valid_iterator_tag_res<true , Ft::forward_iterator_tag>{ };
	
	 template <>
	struct is_ft_iterator_tagged_res<Ft::output_iterator_tag> :
		public valid_iterator_tag_res<true , Ft::output_iterator_tag>{ };
	
	 template <>
	struct is_ft_iterator_tagged_res<Ft::input_iterator_tag> :
		public valid_iterator_tag_res<true , Ft::input_iterator_tag>{ };


template <class Iterator>
class iterator_traits {
public:

  typedef typename Iterator::value_type value_type;
  typedef typename Iterator::difference_type difference_type;
  typedef typename Iterator::pointer pointer;
  typedef typename Iterator::reference reference;
  typedef typename Ft::random_access_iterator_tag  iterator_category;
};



template <class T> class iterator_traits<T *> {

  public:
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;
	typedef T *pointer;
	typedef T &reference;
	typedef Ft::random_access_iterator_tag iterator_category;
};



template <class InputIterator>
	typename iterator_traits<InputIterator>::difference_type
	distance(InputIterator first, InputIterator last) {
		typedef typename iterator_traits<InputIterator>::difference_type difference_type;
		difference_type n = 0;
		while (first != last) {
			++first;
			++n;
		}
		return n;
	}

template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T&>
class iterator {
  public:
	typedef Category iterator_category;
	typedef T value_type;
	typedef Distance difference_type;
	typedef Pointer pointer;
	typedef Reference reference;
};

template <class T> 
class bidirectional_iterator  :	iterator<Ft::bidirectional_iterator_tag, T>  
{
typedef typename iterator<Ft::bidirectional_iterator_tag, T>::iterator_category iterator_category;
	typedef typename iterator<Ft::bidirectional_iterator_tag, T>::value_type value_type;
	typedef typename iterator<Ft::bidirectional_iterator_tag, T>::difference_type difference_type;
	typedef typename iterator<Ft::bidirectional_iterator_tag, T>::pointer pointer;
	typedef typename iterator<Ft::bidirectional_iterator_tag, T>::reference reference;
	private: 
			pointer ptr;
};


template <class T> class iterator_traits<const T *> {
  public:
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;
	typedef const T *pointer;
	typedef const T &reference;
	typedef Ft::random_access_iterator_tag iterator_category;
};


template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
class random_iterator {
public:
  typedef T value_type;
  typedef Distance difference_type;
  typedef Pointer pointer;
  typedef Reference reference;
  typedef Category iterator_category;
  pointer _ptr;
  random_iterator() : _ptr(NULL) {}
  random_iterator(pointer ptr) : _ptr(ptr) {}
  //iterator(const iterator &other) { return other; }
  //iterator( iterator &other){return other;}
  //iterator &operator=(const iterator &other) { (void)other ;return *this;  }
  reference operator*() { return *_ptr; }
  pointer operator->() { return _ptr; }
  random_iterator &operator++() { ++_ptr; return *this; }
  random_iterator operator++(int) { random_iterator tmp = *this; ++_ptr; return tmp; }
  random_iterator &operator--() { --_ptr; return *this; }
  random_iterator operator--(int) { random_iterator tmp = *this; --_ptr; return tmp; }
  random_iterator operator+(Distance n) { return random_iterator(_ptr + n); }
  random_iterator operator-(Distance n) { return random_iterator(_ptr - n); }
  random_iterator &operator+=(Distance n) { _ptr += n; return *this; }
  random_iterator &operator-=(Distance n) { _ptr -= n; return *this; }
  bool operator==(const random_iterator &other) { return _ptr == other._ptr; }
  bool operator!=(const random_iterator &other) { return _ptr != other._ptr; }
  bool operator<(const random_iterator &other) { return _ptr < other._ptr; }
  bool operator>(const random_iterator &other) { return _ptr > other._ptr; }
  bool operator<=(const random_iterator &other) { return _ptr <= other._ptr; }
  bool operator>=(const random_iterator &other) { return _ptr >= other._ptr; }
};


}; // namespace Ft
#endif
