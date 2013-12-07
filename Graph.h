#include <string>
#include <iostream>

//This class will be used to create a graph library.

/**Whenever paths are to be printed, they should be printed with 
	v1 -> v2 -> v3 -> ...
where v1, v2, and v3 are replaced with the names of the vertex **/

/**Whenever trees are to be printed, they should be printed with
	{V, E} 
where V is the set of vertices, and E is the set of edges 
(note: V and E are sets and should be enclosed in brackets)**/

class Graph{
	private:
		//Put your private data members here
		//Put your private methods here
	public:
		//Construct
		Graph();
		//Delete
		~Graph();
		//Read A Graph From A File
		void readFromFile(std::string file);
		//Write A Graph To A File
		void writeToFile(std::string file);
		//Empty
		bool empty();
		//Add Edge
		void addEdge(std::string v1, std::string v2, int weight);
		//Add Vertex
		void addVertex(std::string name, float val);
		//Count Connected Components
		int numConnectedComponents();
		//Tree Check
		bool tree();
		//Minimum Weight Components
		void minWeightComponent(std::string src);
		//Depth First Search
		bool DFS(std::string source, std::string val);
		//Breadth First Search
		bool BFS(std::string source, std::string val);
		//Closeness
		int closeness(std::string v1, std::stringv2);
		//Partition
		bool partitionable();
		//* Subgraph Test
		bool isSubGraph(const Graph& g);
		//Print Valued Path
		void printPathCloseVal(float value);
};
