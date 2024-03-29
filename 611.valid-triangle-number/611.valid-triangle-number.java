import java.util.Arrays;
import java.util.HashMap;

/*
 * @lc app=leetcode id=611 lang=java
 *
 * [611] Valid Triangle Number
 *
 * https://leetcode.com/problems/valid-triangle-number/description/
 *
 * algorithms
 * Medium (49.15%)
 * Likes:    2096
 * Dislikes: 133
 * Total Accepted:    120.3K
 * Total Submissions: 244.7K
 * Testcase Example:  '[2,2,3,4]'
 *
 * Given an integer array nums, return the number of triplets chosen from the
 * array that can make triangles if we take them as side lengths of a
 * triangle.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,2,3,4]
 * Output: 3
 * Explanation: Valid combinations are: 
 * 2,3,4 (using the first 2)
 * 2,3,4 (using the second 2)
 * 2,2,3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,2,3,4]
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int count = 0, n = nums.length;
        for (int i = n - 1; i >= 2; i--) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (nums[l] + nums[r] > nums[i]) {
                    count += r - l;
                    r--;
                } else
                    l++;
            }
        }
        return count;
    }
}
// @lc code=end
