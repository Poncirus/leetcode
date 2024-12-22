#
# @lc app=leetcode id=709 lang=python3
#
# [709] To Lower Case
#
# https://leetcode.com/problems/to-lower-case/description/
#
# algorithms
# Easy (83.76%)
# Likes:    1889
# Dislikes: 2784
# Total Accepted:    577.7K
# Total Submissions: 689.1K
# Testcase Example:  '"Hello"'
#
# Given a string s, return the string after replacing every uppercase letter
# with the same lowercase letter.
# 
# 
# Example 1:
# 
# 
# Input: s = "Hello"
# Output: "hello"
# 
# 
# Example 2:
# 
# 
# Input: s = "here"
# Output: "here"
# 
# 
# Example 3:
# 
# 
# Input: s = "LOVELY"
# Output: "lovely"
# 
# 
# 
# Constraints:
# 
# 
# 1 <= s.length <= 100
# s consists of printable ASCII characters.
# 
# 
#

# @lc code=start
class Solution:
    def toLowerCase(self, s: str) -> str:
        return s.lower()
        
# @lc code=end

