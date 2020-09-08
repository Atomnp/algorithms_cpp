#include<iostream>
#include <stack>

using namespace std;
class Solution {
public:
	static bool isValid(string s) {

		stack<int>st;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				st.push(0);
			}
			else if (s[i] == ')')
			{
				if (!(st.top() == 0))return false;
				st.pop();

			}
			else if (s[i] == '{')
			{
				st.push(1);
			}
			else if (s[i] == '}')
			{
				if (!(st.top() == 1))return false;
				st.pop();
			}
			else if (s[i] == '[')
			{
				st.push(2);
			}
			else if (s[i] == ']')
			{
				if (!(st.top() == 2))return false;
				st.pop();
			}

		}
		if (st.empty())
		{
			return true;
		}
		return false;

	}
	//static long long reverse(long long x) {
	//	long long int result = 0;
	//	long long int lastDigit;
	//	while (true) {
	//		if (x == 0)return result;
	//		lastDigit = x % 10;
	//		result = result * 10 + lastDigit;
	//		x = x / 10;
	//		std::cout << "last digit" << lastDigit << std::endl;
	//		std::cout << "resuklt" <<result << std::endl;
	//	}
	//}

};
int main() {
	Solution::isValid("([)]");
	/*std::cout<<Solution::reverse(1534236469)<<std::endl;*/
}