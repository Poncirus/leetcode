/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (41.18%)
 * Likes:    893
 * Dislikes: 342
 * Total Accepted:    86K
 * Total Submissions: 204.1K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * For example:
 * Given BST [1,null,2,2],
 * 
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 
 * 
 * return [2].
 * 
 * Note: If a tree has more than one mode, you can return them in any order.
 * 
 * Follow up: Could you do that without using any extra space? (Assume that the
 * implicit stack space incurred due to recursion does not count).
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
    vector<int> findMode(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;

        int count = 0;
        int cur = -1;
        int mc = 0;
        inorder(root, count, cur, res, mc);

        return res;
    }

    void inorder(TreeNode *r, int &count, int &cur, vector<int> &res, int &mc)
    {
        if (r->left != nullptr)
            inorder(r->left, count, cur, res, mc);

        if (r->val == cur)
        {
            count++;
        }
        else
        {
            cur = r->val;
            count = 1;
        }

        if (count == mc)
        {
            res.push_back(r->val);
        }
        else if (count > mc)
        {
            mc = count;
            res.clear();
            res.push_back(r->val);
        }

        if (r->right != nullptr)
            inorder(r->right, count, cur, res, mc);
    }
};
// @lc code=end
