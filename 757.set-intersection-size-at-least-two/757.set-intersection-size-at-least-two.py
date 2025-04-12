#
# @lc app=leetcode id=757 lang=python3
#
# [757] Set Intersection Size At Least Two
#
# https://leetcode.com/problems/set-intersection-size-at-least-two/description/
#
# algorithms
# Hard (44.88%)
# Likes:    727
# Dislikes: 86
# Total Accepted:    26.3K
# Total Submissions: 58.5K
# Testcase Example:  '[[1,3],[3,7],[8,9]]'
#
# You are given a 2D integer array intervals where intervals[i] = [starti,
# endi] represents all the integers from starti to endi inclusively.
# 
# A containing set is an array nums where each interval from intervals has at
# least two integers in nums.
# 
# 
# For example, if intervals = [[1,3], [3,7], [8,9]], then [1,2,4,7,8,9] and
# [2,3,4,8,9] are containing sets.
# 
# 
# Return the minimum possible size of a containing set.
# 
# 
# Example 1:
# 
# 
# Input: intervals = [[1,3],[3,7],[8,9]]
# Output: 5
# Explanation: let nums = [2, 3, 4, 8, 9].
# It can be shown that there cannot be any containing array of size 4.
# 
# 
# Example 2:
# 
# 
# Input: intervals = [[1,3],[1,4],[2,5],[3,5]]
# Output: 3
# Explanation: let nums = [2, 3, 4].
# It can be shown that there cannot be any containing array of size 2.
# 
# 
# Example 3:
# 
# 
# Input: intervals = [[1,2],[2,3],[2,4],[4,5]]
# Output: 5
# Explanation: let nums = [1, 2, 3, 4, 5].
# It can be shown that there cannot be any containing array of size 4.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= intervals.length <= 3000
# intervals[i].length == 2
# 0 <= starti < endi <= 10^8
# 
# 
#

# @lc code=start
class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda x:x[1])
        size = 0
        prev_start = -1
        prev_end = -1

        for curr_start, curr_end in intervals:
            if prev_start == -1 or prev_end < curr_start: #if intervals do not overlap
                size += 2
                prev_start = curr_end-1
                prev_end = curr_end

            elif prev_start < curr_start: #if intervals overlap
                if prev_end != curr_end:
                    prev_start = prev_end
                    prev_end = curr_end
                    
                else:
                    prev_start = curr_end-1
                    prev_end = curr_end

                size += 1

        return size
        
# @lc code=end

