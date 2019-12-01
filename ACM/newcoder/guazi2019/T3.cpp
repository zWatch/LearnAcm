#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
	int n = 0;
	scanf("%d\n", &n);
	if (n == 1) {
		char InBuf[2048];
		scanf("%s\n", InBuf);
		strrev(InBuf);
		printf(InBuf);
	}
	else {
		char Buf[2048];
		char InBuf[2048];
		memset(Buf, 0, 2048);
		memset(InBuf, 0, 2048);
		for (int i = 0; i < n; i++) {
			scanf("%s\n", InBuf);
			int l = strlen(InBuf);
			for (int j = 0; j < l; j++) {
				Buf[j] ^= InBuf[j];
			}
		}
		printf(Buf);
	}
	return 0;
}
