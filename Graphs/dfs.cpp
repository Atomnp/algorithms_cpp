#include <iostream>
#include <map>
#include <vector>
#include <stack>
void dfs(std::map<int, std::vector<int>>graph, int startNode, int numOfNodes) {
	std::stack<int> st;
	st.push(startNode);
	//i have named my node starting from 1 so needs numOfNodes+1
	std::vector<bool > visited = std::vector<bool>(numOfNodes+1, false);

	while (!st.empty()) {
		int currentNode = st.top();
		st.pop();
		visited[currentNode] = true;

		std::cout << "node: " << currentNode << std::endl;

		//if it is a leaf node then it has no children
		if (!graph.count(currentNode)) {
			continue;
		}

		auto children = graph[currentNode];
		for (auto item : children) {
			if (!visited[item]) {
				st.push(item);
			}

		}
	}
}

int main() {
	std::cout << "this is dfs" << std::endl;
	std::map<int, std::vector<int>>graph;
	graph[1] = std::vector<int>({ 2,5,6,10 });
	graph[2] = std::vector<int>({ 3,4 });
	graph[6] = std::vector<int>({7});
	graph[7] = std::vector<int>({8,9});
	graph[10] = std::vector<int>({9});

	dfs(graph, 1, 10);
}