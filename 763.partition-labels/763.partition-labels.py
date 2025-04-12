#
# @lc app=leetcode id=763 lang=python3
#
# [763] Partition Labels
#
# https://leetcode.com/problems/partition-labels/description/
#
# algorithms
# Medium (80.20%)
# Likes:    10934
# Dislikes: 426
# Total Accepted:    703.1K
# Total Submissions: 863.4K
# Testcase Example:  '"ababcbacadefegdehijhklij"'
#
# You are given a string s. We want to partition the string into as many parts
# as possible so that each letter appears in at most one part. For example, the
# string "ababcc" can be partitioned into ["abab", "cc"], but partitions such
# as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.
# 
# Note that the partition is done so that after concatenating all the parts in
# order, the resultant string should be s.
# 
# Return a list of integers representing the size of these parts.
# 
# 
# Example 1:
# 
# 
# Input: s = "ababcbacadefegdehijhklij"
# Output: [9,7,8]
# Explanation:
# The partition is "ababcbaca", "defegde", "hijhklij".
# This is a partition so that each letter appears in at most one part.
# A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it
# splits s into less parts.
# 
# 
# Example 2:
# 
# 
# Input: s = "eccbbbbdec"
# Output: [10]
# 
# 
# 
# Constraints:
# 
# 
# 1 <= s.length <= 500
# s consists of lowercase English letters.
# 
# 
#

# @lc code=start
class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        res = []
        count = {}
        for c in s:
            if c not in count:
                count[c] = 0
            count[c] += 1
        
        current = 0
        letters = set()
        for c in s:
            current += 1
            letters.add(c)
            count[c] -= 1
            if count[c] == 0:
                letters.remove(c)
            if not letters:
                res.append(current)
                current = 0
        
        return res
        
# @lc code=end

