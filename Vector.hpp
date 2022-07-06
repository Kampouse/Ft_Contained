
#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "./Iterator.hpp"
#include <cstddef>
#include <iostream>

namespace Ft {
template <class T, typename Alloc = std::allocator<T> > class vector {

public:
  typedef T value_type;
  typedef Alloc allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef typename allocator_type::size_type size_type;
  typedef typename allocator_type::difference_type difference_type;
  // iterator  traits
  typedef Ft::random_iterator<Ft::random_access_iterator_tag, value_type >
      iterator;
  typedef Ft::random_iterator<Ft::random_access_iterator_tag, value_type >
      const_iterator;
  vector(const vector &other);
  size_t capacity(void) { return (this->_capacity); }
  iterator begin() { return iterator(this->_start); }
  // should ths return the end of capacity
  iterator end() { return iterator(this->_end); }
  
  vector &operator=(const vector &other);

  size_type size() const { return this->_end - this->_start; }
 bool empty() const {return size() == 0 ? true:false;}
  size_type max_size() const { return this->_alloc.max_size(); }

void clear() {
    while (this->_start != this->_end)
      this->_alloc.destroy(--this->_end);
  }
iterator insert(iterator position, const value_type &val) 
{
	(void)val;

	size_type pos = &(*position) - _start;
	if(size_type(_end - _start)  >= this->size() + 1 )
		{
			for (size_type i = _end - _start - 1; i >= pos; i--)
			{
						_alloc.construct(_end + 1, _start[i]);
			}
			this->_alloc.construct(_end, *position);
		}
}
iterator  erase(iterator begin) 
{
	std::cout << " erase() " << std::endl;
	pointer  pos = &(*begin);
	_alloc.destroy(pos);
	if( &(*begin) + 1 == _end)
			_alloc.destroy( &(*begin) + 1);
	else
	{
		for (int i = 0; i < _end - &(*begin) - 1; i++)
		{
			_alloc.construct(&(*begin) + i, *(&(*begin) + i + 1));
			_alloc.destroy(&(*begin) + i + 1);
		}
		_end -=1;
	}
	return iterator(pos);
}
iterator  erase(iterator begin,iterator end ) 
{
	pointer  pos = &(*begin); 
	for (int i = 0; i <  &(*end) - &(*begin); i++)
		_alloc.destroy(&(*begin) + i);
	for (int i = 0; i < _end - &(*end) - 1; i++)
		{
			_alloc.construct(&(*begin) + i, *(&(*begin) + i + 1));
			_alloc.destroy(&(*begin) + i + 1);
		}
	_end -= &(*end) - &(*begin);
	return iterator(pos);
}

  size_t capacity() const;
  explicit vector(const allocator_type &allocator = allocator_type())
      : _size(0), _capacity(0), _data(NULL), _start(NULL), _end(NULL),
        _end_capacity(NULL), _alloc(allocator) {}
  explicit vector(size_t n, const value_type &val = value_type(),
                  const allocator_type &allocator = allocator_type())
      : _size(n), _capacity(n), _data(NULL), _alloc(allocator) {
    _start = _alloc.allocate(_capacity);
    _data = _start;
    _end_capacity = _start;
    _end = _start;
    for (size_t i = 0; i < _size; i++) {
      _alloc.construct(_end_capacity++, val);
    }

  }
	void pop_back(void)
	{
		_alloc.destroy(&this->back());
		this->_end--;
	}
  reference operator[](size_type n) { return *(_start + n); }
  reference front () { return *_start; }
  value_type* data() { return _start; };
  value_type* data() const { return _start; };
  reference back() { return *(_end - 1);}
  const_reference operator[](size_type n) const { return *(_start + n); }

  reference at(size_type n) {
    if (n >= size() ) {
      throw std::out_of_range("out of range");
    }
    return *(_start + n);
  }
  const_reference at(size_type n) const {
	if (n >= size() ) {
      throw std::out_of_range("out of range");
    }
    return *(_start + n);
  }


  void push_back(const value_type &value) 
{
	if(_end == _end_capacity)
	{
		int next_capacity = (this->size() > 0) ? (int)(this->size() * 2) : 1;
		this->reserve(next_capacity);
		_capacity = next_capacity;
	}
	_alloc.construct(_end, value);
	_end++;
	_size = this->size();
}
  void reserve(size_type n)
	{
    if (n > this->max_size())
      throw std::length_error("length error");
    if (this->capacity() >= n)
      return;
	  	pointer new_container = _alloc.allocate(n);
		pointer new_end = new_container;
		pointer first = _start;
		while(_start != _end)
		{
			_alloc.construct(new_end++, *_start);
			_alloc.destroy(_start++);
		}
		_alloc.deallocate(first, this->size());
		_start = new_container;
		_end = new_end;
		_end_capacity = new_container + n;
		_capacity = n;
		_size = this->size();
	}

  ~vector() {
    this->clearing();
    this->_alloc.deallocate(this->_start, this->capacity());
  }

	 void resize(size_t n) 
	{
		if(n > this->max_size())
		{
			throw (std::length_error("too long"));
		}
		else if (n < this->size())
		{
			while(this->size() > n)
			{
					--_end; 
					_alloc.destroy(_end);
			}
		}
		else
		{
			while(this->size() < n)
			{
				 _alloc.construct(_end);
				_end++;

			}
		}		
	}

	 void resize(size_t n, const value_type &val)
	 {
		if(n > this->max_size())
				{
					throw (std::length_error("too long"));
				}
				else if (n < this->size())
				{
					while(this->size() > n)
					{
							--_end; 
							_alloc.destroy(_end);
					}
				}
				else
				{
					while(this->size() < n)
					{
						_alloc.construct(_end,val);
						_end++;
					}
				}
	 }

	  allocator_type get_allocator() const { return _alloc; }

	void assign( size_type count, const value_type& value )
	{


	}
	 void print_vector()
	{
	iterator it = _start;
		while(it != end())
		{
			std::cout << *it << " " << std::endl;
			++it;
		}
	}
private:
  size_t _size;
  size_t _capacity;
  value_type *_data;
  pointer _start;
  pointer _end;
  pointer _end_capacity;
  Alloc _alloc;

void clearing() {
    while (this->_start != this->_end_capacity)
      this->_alloc.destroy(--this->_end_capacity);
  }


protected:
};

}; // namespace Ft

#endif // VECTOR_HPP
