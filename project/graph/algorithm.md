### Class Definition and Initialization 

- The Graph class manages graph information and operations. It consists of the number of vertices, edge information, and arrays for parent and rank using the union-find data structure.

- Kruskal's Algorithm Function: Functions for constructing and calculating the Minimum Spanning Tree(MST).

- Adding Edges: The addEdge function adds edges to the graph. Edges are stored as tuples containing the start node, end node, and weight.

- Union-Find Data Structure: This structure is used to check for cycles in the graph and to connect two different vertices.

The find function finds the root node of a given node, using path compression to improve efficiency.
The union function merges the sets to which two nodes belong, ensuring that the smaller tree is placed under the larger tree based on rank.

### Calculating MST:

(1)Sort the list of edges in ascending order based on weight.
(2)Use Kruskal's MST algorithm to construct the minimum spanning tree, using the union-find data structure to prevent cycles.
(3)The union function merges the sets to which two nodes belong, ensuring that the smaller tree is placed under the larger tree based on rank.
(4)The find function finds the root node of a given node, using path compression to improve efficiency.

### Constructing MSF: 

When the given graph is not connected, the concept is to find the minimum spanning tree for each disconnected component. Simply put, the minimum spanning forest is the collection of minimum spanning trees for each connected part (component) of the graph. 

It consists of the minimum spanning trees for all connected parts of the graph. Find the optimal connection structure for each cluster or component and calculate the cumulative sum of the minimum connection values.

### Calculating MSF:

Kruskal's algorithm: Sort the edges in ascending order based on weight, then add the lightest edges one by one without forming cycles. Each added edge forms a new tree or extends an existing tree.

### Weight Calculation:

Calculate the nodes and costs for each connected component.
Sum the weights of all components and output the number of connected nodes and components.
The final calculated risk is determined using logarithmic, square root, and exponential functions. The coefficients 'C' and 'G' are used in the calculation formula to derive the final risk 'R'.
This code uses Kruskal's MST algorithm, an important algorithm in graph theory, to find the minimum spanning tree in an actual graph, extend it to form a minimum spanning forest, and analyze the characteristics of the graph through additional weight calculations. This approach can be applied in various fields such as network design, communication, and optimal pathfinding.