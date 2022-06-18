#include <vector>
#include <iostream>
#include <queue>
#include <string>

#include "LeetCodeTree.h"


namespace Q112 {

    class Solution {
    public:
        int findSecondMinimumValue(TreeNode* root) {
            int smallest = root->val;
            int secondSmallest = -1;



            
            return secondSmallest;

        }
    };

    bool test()
    {
        const std::vector<std::pair<TreeNode*, int>> test_cases{
             { getTree("2,2,5,null,null,5,7"), 5},
             { getTree("2,2,2"), -1},
        };


        Solution solution;


        for (const auto& test_case : test_cases) {
            std::cout << solution.findSecondMinimumValue(test_case.first) << std::endl;
        }

        return true;
    }
}