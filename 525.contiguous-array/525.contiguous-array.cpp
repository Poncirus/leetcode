/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 *
 * https://leetcode.com/problems/contiguous-array/description/
 *
 * algorithms
 * Medium (44.88%)
 * Likes:    2192
 * Dislikes: 121
 * Total Accepted:    162.5K
 * Total Submissions: 380.7K
 * Testcase Example:  '[0,1]'
 *
 * Given a binary array, find the maximum length of a contiguous subarray with
 * equal number of 0 and 1. 
 * 
 * 
 * Example 1:
 * 
 * Input: [0,1]
 * Output: 2
 * Explanation: [0, 1] is the longest contiguous subarray with equal number of
 * 0 and 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [0,1,0]
 * Output: 2
 * Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
 * number of 0 and 1.
 * 
 * 
 * 
 * Note:
 * The length of the given binary array will not exceed 50,000.
 * 
 */

// @lc code=start
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        map<int, int> Hash;
        int cnt = 0;
        Hash[0] = -1;
        int maxLen = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 1)
                cnt++;
            else if (nums[i] == 0)
                cnt--;
            if (!Hash.count(cnt))
                Hash[cnt] = i;
            else
            {
                maxLen = std::max(maxLen, i - Hash[cnt]);
            }
        }
        return maxLen;
    }
};
// @lc code=end
