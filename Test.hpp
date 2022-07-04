#ifndef TEST_HPP
#define TEST_HPP
#include  <iostream>






template<template <typename... Args> class Container,typename... Types >
class Test
{
    public:
    Container<Types...> mine;
	std::vector <Types...> real;
	typename Container<Types...>::iterator it;
	void push_back(Types... args)
	{
		mine.push_back(args...);
		real.push_back(args...);
			std::cout << *this;
	}

};

















template<typename T>
std::ostream &operator<<(std::ostream &os, Test<Ft::vector, T  > &test)
{

	std::cout << "there: "  << "size: " << test.real.size() << " " <<  "capacity: " << test.real.capacity()   << std::endl ;
	for (typename std::vector<T>::iterator it = test.real.begin(); it != test.real.end(); it++)
	{
		os << *it << " "; 
	}
	os << std::endl;
	std::cout<< "-----------------------" << std::endl;
	std::cout << "mine: "  << "size: " << test.mine.size() << " " <<  "capacity: " << test.mine.capacity()   << std::endl ;
	for (typename Ft::vector<T>::iterator it = test.mine.begin(); it != test.mine.end(); it++)
	{
		os << *it << " ";
	}
	return os;
}

#endif

