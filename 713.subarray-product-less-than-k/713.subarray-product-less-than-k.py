#
# @lc app=leetcode id=713 lang=python3
#
# [713] Subarray Product Less Than K
#
# https://leetcode.com/problems/subarray-product-less-than-k/description/
#
# algorithms
# Medium (51.97%)
# Likes:    6973
# Dislikes: 222
# Total Accepted:    452.6K
# Total Submissions: 868.3K
# Testcase Example:  '[10,5,2,6]\n100'
#
# Given an array of integers nums and an integer k, return the number of
# contiguous subarrays where the product of all the elements in the subarray is
# strictly less than k.
# 
# 
# Example 1:
# 
# 
# Input: nums = [10,5,2,6], k = 100
# Output: 8
# Explanation: The 8 subarrays that have product less than 100 are:
# [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
# Note that [10, 5, 2] is not included as the product of 100 is not strictly
# less than k.
# 
# 
# Example 2:
# 
# 
# Input: nums = [1,2,3], k = 0
# Output: 0
# 
# 
# 
# Constraints:
# 
# 
# 1 <= nums.length <= 3 * 10^4
# 1 <= nums[i] <= 1000
# 0 <= k <= 10^6
# 
# 
#

# @lc code=start
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:        
        l = 0
        res = 0
        product = 1
        
        for r in range(len(nums)):
            product *= nums[r]
            
            if product >= k:
                while product >= k and l <= r:
                    product /= nums[l]
                    l += 1
            
            res += r - l + 1
        
        return res

        
# @lc code=end

