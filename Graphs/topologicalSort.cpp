#include <iostream>
#include <map>
#include <vector>

int dfs(
		std::map<int, std::vector<int>>&graph, 
		int currentnode, int orderingPosition, 
		std::vector<bool> &visited, 
		std::vector<int> &ordering
) 
{
	int size = graph[currentnode].size();
	
	visited[currentnode] = true;
	if (size > 0) {
		for (auto item : graph[currentnode]) {
			int node = item;

			if (!visited[node]) {
				if (size > 0) {
					orderingPosition = dfs(graph, node, orderingPosition, visited, ordering);
				}
			}
		}
	}
	ordering[orderingPosition] = currentnode;
	return orderingPosition - 1;

}

void topSort(std::map<int,std::vector<int>>graph,int numOfNodes) {
	std::vector<bool> visited = std::vector<bool>(numOfNodes, false);
	std::vector<int> ordering = std::vector<int>(numOfNodes);

	int orderingPostion = numOfNodes-1;

	for (auto item : graph) {
		int currentNode = item.first;
		
		if (!visited[currentNode] || graph[currentNode].size() == 0) {
			dfs( graph,currentNode, orderingPostion, visited,ordering);
		}
	}
	
	std::cout << "the vector after topological sort is given below" << std::endl;
	for (auto item : ordering) {
		std::cout << item << std::endl;
	}

}

int main() {
	std::map<int, std::vector<int>>graph;
	graph[0] = std::vector<int>({ 1,2,5 });
	graph[1] = std::vector<int>({ 2,3 });
	graph[2] = std::vector<int>({ 3,4 });
	graph[3] = std::vector<int>({ 4 });
	graph[4] = std::vector<int>({  });
	graph[5] = std::vector<int>({ 4 });

	std::cout << "------------------------------------------" << std::endl;
	topSort(graph,graph.size());


}