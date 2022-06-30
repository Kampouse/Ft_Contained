
#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>


namespace Ft  {



template <class  T, typename Alloc = std::allocator<T> > 
class vector{


	public:
		typedef T												value_type;

		typedef Alloc											allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename allocator_type::size_type				size_type;
		typedef typename allocator_type::difference_type		difference_type;

		vector(unsigned long n);
		vector(const vector &other);
		~vector()
	{
		_alloc.deallocate(_start, _end - _start); 

		
	};
		vector &operator=(const vector &other);
		unsigned long size() const;
		unsigned long capacity() const;
		bool empty() const;
	//allocator_type mean  come from Alloc  Typdef
	explicit  vector (const allocator_type &allocator = allocator_type()): _size(0),_capacity(0),_data(nullptr),_alloc(allocator){} 


	private:
		unsigned long _size;
		unsigned long _capacity;
		T *_data;
		pointer   _start;
		pointer   _end;
		Alloc _alloc;
		void push_back(const T &value);
		void reserve (unsigned long n);
	protected:
	
	 
	

};





}; 

#endif // VECTOR_HPP


