#ifndef TEST_HPP
#define TEST_HPP
#include  <iostream>
#include "assert.h" 
#include  "Vector.hpp"
#define  LOCATION   std::string(  std::string(__FILE__) + " Line: " +   std::to_string(__LINE__ ))  
template<class T>

class Test
{
    public:
    Ft::vector 	<T> mine;
	std::vector <T> real;
	std::vector<std::string> error;
	int asserted(bool status,std::string  message  )
	{
		if (status)
		{
			std::cout << "PASS: " << " " << message << std::endl;
			return (status); 
		}
		else
		{
			std::cout << "Fail: " << " " << message << std::endl;
			error.push_back(message);
			return (status);
		}
	}
	int compare(void) 
	{
			typename std::vector<T>::iterator iter_real = real.begin();
			typename Ft::vector<T>::iterator  iter = mine.begin();
			 int status = 1; 
			std::cout << "<<---compare()---->>" << std::endl; 
			while (iter != mine.end() && iter_real != real.end())
			{
				if (*iter != *iter_real)
				{
					std::cout << "Fail: " << " " << "self_compare" << std::endl;
					error.push_back("self_compare");
					status = 0;
					break;
				}
				iter++;
				iter_real++;
			}
			asserted (status, LOCATION );
			return (1);
	}

	void push_back( T args)
	{
		mine.push_back(args);
		real.push_back(args);
		std::cout << *this;
		std::cout << "<< -- add_back()-->>" << std::endl; 
	}
	void size(void)
	{
		std::cout << "<<---size()---->>" << std::endl; 
		if(asserted(mine.size() == real.size(),LOCATION ) == 0)
			{
				std::cout << "real size:-> " << real.empty() << std::endl;
				std::cout << "mine size:-> " << mine.empty() << std::endl;
			}
	}
	void max_size(void)
	{
		std::cout << "<<---max_size()---->>" << std::endl; 
		if(asserted(mine.max_size() == real.max_size(),LOCATION ) == 0)
			{
				std::cout << "real size:-> " << real.empty() << std::endl;
				std::cout << "mine size:-> " << mine.empty() << std::endl;
			}

	}
	void empty(void)
	{
		std::cout << "<<---empty()---->>" << std::endl; 
		if(asserted(mine.empty() == real.empty (),LOCATION ) == 0)
			{
				std::cout << "real size:-> " << real.empty() << std::endl;
				std::cout << "mine size:-> " << mine.empty() << std::endl;
			}
	}
	void capacity(void)
	{
		std::cout << "<<---capacity()---->>" << std::endl; 
		if(asserted(mine.capacity() == real.capacity(),LOCATION ) == 0)
		{
			std::cout << "real size:-> " << real.capacity() << std::endl;
			std::cout << "mine size:-> " << mine.capacity() << std::endl;
		}

	}
	void reserve(std::size_t n  )
		{
			std::cout << "<<---reserve()---->>" << std::endl; 
			mine.reserve(n);
			real.reserve(n);
			if(asserted( mine.capacity() == real.capacity (),LOCATION ) == 0)
			{
				std::cout << "real size:-> " << real.capacity() << std::endl;
				std::cout << "mine size:-> " << mine.capacity() << std::endl;

			}
		}

	void front(void)
		{

			std::cout << "<<---front()---->>" << std::endl; 
			if(asserted( mine.front() == real.front(),LOCATION ) == 0)
			{
				std::cout << "front():-> " << mine.front() << std::endl;
				std::cout << "real front():-> " << real.front() << std::endl;

			}
		}

	void back(void)
		{
			std::cout << "<<---back()---->>" << std::endl; 
			if(asserted( mine.back() == real.back(),LOCATION ) == 0)
			{
				std::cout << "back():-> " << mine.front() << std::endl;
				std::cout << "real back():-> " << real.front() << std::endl;
			}
		} 
	void resize(size_t n)
		{
			std::cout  << "<<---resize()---->>" << std::endl;
			real.resize(n);
			mine.resize(n);
			if(asserted(mine.size() == real.size(), LOCATION ) == 0)
			{
				std::cout << "real size:-> " << real.size() << std::endl;
				std::cout << "mine size:-> " << mine.size() << std::endl;
			}
		}
	void resize(size_t n,T value)
		{
			std::cout  << "<<---resize()---->>" << std::endl;
			real.resize(n,value);
			mine.resize(n,value);
			if(asserted(mine.size() == real.size(), LOCATION ) == 0 || compare() == 0)
			{
				std::cout << "real size:-> " << real.size() << std::endl;
				std::cout << "mine size:-> " << mine.size() << std::endl;
				std::cout << "real size:-> " << real.size() << std::endl;
				std::cout << "mine size:-> " << mine.size() << std::endl;
				std::cout << "real capacity:-> " << real.capacity() << std::endl;
				std::cout << "mine capacity:-> " << mine.capacity() << std::endl;
			}
			
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
	
	return (os);
}

#endif

