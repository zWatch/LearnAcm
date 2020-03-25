#include "sort.hpp"
#include <fstream>
#include <iostream>
#include <random>
using namespace std;

void gen_test_data(){
	ofstream ofs("example.txt",ios::out);
	mt19937 mt1;
	int i=0;
	while(i++<10'000'000){
		ofs<<mt1()<<endl;	
	}
	ofs.close();
}

int main(int argc, char** argv){
	//random_device rd;
	//gen_test_data();
	//cout<<mt1()<<endl;
	return 0;
};

