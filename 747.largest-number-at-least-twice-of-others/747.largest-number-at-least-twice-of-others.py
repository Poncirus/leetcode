#
# @lc app=leetcode id=747 lang=python3
#
# [747] Largest Number At Least Twice of Others
#
# https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/
#
# algorithms
# Easy (50.35%)
# Likes:    1271
# Dislikes: 921
# Total Accepted:    285.1K
# Total Submissions: 566.1K
# Testcase Example:  '[3,6,1,0]'
#
# You are given an integer array nums where the largest integer is unique.
# 
# Determine whether the largest element in the array is at least twice as much
# as every other number in the array. If it is, return the index of the largest
# element, or return -1 otherwise.
# 
# 
# Example 1:
# 
# 
# Input: nums = [3,6,1,0]
# Output: 1
# Explanation: 6 is the largest integer.
# For every other number in the array x, 6 is at least twice as big as x.
# The index of value 6 is 1, so we return 1.
# 
# 
# Example 2:
# 
# 
# Input: nums = [1,2,3,4]
# Output: -1
# Explanation: 4 is less than twice the value of 3, so we return -1.
# 
# 
# 
# Constraints:
# 
# 
# 2 <= nums.length <= 50
# 0 <= nums[i] <= 100
# The largest element in nums is unique.
# 
# 
#

# @lc code=start
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        first_max = second_max = -1
        max_ind = 0

        for i, num in enumerate(nums):
            if num >= first_max:
                first_max, second_max = num, first_max
                max_ind = i
            elif num > second_max:
                second_max = num

        if first_max < 2*second_max:
            max_ind = -1

        return max_ind

        
# @lc code=end

