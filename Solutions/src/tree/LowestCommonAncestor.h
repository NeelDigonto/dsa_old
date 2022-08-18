#pragma once
#include <core/Common.h>
#include <tree/LeetCodeTree.h>

namespace LowestCommonAncestor {

	class Solution {	
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
			if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
			return root;
		}
	};

	void test() {

	}
}