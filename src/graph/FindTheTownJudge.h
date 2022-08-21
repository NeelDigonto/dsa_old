#pragma once
#include "core/Common.h"

namespace FindTheTownJudge {


    class Solution {
    public:
        int findJudge(int n, const vector<vector<int>>& trust) {

            // indegree - outdegree == n - 1

            vector<int> degrees(n + 1, 0);

            for (auto& edge : trust) {
                degrees[edge[0]]--; // trusting == outdegree
                degrees[edge[1]]++; // trusted == indegree
            }

            for (auto i = 1; i != n + 1; ++i) {
                if (degrees[i] == n - 1)
                    return i;
            }

            return -1;

        }
    private:
        vector<vector<int>> graph_;
    };

    void test() {
        cout << Solution{}.findJudge(2, { {1, 2} }) << endl;
        cout << Solution{}.findJudge(3, { {1, 3}, {2, 3} }) << endl;
        cout << Solution{}.findJudge(3, { {1, 3}, {2, 3}, {3, 1} }) << endl;

    }


}