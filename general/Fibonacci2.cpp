#include <type_traits>
#include <typeinfo>
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

template<typename ValueTupe>
class FibonacciMatrix {
public:
	ValueTupe n_d1;
	ValueTupe n_;
	ValueTupe n_a1;

	constexpr int max_n_dec() {
		switch (sizeof(ValueTupe)) {
		case 64 :
			if (std::is_unsigned<ValueTupe>()) return 93;
			else return 92;
			break;
		case 32 :
			if (std::is_unsigned<ValueTupe>()) return 93;
			else return 92;
			break;
		case 16 : 
			break;
		default:
			
			break;
		}
	}

	static constexpr int max_n= max_n_dec();

	FibonacciMatrix operator*(FibonacciMatrix& other) {
		FibonacciMatrix ret;
		ret.n_d1 = this->n_d1 * other.n_d1 + this->n_ * other.n_;
		ret.n_ = this->n_d1 * other.n_ + this->n_ * other.n_a1;
		ret.n_a1 = this->n_ * other.n_ + this->n_a1 * other.n_a1;
		return ret;
	}
};


