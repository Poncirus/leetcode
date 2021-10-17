/*
 * @lc app=leetcode id=645 lang=java
 *
 * [645] Set Mismatch
 *
 * https://leetcode.com/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (41.05%)
 * Likes:    1431
 * Dislikes: 493
 * Total Accepted:    144.9K
 * Total Submissions: 353K
 * Testcase Example:  '[1,2,2,4]'
 *
 * You have a set of integers s, which originally contains all the numbers from
 * 1 to n. Unfortunately, due to some error, one of the numbers in s got
 * duplicated to another number in the set, which results in repetition of one
 * number and loss of another number.
 * 
 * You are given an integer array nums representing the data status of this set
 * after the error.
 * 
 * Find the number that occurs twice and the number that is missing and return
 * them in the form of an array.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 * Example 2:
 * Input: nums = [1,1]
 * Output: [1,2]
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
    public int[] findErrorNums(int[] nums) {
        int[] res = new int[2];
        for (int i = 0; i < nums.length; i++) {
            while (nums[i] != i + 1) {
                int idx = nums[i] - 1;
                if (nums[idx] == nums[i]) {
                    res[0] = nums[i];
                    res[1] = i + 1;
                    break;
                }

                int t = nums[i];
                nums[i] = nums[idx];
                nums[idx] = t;

                if (t == res[0]) {
                    res[1] = i + i;
                    break;
                }
            }
        }

        return res;
    }
}
// @lc code=end

