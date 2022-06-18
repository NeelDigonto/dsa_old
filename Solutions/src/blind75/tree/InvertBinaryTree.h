#pragma once
#include "../../tree/LeetCodeTree.h"

namespace Q226 {
    // divide and conquer
    class Solution {
    public:
        TreeNode* invertTree(TreeNode* _root) {
            if (!_root) return nullptr;

            invertTree(_root->left);
            invertTree(_root->right);

            std::swap(_root->left, _root->right);

            return _root;
        }
            
    };

    void test() {
        TreeNode* root = new TreeNode(4);

        root->left = new TreeNode(2);
        root->right = new TreeNode(7);

        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(3);
        root->right->left = new TreeNode(6);
        root->right->right = new TreeNode(9);

        Solution sol;
        BinaryTree::printLvlOrderTraverse(sol.invertTree(root));
    }
}