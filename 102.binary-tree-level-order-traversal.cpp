/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (52.30%)
 * Likes:    2342
 * Dislikes: 62
 * Total Accepted:    524.1K
 * Total Submissions: 1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> retv;
		if (!root) return retv;
		std::queue<TreeNode*> q; 
		q.push(root);
		vector<int> v;
		for (int cur_level_sz = 1, next_level_sz = 0; !q.empty(); ) {
			TreeNode *node = q.front(); 
            q.pop();
			v.push_back(node->val); 
            --cur_level_sz;
			if (node->left) { q.push(node->left); ++next_level_sz; }
			if (node->right) { q.push(node->right); ++next_level_sz; }
			if (!cur_level_sz) {
				retv.push_back(v); 
                v.clear();
				cur_level_sz = next_level_sz; 
                next_level_sz = 0;
			}
		}
		return retv;
    }
};
// @lc code=end

