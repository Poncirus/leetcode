/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (35.80%)
 * Likes:    1251
 * Dislikes: 219
 * Total Accepted:    168.9K
 * Total Submissions: 466.1K
 * Testcase Example:  '"3+2*2"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string contains only non-negative integers, +, -, *, /
 * operators and empty spaces  . The integer division should truncate toward
 * zero.
 * 
 * Example 1:
 * 
 * 
 * Input: "3+2*2"
 * Output: 7
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: " 3/2 "
 * Output: 1
 * 
 * Example 3:
 * 
 * 
 * Input: " 3+5 / 2 "
 * Output: 5
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int calculate(string s)
    {
        int res = 0;
        int sign = 1;

        int num;
        int n;

        for (size_t i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
            case ' ':
                break;
            case '*':
                i++;
                while (s[i] == ' ')
                {
                    i += 1;
                }
                n = 0;
                for (; i < s.length() && s[i] >= '0' && s[i] <= '9'; i++)
                {
                    n = n * 10 - '0' + s[i];
                }
                i--;
                num = num * n;
                break;
            case '/':
                i++;
                while (s[i] == ' ')
                {
                    i += 1;
                }
                n = 0;
                for (; i < s.length() && s[i] >= '0' && s[i] <= '9'; i++)
                {
                    n = n * 10 - '0' + s[i];
                }
                i--;
                num = num / n;
                break;
            case '+':
                res += sign * num;
                sign = 1;
                break;
            case '-':
                res += sign * num;
                sign = -1;
                break;

            default:
                num = 0;
                for (; i < s.length() && s[i] >= '0' && s[i] <= '9'; i++)
                {
                    num = num * 10 - '0' + s[i];
                }
                i--;
                break;
            }
        }

        res += sign * num;
        return res;
    }
};
// @lc code=end
