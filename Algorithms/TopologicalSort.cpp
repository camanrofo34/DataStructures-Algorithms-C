/**
Topological sort algorithm is used for sorting a directed acyclic graph (DAG). 
This algorithm sorts the vertices in a linear ordering such that for every 
directed edge u -> v, vertex u comes before v in the ordering. Topological 
sorting is often used in scheduling tasks, ordering of formula cell evaluation 
in spreadsheets, and resolving symbol dependencies in linkers.

Time Complexity:

Worst Case: O(V + E)
Best Case: O(V + E)
Average Case: O(V + E)

V: Number of vertices
E: Number of edges

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<bool> visited;
vector<int> topological_order;
vector<vector<int>> graph;
// Function to perform topological sort on a graph
void dfs(int v) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
    topological_order.push_back(v);
}

void topological_sort() {
    int number_of_vertices = graph.size();
    visited.assign(number_of_vertices, false);
    topological_order.clear();
    for (int i = 0; i < number_of_vertices; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(topological_order.begin(), topological_order.end());
}