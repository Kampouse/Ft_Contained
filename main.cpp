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
	Ft::vector<int> simple = 	 Ft::vector<int>();
	

}
