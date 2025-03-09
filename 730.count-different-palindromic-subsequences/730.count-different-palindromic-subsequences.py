#
# @lc app=leetcode id=730 lang=python3
#
# [730] Count Different Palindromic Subsequences
#
# https://leetcode.com/problems/count-different-palindromic-subsequences/description/
#
# algorithms
# Hard (46.34%)
# Likes:    1955
# Dislikes: 102
# Total Accepted:    40.4K
# Total Submissions: 87.1K
# Testcase Example:  '"bccb"'
#
# Given a string s, return the number of different non-empty palindromic
# subsequences in s. Since the answer may be very large, return it modulo 10^9
# + 7.
# 
# A subsequence of a string is obtained by deleting zero or more characters
# from the string.
# 
# A sequence is palindromic if it is equal to the sequence reversed.
# 
# Two sequences a1, a2, ... and b1, b2, ... are different if there is some i
# for which ai != bi.
# 
# 
# Example 1:
# 
# 
# Input: s = "bccb"
# Output: 6
# Explanation: The 6 different non-empty palindromic subsequences are 'b', 'c',
# 'bb', 'cc', 'bcb', 'bccb'.
# Note that 'bcb' is counted only once, even though it occurs twice.
# 
# 
# Example 2:
# 
# 
# Input: s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"
# Output: 104860361
# Explanation: There are 3104860382 different non-empty palindromic
# subsequences, which is 104860361 modulo 10^9 + 7.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= s.length <= 1000
# s[i] is either 'a', 'b', 'c', or 'd'.
# 
# 
#

# @lc code=start
class Solution(object):
    def countPalindromicSubsequences(self, s: str):
        M = 10**9 + 7

        fwd = deque()
        dic = defaultdict(lambda: -1)
        for i in range(len(s)-1,-1,-1):
            ch = s[i]
            dic[ch] = i
            fwd.appendleft(dic.copy())

        bwd = []
        dic = defaultdict(lambda: -1)
        for i,ch in enumerate(s):
            dic[ch] = i
            bwd.append(dic.copy())

        @lru_cache(None)
        def dp(i,j):
            if i > j:
                return 1  # empty string
            ans = 1  # empty string
            for l in ('a','b','c','d'):
                m = fwd[i][l]
                n = bwd[j][l]

                if m == -1 or n < i or m > j:
                    continue
                ans += 1  # unique char
                if m < n:
                    ans += dp(m+1,n-1)
            return ans%M

        return dp(0,len(s)-1)-1
        
# @lc code=end

