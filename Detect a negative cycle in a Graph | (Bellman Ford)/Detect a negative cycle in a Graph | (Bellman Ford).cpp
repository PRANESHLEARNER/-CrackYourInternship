
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a weighted edge in graph
struct Edge {
	int src, dest, weight;
};

// A structure to represent a connected, directed and
// weighted graph
struct Graph {
	// V-> Number of vertices, E-> Number of edges
	int V, E;

	// Graph is represented as an array of edges.
	struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[graph->E];
	return graph;
}


bool isNegCycleBellmanFord(struct Graph* graph, int src,
						int dist[])
{
	int V = graph->V;
	int E = graph->E;

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX
				&& dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	for (int i = 0; i < E; i++) {
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX
			&& dist[u] + weight < dist[v])
			return true;
	}

	return false;
}

// Returns true if given graph has negative weight
// cycle.
bool isNegCycleDisconnected(struct Graph* graph)
{

	int V = graph->V;

	// To keep track of visited vertices to avoid
	// recomputations.
	bool visited[V];
	memset(visited, 0, sizeof(visited));

	// This array is filled by Bellman-Ford
	int dist[V];

	// Call Bellman-Ford for all those vertices
	// that are not visited
	for (int i = 0; i < V; i++) {
		if (visited[i] == false) {
			// If cycle found
			if (isNegCycleBellmanFord(graph, i, dist))
				return true;

			// Mark all vertices that are visited
			// in above call.
			for (int i = 0; i < V; i++)
				if (dist[i] != INT_MAX)
					visited[i] = true;
		}
	}

	return false;
}

// Driver Code
int main()
{

	// Number of vertices in graph
	int V = 5;

	// Number of edges in graph
	int E = 8;

	// Let us create the graph given in above example
	struct Graph* graph = createGraph(V, E);

	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = -1;

	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 4;

	graph->edge[2].src = 1;
	graph->edge[2].dest = 2;
	graph->edge[2].weight = 3;

	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 2;

	graph->edge[4].src = 1;
	graph->edge[4].dest = 4;
	graph->edge[4].weight = 2;

	graph->edge[5].src = 3;
	graph->edge[5].dest = 2;
	graph->edge[5].weight = 5;

	graph->edge[6].src = 3;
	graph->edge[6].dest = 1;
	graph->edge[6].weight = 1;

	graph->edge[7].src = 4;
	graph->edge[7].dest = 3;
	graph->edge[7].weight = -3;

	if (isNegCycleDisconnected(graph))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
