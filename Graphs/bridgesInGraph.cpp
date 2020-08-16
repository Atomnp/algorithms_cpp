#include <iostream>
#include <vector>

struct Edge {
	int from;
	int to;
	
	Edge() :from(-1), to(-1) {

	}
	Edge(int f,int t):from(f),to(t){}

};

class Graph {
private:
	std::vector<std::vector<int>> graph;
	std::vector<bool> isVisited;
	std::vector<Edge> bridgeEdges;
	int numberOfOutgoingEdgesFromRoot, numberOfNodes;
	std::vector<int> ids, lowValues;

	// to give different id to the nodes during dfs
	int id;

	int min(int a, int b) {
		if (a <= b)return a;
		return b;
	}


public:
	Graph(std::vector<std::vector<int>>graph) {
		this->graph = graph;
		numberOfNodes = graph.size();
		//array to store visited node
		isVisited = std::vector<bool>(numberOfNodes, false);
		lowValues = std::vector<int>(numberOfNodes);
		ids = std::vector<int>(numberOfNodes);
		id = 0;
	}

	void dfs( int parent, int currentNode) {
		isVisited[currentNode] = true;

		//initiallay setting currentNode and lowValues to their respective
		//number during dfs
		ids[currentNode] = lowValues[currentNode] = id++;


		//get items from adjacenct list
		for (auto child : graph[currentNode]) {
			//in adjancy list child also contain reference to parent
			//but parent will already be visited so continue
			if (child == parent)continue;
			if (!isVisited[child]) {
				dfs(currentNode, child);
				lowValues[currentNode] = min(lowValues[currentNode], lowValues[child]);

				if (ids[currentNode] < lowValues[child]) {
					bridgeEdges.push_back(Edge(currentNode, child));
				}
			}
			else {
				lowValues[currentNode] = min(ids[child], lowValues[currentNode]);

			}
		}
	}

	void findBridges() {

		//loop which helps to find bridges in graph
		//also if there are multiple connected components
		for (int i = 0; i < numberOfNodes; i++) {

			//before visitiing each connected component group 
			//initialize number of out going edges to 0
			numberOfOutgoingEdgesFromRoot = 0;
			if (!isVisited[i]) {
				int root = i;
				int parent = -1;
				int currentNode = i;
				if (!isVisited[i])
				{
					dfs(parent, currentNode);
				}
				

			}
		}
	}
	void logBridgeEdges() {
		for (auto bridge :bridgeEdges) {
			std::cout << "edge ("<<bridge.from<<", "<<bridge.to<<") " << " is bridge edge \n";
		}
	}
};

int main() {

	//create graph for input
	std::vector<std::vector<int>>graph = { {1,2},{0,2},{0,1,3,5},{2,4},{3},{2,6,8},{5,7},{6,8},{7,5} };
	auto solver = new Graph(graph);
	solver->findBridges();
	std::cout << "finding bridges point complete" << std::endl;
	solver->logBridgeEdges();


}


