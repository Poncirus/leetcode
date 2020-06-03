/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 *
 * https://leetcode.com/problems/burst-balloons/description/
 *
 * algorithms
 * Hard (50.08%)
 * Likes:    2209
 * Dislikes: 61
 * Total Accepted:    92.6K
 * Total Submissions: 181.7K
 * Testcase Example:  '[3,1,5,8]'
 *
 * Given n balloons, indexed from 0 to n-1. Each balloon is painted with a
 * number on it represented by array nums. You are asked to burst all the
 * balloons. If the you burst balloon i you will get nums[left] * nums[i] *
 * nums[right] coins. Here left and right are adjacent indices of i. After the
 * burst, the left and right then becomes adjacent.
 * 
 * Find the maximum coins you can collect by bursting the balloons wisely.
 * 
 * Note:
 * 
 * 
 * You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can
 * not burst them.
 * 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 * 
 * 
 * Example:
 * 
 * 
 * Input: [3,1,5,8]
 * Output: 167 
 * Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  -->
 * []
 * coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 * 
 */

// @lc code=start
class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int N = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        // rangeValues[i][j] is the maximum # of coins that can be obtained
        // by popping balloons only in the range [i,j]
        vector<vector<int>> rangeValues(nums.size(), vector<int>(nums.size(), 0));

        // build up from shorter ranges to longer ranges
        for (int len = 1; len <= N; ++len)
        {
            for (int start = 1; start <= N - len + 1; ++start)
            {
                int end = start + len - 1;
                // calculate the max # of coins that can be obtained by
                // popping balloons only in the range [start,end].
                // consider all possible choices of final balloon to pop
                int bestCoins = 0;
                for (int final = start; final <= end; ++final)
                {
                    int coins = rangeValues[start][final - 1] + rangeValues[final + 1][end]; // coins from popping subranges
                    coins += nums[start - 1] * nums[final] * nums[end + 1];                  // coins from final pop
                    if (coins > bestCoins)
                        bestCoins = coins;
                }
                rangeValues[start][end] = bestCoins;
            }
        }
        return rangeValues[1][N];
    }
};
// @lc code=end
