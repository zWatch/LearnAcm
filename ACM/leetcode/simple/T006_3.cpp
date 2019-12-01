#include <string>
#include <stack>
#include <vector>
#include <array>
using namespace std;
class Solution {
public:
	int encode[128];

	Solution() {
		encode['(']=1;
		encode['[']=2;
		encode['{']=3;
		encode[')']=-1;
		encode[']']=-2;
		encode['}']=-3;
	}
	
	inline int getEnCode(char s) {
		return encode[s];
	}

public:
	bool isValid(string s) {

		stack<char> ss;
		//ss.clear();

		for (auto i = 0; i<s.length(); i++) {
			bool isEmpty = ss.empty();
			if (getEnCode(s[i])>0) {
				
				ss.push(s[i]);
				
				if (ss.size() > (s.length()+1)/2) {
					return false;
				}
			}
			else{
				if (ss.empty()) {
					return false;
				}
				if(getEnCode(ss.top())+getEnCode(s[i]) != 0){
					return false;
				}
				ss.pop();
			}
		}
		return ss.empty();
	}
};

