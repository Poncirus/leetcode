/*
 * @lc app=leetcode id=397 lang=cpp
 *
 * [397] Integer Replacement
 *
 * https://leetcode.com/problems/integer-replacement/description/
 *
 * algorithms
 * Medium (32.36%)
 * Likes:    343
 * Dislikes: 313
 * Total Accepted:    54K
 * Total Submissions: 165.1K
 * Testcase Example:  '8'
 *
 * 
 * Given a positive integer n and you can do operations as follow:
 * 
 * 
 * 
 * 
 * If n is even, replace n with n/2.
 * If n is odd, you can replace n with either n + 1 or n - 1.
 * 
 * 
 * 
 * 
 * What is the minimum number of replacements needed for n to become 1?
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 8
 * 
 * Output:
 * 3
 * 
 * Explanation:
 * 8 -> 4 -> 2 -> 1
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * 7
 * 
 * Output:
 * 4
 * 
 * Explanation:
 * 7 -> 8 -> 4 -> 2 -> 1
 * or
 * 7 -> 6 -> 3 -> 2 -> 1
 * 
 * 
 */

// @lc code=start
class Solution
{
private:
    unordered_map<int, int> visited;

public:
    int integerReplacement(int n)
    {
        if (n == 1)
        {
            return 0;
        }
        if (visited.count(n) == 0)
        {
            if (n & 1 == 1)
            {
                visited[n] = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
            }
            else
            {
                visited[n] = 1 + integerReplacement(n / 2);
            }
        }
        return visited[n];
    }
};
// @lc code=end
