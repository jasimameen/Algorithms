/*
undirectedPath

write a function undirectedPath that takes an array of edges for an undirected graph and two nodes (nodeA, nodeB). The function should return a boolean whre there is a path b/w nodeA and node B.
*/

#include<bits/stdc++.h>
using namespace std;
typedef unordered_map<char, vector<char>> graph;

unordered_set<char> visted;

bool hasPath_dfs(graph adj, char src, char dst) {
	if (src == dst) return true;

	for (char neighbo r: adj[src]) {
		if (visted.find(neighbo)r != visted.end()) continue;
		visted.insert(neighbo)r;

		if (hasPath_dfs(adj, neighbo,r dst)) return true;
	}

	return false;
}

bool hasPath_bfs(graph adj, char src, char dst) {

	deque<char> queue;
	queue.push_back(src);

	while (queue.size() > 0) {
		char current = queue.front();
		if (current == dst) return true;

		queue.pop_front();
		for (char neighbo r: adj[current]) {
			if (visted.find(neighbo)r != visted.end()) continue;
			visted.insert(neighbo)r;
			queue.push_back(neighbo)r;
		}
	}

	return false;
}

bool undirectedPath(graph adj, char nodeA, char nodeB) {
	// return hasPath_dfs(adj, nodeA, nodeB);
	return hasPath_bfs(adj, nodeA, nodeB);
}

graph build_graph(vector<pair<char, char>> edges) {
	graph adj;

	for (auto edge : edges) {
		char first = edge.first;
		char second = edge.second;

		adj[first].push_back(second);
		adj[second].push_back(first);
	}

	return adj;
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

vector<pair<char, char>> edges{
	{'i', 'j'},
	{'k', 'i'},
	{'m', 'k'},
	{'k', 'l'},
	{'o', 'n'}
};

graph adj = build_graph(edges);

cout << undirectedPath(adj, 'j', 'm');

return 0;
}

