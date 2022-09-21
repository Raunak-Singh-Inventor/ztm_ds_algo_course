#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Graph {
    int numberOfNodes;
    map<char, vector<char>> adjacentList;

public:
    Graph() {
        numberOfNodes =  0;
    }

    void addVertex(char node) {
        if(adjacentList.find(node)!=adjacentList.end()) {
            cout << "node is already in graph" << endl;
            return;
        }
        adjacentList[node] = {};
    }

    void addEdge(char node1, char node2) {
        if(adjacentList.find(node1)==adjacentList.end()) {
            cout << "node1 is not in graph" << endl;
            return;
        }
        if(adjacentList.find(node2)==adjacentList.end()) {
            cout << "node2 is not in graph" << endl;
            return;
        }
        adjacentList[node1].push_back(node2);
        adjacentList[node2].push_back(node1);
    }

    void showConnections() {
        for(auto &it: adjacentList) {
            vector<char> nodeConnections = it.second;
            string connections;
            for(auto vertex: nodeConnections) {
                connections += vertex;
                connections += " ";
            }
            cout << it.first << "-->" << connections << endl;
        }
    }
};

int main() {
    Graph myGraph = Graph();
    myGraph.addVertex('0');
    myGraph.addVertex('1');
    myGraph.addVertex('2');
    myGraph.addVertex('3');
    myGraph.addVertex('4');
    myGraph.addVertex('5');
    myGraph.addVertex('6');
    myGraph.addEdge('3', '1');
    myGraph.addEdge('3', '4');
    myGraph.addEdge('4', '2');
    myGraph.addEdge('4', '5');
    myGraph.addEdge('1', '2');
    myGraph.addEdge('1', '0');
    myGraph.addEdge('0', '2');
    myGraph.addEdge('6', '5');

    myGraph.showConnections();
    return 0;
}
