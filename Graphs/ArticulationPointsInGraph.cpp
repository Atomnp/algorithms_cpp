/*
two find articulation point in graph there are two different conditions
1.if the given node is root node
-> the node will be articulation point if there are two independent 
	outgoing edges from root node

2.For nodes other than root node
-> it is articulation point of id[givenNode]<=lowPointOf(itsChildredn)

*/
#include <iostream>
#include <vector>

class Graph {
private:
	std::vector<std::vector<int>> graph;
	std::vector<bool> isVisited;
	std::vector<bool> isArticulationPoint;
	int numberOfOutgoingEdgesFromRoot,numberOfNodes;
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
		//array to store articulation point	
		isArticulationPoint = std::vector<bool>(numberOfNodes, false);
		lowValues = std::vector<int>(numberOfNodes);
		ids = std::vector<int>(numberOfNodes);
		id = 0;
	}

	void dfs( int root, int parent, int currentNode) {
		//when root has more than one outgoing edges
		//it becomes parent more than one each for its adjacent childs
		if (parent == root)numberOfOutgoingEdgesFromRoot++;
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
				dfs(root, currentNode, child);
				lowValues[currentNode] = min(lowValues[currentNode],lowValues[child]);

				if (ids[currentNode] <= lowValues[child]) {
					isArticulationPoint[currentNode] = true;
				}
			}
			else {
				lowValues[currentNode] = min(ids[child], lowValues[currentNode]);

			}
		}
	}

	void findArticulationPoint() {

		//loop which helps to find articulation points in graph
		//also if there are multiple connected components
		for (int i = 0; i < numberOfNodes; i++) {

			//before visitiing each connected component group 
			//initialize number of out going edges to 0
			numberOfOutgoingEdgesFromRoot = 0;
			if (!isVisited[i]) {
				int root = i;
				int parent = -1;
				int currentNode = i;
				dfs(root, parent, currentNode);
				//condition number 1 when the node is root node
				//if number of outgoing edge is greater than 1
				if (numberOfOutgoingEdgesFromRoot > 1) {
					isArticulationPoint[i] = true;
				}
				else {
					// this overrites if it is set true in the dfs function to true
					//we have special case for root node so cant apply the rule applied in dfs method
					isArticulationPoint[i] = false;
				}
			}
		}
	}
	void logArticulationPoints() {
		int i = 0;
		for (auto isTrue : isArticulationPoint) {
			if (isTrue) {
				std::cout << i << " is articulation point \n";
			}
			i++;
		}
	}
};

int main() {

	//create graph for input
	std::vector<std::vector<int>>graph = { {1,2},{0,2},{0,1,3,5},{2,4},{3},{2,6,8},{5,7},{6,8},{7,5} };
	auto solver = new Graph(graph);
	solver->findArticulationPoint();
	std::cout << "finding articulation point complete" << std::endl;
	solver->logArticulationPoints();


}


