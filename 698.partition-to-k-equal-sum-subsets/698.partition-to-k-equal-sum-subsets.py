#
# @lc app=leetcode id=698 lang=python3
#
# [698] Partition to K Equal Sum Subsets
#
# https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
#
# algorithms
# Medium (38.11%)
# Likes:    7234
# Dislikes: 520
# Total Accepted:    287.7K
# Total Submissions: 755.2K
# Testcase Example:  '[4,3,2,3,5,2,1]\n4'
#
# Given an integer array nums and an integer k, return true if it is possible
# to divide this array into k non-empty subsets whose sums are all equal.
# 
# 
# Example 1:
# 
# 
# Input: nums = [4,3,2,3,5,2,1], k = 4
# Output: true
# Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3),
# (2,3) with equal sums.
# 
# 
# Example 2:
# 
# 
# Input: nums = [1,2,3,4], k = 3
# Output: false
# 
# 
# 
# Constraints:
# 
# 
# 1 <= k <= nums.length <= 16
# 1 <= nums[i] <= 10^4
# The frequency of each element is in the range [1, 4].
# 
# 
#

# @lc code=start
class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        total = sum(nums)
        if total % k != 0:
            return False
        
        target = total / k
        buckets = [0] * k

        def recurse(i):
            if i == len(nums):    
                return True

            for j in range(k):
                if buckets[j] + nums[i] <= target:
                    buckets[j] += nums[i]

                    if recurse(i + 1):
                        return True

                    buckets[j] -= nums[i]

                    if buckets[j] == 0:
                        break

            return False

        return recurse(0)


        
# @lc code=end

