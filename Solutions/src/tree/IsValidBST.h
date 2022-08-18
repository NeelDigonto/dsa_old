#pragma once
#include <core/Common.h>
#include <tree/LeetCodeTree.h>

namespace IsValidBST {

    class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            return isValidBST(root, nullptr, nullptr);
        }

        bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
            if (!root) return true;
            if (minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
                return false;
            return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
        }
    };

    void test() {

        auto tree = new TreeNode(2);
        tree->left = new TreeNode(1);
        tree->right = new TreeNode(3);

        cout << boolalpha << Solution{}.isValidBST(tree) << endl;

        tree = new TreeNode(2);
        tree->left = new TreeNode(2);
        tree->right = new TreeNode(2);

        cout << boolalpha << Solution{}.isValidBST(tree) << endl;


    }

}