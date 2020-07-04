/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (40.54%)
 * Likes:    3085
 * Dislikes: 173
 * Total Accepted:    267.3K
 * Total Submissions: 623K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given a string s and a non-empty string p, find all the start indices of p's
 * anagrams in s.
 * 
 * Strings consists of lowercase English letters only and the length of both
 * strings s and p will not be larger than 20,100.
 * 
 * The order of output does not matter.
 * 
 * Example 1:
 * 
 * Input:
 * s: "cbaebabacd" p: "abc"
 * 
 * Output:
 * [0, 6]
 * 
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of
 * "abc".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s: "abab" p: "ab"
 * 
 * Output:
 * [0, 1, 2]
 * 
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int len = p.size();
        if (len > s.size())
            return vector<int>{};

        map<char, int> m;

        for (int i = 0; i < p.size(); i++)
        {
            m[p[i]]++;
        }

        vector<int> res;

        int end = 0;
        for (int i = 0; i <= s.size() - len; i++)
        {
            while (end < s.size() && end - i < len)
            {
                m[s[end]]--;
                while (m[s[end]] < 0)
                {
                    m[s[i]]++;
                    i++;
                }

                end++;
            }

            if (end - i == len)
            {
                res.push_back(i);
            }

            m[s[i]]++;
        }

        return res;
    }
};
// @lc code=end
