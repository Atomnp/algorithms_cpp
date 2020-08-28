/*
this program generates n bit binary number where each prefix has number of 1 greater than number of zero
*/

#include <iostream>
#include <vector>

void solve(int numberOfBitsLeft, int numberOfOnes, int numberOfZeros,std::string tempString,std::vector<std::string>&result) {
	if (numberOfBitsLeft == 0) {
		result.push_back(tempString);
		return;
	}
	if (numberOfOnes > numberOfZeros) {
		std::string temp = tempString;
		temp.push_back('0');
		solve(numberOfBitsLeft - 1, numberOfOnes, numberOfZeros+1, temp, result);
	}
	std::string temp = tempString;
	temp.push_back('1');
	solve(numberOfBitsLeft - 1, numberOfOnes + 1, numberOfZeros, temp, result);

}

std::vector<std::string>solve(int numberOfBits) {
	int numberOfOnes = 0;
	int numberOfZeros = 0;
	std::string tempString = "";
	std::vector<std::string>result;
	solve(numberOfBits, numberOfOnes, numberOfZeros,tempString,result);
	return result;
}

int main() {

	int numberOfbits = 3;
	
	std::vector<std::string>result=solve(numberOfbits);
	
	for (auto item : result) {
		std::cout << item << std::endl;
	}
}