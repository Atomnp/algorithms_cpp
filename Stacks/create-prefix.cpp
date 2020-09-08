#include <iostream>
//prototype of createPostfix function defined in another file
std::string createPostfix(std::string);

std::string reverse(std::string str) {
	std::string result;
	int n = str.size() - 1;
	for (int i = 0; i <= n; i++) {
		result.push_back(str[n - i]);
	}
	return result;

}

std::string createPrefix(std::string input) {
	//reverse the input
	std::string reversedInput = reverse(input);
	//create the postfix
	//create the postfix
	std::string pf=createPostfix(reversedInput);


	//again reverse the postfix outpot
	std::string result = reverse(pf);
	return result;

}
//testing
int main() {
	std::string input = "A + B * C + D";
	std::string result = createPrefix(input);
	std::cout<<"the prefix of"<<input <<" is "<<result<< std::endl;

}
