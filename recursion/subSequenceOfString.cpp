#include <iostream>
#include <vector>
#include <algorithm>



void solve(std::string input, std::vector<std::string>& output,std::string temp) {
	if (input.length() == 0) {
		output.push_back(temp);
		
	}
	else {
		auto lastElm = input.back();
		input.pop_back();

		solve(input, output, temp);
		temp.push_back(lastElm);
		solve(input, output, temp);
	}

}
std::vector<std::string> subSequence(std::string input) {
	//this step in unimportant
	std::reverse(input.begin(), input.end());
	std::vector<std::string>output;
	std::string temp = "";
	solve(input, output, temp);

	//sorting is also not important
	//just for making output more readable
	std::sort(output.begin(), output.end());
	std::sort(output.begin(),output.end(), [](std::string a, std::string b) {
		return a.length() < b.length();
	});
	
	return output;
}

//test client
int main() {
	std::string input = "abc";

	std::vector<std::string> output=subSequence(input);

	for (auto item : output) {
		if (item.length() == 0) {
			std::cout << "null string" << std::endl;
			continue;
		}
		std::cout << item << std::endl;
	}
}