#include "./Vector.hpp"
#include <iostream>
#include <vector>
#define HEADER std

int print_vector(HEADER::vector<int> vec) {
  for (unsigned long i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
int main(void) {
  HEADER::vector<int> vec;
 HEADER::vector<int>::iterator it;
  vec.push_back(1);
  vec.push_back(1);
  vec.push_back(1);
  vec.push_back(1);
  vec.push_back(1);
  vec.reserve(100);
  it = vec.begin();
  it++;
  vec.insert(it , 5); 
	print_vector(vec);
}
/*
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
        std::vector<std::string> nothing_vector(10);
        Ft::vector<std::string> nothing_vector_(10);
        std::string hello = "hello";
        *(nothing_vector_.begin()) = hello;
        std::cout << *(nothing_vector_.begin());

}
{
        std::vector<int> nothing_vector(10);
        std::vector<int>::iterator it = nothing_vector.begin();
        it++;
        Ft::vector<int> nothing_vector_(10);
        Ft::vector<int>::iterator it_ = nothing_vector_.begin();
        (void)it;
        (void)it_;
        *it	  = 20;
        *it_  = 25;
        std::cout << "boring " << nothing_vector_[0];
        it_++;
        *it_  = 30;
        std::cout << "dereferencing it: " << *it << std::endl;
        it_--;
        std::cout << "dereferencing it_ " << *it_ << std::endl;
}
*/
