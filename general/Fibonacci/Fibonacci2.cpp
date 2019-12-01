#include <type_traits>
#include <typeinfo>
#include <exception>
#include <iostream>

#include "quick_log2.hpp

/*
{{0, 1, 1},
	{ 1,1,2 },
	{ 2,3,5 },
	{ 13,21,34 },
	{ 610,987,1597 },
	{ 1346269,2178309,3524578 },
{ 6557470319842,10610209857723,17167680177565 }};
*/
//signed long long over is 92
//unsigned long long over is 93

//typedef unsigned long long  FibonacciMatrix_INTTYPE;
//ValueType 是如下内容之一
//long long (signed or unsigned)
//int32 (signed or unsigned)
//int16 (signed or unsigned)

template<typename ValueTupe>
class FibonacciMatrix {
public:
	ValueTupe n_d1;
	ValueTupe n_;
	ValueTupe n_a1;

	//返回不溢出的最大的n
	static constexpr int max_n_dec() {
		switch (sizeof(ValueTupe)) {
		case 64/8 :
			if (std::is_unsigned<ValueTupe>()) return 93;
			else return 92;
			break;
		case 32/8 :
			if (std::is_unsigned<ValueTupe>()) return 47;
			else return 46;
			break;
		case 16/8 : 
			if (std::is_unsigned<ValueTupe>()) return 24;
			else return 23;
			break;
		default:
			return 0;
			break;
		}
	}

	static constexpr int max_n = max_n_dec();
	static const FibonacciMatrix FibonacciMatrix_cache[];

	FibonacciMatrix operator*(const FibonacciMatrix& other) {
		FibonacciMatrix ret;
		ret.n_d1 = this->n_d1 * other.n_d1 + this->n_ * other.n_;
		ret.n_ = this->n_d1 * other.n_ + this->n_ * other.n_a1;
		ret.n_a1 = this->n_ * other.n_ + this->n_a1 * other.n_a1;
		return ret;
	}

 	ValueTupe operator[](int n){
		if(n<max_n_dec()){
			FibonacciMatrix ret = {1,0,1};
			while (n!=0) {
				int bit = n & (~n+1);
				int index = quick_logi32(bit);
				ret =ret*(FibonacciMatrix_cache[index]);
				n = n ^ bit;
			}
			return ret.n_;
		}
		return 0;
	}
};

template<typename ValueTupe>
const FibonacciMatrix<ValueTupe> FibonacciMatrix<ValueTupe>::FibonacciMatrix_cache[] = { 
	{0, 1, 1},
	{ 1,1,2 },
	{ 2,3,5 },
	{ 13,21,34 },
	{ 610,987,1597 },
	{ 1346269,2178309,3524578 },
	{ 6557470319842,10610209857723,17167680177565 }
};


typedef FibonacciMatrix<long long> Fibonacci;
 
#ifndef MAIN
#define MAIN FIBONACCI2_CPP
int main(){
	Fibonacci f;
	std::cout<<f[1]<<std::endl;
	std::cout<<f[2]<<std::endl;
	std::cout<<f[3]<<std::endl;
	std::cout<<f[4]<<std::endl;
	std::cout<<f[5]<<std::endl;
	std::cout<<f[6]<<std::endl;
	return 0;
}
#endif
