/*
 * @lc app=leetcode id=466 lang=cpp
 *
 * [466] Count The Repetitions
 *
 * https://leetcode.com/problems/count-the-repetitions/description/
 *
 * algorithms
 * Hard (27.91%)
 * Likes:    175
 * Dislikes: 140
 * Total Accepted:    10.5K
 * Total Submissions: 37.2K
 * Testcase Example:  '"acb"\n4\n"ab"\n2'
 *
 * Define S = [s,n] as the string S which consists of n connected strings s.
 * For example, ["abc", 3] ="abcabcabc". 
 * On the other hand, we define that string s1 can be obtained from string s2
 * if we can remove some characters from s2 such that it becomes s1. For
 * example, “abc”  can be obtained from “abdbec” based on our definition, but
 * it can not be obtained from “acbbe”.
 * You are given two non-empty strings s1 and s2 (each at most 100 characters
 * long) and two integers 0 ≤ n1 ≤ 10^6 and 1 ≤ n2 ≤ 10^6. Now consider the
 * strings S1 and S2, where S1=[s1,n1] and S2=[s2,n2]. Find the maximum integer
 * M such that [S2,M] can be obtained from S1.
 * 
 * Example:
 * 
 * Input:
 * s1="acb", n1=4
 * s2="ab", n2=2
 * 
 * Return:
 * 2
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2)
    {
        vector<int> repeatCount(n1 + 1, 0);
        vector<int> nextIndex(n1 + 1, 0);
        int j = 0, cnt = 0;
        for (int k = 1; k <= n1; ++k)
        {
            for (int i = 0; i < s1.size(); ++i)
            {
                if (s1[i] == s2[j])
                {
                    ++j;
                    if (j == s2.size())
                    {
                        j = 0;
                        ++cnt;
                    }
                }
            }
            repeatCount[k] = cnt;
            nextIndex[k] = j;
            for (int start = 0; start < k; ++start)
            {
                if (nextIndex[start] == j)
                { // see if you have met this nextIndex before
                    // if found, you can calculate the 3 parts
                    int prefixCount = repeatCount[start]; // prefixCount is the start-th repeatCount
                    // (repeatCount[k] - prefixCount) is the repeatCount of one occurrance of the pattern
                    // There are (n1 - start) / (k - start) occurrances of the pattern
                    // So (n1 - start) / (k - start) * (repeatCount[k] - prefixCount) is the repeatCount of the repetitive part
                    int patternCount = (n1 - start) / (k - start) * (repeatCount[k] - prefixCount);
                    // The suffix contains the incomplete repetitive remnant (if any)
                    // Its length is (n1 - start) % (k - start)
                    // So the suffix repeatCount should be repeatCount[start + (n1 - start) % (k - start)] - prefixCount
                    int suffixCount = repeatCount[start + (n1 - start) % (k - start)] - prefixCount;
                    return (prefixCount + patternCount + suffixCount) / n2;
                }
            }
        }
        return repeatCount[n1] / n2;
    }
};
// @lc code=end
