#include <iostream>
#include <map>
#include <vector>
#include <queue>
void dfs(std::map<int, std::vector<int>>graph, int startNode, int numOfNodes) {
	std::queue<int> q;
	q.push(startNode);
	
	std::vector<bool > visited = std::vector<bool>(numOfNodes, false);

	while (!q.empty()) {
		int currentNode = q.front();
		q.pop();
		visited[currentNode] = true;

		std::cout << "node: " << currentNode << std::endl;

		//if it is a leaf node then it has no children
		if (!graph.count(currentNode)) {
			continue;
		}

		auto children = graph[currentNode];
		for (auto item : children) {
			if (!visited[item]) {
				q.push(item);
			}

		}
	}
}

int main() {
	std::cout << "this is dfs" << std::endl;
	//this graph is based on adjacency list just take out pen and paper and start to draw the graph 
	//you will understand
	std::map<int, std::vector<int>>graph;
	graph[0] = std::vector<int>({ 7,9,11 });
	graph[1] = std::vector<int>({ 10,8 });
	graph[2] = std::vector<int>({ 12,3 });
	graph[3] = std::vector<int>({ 2,4,7 });
	graph[4] = std::vector<int>({ 3 });
	graph[5] = std::vector<int>({ 6 });
	graph[6] = std::vector<int>({ 5,7 });
	graph[7] = std::vector<int>({ 0,3,6 });
	graph[8] = std::vector<int>({ 1,9,12 });
	graph[9] = std::vector<int>({ 0,8,10 });
	graph[10] = std::vector<int>({ 1,9 });
	graph[11] = std::vector<int>({ 0 });
	graph[12]= std::vector<int>({ 2,8 });

	dfs(graph, 0, 13);
}