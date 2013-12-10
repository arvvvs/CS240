#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

Graph::Graph() {

}

Graph::~Graph() {

}

void Graph::readFromFile(string file) {
	//Setup
	ifstream inFile;
	string line;
	int vCount;
	

	//Opening and checking input is good;
	inFile.open(file);
	if(inFile.good() && !inFile.bad()) {
		
		//reading the first line and placing it in 'vCount'
		getline(inFile, line);
		istringstream ( line ) >> vCount;

		

	} else {
		//Error reading, return this statement.
		cout << "Invalid file: " << file << endl;
	}

}

void Grpah::writeToFile(string file) {

}

bool Graph::empty() {
	return vertices.empty() ? true : false;
}

void Graph::addEdge(string v1, string v2, int weight) {
	//Basically need to resolve the string names to array positions,
	//then check that spot and put this weight in it.
	it=mymap.find(v1);
	it2=mymap.find(v2);
	matrix[it][it2]=weight;	
}

void Graph::addVertex(string name, float val) {
	Vertex v = new Vertex();
	v.name = name;
	v.value = val;
	vertices.insert(v);
	//More needs to be done, needs to be added to the maps and some other stuff im probably forgetting.
}

int Graph::numConnectedComponents() {

}

bool Graph::tree() {

}

void Graph::minWeightComponent(string src) {

}

bool Graph::DFS(string source, string val) {

}

bool Graph::BFS(string source, string val) {

}

int Graph::closeness(string v1, string v2) {

}

bool Graph::partitionable() {

}

bool Graph::isSubGraph(const Graph& g) {

}

void printPathCloseVal(float value) {

}
