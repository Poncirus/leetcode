/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 *
 * https://leetcode.com/problems/remove-k-digits/description/
 *
 * algorithms
 * Medium (27.49%)
 * Likes:    2240
 * Dislikes: 101
 * Total Accepted:    141.8K
 * Total Submissions: 500.6K
 * Testcase Example:  '"1432219"\n3'
 *
 * Given a non-negative integer num represented as a string, remove k digits
 * from the number so that the new number is the smallest possible.
 * 
 * 
 * Note:
 * 
 * The length of num is less than 10002 and will be ≥ k.
 * The given num does not contain any leading zero.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: num = "1432219", k = 3
 * Output: "1219"
 * Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219
 * which is the smallest.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: num = "10200", k = 1
 * Output: "200"
 * Explanation: Remove the leading 1 and the number is 200. Note that the
 * output must not contain leading zeroes.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: num = "10", k = 2
 * Output: "0"
 * Explanation: Remove all the digits from the number and it is left with
 * nothing which is 0.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        vector<char> stack;
        if (k == num.size())
            return "0";
        int index = 0;
        while (index < num.size())
        {
            int n = stack.size();
            while (k && n && stack[n - 1] > num.at(index))
            {
                k--;
                stack.pop_back();
                n = stack.size();
            }
            stack.push_back(num.at(index++));
        }
        while (k-- > 0)
        {
            stack.pop_back();
        }
        int n = stack.size();
        string small = "";
        while (!stack.empty())
        {
            small = stack[n - 1] + small;
            n--;
            stack.pop_back();
        }
        while (small.size() > 1 && small[0] == '0')
        {
            small = small.substr(1);
        }
        return small;
    }
};
// @lc code=end
