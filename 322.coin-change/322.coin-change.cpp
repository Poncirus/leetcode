/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (33.71%)
 * Likes:    3742
 * Dislikes: 132
 * Total Accepted:    381.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 */

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (auto p = dp.begin(); p < dp.end(); p++)
        {
            if (*p == -1)
                continue;

            for (auto q = coins.begin(); q < coins.end(); q++)
            {
                if (p + *q < dp.end() && (*p + 1 < *(p + *q) || *(p + *q) == -1))
                {
                    *(p + *q) = *p + 1;
                }
            }
        }

        return *(dp.end() - 1);
    }
};
// @lc code=end
