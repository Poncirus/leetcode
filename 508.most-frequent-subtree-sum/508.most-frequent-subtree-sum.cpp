/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
 *
 * https://leetcode.com/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (56.63%)
 * Likes:    624
 * Dislikes: 120
 * Total Accepted:    70.7K
 * Total Submissions: 122.4K
 * Testcase Example:  '[5,2,-3]'
 *
 * 
 * Given the root of a tree, you are asked to find the most frequent subtree
 * sum. The subtree sum of a node is defined as the sum of all the node values
 * formed by the subtree rooted at that node (including the node itself). So
 * what is the most frequent subtree sum value? If there is a tie, return all
 * the values with the highest frequency in any order.
 * 
 * 
 * Examples 1
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -3
 * 
 * return [2, -3, 4], since all the values happen only once, return all of them
 * in any order.
 * 
 * 
 * Examples 2
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -5
 * 
 * return [2], since 2 happens twice, however -5 only occur once.
 * 
 * 
 * Note:
 * You may assume the sum of values in any subtree is in the range of 32-bit
 * signed integer.
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
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        vector<int> res;
        map<int, int> m;
        rec(root, m);

        int max = 0;
        for (auto p = m.begin(); p != m.end(); p++)
        {
            if (p->second > max)
            {
                max = p->second;
                res.clear();
                res.push_back(p->first);
            }
            else if (p->second == max)
            {
                res.push_back(p->first);
            }
        }

        return res;
    }

    int rec(TreeNode *root, map<int, int> &m)
    {
        if (root == nullptr)
            return 0;

        int sum = root->val;
        sum += rec(root->left, m);
        sum += rec(root->right, m);

        m[sum]++;
        return sum;
    }
};
// @lc code=end
