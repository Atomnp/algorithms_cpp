#include<iostream>
#include <vector>
#include <limits>

struct Edge {
	int from;
	int to;
	int weight;

	Edge(int from, int to,int weight):from(from),to(to), weight(weight){}

};

class Graph {
private:
	std::vector<Edge *>edges;
public:
	void addEdge(Edge* edge) {
		edges.push_back(edge);
	}

	std::vector<double> bellmanFord(int numberOfNodes) {
		//create dist array
		std::vector<double>dist = std::vector<double>(numberOfNodes, INFINITY);
		//start node is always assumed to be node 0
		dist[0] = 0;
		

		//if it doesnot contain negative cycless we get shortes path in this iteration
		for (int i = 0; i < numberOfNodes-1; i++) {
			for (auto edge : edges) {
				auto newDistance = dist[edge->from] + edge->weight;
				if (newDistance < dist[edge->to]) {
					dist[edge->to] = newDistance;
				}
			}
			std::cout << "value of i" << i << std::endl;
		}

		//check negative cycle
		for (int i = 0; i < numberOfNodes-1; i++) {
			for (auto edge : edges) {
				auto newDistance = dist[edge->from] + edge->weight;
				if (newDistance < dist[edge->to]) {
					dist[edge->to] = -INFINITY;
				}
			}
		}

		return std::move(dist);


	}
};

int main() {
	//create graph
	//call bellman ford function
	std::cout << "bellman ford started" << std::endl;

	auto graph = Graph();
	graph.addEdge(new Edge(0, 1, 1));
	graph.addEdge( new Edge(0, 1, 1));
	graph.addEdge( new Edge(1, 2, 1));
	graph.addEdge( new Edge(2, 4, 1));
	graph.addEdge( new Edge(4, 3, -3));
	graph.addEdge( new Edge(3, 2, 1));
	graph.addEdge( new Edge(1, 5, 4));
	graph.addEdge( new Edge(1, 6, 4));
	graph.addEdge( new Edge(5, 6, 5));
	graph.addEdge( new Edge(6, 7, 4));
	graph.addEdge( new Edge(5, 7, 3));

	auto dist=graph.bellmanFord(9);
	std::cout<<"bellman ford complete"<<std::endl;


	//if the distance of any node is  -inf then we know that there is negative cycle in the graph
	//NOTE : we assume 0 to be the start node 
	int i = 0;
	for (auto distance : dist) {
		std::cout << " distance from 0 to node i is " << distance << std::endl;
	}
}