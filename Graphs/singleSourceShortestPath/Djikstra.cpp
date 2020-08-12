#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <limits>
#include <utility>
#include <exception>

template <typename T>
void print_edgeQueue(T& q) {
    while (!q.empty()) {
        auto top = q.top();
        std::cout << " from " << top.from << "  to  " << top.to << " with weight  " << top.weight << std::endl;
        q.pop();
    }
}

//data structure to represent Edge
struct Edge {
    int from;
    int to;
    int weight;

    Edge(int from, int to, int weight) :from(from), to(to), weight(weight) {}
};


//this node is stored in the priority queue which stores information about node id and its pathLengths
struct Node {
    int id;
    int pathValue;

    Node(int id, int pathValue) :id(id), pathValue(pathValue) {}
};
void dijkstraShortestPath(int startNode, int endNode,std::vector<int>&prev, int numberOfNodes, std::vector<std::vector<Edge*>>graph);

int main() {

    //constructed directed asyclic graph
    //if you want to see how graphs look take out your pen and paper
    std::vector<std::vector<Edge*>>graph = std::vector<std::vector<Edge*>>(6);
    graph[0] = std::vector<Edge*>({ new Edge(0,1,5),new Edge(0,2,3),new Edge(0,3,2) });
    graph[1] = std::vector<Edge*>({ new Edge(1,3,7) });
    graph[2] = std::vector<Edge*>({ new Edge(2,4,9) });
    graph[3] = std::vector<Edge*>({ new Edge(4,5,1) });
    graph[4] = std::vector<Edge*>({ new Edge(4,3,1) });
    graph[5] = std::vector<Edge*>({ new Edge(5,4,2) });

    try {
        std::vector<int> prev = std::vector<int>(graph.size(),-1);
        int startNode = 0;
        int endNode = 4;
        int numberOfNodes = graph.size();
        
        dijkstraShortestPath(startNode,endNode, prev, numberOfNodes, graph);

        int previous = endNode;
        std::cout << " displayed in the format end-->> ...... start" << std::endl;
        while (previous != -1) {
            auto separator = prev[previous] != -1 ? "-->" : "";
            std::cout << previous <<separator ;
            previous = prev[previous];
        }

    }
    catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
   


}
//given single starting node and graph represented by adjacency list
//this function returns lengyh of shortest path to all the nodes from given start node
void dijkstraShortestPath(int startNode,int endNode,std::vector<int>& prev, int numberOfNodes, std::vector< std::vector<Edge*>>graph) {

    //set the min priority queue
    auto cmp = [](const Node& left, const  Node& right) { return (left.pathValue > right.pathValue); };
    std::priority_queue<Node, std::vector<Node>, decltype(cmp)> pQueue(cmp);

    //set the path initially to infinity
    std::vector<int >pathLengths = std::vector<int>(numberOfNodes, std::numeric_limits<int>::max());
    std::vector<bool >visited = std::vector<bool>(numberOfNodes, false);
    pathLengths[startNode] = 0;
   

    pQueue.push(Node(startNode, 0));
    while (!pQueue.empty()) {
        auto topNode = pQueue.top();
        pQueue.pop();
        visited[topNode.id] = true;

        //
        if (pathLengths[topNode.id] < topNode.pathValue) continue;

        for (auto edge : graph[topNode.id]) {

            //if some node is visited already there is no way it can be relaxed further
            if (visited[edge->to])continue;
            int newPath = pathLengths[topNode.id] + edge->weight;
            //relaxacation condition
            if (newPath < pathLengths[edge->to]) {
                pathLengths[edge->to] = newPath;
                pQueue.push(Node(edge->to, newPath));
                prev[ edge->to] = topNode.id;
            }
        }
        if (topNode.id == endNode) {
            return;

        }
    }
    throw(std::exception("no  path found"));

}