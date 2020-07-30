/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (43.48%)
 * Likes:    4866
 * Dislikes: 160
 * Total Accepted:    331.2K
 * Total Submissions: 755.1K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 * 
 * Example 1:
 * 
 * 
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the
 * integer k is [-1e7, 1e7].
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int cum = 0;       // cumulated sum
        map<int, int> rec; // prefix sum recorder
        int cnt = 0;       // number of found subarray
        rec[0]++;          // to take into account those subarrays that begin with index 0
        for (int i = 0; i < nums.size(); i++)
        {
            cum += nums[i];
            cnt += rec[cum - k];
            rec[cum]++;
        }
        return cnt;
    }
};
// @lc code=end
