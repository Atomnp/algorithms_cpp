#include "UnionFind.h"
using namespace std;
void UnionFind::join(int i, int j) {
	
	if (isConnected(i, j))return;
	int rootOfI=root(i);
	int rootOfJ = root(j);

	int sizeOfI = size[rootOfI];
	int sizeOfJ = size[rootOfJ];

	if (sizeOfI <= sizeOfJ) {
		entries[rootOfI] = rootOfJ;
		size[rootOfJ] += size[rootOfI];
	}
	else {
		size[rootOfI] += size[rootOfJ];
		entries[rootOfJ] = rootOfI;
	}
}

bool UnionFind::isConnected(int i, int j) {
	int rootOfI = root(i);
	int rootOfJ = root(j);
	if (rootOfI == rootOfJ)return true;
	return false;
}
int UnionFind::root(int i) {
	
	while (entries[i] != i) {
		i = entries[i];
	}
	return i;
}