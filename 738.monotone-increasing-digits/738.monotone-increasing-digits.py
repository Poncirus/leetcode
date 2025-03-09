#
# @lc app=leetcode id=738 lang=python3
#
# [738] Monotone Increasing Digits
#
# https://leetcode.com/problems/monotone-increasing-digits/description/
#
# algorithms
# Medium (48.61%)
# Likes:    1350
# Dislikes: 111
# Total Accepted:    60.1K
# Total Submissions: 123.5K
# Testcase Example:  '10'
#
# An integer has monotone increasing digits if and only if each pair of
# adjacent digits x and y satisfy x <= y.
# 
# Given an integer n, return the largest number that is less than or equal to n
# with monotone increasing digits.
# 
# 
# Example 1:
# 
# 
# Input: n = 10
# Output: 9
# 
# 
# Example 2:
# 
# 
# Input: n = 1234
# Output: 1234
# 
# 
# Example 3:
# 
# 
# Input: n = 332
# Output: 299
# 
# 
# 
# Constraints:
# 
# 
# 0 <= n <= 10^9
# 
# 
#

# @lc code=start
class Solution(object):
    def monotoneIncreasingDigits(self, n):
        # First, handle the single-digit cases.
        if n < 10:
            return n

		# Convert the number into a list of integers
        l = []
        for _,c in enumerate(str(n)):
            l.append(int(c))
        n = len(l)

		# Tranverse from right to left 
        for i in range(n-1,0,-1):
            if l[i] < l[i-1]:
                l[i-1] -= 1
                for i in range(i,n):
                    l[i] = 9
        
		# Convert the list back to a number
        return int("".join([str(x) for x in l]))
        
# @lc code=end

