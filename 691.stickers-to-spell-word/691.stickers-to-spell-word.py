#
# @lc app=leetcode id=691 lang=python3
#
# [691] Stickers to Spell Word
#
# https://leetcode.com/problems/stickers-to-spell-word/description/
#
# algorithms
# Hard (46.44%)
# Likes:    679
# Dislikes: 65
# Total Accepted:    28.6K
# Total Submissions: 61.1K
# Testcase Example:  '["with","example","science"]\n"thehat"'
#
# We are given n different types of stickers. Each sticker has a lowercase
# English word on it.
# 
# You would like to spell out the given string target by cutting individual
# letters from your collection of stickers and rearranging them. You can use
# each sticker more than once if you want, and you have infinite quantities of
# each sticker.
# 
# Return the minimum number of stickers that you need to spell out target. If
# the task is impossible, return -1.
# 
# Note: In all test cases, all words were chosen randomly from the 1000 most
# common US English words, and target was chosen as a concatenation of two
# random words.
# 
# 
# Example 1:
# 
# 
# Input: stickers = ["with","example","science"], target = "thehat"
# Output: 3
# Explanation:
# We can use 2 "with" stickers, and 1 "example" sticker.
# After cutting and rearrange the letters of those stickers, we can form the
# target "thehat".
# Also, this is the minimum number of stickers necessary to form the target
# string.
# 
# 
# Example 2:
# 
# 
# Input: stickers = ["notice","possible"], target = "basicbasic"
# Output: -1
# Explanation:
# We cannot form the target "basicbasic" from cutting letters from the given
# stickers.
# 
# 
# 
# Constraints:
# 
# 
# n == stickers.length
# 1 <= n <= 50
# 1 <= stickers[i].length <= 10
# 1 <= target <= 15
# stickers[i] and target consist of lowercase English letters.
# 
# 
#

from typing import Dict, List
import copy

# @lc code=start


class Solution:
    def minStickers(self, stickers: List[str], target: str) -> int:
        n = len(target)
        maxMask = 1 << n
        # dp[i] := min # of stickers to spell out i, where i is the bit mask of
        # target.
        dp = [float('inf')] * maxMask
        dp[0] = 0
        
        # Preprocess the stickers to create a mapping of character frequencies
        stickerCounts = []
        for sticker in stickers:
            stickerCounts.append(collections.Counter(sticker))
        
        for mask in range(maxMask):
            if dp[mask] == float('inf'):
                continue
            # Try to expand from `mask` by using each sticker.
            for i, stickerCount in enumerate(stickerCounts):
                # Skip over stickers that do not contain any characters we need
                if not any(c in stickerCount for c in target):
                    continue
                superMask = mask
                for c, freq in stickerCount.items():
                    for j, t in enumerate(target):
                        # Try to apply it on a missing char.
                        if c == t and not (superMask >> j & 1):
                            superMask |= 1 << j
                            freq -= 1
                            if freq == 0:
                                break
                dp[superMask] = min(dp[superMask], dp[mask] + 1)
        
        return -1 if dp[-1] == float('inf') else dp[-1]
        
# @lc code=end

s = Solution()
print(s.minStickers(["fly","me","charge","mind","bottom"], "centorder"))
print(s.calculated)
