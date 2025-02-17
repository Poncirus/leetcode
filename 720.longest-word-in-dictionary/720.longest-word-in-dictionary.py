#
# @lc app=leetcode id=720 lang=python3
#
# [720] Longest Word in Dictionary
#
# https://leetcode.com/problems/longest-word-in-dictionary/description/
#
# algorithms
# Medium (52.93%)
# Likes:    2007
# Dislikes: 1500
# Total Accepted:    166.6K
# Total Submissions: 313.5K
# Testcase Example:  '["w","wo","wor","worl","world"]'
#
# Given an array of strings words representing an English Dictionary, return
# the longest word in words that can be built one character at a time by other
# words in words.
# 
# If there is more than one possible answer, return the longest word with the
# smallest lexicographical order. If there is no answer, return the empty
# string.
# 
# Note that the word should be built from left to right with each additional
# character being added to the end of a previous word. 
# 
# 
# Example 1:
# 
# 
# Input: words = ["w","wo","wor","worl","world"]
# Output: "world"
# Explanation: The word "world" can be built one character at a time by "w",
# "wo", "wor", and "worl".
# 
# 
# Example 2:
# 
# 
# Input: words = ["a","banana","app","appl","ap","apply","apple"]
# Output: "apple"
# Explanation: Both "apply" and "apple" can be built from other words in the
# dictionary. However, "apple" is lexicographically smaller than "apply".
# 
# 
# 
# Constraints:
# 
# 
# 1 <= words.length <= 1000
# 1 <= words[i].length <= 30
# words[i] consists of lowercase English letters.
# 
# 
#

# @lc code=start
class Solution:
    def longestWord(self, words: List[str]) -> str:
        valid = set([""])
        for word in sorted(words, key=len):
            if word[:-1] in valid:
                valid.add(word)
        return max(sorted(valid), key=len)
        
# @lc code=end

