#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    // Note:
    //     Compiles, but does not run (as of 12/12/13 1:01pm)
    // Additional Info:
    //     While trying to test partitionable(), attempting to run shows "terminate called after throwing an instance of 'std::bad_alloc'"
    //     I do not have acess to GDB at the current time.
    
    /*
     * Test of:
     *     Partitionable()
     *
     * Results:
     *     Unknown.
     * Reason:
     *     See above note.
     */
    Graph g;
    g.addVertex("New York", 1);
    g.addVertex("Paris", 1);
    g.addVertex("London", 1);
    g.addVertex("Geneva", 1);
    
    g.addEdge("New York", "Paris", 1);
    g.addEdge("Paris", "London", 1);
    g.addEdge("London", "Geneva", 1);
    
    cout << ((g.partitionable()) ? "Partitionable!" : "Not Partitionable!") << endl;
    
    g.addEdge("New York", "London", 1);
    
    cout << ((g.partitionable()) ? "Partitionable!" : "Not Partitionable!") << endl;
    
    /* Expected output: 
     *
     * Partitionable!
     * Not Partitionable!
     *
     */
}
