#
# @lc app=leetcode id=740 lang=python3
#
# [740] Delete and Earn
#
# https://leetcode.com/problems/delete-and-earn/description/
#
# algorithms
# Medium (56.63%)
# Likes:    7700
# Dislikes: 392
# Total Accepted:    386.5K
# Total Submissions: 682.4K
# Testcase Example:  '[3,4,2]'
#
# You are given an integer array nums. You want to maximize the number of
# points you get by performing the following operation any number of
# times:
# 
# 
# Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must
# delete every element equal to nums[i] - 1 and every element equal to nums[i]
# + 1.
# 
# 
# Return the maximum number of points you can earn by applying the above
# operation some number of times.
# 
# 
# Example 1:
# 
# 
# Input: nums = [3,4,2]
# Output: 6
# Explanation: You can perform the following operations:
# - Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
# - Delete 2 to earn 2 points. nums = [].
# You earn a total of 6 points.
# 
# 
# Example 2:
# 
# 
# Input: nums = [2,2,3,3,3,4]
# Output: 9
# Explanation: You can perform the following operations:
# - Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums =
# [3,3].
# - Delete a 3 again to earn 3 points. nums = [3].
# - Delete a 3 once more to earn 3 points. nums = [].
# You earn a total of 9 points.
# 
# 
# Constraints:
# 
# 
# 1 <= nums.length <= 2 * 10^4
# 1 <= nums[i] <= 10^4
# 
# 
#

# @lc code=start
class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        points = {}
        for num in nums:
            if num not in points:
                points[num] = 0
            points[num] += 1

        sorted_points = sorted(points.keys())
        a = 0
        b = 0
        for i in range(len(sorted_points)):
            if i == 0 or sorted_points[i] != sorted_points[i-1] + 1:
                a = max(a, b)
                b = max(a, b) + sorted_points[i] * points[sorted_points[i]]
            else:
                a, b = max(a,b), a + sorted_points[i] * points[sorted_points[i]]
        return max(a, b)


        
# @lc code=end

