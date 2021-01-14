/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 *
 * https://leetcode.com/problems/lexicographical-numbers/description/
 *
 * algorithms
 * Medium (49.59%)
 * Likes:    546
 * Dislikes: 69
 * Total Accepted:    52.6K
 * Total Submissions: 103.5K
 * Testcase Example:  '13'
 *
 * Given an integer n, return 1 - n in lexicographical order.
 * 
 * For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
 * 
 * Please optimize your algorithm to use less time and space. The input size
 * may be as large as 5,000,000.
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> res;
        helper(1, n, res);
        return res;
    }

    void helper(int target, int n, vector<int> &res)
    {
        if (target > n)
            return;
        res.push_back(target);
        helper(target * 10, n, res);
        if (target % 10 != 9)
            helper(target + 1, n, res);
    }
};
// @lc code=end
