/*
 * @lc app=leetcode id=581 lang=java
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int[] cloned = nums.clone();
        Arrays.sort(cloned);
        int start = -1, end = -1;
        for (int i = 0; i < nums.length; i++) {
            start = (start == -1 && nums[i] != cloned[i]) ? i : start;
            end = (nums[i] != cloned[i]) ? i : end;
        }
        return (start == -1) ? 0 : end - start + 1;
    }
}
// @lc code=end

