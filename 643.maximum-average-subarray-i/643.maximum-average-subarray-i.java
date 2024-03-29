/*
 * @lc app=leetcode id=643 lang=java
 *
 * [643] Maximum Average Subarray I
 *
 * https://leetcode.com/problems/maximum-average-subarray-i/description/
 *
 * algorithms
 * Easy (42.71%)
 * Likes:    1235
 * Dislikes: 147
 * Total Accepted:    117K
 * Total Submissions: 273.6K
 * Testcase Example:  '[1,12,-5,-6,50,3]\n4'
 *
 * You are given an integer array nums consisting of n elements, and an integer
 * k.
 * 
 * Find a contiguous subarray whose length is equal to k that has the maximum
 * average value and return this value. Any answer with a calculation error
 * less than 10^-5 will be accepted.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,12,-5,-6,50,3], k = 4
 * Output: 12.75000
 * Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5], k = 1
 * Output: 5.00000
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= k <= n <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int sum = 0;
        double res = Double.NEGATIVE_INFINITY;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (i < k - 1) {
                continue;
            }

            res = Math.max(res, (double)sum / k);
            sum -= nums[i - k + 1];
        }
        return res;
    }
}
// @lc code=end

