/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (49.21%)
 * Likes:    1516
 * Dislikes: 93
 * Total Accepted:    302.2K
 * Total Submissions: 601.1K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (root == NULL)
        {
            return vector<string>{};
        }

        vector<string> res;

        vector<string> l = binaryTreePaths(root->left);
        res.insert(res.end(), l.begin(), l.end());
        vector<string> r = binaryTreePaths(root->right);
        res.insert(res.end(), r.begin(), r.end());

        for (int i = 0; i < res.size(); i++)
        {
            res[i] = to_string(root->val) + "->" + res[i];
        }

        if (res.size() == 0)
        {
            res.push_back(to_string(root->val));
        }

        return res;
    }
};
// @lc code=end
