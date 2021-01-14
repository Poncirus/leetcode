/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
 *
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (59.62%)
 * Likes:    885
 * Dislikes: 61
 * Total Accepted:    101.6K
 * Total Submissions: 166.5K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * You need to find the largest value in each row of a binary tree.
 * 
 * Example:
 * 
 * Input: 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      / \   \  
 * ⁠     5   3   9 
 * 
 * Output: [1, 3, 9]
 * 
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> res;

        if (root == nullptr)
            return res;

        queue<TreeNode *> q;
        int m = INT_MIN;

        q.push(root);
        q.push(nullptr);

        while (true)
        {
            if (q.front() == nullptr)
            {
                res.push_back(m);
                m = INT_MIN;

                if (q.size() == 1)
                    break;

                q.push(nullptr);
            }
            else
            {
                m = max(m, q.front()->val);

                if (q.front()->left != nullptr)
                    q.push(q.front()->left);

                if (q.front()->right != nullptr)
                    q.push(q.front()->right);
            }

            q.pop();
        }

        return res;
    }
};
// @lc code=end
