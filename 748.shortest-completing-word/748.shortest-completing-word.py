#
# @lc app=leetcode id=748 lang=python3
#
# [748] Shortest Completing Word
#
# https://leetcode.com/problems/shortest-completing-word/description/
#
# algorithms
# Easy (61.01%)
# Likes:    579
# Dislikes: 1123
# Total Accepted:    90.3K
# Total Submissions: 148K
# Testcase Example:  '"1s3 PSt"\n["step","steps","stripe","stepple"]'
#
# Given a string licensePlate and an array of strings words, find the shortest
# completing word in words.
# 
# A completing word is a word that contains all the letters in licensePlate.
# Ignore numbers and spaces in licensePlate, and treat letters as case
# insensitive. If a letter appears more than once in licensePlate, then it must
# appear in the word the same number of times or more.
# 
# For example, if licensePlate = "aBc 12c", then it contains letters 'a', 'b'
# (ignoring case), and 'c' twice. Possible completing words are "abccdef",
# "caaacab", and "cbca".
# 
# Return the shortest completing word in words. It is guaranteed an answer
# exists. If there are multiple shortest completing words, return the first one
# that occurs in words.
# 
# 
# Example 1:
# 
# 
# Input: licensePlate = "1s3 PSt", words = ["step","steps","stripe","stepple"]
# Output: "steps"
# Explanation: licensePlate contains letters 's', 'p', 's' (ignoring case), and
# 't'.
# "step" contains 't' and 'p', but only contains 1 's'.
# "steps" contains 't', 'p', and both 's' characters.
# "stripe" is missing an 's'.
# "stepple" is missing an 's'.
# Since "steps" is the only word containing all the letters, that is the
# answer.
# 
# 
# Example 2:
# 
# 
# Input: licensePlate = "1s3 456", words = ["looks","pest","stew","show"]
# Output: "pest"
# Explanation: licensePlate only contains the letter 's'. All the words contain
# 's', but among these "pest", "stew", and "show" are shortest. The answer is
# "pest" because it is the word that appears earliest of the 3.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= licensePlate.length <= 7
# licensePlate contains digits, letters (uppercase or lowercase), or space '
# '.
# 1 <= words.length <= 1000
# 1 <= words[i].length <= 15
# words[i] consists of lower case English letters.
# 
# 
#

# @lc code=start
class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        def _get_count(s: str):
            count = {}
            for c in s:
                if not c.isalpha():
                    continue
                lc = c.lower()
                if lc not in count:
                    count[lc] = 0
                count[lc] += 1
            return count
        
        license_count = _get_count(licensePlate)

        words.sort(key=len)
        for word in words:
            count = _get_count(word)
            match = True
            for k in license_count:
                if count.get(k, 0)  < license_count[k]:
                    match = False
                    break

            if match:
                return word
        
        return None
        
# @lc code=end

