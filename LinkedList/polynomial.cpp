#include <iostream>
#include <string>
class Polynomial {
private:
	struct Data {
		int degree;
		int coeff;
		Data* next;
		Data(int degree, int coeff) :degree(degree), coeff(coeff) {
			next = nullptr;
		}
	};
	Data* head;
	char var;

	bool isNumber(char c) {
		if (c >= '0' and c <= '9')return true;
		return false;
	}
	bool isLetter(char c) {
		if (c >= 'a' and c <= 'z')return true;
		return false;
	}
	bool isOperator(char c) {
		if (c == '+' or c == '-')return true;
		return false;
	}

	void insert(int deg, int coef) {
		if (head == nullptr) {
			head = new Data(deg, coef);
			return;
		}
		if (deg > head->degree) {
			auto temp = new Data(deg, coef);
			temp->next = head;
			head = temp;
			return;
		}
		auto ptr = head;
		auto preptr = head->next;
		while (preptr != nullptr) {

			if (preptr->degree <= deg) {
				break;
			}
			preptr = preptr->next;
			ptr = ptr->next;
		}
		if (preptr == nullptr) {
			ptr->next = new Data(deg, coef);
			return;
		}
		if (preptr->degree == deg) {
			preptr->coeff += coef;
		}
		else {
			auto newData = new Data(deg, coef);
			newData->next = preptr;
			ptr->next = newData;
		}
	}

public:
	Polynomial() {
		var = 'x';
		head = nullptr;
	}
	Polynomial(std::string s) {
		std::string tempCoeff;
		std::string tempDegree;
		bool expMode = false;
		bool varMode = false;
		bool isNegative = false;

		for (int i = 0; i <= s.length(); i++) {

			if (isOperator(s[i]) or i == s.length()) {
				if (tempCoeff.length() > 0 or tempDegree.length() > 0) {
					int degree = tempDegree.length() == 0 ? 1 : stoi(tempDegree);
					if (varMode)degree = 0;
					int coefficient;
					if (tempCoeff.length() == 0) {
						coefficient = 1;
					}
					else {
						coefficient = !isNegative ? stoi(tempCoeff) : -1 * stoi(tempCoeff);
					}

					insert(degree, coefficient);
					tempCoeff = "";
					tempDegree = "";
					expMode = false;
					varMode = false;
				}
				if (s[i] == '-') {
					isNegative = true;
				}
				continue;

			}
			if (s[i] == ' ')continue;

			if (varMode and s[i] == '^') {
				expMode = true;
				varMode = false;
				continue;
			}
			if (expMode == true and !isNumber(s[i]) and !isOperator(s[i]) || (varMode and !s[i] != '^')) {
				std::cout << "syntax error" << std::endl;
				exit(0);
			}
			else if (expMode == true and isNumber(s[i])) {
				tempDegree.push_back(s[i]);
			}

			if (!expMode and isNumber(s[i])) {
				tempCoeff.push_back(s[i]);
			}

			if (isLetter(s[i])) {
				var = s[i];
				varMode = true;
				continue;
			}
		}
	}
	Polynomial operator+(const Polynomial& b) {
		Polynomial temp;
		auto first = head;
		auto second = b.head;

		while (true) {
			if (first == nullptr and second == nullptr) {
				break;
			}
			else if (first == nullptr) {
				temp.insert(second->degree, second->coeff);
				second = second->next;
			}
			else if (second == nullptr) {
				temp.insert(first->degree, first->coeff);
				first = first->next;
			}
			else if (first->degree == second->degree) {
				auto resultCoeff = first->coeff + second->coeff;
				if (resultCoeff != 0) {
					temp.insert(first->degree, resultCoeff);

				}
				first = first->next;
				second = second->next;

			}
			else if (first->degree > second->degree) {
				temp.insert(first->degree, first->coeff);
				first = first->next;
			}
			else {
				temp.insert(second->degree, second->coeff);
				second = second->next;
			}
		}

		return temp;
	}
	void print() {
		auto temp = head;
		std::string eqn = "";
		while (temp != nullptr) {
			int dg = temp->degree;
			int cf = temp->coeff;
			if (cf > 0 and eqn.length() > 0) {
				eqn += "+";
			}

			eqn += std::to_string(cf);
			if (dg != 0) {
				eqn.push_back(var);
				eqn += "^" + std::to_string(dg);
				eqn.push_back(' ');
			}
			temp = temp->next;
		}
		std::cout << eqn << std::endl;
	}
};

//unit test
int main() {
	Polynomial p1(" 55 x^4 + 3x^2  + 9x - 9x^9 ");
	Polynomial p2(" 33 x^4 - 3x^2 +9x- 5x^3");
	Polynomial p3 = p1 + p2;

	p1.print();
	std::cout << "-----" << std::endl;
	p2.print();
	std::cout << "-----" << std::endl;
	p3.print();
}