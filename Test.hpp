#ifndef TEST_HPP
#define TEST_HPP
#include  <iostream>
#include "assert.h" 
#include  "Vector.hpp"

template<class T>

class Test
{
    public:
    Ft::vector 	<T> mine;


	std::vector <T> real;
	void push_back( T args)
	{
		mine.push_back(args);
		real.push_back(args);
		std::cout << *this;
		std::cout << "<< -- add_back()-->>" << std::endl; 
	}
	void size(void)
	{
		std::cout << "size()" << std::endl;  
		std::cout << "mine size:-> " << mine.size() << std::endl;
		std::cout << "real size:-> " << real.size() << std::endl;
		assert(mine.size() == real.size());
	}
	void max_size(void)
	{
		std::cout << "mine max_size: " << std::endl;
		std::cout << "mine size:-> " << mine.max_size() << std::endl;
		std::cout << "real size:-> " << real.max_size() << std::endl;
		assert(mine.max_size() == real.max_size());
	}
	void empty(void)
	{
		std::cout << "empty()" << std::endl;
		std::cout << "mine size:-> " << mine.empty() << std::endl;
		std::cout << "real size:-> " << real.empty() << std::endl;
		assert(mine.empty() == real.empty());
	}
	void capacity(void)
	{
		std::cout << "capacity()" << std::endl;
		std::cout << "mine size:-> " << mine.capacity() << std::endl;
		std::cout << "real size:-> " << real.capacity() << std::endl;
		assert(mine.capacity() == real.capacity());

	}
	void reserve(std::size_t n  )
		{
			std::cout << "reserve()" << std::endl;
			mine.reserve(n);
			real.reserve(n);
			std::cout << "real size:-> " << real.capacity() << std::endl;
			std::cout << "mine size:-> " << mine.capacity() << std::endl;
			 assert(mine.capacity() == real.capacity ());



		}
};

template<typename T>
std::ostream &operator<<(std::ostream &os, Test<T> &test)
{
	std::cout << "|there: "  << "size: " << test.real.size() << " " <<  "capacity: " << test.real.capacity()   << std::endl ;
	for (typename std::vector<T>::iterator it = test.real.begin(); it != test.real.end(); it++)
	{
		os << " "  << *it << " ";
	}
	os << std::endl;
	std::cout<< "|-----------------------" << std::endl;
	std::cout << "|mine: "  << "size: " << test.mine.size() << " " <<  "capacity: " << test.mine.capacity()   << std::endl ;
	for (typename Ft::vector<T>::iterator it = test.mine.begin(); it != test.mine.end(); it++)
	{
		os << " "  << *it << " ";
	}
	os << std::endl;
	

	return os;
}

#endif

