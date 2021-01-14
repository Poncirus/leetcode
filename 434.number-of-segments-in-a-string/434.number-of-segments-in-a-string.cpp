/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (37.50%)
 * Likes:    222
 * Dislikes: 727
 * Total Accepted:    76K
 * Total Submissions: 201.9K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * Count the number of segments in a string, where a segment is defined to be a
 * contiguous sequence of non-space characters.
 * 
 * Please note that the string does not contain any non-printable characters.
 * 
 * Example:
 * 
 * Input: "Hello, my name is John"
 * Output: 5
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int countSegments(string s)
    {
        int res = 0;
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (s[i] != ' ')
            {
                res++;
                while (i < s.size() && s[i] != ' ')
                {
                    i++;
                }
            }
        }

        return res;
    }
};
// @lc code=end
