#
# @lc app=leetcode id=693 lang=python3
#
# [693] Binary Number with Alternating Bits
#
# https://leetcode.com/problems/binary-number-with-alternating-bits/description/
#
# algorithms
# Easy (63.03%)
# Likes:    1381
# Dislikes: 112
# Total Accepted:    146.2K
# Total Submissions: 231.6K
# Testcase Example:  '5'
#
# Given a positive integer, check whether it has alternating bits: namely, if
# two adjacent bits will always have different values.
# 
# 
# Example 1:
# 
# 
# Input: n = 5
# Output: true
# Explanation: The binary representation of 5 is: 101
# 
# 
# Example 2:
# 
# 
# Input: n = 7
# Output: false
# Explanation: The binary representation of 7 is: 111.
# 
# Example 3:
# 
# 
# Input: n = 11
# Output: false
# Explanation: The binary representation of 11 is: 1011.
# 
# 
# Constraints:
# 
# 
# 1 <= n <= 2^31 - 1
# 
# 
#

# @lc code=start
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        bit = n % 2
        n = n >> 1
        while n != 0:
            if bit + n % 2 != 1:
                return False
            bit = n % 2
            n = n >> 1
        return True

        
# @lc code=end

