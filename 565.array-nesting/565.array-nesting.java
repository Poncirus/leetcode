/*
 * @lc app=leetcode id=565 lang=java
 *
 * [565] Array Nesting
 */

// @lc code=start
class Solution {
    public int arrayNesting(int[] nums) {
        int count, max = 0;
        for (int i = 0; i < nums.length; i++) {
            count = 0;
            int index = i;
            while (nums[index] != -1) {
                int temp = nums[index];
                nums[index] = -1;
                index = temp;
                count++;
            }
            max = Math.max(count, max);
        }
        return max;
    }
}
// @lc code=end
