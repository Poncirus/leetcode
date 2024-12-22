#
# @lc app=leetcode id=696 lang=python3
#
# [696] Count Binary Substrings
#
# https://leetcode.com/problems/count-binary-substrings/description/
#
# algorithms
# Easy (65.70%)
# Likes:    4031
# Dislikes: 885
# Total Accepted:    220.7K
# Total Submissions: 335.8K
# Testcase Example:  '"00110011"'
#
# Given a binary string s, return the number of non-empty substrings that have
# the same number of 0's and 1's, and all the 0's and all the 1's in these
# substrings are grouped consecutively.
# 
# Substrings that occur multiple times are counted the number of times they
# occur.
# 
# 
# Example 1:
# 
# 
# Input: s = "00110011"
# Output: 6
# Explanation: There are 6 substrings that have equal number of consecutive 1's
# and 0's: "0011", "01", "1100", "10", "0011", and "01".
# Notice that some of these substrings repeat and are counted the number of
# times they occur.
# Also, "00110011" is not a valid substring because all the 0's (and 1's) are
# not grouped together.
# 
# 
# Example 2:
# 
# 
# Input: s = "10101"
# Output: 4
# Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal
# number of consecutive 1's and 0's.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= s.length <= 10^5
# s[i] is either '0' or '1'.
# 
# 
#

# @lc code=start
class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        if len(s) == 0:
            return 0
        numbers = []
        current = (s[0] == 1)
        count = 0
        for c in s:
            if (c == "1") == current:
                count += 1
            else:
                current = (c == "1")
                numbers.append(count)
                count = 1
        numbers.append(count)
        print(numbers)

        res = 0
        for i in range(1, len(numbers)):
            res += min(numbers[i], numbers[i-1])
        return res
        
# @lc code=end

print(Solution().countBinarySubstrings("00110011"))

