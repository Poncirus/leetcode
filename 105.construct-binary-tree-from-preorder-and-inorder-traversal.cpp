/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (45.88%)
 * Likes:    2640
 * Dislikes: 75
 * Total Accepted:    306.6K
 * Total Submissions: 668.2K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
class Solution
{
public:
    using cIter = vector<int>::const_iterator;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return buildTree(preorder.cbegin(), preorder.cend(), inorder.cbegin(), inorder.cend());
    }
    TreeNode *buildTree(cIter preBeg, cIter preEnd, cIter inBeg, cIter inEnd)
    {
        if (preBeg >= preEnd || inBeg >= inEnd)
            return NULL;
        TreeNode *root = new TreeNode(*preBeg);
        auto inRoot = std::find(inBeg, inEnd, root->val);
        root->left = buildTree(next(preBeg), next(preBeg, inRoot - inBeg + 1), inBeg, inRoot);
        root->right = buildTree(next(preBeg, inRoot - inBeg + 1), preEnd, next(inRoot), inEnd);
        return root;
    }
};
// @lc code=end
