#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
std::vector<int> dfs(std::map<int, std::vector<int>>graph, int startNode, int numOfNodes) {
	std::queue<int> q;
	std::vector<int>prevArr = std::vector<int>(numOfNodes, -1);
	q.push(startNode);


	std::vector<bool > visited = std::vector<bool>(numOfNodes, false);

	while (!q.empty()) {
		int currentNode = q.front();
		q.pop();
		visited[currentNode] = true;

		std::cout << "node: " << currentNode << std::endl;

		auto children = graph[currentNode];
		for (auto item : children) {
			if (!visited[item]) {
				q.push(item);
				prevArr[item] = currentNode;
			}

		}

	}
	return std::move(prevArr);

}

void shortestPath(int start, int end, int numberOfNodes, std::map<int, std::vector<int>> graph) {

	auto prevArr = dfs(graph, start, numberOfNodes);
	std::stack<int>path;
	std::cout << "shortest path from " << start << " to " << end << std::endl;

	//last is used while displaying output
	int last = end;

	while (end != start) {
		path.push(end);
		end = prevArr[end];
	}
	path.push(start);


	// for printing path
	while (!path.empty()) {
		std::string joinString = path.top() != last ? "-->" : "";
		std::cout << path.top() << joinString;
		path.pop();
	}
}

//test client for shortest path using bfs
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
	graph[12] = std::vector<int>({ 2,8 });

	std::cout << "------------------------------------------" << std::endl;
	shortestPath(11, 2, graph.size(), graph);
}