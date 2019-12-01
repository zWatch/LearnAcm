#include <string>
#include <stack>
#include <vector>
#include <array>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		
		vector<char> ss(2048);
		ss.clear();

		for (auto c: s) {
			bool isEmpty = ss.empty();
			switch (c) {
			case '(':ss.push_back('('); break;
			case '{':ss.push_back('{'); break;
			case '[':ss.push_back('['); break;
			
			case ')':if (isEmpty || ss.at(ss.size() - 1) != '(') return false; ss.pop_back(); break;
			case '}':if (isEmpty || ss.at(ss.size() - 1) != '{') return false; ss.pop_back(); break;
			case ']':if (isEmpty || ss.at(ss.size() - 1) != '[') return false; ss.pop_back(); break;
			}
		}
		return ss.empty();
	}
};

