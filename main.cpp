#include <iostream> 
#include <vector> 
#include "./Vector.hpp"

int print_vector(std::vector<int>vec) 
{
	for (unsigned long i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}

int main(void)
{
	//Ft::vector<int> simple = 	 Ft::vector<int>();
//there implementation  
{
	std::vector<int> nothing_vector;
	Ft::vector<int> nothing_vector_;
}
{
	std::vector<int> nothing_vector(10);
	Ft::vector<int> nothing_vector_(10);
}
{
	std::vector<int> nothing_vector(10);
	std::vector<int>::iterator it = nothing_vector.begin();
	Ft::vector<int> nothing_vector_(10);
	Ft::vector<int>::iterator it_ = nothing_vector_.begin();
	(void)it;
	(void)it_;
std::cout << "dereferencing it: " << *it << std::endl;
std::cout << "dereferencing it_ " << *it_ << std::endl;
}



}
