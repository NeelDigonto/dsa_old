#pragma once
#include "../../tree/LeetCodeTree.h"

namespace Q100 {
    class Solution {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if (!p && !q) return true;
            if (!p || !q) return false;

            return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

        }
    };

    void test() {
        /*TreeNode* root1 = new TreeNode(1);
        root1->left = new TreeNode(2);
        root1->right = new TreeNode(3);

        TreeNode* root2 = new TreeNode(1);
        root2->left = new TreeNode(2);
        root2->right = new TreeNode(3);*/

        TreeNode* root1 = new TreeNode(1);
        root1->left = new TreeNode(2);

        TreeNode* root2 = new TreeNode(1);
        root2->right = new TreeNode(3);


        Solution sol;
        std::cout << sol.isSameTree(root1, root2);
    }
}