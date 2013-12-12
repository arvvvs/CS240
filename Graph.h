#include <string>
#include <vector>
#include <set>
#include <stack>
#include <unordered_map>

struct Vertex {
	float value;
	std::string name;
	bool latch;
};

class Graph{
	private:
		std::vector<vector<int>> matrix;
		std::set<Vertex*> vertices;
		std::unordered_map<string, int> vMap;
		int setCount;
		int edgeCount;
		
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
		bool recurDFS(int indice, std::string val);
		//Breadth First Search
		bool BFS(std::string source, float val);
		//Closeness
		int closeness(std::string v1, std::stringv2);
		//Partition
		bool partitionable();
		//* Subgraph Test
		bool isSubGraph(const Graph& g);
		//Print Valued Path
		void printPathCloseVal(float value);
};