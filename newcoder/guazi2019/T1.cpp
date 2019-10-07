#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
using namespace std;
//以空格为分隔符将单词倒叙

int main(int, char**){
    char* buf=new char[10000+1];
    char* OutBuf=new char[10000+1];
    cin.getline(buf, 10000+1);   
    auto wordsLen=cin.gcount()-1; 
	OutBuf[wordsLen] = 0;
	auto wordEnd = wordsLen;
    for (auto i=wordsLen-1; i>=0; i--)
    {
		if(buf[i]==' '){
			strncpy(OutBuf+wordsLen-wordEnd, buf+i+1, wordEnd-i-1);
			OutBuf[wordsLen -i -1] = ' ';
			wordEnd = i;
			//更新wordEnd=pos ' '
		}
		else if (i==0) {
			strncpy(OutBuf + wordsLen - wordEnd, buf, wordEnd - i);
			//wordEnd = i;
		}
    }
    cout<<OutBuf;
    return 0;
}