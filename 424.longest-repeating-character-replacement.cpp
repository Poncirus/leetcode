/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
 *
 * algorithms
 * Medium (45.46%)
 * Likes:    1336
 * Dislikes: 79
 * Total Accepted:    67.5K
 * Total Submissions: 144.9K
 * Testcase Example:  '"ABAB"\n2'
 *
 * Given a string s that consists of only uppercase English letters, you can
 * perform at most k operations on that string.
 * 
 * In one operation, you can choose any character of the string and change it
 * to any other uppercase English character.
 * 
 * Find the length of the longest sub-string containing all repeating letters
 * you can get after performing the above operations.
 * 
 * Note:
 * Both the string's length and k will not exceed 10^4.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "ABAB", k = 2
 * 
 * Output:
 * 4
 * 
 * Explanation:
 * Replace the two 'A's with two 'B's or vice versa.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "AABABBA", k = 1
 * 
 * Output:
 * 4
 * 
 * Explanation:
 * Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int size = s.size();
        int ret = 0;
        vector<int> count(26, 0);
        int start = 0;
        int end = 0;
        int localMaxFreq = 0;
        for (; end < size; end++)
        {
            count[s[end] - 'A'] += 1;
            localMaxFreq = max(localMaxFreq, count[s[end] - 'A']);
            if ((end - start + 1) - localMaxFreq > k)
            {
                ret = max(ret, (end - start));
                count[s[start] - 'A'] -= 1;
                start += 1;
                localMaxFreq = *(max_element(count.begin(), count.end()));
            }
        }
        return max(ret, end - start);
    }
};
// @lc code=end
