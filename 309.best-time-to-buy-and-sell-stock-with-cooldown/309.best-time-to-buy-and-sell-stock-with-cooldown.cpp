/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (45.60%)
 * Likes:    2185
 * Dislikes: 77
 * Total Accepted:    132.4K
 * Total Submissions: 287.5K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 * 
 * 
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1
 * day)
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,0,2]
 * Output: 3 
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 * 
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1)
            return 0;

        vector<vector<int>> dp;
        for (int i = 0; i < prices.size(); i++)
        {
            dp.push_back(vector<int>{0, -prices[0]});
        }

        dp[1][1] = max(-prices[1], dp[1][1]);
        for (int i = 2; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 2][1] + prices[i - 1], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return max(dp[prices.size() - 1][0], dp[prices.size() - 2][1] + prices[prices.size() - 1]);
    }
};
// @lc code=end
