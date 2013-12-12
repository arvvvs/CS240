#include <iostream>
#include <fstream>
#include <queue>
#include <sstream>
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
		stringstream ( line ) >> vCount;
	
		vector<string> input;

		while(getline(inFile, line)) 
			input.push_back(line);		
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

void Graph::writeToFile(string file) {
	string house = file;
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
	vertices.push_back(v);
	matrix.push_back(vector<int>());
	for(int i = 0; i < (vCount + 1); ++i) {
		matrix[matrix.size() - 1].push_back(0);
		if(i < vCount - 1)
			matrix[i].push_back(0);
	}
	vMap[name] = (vertices.size() - 1);
	vCount++;
}


int Graph::numConnectedComponents() {
	//Setting the dummy boolean in the structs to false.
	for(Vertex* v : vertices)
		v->latch = false;

	vector<set<int>> sets;
	int k;

	//Looping through all the vertices.
	for(int i = 0; i < vCount; ++i) {

		//If the vertice hasn't been seen, will do a BFS from it and add all nodes to a set.
		//The code is very similar to BFS.
		if(!(vertices[i])->latch) {
			queue<int> q;
			sets.push_back(set<int>());
			sets[sets.size() - 1].insert(i);
			q.push(i);
			while(!q.empty()) {
				k = q.front();
				q.pop();
				vertices[k]->latch = true;
				for(int j = 0; j < vCount; ++j) {
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
	if(numConnectedComponents() == 1 && edgeCount == (vCount - 1))
		return true;
	else
		return false;
}

void Graph::minWeightComponent(string src) {
	string bogus = src;
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
		for(int i = 0; i < vCount; ++i) {
			if(matrix[indice][i] != 0 && !vertices[i]->latch)
				recurDFS(i, val, found);
		}
	}
}

bool Graph::BFS(string source, float val) {
	queue<int> q;
	for(Vertex* s : vertices)
		s->latch = false;
	int v = vMap[source];
	q.push(v);
	while(!q.empty()) {
		v = q.front();
		q.pop();
		vertices[v]->latch = true;
		if(vertices[v]->value == val)
			return true;
		for(int i = 0; i < vCount; ++i) {
			if(matrix[v][i] != 0 && !vertices[i]->latch)
				q.push(i);
		}
	}
	return false;
}

//Uses BFS
int Graph::closeness(string v1, string v2) {
	int one = vMap[v1], two = vMap[v2], count = 1;
	queue<int> q;
	bool found = false;
	q.push(one);
	while(!q.empty()) {
		one = q.front();
		q.pop();
		vertices[one]->latch = true;

		for(int i = 0; i < vCount; ++i) {
			if(matrix[one][i] != 0 && !vertices[i]->latch) {
				q.push(i);
				if(i == two)
					found == true;
			}
		}
		if(!found)
			count++;
		else
			break;
	}
	return count;
}

bool Graph::partitionable() {
}

bool Graph::isSubGraph(const Graph& g) {	
	return false;
}

void printPathCloseVal(float value) {
	float cow = value;
}
