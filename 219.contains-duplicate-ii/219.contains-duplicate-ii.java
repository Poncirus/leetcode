import java.util.HashSet;

/*
 * @lc app=leetcode id=219 lang=java
 *
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (39.98%)
 * Likes:    1732
 * Dislikes: 1571
 * Total Accepted:    379.9K
 * Total Submissions: 950.1K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * Given an integer array nums and an integer k, return true if there are two
 * distinct indices i and j in the array such that nums[i] == nums[j] and abs(i
 * - j) <= k.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 0 <= k <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Set<Integer> s = new HashSet<>();
        int i = 0;
        int j = 0;

        while (j < k && j < nums.length) {
            if (!s.add(nums[j])) {
                return true;
            }
            j++;
        }

        while (j < nums.length) {
            if (!s.add(nums[j])) {
                return true;
            }
            s.remove(nums[i]);
            i++;
            j++;
        }

        return false;
    }
}
// @lc code=end

