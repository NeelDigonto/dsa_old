#include <vector>
#include <iostream>
#include <queue>
#include <string>

#include "LeetCodeTree.h"


namespace Q111 {

    class Solution {
    public:
        int minDepth(TreeNode* root) {
        }
    };

    bool test()
    {
        const std::vector<std::pair<TreeNode*, int>> test_cases{
            //{ getTree("3,9,20,null,null,15,7"), 2},
            { getTree("2,null,3,null,4,null,5,null,6"), 5},
        };

        //printTree(getTree("2,null,3,null,4,null,5,null,6"));


        Solution solution;


        for (const auto& test_case : test_cases) {
            std::cout << solution.minDepth(test_case.first) << std::endl;
        }

        return true;
    }
}