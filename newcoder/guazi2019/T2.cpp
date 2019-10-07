#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstring>
using namespace std;
//以空格为分隔符将单词倒叙

int main(int, char**) {
	//1:2:5:10
	//slove(x+2y+5z+10w=n)
	
	/*
	int r = 0;
	int n = 0;
	cin >> n;
	{
		for (int d = 0; n>=10*d; d++) {
			for (int c = 0; n >=10*d+5*c ; c++) {
				for (int b = 0; n >= 10 * d + 5 * c+b*2; b++) {
					r++;
				}
			}
		}
	};
	cout << (r) % ((int)(1e9 + 7));
	//*/
	
	int amount=0;
	cin >> amount;
	vector<int> coins{1,2,5,10};
	vector<int> dp(amount + 1, 0);
	dp[0] = 1;
	for (int coin : coins)
	{
		for (int i = coin; i <= amount; ++i)
		{
			dp[i] = (dp[i - coin] + dp[i])%((int)(1e9+7));
		}
	}
	
	cout << dp[amount]%((int)(1e9+7));
	//*/
	return 0;
}

//n mod 10=a
//n mod 5=b
//n mod 2=c
//n mod 1=a

/*
if n=1
	{
	{1,0,0,0}
	}=1
if n=2
	{
	{2,0,0,0}
	{0,1,0,0}
	}=2
if n=3
	{
	{1,1,0,0}
	{3,0,0,0}
	}=2

if n=4
	{
	{0,2,0,0}
	{2,1,0,0}
	{4,0,0,0}
	}=3

if n=5
	{
	{0,0,1,0}
	{1,2,0,0}
	{3,1,0,0}
	{5,0,0,0}
	}=4

if n=6
	{
	{1,0,1,0}

	{0,3,0,0}
	
	{2,2,0,0}
	{4,1,0,0}
	{6,0,0,0}
	}=5

if n=11
	{
	...
	}=12





g(n, {s})={
	x,y,z,w
	{g(s_n, {s}-s_n)}:(w-1)
		if(a*x>){
		
		}
}

g(){

}



*/


/*
时间限制：1秒

空间限制：65536K

有1分，2分，5分，10分四种硬币，每种硬币数量无限，给定n分钱(n <= 100000)，有多少中组合可以组成n分钱？

输入描述:
输入整数n.(1<=n<=100000)

输出描述:
输出组合数，答案对1e9+7取模。

输入例子1:
13

输出例子1:
16
*/
