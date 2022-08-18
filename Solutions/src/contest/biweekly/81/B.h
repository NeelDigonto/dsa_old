#pragma once
#include <core/Common.h>

namespace BW81B {

	class Graph {
	public:
		size_t n_;
		vector<bool> visited;
		vector<vector<int>> adj;
		size_t visited_count = 0;

		Graph(size_t _n)  {
			n_ = _n;
			visited = vector(n_, false);
			adj = vector<vector<int>>(n_, vector<int>{});
		}

		void addEdge(int u, int v)
		{
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		void DFS(int v)
		{
			visited[v] = true;
			visited_count++;

			for (auto it = adj[v].begin(); it != adj[v].end(); ++it)
				if (!visited[*it])
					DFS(*it);
		}

		size_t countUnvisited() {
			size_t count = 0;
			for (auto it = visited.begin(); it != visited.end(); ++it)
				if (*it == false)
					count++;

			return count;
			
		}
	};

	class Solution {
	public:
		long long countPairs(int n, const vector<vector<int>>& edges) {
			vector<unordered_set<int>> nodes(n, unordered_set<int>{});
			size_t count = 0;
			Graph graph(n);
			
			for (const auto& edge : edges) {
				const auto u = edge[0];
				const auto v = edge[1];
				graph.addEdge(u, v);
			}

			for (size_t i = 0; i != n; ++i) {
				graph.visited_count = 0;
				graph.DFS(i);
				count += n - graph.visited_count;
				graph.visited = move(vector<bool>(n, false));
			}

			return count / 2;
		}
	};

	void test() {
		cout << Solution{}.countPairs(3, { {0,1},{0,2 }, { 1,2 }}) << endl;
		cout << Solution{}.countPairs(7, { {0,2}, {0,5}, {2,4}, {1,6}, {5,4 }}) << endl;
		cout << Solution{}.countPairs(3, { {0, 1 }, {0, 2} }) << endl;
	}
}