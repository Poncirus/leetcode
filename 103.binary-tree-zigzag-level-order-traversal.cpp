/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (45.34%)
 * Likes:    1581
 * Dislikes: 84
 * Total Accepted:    307.6K
 * Total Submissions: 678.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> retv;
		if (!root) return retv;
		std::queue<TreeNode*> q; 
		q.push(root);
        bool reverse = false;
		vector<int> v;
		for (int cur_level_sz = 1, next_level_sz = 0; !q.empty(); ) {
			TreeNode *node = q.front(); 
            q.pop();
			v.push_back(node->val); 
            --cur_level_sz;
			if (node->left) { q.push(node->left); ++next_level_sz; }
			if (node->right) { q.push(node->right); ++next_level_sz; }
			if (!cur_level_sz) {
				retv.push_back(reverse ? vector<int>(v.crbegin(), v.crend()) : v); 
                v.clear();
				cur_level_sz = next_level_sz; 
                next_level_sz = 0;
                reverse = !reverse;
			}
		}
		return retv;
    }
};
// @lc code=end

