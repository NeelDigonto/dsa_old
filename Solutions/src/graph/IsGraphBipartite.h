#pragma once
#include <core/Common.h>
#include <core/Graph.h>

using namespace std;

namespace IsGraphBipartite {

    class Solution {
    public:
        bool isBipartite(const vector<vector<int>>& graph) {
            const auto n = graph.size();
            vector<bool> visited(n, false);
            vector<int> colors(n, false);
            constexpr auto c1 = 0, c2 = 1, cn = -1;
            queue<size_t> toVisit;

            size_t visitedUntill = 0;
            while (visitedUntill != n) {
                //process component
                toVisit.push(visitedUntill);

                while (!toVisit.empty()) {
                    size_t currentNode = toVisit.front();
                    toVisit.pop();

                    visited[currentNode] = true;
                    //cout << currentNode << endl;
                    if (colors[currentNode] == -1)
                        colors[currentNode] = 0;

                    for (size_t i = 0; i != graph[currentNode].size(); ++i) {
                        const auto node = graph[currentNode][i];
                        if(!visited[node])
                            toVisit.push(node);
                        if (colors[node] != -1 && colors[node] != !colors[currentNode])
                            return false;
                    }
                }

                visitedUntill = std::distance(visited.begin(), std::find(visited.begin() + visitedUntill, visited.end(), false));
            }

            return true;
        }
    };

    void test() {
        cout << boolalpha << Solution{}.isBipartite({ {1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2} }) << endl;
        cout << boolalpha << Solution{}.isBipartite({{1, 3}, {0, 2}, {1, 3}, {0, 2}} ) << endl;
    }

}