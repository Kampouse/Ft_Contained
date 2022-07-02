
#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>
#include <cstddef>
#include "./Iterator.hpp"

namespace Ft  {
template <class  T, typename Alloc = std::allocator<T> > 
class vector {


	public:
		typedef T												value_type;
		typedef Alloc											allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename allocator_type::size_type				size_type;
		typedef typename allocator_type::difference_type		difference_type;
		// iterator  traits
		typedef Ft::random_iterator<Ft::random_access_iterator_tag, value_type > iterator;
		typedef Ft::random_iterator<Ft::random_access_iterator_tag, value_type > const_iterator;
		vector(const vector &other);
	size_t 	capacity(void){return(this->_capacity);}
		iterator begin() {return iterator(this->_start);}
		void clear()
	{
		while(this->_start !=  this->_end )
		{
			this->_alloc.destroy(--this->_end);
		}
	}
		vector &operator=(const vector &other);
		size_t  size() const;
		size_t  capacity() const;
		bool empty() const;
		
	//allocator_type mean  come from Alloc  Typdef
	explicit  vector (const allocator_type &allocator = allocator_type()): _size(0),_capacity(0),_data(NULL)
	,_start(NULL),_end(NULL), _alloc(allocator){} 
	explicit vector(size_t n ,const value_type& val =  value_type(), const allocator_type &allocator = allocator_type()):_size (n),_capacity(n),_data(NULL),_alloc(allocator)
	{
		_start  = _alloc.allocate(_capacity);
		_data = _start;
		_end = _start;
		for (size_t i = 0; i < _size; i++)
		{
			_alloc.construct(_end++, val);
		}
	} 
	~vector()
	{
		this->clear();
		 //  should thi be with end   otherway?
		this->_alloc.deallocate(this->_start,this->capacity());
	}
	private:
		size_t  _size;
		size_t  _capacity;
		value_type  *_data;
		pointer   _start;
		pointer   _end;
		Alloc _alloc;
		void push_back(const value_type  &value);
		void reserve (size_t  n);
	protected:
	
	 
	
  
};




}; 

#endif // VECTOR_HPP


