#include <iostream>
#include <vector>

void solve(int remOpenPar, int remClosedPar, std::string temp, std::vector<std::string>& result) {
    if (remClosedPar < remOpenPar) {
        return;
    }
    if (remClosedPar == 0 && remOpenPar == 0) {
        result.push_back(temp);
        return;
    }

    std::string temp1 = temp;
    std::string temp2 = temp;

    temp1.push_back('(');
    temp2.push_back(')');
    if (remOpenPar > 0) {
        solve(remOpenPar - 1, remClosedPar, temp1, result);
    }
    if (remClosedPar > 0) {
        solve(remOpenPar, remClosedPar - 1, temp2, result);
    }



}
std::vector<std::string>solve(int numOfPair) {
    int remainingOpenParenthesis = numOfPair;
    int remainingClosedParenthesis = numOfPair;
    std::vector<std::string>result;
    std::string temp = "";
    solve(remainingOpenParenthesis, remainingClosedParenthesis, temp, result);
    return result;

}
int main() {
    std::cout << "balanced parenthes is started";
    int numOfPair = 4;
    std::vector<std::string>result = solve(numOfPair);
    std::cout << "complete" << std::endl;
    for (auto item : result) {
        std::cout << item<<std::endl;
    }
}