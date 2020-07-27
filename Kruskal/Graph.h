#pragma once
#include <vector>
#include <utility>
using namespace std;
typedef std::vector<pair<int, pair<int, int>>> EdgeList;
class Graph {
	int numOfVertex;
public:
	Graph(int n):numOfVertex(n) {

	}
	EdgeList edges;
	
	void addEdge( int firstNode, int secondNode, int weight ) {
		//std::cout << firstNode << "  " << secondNode <<"  "<<weight<< std::endl;
		edges.push_back({ weight, {firstNode, secondNode} });
	}
	void printEdges(){
		for (auto item : edges) {
			std::cout << item.first << " , " ;
		}

	}
	void minimumSpanningTree() {
		int sizeOfEdges = edges.size();
		UnionFind uf(sizeOfEdges);
		int count=0;
		
		for (auto item : edges) {
			auto first = item.second.first;
			auto second = item.second.second;
			if (!uf.isConnected(first, second)) {
				std::cout << first << " --> " << second << "  " <<  std::endl;
				count++;
				if (count == numOfVertex - 1) {
					return;
				}
			}
			uf.join(first, second);

			
		}
	}
};
