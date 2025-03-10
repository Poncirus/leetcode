#
# @lc app=leetcode id=745 lang=python3
#
# [745] Prefix and Suffix Search
#
# https://leetcode.com/problems/prefix-and-suffix-search/description/
#
# algorithms
# Hard (41.23%)
# Likes:    2303
# Dislikes: 489
# Total Accepted:    102.5K
# Total Submissions: 248.5K
# Testcase Example:  '["WordFilter","f"]\n[[["apple"]],["a","e"]]'
#
# Design a special dictionary that searches the words in it by a prefix and a
# suffix.
# 
# Implement the WordFilter class:
# 
# 
# WordFilter(string[] words) Initializes the object with the words in the
# dictionary.
# f(string pref, string suff) Returns the index of the word in the dictionary,
# which has the prefix pref and the suffix suff. If there is more than one
# valid index, return the largest of them. If there is no such word in the
# dictionary, return -1.
# 
# 
# 
# Example 1:
# 
# 
# Input
# ["WordFilter", "f"]
# [[["apple"]], ["a", "e"]]
# Output
# [null, 0]
# Explanation
# WordFilter wordFilter = new WordFilter(["apple"]);
# wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix =
# "a" and suffix = "e".
# 
# 
# 
# Constraints:
# 
# 
# 1 <= words.length <= 10^4
# 1 <= words[i].length <= 7
# 1 <= pref.length, suff.length <= 7
# words[i], pref and suff consist of lowercase English letters only.
# At most 10^4 calls will be made to the function f.
# 
# 
#

# @lc code=start
class WordFilter(object):

    def __init__(self, words):
        self.inputs = {}
        for index, word in enumerate(words):
            prefix = ''
            for char in [''] + list(word):
                prefix += char
                suffix = ''
                for char in [''] + list(word[::-1]):
                    suffix += char
                    self.inputs[prefix + '.' + suffix[::-1]] = index

    def f(self, prefix, suffix):
        return self.inputs.get(prefix + '.' + suffix, -1)
        


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(pref,suff)
# @lc code=end

