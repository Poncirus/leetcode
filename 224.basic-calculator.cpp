/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (35.52%)
 * Likes:    1306
 * Dislikes: 120
 * Total Accepted:    152.4K
 * Total Submissions: 422.3K
 * Testcase Example:  '"1 + 1"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string may contain open ( and closing parentheses ), the plus
 * + or minus sign -, non-negative integers and empty spaces  .
 * 
 * Example 1:
 * 
 * 
 * Input: "1 + 1"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: " 2-1 + 2 "
 * Output: 3
 * 
 * Example 3:
 * 
 * 
 * Input: "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
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
        stack<int> st;

        for (size_t i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
            case ' ':
                break;
            case '(':
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
                break;
            case ')':
                sign = st.top();
                st.pop();
                res = st.top() + sign * res;
                st.pop();
                break;
            case '+':
                sign = 1;
                break;
            case '-':
                sign = -1;
                break;

            default:
                int num = 0;
                for (; i < s.length() && s[i] >= '0' && s[i] <= '9'; i++)
                {
                    num = num * 10 - '0' + s[i];
                }
                res += sign * num;
                i--;
                break;
            }
        }

        return res;
    }
};
// @lc code=end
