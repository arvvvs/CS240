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
	for(int i = 0; i < vertices.size(); i++)
		delete vertices[i];
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
	Vertex* v = new Vertex({val, name, false, '\0'});
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
	for(int i = 0; i < vertices.size(); i++)
		vertices[i]->latch = false;

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
	for(int i = 0; i < vertices.size(); i++)
		vertices[i]->latch = false;
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
	for(int i = 0; i < vertices.size(); i++)
		vertices[i]->latch = false;
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
					found = true;
			}
		}
		if(!found)
			count++;
		else
			break;
	}
	return count;
}

// Here be dragons
bool Graph::partitionable() {
    // If we have three or less vertexes,
    // the graph is automatically partitionable
    // (Check this? Maybe I'm thinking of it wrong...)
    if (vertices.size() <= 3)
        return true;
    
    // Assign a blank color to all vertexes.
    for(int i = 0; i < vertices.size(); i++)
		vertices[i]->color = '\0';
	// Mark the current vertex. We don't need to worry about names, all we care about is adjacency.
	int currIndex;
	
	// Assign the first node a color..
    vertices[0]->color = 'b';
	bool zeros = false;
	
	// Starting from the first node and iterating the the last node in increments of 1...
	for (currIndex = 0; currIndex < vertices.size(); currIndex++)
	{
	    // If this node doesn't already have a color, skip it. We'll process it the second time around
	    if (vertices[currIndex]->color == '\0')
	        zeros = true;
	    else // if it does have one, we've already processed it's path
	        continue;
	        
        // If this node is not partitionable, neither is the graph.
	    if (!recurPartitionable(currIndex, 'b'))
	        return false;
	}

    // Until we have no uncolored nodes.
    while (zeros)
    {
        bool set = false;
    	// Nth iteration, we need to process all previously unprocessed nodes!
    	for (currIndex = 0; currIndex < vertices.size(); currIndex++)
    	{
    	    // If uncolored...
    	    if (vertices[currIndex]->color == '\0')
    	    {
    	        // ...and it's the first, set color and mark first
    	        if (zeros && !set)
    	        {
    	            vertices[currIndex]->color = 'b';
                    zeros = false;
                    set = true;
    	        }
    	        else // if it's not the first, let us know that there are more uncolored roots.
    	            zeros = true;
    	    }
    	    else // if it does have a color already, we've already processed its path
    	        continue;
    	        
            // If this node is not partitionable, neither is the graph.
    	    if (!recurPartitionable(currIndex, 'b'))
    	        return false;
    	}
    }
	
	// If we never return false, the answer by default is true.
	return true;
}

// And more dragons...
bool Graph::recurPartitionable(int currIndex, char currColor)
{
    char nextColor = (currColor == 'r') ? 'b' : 'r';
    
    // The interior index (to check path from node )
    int inIndex;
    for (inIndex = 0; inIndex <= vertices.size(); inIndex++)
    {
        // We don't want to check itself! We also only want to check for edges that exist!
        if (inIndex != currIndex && matrix[currIndex][inIndex] > 0)
        {
            if (vertices[inIndex]->color == '\0') // If we have not assigned a color, assign the next color.
                vertices[inIndex]->color = nextColor;
            else if (vertices[inIndex]->color == currColor) // If we have assigned a color, and it is the same as the current color, we cannot partition
                return false;
            
            // If this node is not partitionable, neither is the graph.
            if (!recurPartitionable(inIndex, nextColor))
                return false;
        }
    }
}

bool Graph::isSubGraph(const Graph& g) {	
	return false;
}

void printPathCloseVal(float value) {
	float cow = value;
}
