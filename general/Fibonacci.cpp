#include <algorithm>
#include <iostream>
#include <cstdio>

#define DEBUG_FIBONACCI 1
constexpr int Max_N_TRY = 7;//[log(97)]+1;
constexpr int LOG_Max_N = Max_N_TRY;

typedef unsigned long long  FibonacciMatrix_INTTYPE;
//typedef long long FibonacciMatrix_INTTYPE;

class FibonacciMatrix{
public:
	FibonacciMatrix_INTTYPE n_d1;
	FibonacciMatrix_INTTYPE n_;
	FibonacciMatrix_INTTYPE n_a1;

	FibonacciMatrix operator*(FibonacciMatrix& other) {
		FibonacciMatrix ret;
		ret.n_d1 = this->n_d1 * other.n_d1 + this->n_ * other.n_;
		ret.n_ = this->n_d1 * other.n_ + this->n_ * other.n_a1;
		ret.n_a1 = this->n_ * other.n_ + this->n_a1 * other.n_a1;
		return ret;
	}

};

std::ostream& operator<<(std::ostream& out, FibonacciMatrix& other) {
	out <<"F(n-1):" <<other.n_d1 << " F(n):" << other.n_ << " F(n+1):" << other.n_a1 << std::endl;
	return out;
}

static FibonacciMatrix* FibonacciMatrix_cache;

/*
i=log(FibonacciMatrix_N)
*/
//work 
//{ long long : LOG_MAX_N=7}
//{ int : WAIT}
bool initFibonacciMatrix(int i){
	FibonacciMatrix start{0,1,1};
	
	FibonacciMatrix_cache = new FibonacciMatrix[LOG_Max_N];
	if (FibonacciMatrix_cache) {
		FibonacciMatrix_cache[0] = start;
		for (int i = 1; i < LOG_Max_N; i++) {
			start = start * start;
			FibonacciMatrix_cache[i] = start;
		}
		return true;
	}
	return false;
}

//work
FibonacciMatrix getFibonacciMatrix(int n){
	FibonacciMatrix ret = {1,0,1};
	while (n!=0) {
		int bit = n & (~n+1);
		int index = (int)log2(bit);
		ret =ret*FibonacciMatrix_cache[index];
		n = n ^ bit;
	}
	return ret;
}


#ifdef DEBUG_FIBONACCI
inline bool FibonacciMatrixOverflow(FibonacciMatrix& max, FibonacciMatrix& max_2) {
	return
		max_2.n_a1 < max_2.n_
		|| max_2.n_ < max_2.n_d1
		|| max_2.n_d1 < 0
		|| max_2.n_a1 < 0
		|| max_2.n_ < 0
		|| max.n_a1 < max_2.n_a1
		|| max.n_d1 < max_2.n_d1
		|| max.n_ < max_2.n_;
}

inline bool FibonacciMatrixOverflow_2(FibonacciMatrix& max) {
	return max.n_a1 < max.n_
		|| max.n_ < max.n_d1
		|| max.n_a1 < 0
		|| max.n_d1 < 0
		|| max.n_ < 0
		;
}

//error not work
void FindMaxFibonacciMatrix_N() {
	int Hight_Bit_Loc = 0;
	long long real_MAX_N = 0;
	for (Hight_Bit_Loc = 1; Hight_Bit_Loc<LOG_Max_N; Hight_Bit_Loc++) {
		if(
			FibonacciMatrix_cache[Hight_Bit_Loc].n_a1
			< FibonacciMatrix_cache[Hight_Bit_Loc].n_
			|| FibonacciMatrix_cache[Hight_Bit_Loc].n_d1<0
			|| FibonacciMatrix_cache[Hight_Bit_Loc].n_<0
			|| FibonacciMatrix_cache[Hight_Bit_Loc].n_a1<0
			){
			break;
		}
	}

	FibonacciMatrix max = FibonacciMatrix_cache[Hight_Bit_Loc-1];
	real_MAX_N = 1ll<< Hight_Bit_Loc-1;

	for (int i= Hight_Bit_Loc-2; i>0; i--) {
		FibonacciMatrix max_2 = max * FibonacciMatrix_cache[i];
		if(!FibonacciMatrixOverflow(max, max_2)){
			real_MAX_N += 1ll << Hight_Bit_Loc;
			max = max_2;
		}
	}

	std::cout << "max: "<< max << endl;
	std::cout << "max/2: "<< getFibonacciMatrix(real_MAX_N/2) << endl;
	std::cout << "max+1: "<< getFibonacciMatrix(real_MAX_N+1) << endl;
	std::cout << "max*2: "<< getFibonacciMatrix(real_MAX_N*2) << endl;
	std::cout << "MAX_N: " << real_MAX_N << endl;
	std::cout <<"LOG_MAX_N: " <<log2(real_MAX_N) << endl;
}

int FindOverflowPos() {
	int ret = 0;
	FibonacciMatrix f;
	for (ret=1; ret<(2<<(Max_N_TRY)); ret++) {
		f = getFibonacciMatrix(ret);
		if (FibonacciMatrixOverflow_2(f)) {
			break;
		};
	}
	std::cout<<"break at " << ret<<" FM is : "<< f << std::endl;
	std::cout<<"FM(ret-1) " <<" FM is : "<< getFibonacciMatrix(ret-1) << std::endl;
	return 0;
}


void OutPutFibonacciMatrix() {
	int end = 92 + 1;
	//printf("{");
	std::cout << "{" << std::endl;
	for (int i = 0; i< Max_N_TRY-1; i++) {
		auto fm = FibonacciMatrix_cache[i];
		std::cout << "{"<< fm.n_d1<< ","<< fm.n_<<","<< fm.n_a1<<"}," << std::endl;

		//printf("{%lld, %lld, %lld},\n", fm.n_d1 , fm.n_, fm.n_a1);
	}
	auto fm = FibonacciMatrix_cache[Max_N_TRY - 1];
	//printf("{%lld, %lld, %lld}}\n", fm.n_d1, fm.n_, fm.n_a1);
	std::cout << "{" << fm.n_d1 << "," << fm.n_ << "," << fm.n_a1 << "}}" << std::endl;
}

int main() {
	initFibonacciMatrix(0);
	FindOverflowPos(); //ans is 92
	//OutPutFibonacciMatrix();
	
	/*
	for (int i : {1,2,3}) {
		auto s = getFibonacciMatrix(i);
		std::cout << s;
	}
	*/

	//FindMaxFibonacciMatrix_N();
}
#endif // DEBUG_FIBONACCI


