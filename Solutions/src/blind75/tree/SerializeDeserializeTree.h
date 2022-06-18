#pragma once
#include "../../tree/LeetCodeTree.h"

namespace Q297 {

    class Codec {
    public:
        using arr_rep_t = std::vector<std::optional<int>>;

        // Encodes a tree to a single string.
        std::string serialize(TreeNode* _root) {
            return BinaryTree::serialize(_root);
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(std::string data) {
            return BinaryTree::deserialize(data);
        }
    };

    void test() {

        Codec sol;

        /*TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->right = new TreeNode(4);
        root->right->right = new TreeNode(5);
        root->right->right->right = new TreeNode(6);
        root->right->right->right->right = new TreeNode(7);*/

        /*TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->right->left = new TreeNode(4);
        root->right->right = new TreeNode(5);*/

        /*TreeNode* root = nullptr; */

        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);


        std::string data = sol.serialize(root);
        TreeNode* tree = sol.deserialize(data);

        BinaryTree::lvlorderTraverse(tree, [](std::optional<int> _elem) {
            std::cout << (_elem.has_value() ? std::to_string(_elem.value()) : "null") << ", ";
            });
    }

}