#include <vector>
#include <iostream>
#include <queue>
#include <string>

#include "LeetCodeTree.h"


namespace Q111 {

    class Solution {
    public:
        int minDepth(TreeNode* root) {

            if (root == nullptr) return 0;

            auto isLeaf = [](TreeNode* root) -> bool {
                return !root->left && !root->right;
            };

            std::queue<TreeNode*> queqe;
            queqe.push(root);

            std::size_t current_depth = 1, proccessed_nodes = 1, next_depth_nodes = 3;

            while (!queqe.empty()) {
                TreeNode* current = queqe.front();

                if (isLeaf(current)) return current_depth;

                if (current->left != nullptr) queqe.push(current->left);
                if (current->right != nullptr) queqe.push(current->right);
                queqe.pop();

                proccessed_nodes += 2;
                if (proccessed_nodes == next_depth_nodes) {
                    next_depth_nodes += 2 * ++current_depth;
                }
            }

            return current_depth;
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