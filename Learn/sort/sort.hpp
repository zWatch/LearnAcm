#pragma once
#include <algorithm>

class Learn_sort{
	
};

class Learn_stl_sort{
public:
	void test_place_in_sort(){
		
	
	};
};
/*
1 4 6 2 3 5
f=0 s=3
	f<s no swap
	f=1 s=3 c=1
	1 4 6 2 3 5
	f>s swap 
	f=1 s=4
	1 2 6 4 3 5
	f<s no swap
	f=2 s=4
	1 2 6 4 3 5
	f>s swap
	f=2 s=5
	1 2 3 4 6 5
	
	f<s no swap
	f=3 s=5
	1 2 3 4 6 5
	
	f<s no swap
	f=4 s=5
	1 2 3 4 6 5

	f>s swap
	f=4 s=6
	1 2 3 4 5 6

*/