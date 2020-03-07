/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (43.20%)
 * Likes:    1282
 * Dislikes: 27
 * Total Accepted:    193.2K
 * Total Submissions: 447.3K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
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
    using vcIt = vector<int>::const_iterator;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return buildTree(inorder.cbegin(), inorder.cend(), postorder.cbegin(), postorder.cend());
    }
    TreeNode *buildTree(vcIt inBeg, vcIt inEnd, vcIt postBeg, vcIt postEnd)
    {
        if (inBeg >= inEnd || postBeg >= postEnd)
            return NULL;
        TreeNode *root = new TreeNode(*prev(postEnd));
        auto inRoot = find(inBeg, inEnd, root->val);
        root->left = buildTree(inBeg, inRoot, postBeg, next(postBeg, inRoot - inBeg));
        root->right = buildTree(next(inRoot), inEnd, next(postBeg, inRoot - inBeg), prev(postEnd));
        return root;
    }
};
// @lc code=end
