/*
*this program find the strongly component components in the graph usin kosaraju's algorithm
*
*
*/

#include <iostream>
#include <vector>
#include <stack>
#include<set>

class Kosaraju {
	std::vector<std::set<int>>graph;
	std::stack<int>st;
	std::vector<bool>visited;
	int numberOfNodes;

public:
	Kosaraju(std::vector<std::set<int>>_graph) {
		numberOfNodes = _graph.size();
		graph = _graph;

		for (int i = 0; i < numberOfNodes; i++) {
			visited.push_back(false);
		}

	}
	void solve() {
		//perform dfs and fill the stack

		for (int i = 0; i < numberOfNodes; i++) {
			if (!visited[i]) {
				dfs(graph,i);
				st.push(i);
			}
		}
		//reverse the directed edges in the graph
		auto reversedGraph = reverseGraph(graph);

		//reset the visited array
		for (int i = 0; i < visited.size(); i++) {
			visited[i] = false;
		}

		
		//perform dfs again by pulling the element from the top of the stack
		std::cout << "various strongly component groups are listed as" << std::endl;
		while (!st.empty()) {
			std::vector<int>component;
			auto top = st.top();
			if (!visited[top]) {
				visit(reversedGraph, top);
				std::cout <<top << ",";
				st.pop();
				std::cout << "\n--------------------\n";
			}
			else {
				st.pop();
			}
			
		}
	}
	//function to reverse the graph
	std::vector <std::set<int>>reverseGraph(std::vector<std::set<int>>graph) {
		
		//reverse the graph and return

		std::vector<std::set<int>>reverseGraph(graph.size());
		
		int i = 0;
		for (std::set<int> edges : graph) {
			for (auto item : edges) {
				reverseGraph[item].insert(i);
			}
			i++;
		}
		return reverseGraph;
	}

	void dfs(std::vector<std::set<int>>graph,int node) {
		visited[node] = true;
		for (auto childNode:graph[node]) {
			if(!visited[childNode]) {
				dfs(graph, childNode);
				st.push(childNode);
			}
		}
	}

	void visit(std::vector<std::set<int>>graph, int node) {
		visited[node] = true;
		
		for (auto childNode : graph[node]) {
			if (!visited[childNode]) {
				visit(graph, childNode);
				std::cout << childNode << ", ";

			}
		}

	}
};

int main() {
	//create graph for input 
	std::vector < std::set<int> >graph = { {1},{2,3},{0},{4},{5},{3},{5,7},{8},{9},{6,10},{} };
	auto solver = Kosaraju(graph);
	solver.solve();

}