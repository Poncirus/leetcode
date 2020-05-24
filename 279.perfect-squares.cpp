/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (44.63%)
 * Likes:    2482
 * Dislikes: 177
 * Total Accepted:    269.6K
 * Total Submissions: 592.6K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3 
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> can;
        for (int i = 1; i * i <= n; i++)
        {
            can.push_back(i * i);
        }

        vector<int> dp;
        dp.push_back(0);
        for (int i = 1; i <= n; i++)
        {
            int t = n;
            for (auto p = can.begin(); p < can.end(); p++)
            {
                if (i - *p >= 0 && dp[i - *p] + 1 < t)
                {
                    t = dp[i - *p] + 1;
                }
            }
            dp.push_back(t);
        }

        return dp[n];
    }
};
// @lc code=end
