#include <iostream>
#include <vector>

double min(double a, double b) {
	if (a <= b)return a;
	return b;
}

//to print 2d array with equal number of rows and columns
void print2Darray(std::vector<std::vector<double>>& matrix,int numberOfRows)  {

	std::cout << "[\n";
	for (int i = 0; i < numberOfRows; i++) {
		for (int j = 0; j < numberOfRows; j++) {
			std::cout << matrix[i][j] << " ,";
		}
		std::cout << "\n";
	}

	std::cout << "]";
}


//expected arry has equal number of rows and columns

void floydWarshall(std::vector<std::vector<double>>& matrix,int numberOfRows) {
	//compute the required matrix
	for (int k = 0; k < numberOfRows;k++) {
		for (int i = 0; i < numberOfRows; i++) {
			if (i == k)continue;
			for (int j = 0; j < numberOfRows;j++) {
				if (j == k||j==i)continue;
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}
}

int main() {
	std::cout << "floyd warshall algorithm started" << std::endl;

	//create 2d matrix input representing graph
	
	//row we want in out input matrix
	int numberOfRows = 4;
	std::vector<std::vector<double>>matrix = std::vector<std::vector<double>>(numberOfRows);
	matrix[0] = { 0 , 3 , INFINITY , 7,5 };
	matrix[1] = { 8 , 0 , 2 , INFINITY };
	matrix[2] = { 5 , INFINITY , 0 , 1 };
	matrix[3] = { 2 , INFINITY , INFINITY , 0 };

	floydWarshall(matrix,numberOfRows);

	std::cout << "array with shortest path of each pair is " << std::endl;
	print2Darray(matrix,numberOfRows);


}