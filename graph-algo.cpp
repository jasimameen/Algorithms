#include<bits/stdc++.h>

using namespace std;

typedef unordered_map<char, vector<char>>  graph;

void dfs_iterative(graph data, char source) {
	stack<char> stack;
	stack.push(source);

	while (stack.size() > 0) {
		char current = stack.top();
		stack.pop();
		cout << current << " ";
		for (char neighbour : data[current]) {
			stack.push(neighbour);
		}
	}
}

void dfs_recursive(graph data, char source) {
	cout << source <<  " ";

	for (char neighbour : data[source]) {
		dfs_recursive(data, neighbour);
	}
}

void bfs(graph data, char source) {
	deque<char> queue;
	queue.push_front(source);

	while(queue.size() > 0) {
		char current = queue.front();
		cout << current << " ";
		queue.pop_front();

		for(char neighbour : data[current]) {
			queue.push_back(neighbour);
		}
	}

}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

graph data;

data['a'] = {'c', 'b'};
data['b'] = {'d'};
data['c'] = {'e'};
data['d'] = {'f'};
data['e'] = {};
data['f'] = {};

// Depth-First-Traversal
// dfs_iterative(data, 'a');
// dfs_recursive(data, 'a');

// Breadth-First-Traversal
bfs(data, 'a');

return 0;
}

