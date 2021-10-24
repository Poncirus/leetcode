/*
 * @lc app=leetcode id=665 lang=java
 *
 * [665] Non-decreasing Array
 *
 * https://leetcode.com/problems/non-decreasing-array/description/
 *
 * algorithms
 * Medium (21.16%)
 * Likes:    3317
 * Dislikes: 657
 * Total Accepted:    161.3K
 * Total Submissions: 762.4K
 * Testcase Example:  '[4,2,3]'
 *
 * Given an array nums with n integers, your task is to check if it could
 * become non-decreasing by modifying at most one element.
 * 
 * We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for
 * every i (0-based) such that (0 <= i <= n - 2).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,2,3]
 * Output: true
 * Explanation: You could modify the first 4 to 1 to get a non-decreasing
 * array.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,2,1]
 * Output: false
 * Explanation: You can't get a non-decreasing array by modify at most one
 * element.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 10^4
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
    public boolean checkPossibility(int[] nums) {
        int pp = Integer.MIN_VALUE;
        int p = Integer.MIN_VALUE;

        boolean mod = false;

        for (int n : nums) {
            if (n >= p) {
                pp = p;
                p = n;
                continue;
            }

            if (mod) {
                return false;
            }

            mod = true;

            if (n >= pp) {
                pp = n;
                p = n;
            } else {
                pp = p;
                p = p;
            }
        }

        return true;
    }
}
// @lc code=end

