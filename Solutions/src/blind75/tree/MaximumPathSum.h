#pragma once
#include <limits>
#include "../../tree/LeetCodeTree.h"

namespace Q124 {
    class Solution {
        int max_ = std::numeric_limits<int>::min();
    public:
        int _maxPathSum(TreeNode* _root) {
            if (!_root) return 0;

            int max_left = _maxPathSum(_root->left);
            int max_right = _maxPathSum(_root->right);
            int val = _root->val;

            int edge_max = std::max({ max_left + val, max_right + val, val });
            max_ = std::max({ max_, edge_max, max_left + val + max_right });
            return edge_max;
        }
        int maxPathSum(TreeNode* _root) {
            _maxPathSum(_root);
            return max_;
        }
    };

    void test() {
        //TreeNode* root = BinaryTree::deserialize_t({1, 2, 3, std::nullopt ,std::nullopt ,std::nullopt ,std::nullopt });
        //TreeNode* root = BinaryTree::deserialize_t({ -10, 9, 20, std::nullopt ,std::nullopt, 15, 7, std::nullopt, std::nullopt, std::nullopt, std::nullopt });
        TreeNode* root = BinaryTree::deserialize_t({ -3, std::nullopt, std::nullopt });

        std::cout << Solution().maxPathSum(root);
        
    }
}