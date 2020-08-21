#include <iostream>
#include <set>
#include <vector>
#include<stack>

class Tarjan {
private:
	std::vector<std::set<int>>graph;
	int numberOfNodes;
	std::vector<bool>isVisited;
	//track the time count to give to each node
	int id;
	//to give id to the nodes while performing dfs
	std::vector<int>ids;
	//to store the low link value of each node
	std::vector<int>lowValues;

	std::stack<int>stack;
	std::vector<bool>onStack;

	int min(int a, int b) {
		return a <= b ? a : b;
	}

public:
	Tarjan(std::vector<std::set<int>> graph):id(0),graph(graph){
		numberOfNodes = graph.size();
		for (int i = 0; i < numberOfNodes; i++) {
			onStack.push_back(false);
			isVisited.push_back(false);
		}
		ids = std::vector<int>(numberOfNodes);
		lowValues= std::vector<int>(numberOfNodes);
	}

	void solve() {
		for (int i = 0; i < numberOfNodes; i++) {
			if(!isVisited[i])dfs(i);
		}
	}

	//this function should do all job
	void dfs( int at){
		stack.push(at);
		ids[at] = id; 
		lowValues[at] = id++;
		isVisited[at] = true;
		onStack[at] = true;
		//get all child associated with this node
		for (int to : graph[at]){
			if (!isVisited[to]) {
				dfs( to);
			}
			//update low link value
			if (onStack[to]) {
				lowValues[at] = min(lowValues[at], lowValues[to]);
			}
		}

		if (ids[at] == lowValues[at]) {
			while (!stack.empty()) {
				int node = stack.top();
				stack.pop();
				std::cout << node << " ,";
				onStack[node] = false;
				lowValues[node] = ids[at];
				if (node == at) {
					break;
				}

			}
			std::cout << "\n--------------------------------------\n";
		}
	}
};
//test client
int main() {
	std::cout << "Strongly connected component are shown below" << std::endl;
	std::vector < std::set<int> >graph = { {1},{2},{0},{4,7},{5},{6,0}, {0,2,4},{3,5} };
	auto solver = Tarjan(graph);
	solver.solve();
	std::cout << "completed " << std::endl;
}