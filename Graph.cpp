#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#include "Graph.h"

using namespace std;

Graph::Graph() {

}

Graph::~Graph() {
	for(Vertex* v : vertices)
		delete v;
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
	
		vector<string> input;

		while(getline(inFile, line)) 
			input.insert(line);		
		inFile.close();

		for(int i = 0; i < vCount; ++i) {
			string name, v1, v2;
			float value;
			int weight;
		
			stringstream s(input.at(i));
			if(i < vCount) {
				s >> name >> value;
				addVertex(name.substr(0, name.size() - 1), value);
			} else {					
				s >> v1 >> v2 >> weight;
				addEdge(v1.substr(0, v1.size() - 1), v2.substr(0, v2.size() - 1), weight);
			}
		}

	} else {
		//Error reading, return this statement.
		cout << "Invalid file: " << file << endl;
	}

}

void Grpah::writeToFile(string file) {

}

bool Graph::empty() {
	return vertices.empty();
}

void Graph::addEdge(string v1, string v2, int weight) {
	matrix[vMap[v1]][vMap[v2]] = weight;
	matrix[vMap[v2]][vMap[v1]] = weight;
	edgeCount++;
}

//Pretty straight forward, just make the object and adjust the matrix accordingly.
void Graph::addVertex(string name, float val) {
	Vertex* v = new Vertex({val, name, false});
	vertices.insert(v);
	matrix.push_back(vector<int>());
	for(int i = 0; i < matrix.size(); ++i) {
		matrix[matrix.size() - 1].push_back(0);
		if(i < matrix.size() - 1)
			matrix[i].push_back(0);
	}
	vMap[name] = (vertices.size() - 1);
	setCount++;
}


int Graph::numConnectedComponents() {
	//Setting the dummy boolean in the structs to false.
	for(Vertex* v : vertices)
		v->latch = false;

	vector<set<int>>* sets = new vector<set<int>>();
	int k;

	//Looping through all the vertices.
	for(int i = 0; i < vertices.size(); ++i) {

		//If the vertice hasn't been seen, will do a BFS from it and add all nodes to a set.
		//The code is very similar to BFS.
		if(!vertices[i]->latch) {
			queue<int>* q = new queue<int>;
			sets.push_back(set<int>);
			sets[sets.size() - 1].insert(i);
			q.push(i);
			while(!q.empty()) {
				k = q.front();
				q.pop();
				for(int j = 0; j < vertices.size(); ++j) {
					if(matrix[k][j] != 0 && !vertices[j]->latch)
						q.push(j);
				}
			}
		}
	}

	return sets.size();

}

//if graph is not disjoint and number of edges = #vertices - 1
bool Graph::tree() {
	if(numConnectedComponents() == 1 && edgeCount = (setCount - 1))
		return true;
	else
		return false;
}

void Graph::minWeightComponent(string src) {

}

//Just uses recursion
bool Graph::DFS(string source, string val) {
	for(Vertex* v : vertices)
		v->latch = false;
	int i = vMap[source];
	bool found = false;
	recurDFS(i, val, found);
	return found;
}

void Graph::recurDFS(int indice, string val, bool& found) {
	vertices[indice]->latch = true;
	if(vertices[indice]->name.compare(val) != 0)
		found = true;
	if(!found) {
		for(int i = 0; i < vertices.size(); ++i) {
			if(matrix[indice][i] != 0 && !vertices[i]->latch)
				recurDFS(i, val, found);
		}
	}
}

bool Graph::BFS(string source, float val) {
	queue<int>* q = new q<int>();
	for(Vertex* s : vertices)
		s->latch = false;
	int v = vMap[source];
	vertices[v]->latch = true;
	q.push(v);
	while(!q.empty()) {
		v = q.front();
		q.pop();
		if(vertices[v]->value == val)
			return true;
		for(int i = 0; i < vertices.size(); ++i) {
			if(matrix[v][i] != 0 && !vertices[i]->latch)
				q.push(i);
		}
	}
	delete [] q;
	return false;
}

int Graph::closeness(string v1, string v2) {

}

bool Graph::partitionable() {

}

bool Graph::isSubGraph(const Graph& g) {

}

void printPathCloseVal(float value) {

}
