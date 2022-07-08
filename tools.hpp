#ifndef TOOLS_HPP
#define TOOLS_HPP
#include <iostream>


static class  nullptr_t {
public:
	template<typename T>
	operator T*() const {return nullptr;}
template<class C, class T >
	operator T C::*() const { return nullptr;}

private:
void operator&() const;
} u_nullptr{};

namespace  Ft {

	template  <bool Cond , typename T = void> struct enable_if {};
	template  <typename T> struct enable_if<true, T> { typedef T type; };


		template <bool is_integral, typename T> struct is_integral_helper {
			typedef T type;
			static const bool value = is_integral;
		};  


		template <typename> 
		struct is_integral_type : public is_integral_helper<false,bool> {};

		template <>
		struct is_integral_type<bool> : public is_integral_helper<true,bool> {};
		
		template <>
		struct is_integral_type<char> : public is_integral_helper<true,char> {};
			
		template <>
		struct is_integral_type<signed char> : public is_integral_helper<true,signed char> {};
		
		template <>
		struct is_integral_type<short int> : public is_integral_helper<true,short int> {};
		
		template <>
		struct is_integral_type<int> : public is_integral_helper<true,int> {};

		template <>
		struct is_integral_type<long int > : public is_integral_helper<true,long int> {};
			
		template <>
		struct is_integral_type<long long int > : public is_integral_helper<true,long long int> {};

		template <>
		struct is_integral_type<unsigned long int> : public is_integral_helper<true,unsigned long int> {};
		
		template <>
		struct is_integral_type<unsigned long long int> : public is_integral_helper<true,unsigned long long int > {};

		template <>
		struct is_integral_type<unsigned short int> : public is_integral_helper<true,unsigned short int> {};
									
		template <>
		struct is_integral_type<unsigned int> : public is_integral_helper<true,unsigned int> {};

		template <>
		struct is_integral_type<unsigned char> : public is_integral_helper<true,unsigned char> {};

		template <> 
		struct is_integral_type<wchar_t> : public is_integral_helper<true,wchar_t> {};

		template <>
		struct is_integral_type<char16_t> : public is_integral_helper<true,char16_t> {};
		
		template <>
		struct is_integral_type<char32_t> : public is_integral_helper<true,char32_t> {};



		template <typename T> 
			struct is_integral  : public is_integral_type<T> {};

}
