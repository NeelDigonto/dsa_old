#pragma once
#include "core/Common.h"

namespace PathInGraph {


    class Solution {
    private:
        void addEdge(int u, int v) {
            graph_[u].push_back(v);
            graph_[v].push_back(u);
        }

        bool isPathPresentBFS(int source, int destination) {
            queue<int> to_visit;
            vector<int> visited(graph_.size(), false);

            to_visit.push(source);

            while (!to_visit.empty()) {
                const auto node = to_visit.front();
                visited[node] = true;
                to_visit.pop();

                for (auto& adj_node : graph_[node]) {
                    if (!visited[adj_node]) {
                        to_visit.push(adj_node);
                    }
                }
            }

            return visited[destination];

        }




    public:
        bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
            graph_.resize(n, vector<int>{});


            for (auto& edge : edges) {
                auto u = edge[0], v = edge[1];
                addEdge(u, v);
            }


            return isPathPresentBFS(source, destination);
        }
    private:
        vector<vector<int>> graph_;
    };

    int add(int a, int b) {
        return a * b;
    }


    void test() {
        cout << add(2, 3);
    }


}