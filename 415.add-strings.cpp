/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (46.11%)
 * Likes:    956
 * Dislikes: 269
 * Total Accepted:    183.9K
 * Total Submissions: 390.1K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int add = 0;

        int i = num1.size() - 1;
        int j = num2.size() - 1;

        string res;

        while (i >= 0 || j >= 0 || add != 0)
        {
            int n1 = i < 0 ? (int)'0' : num1[i];
            int n2 = j < 0 ? (int)'0' : num2[j];

            int n = n1 - '0' + n2 - '0' + add;
            res = (char)(n % 10 + '0') + res;
            add = n / 10;

            i--;
            j--;
        }

        return res;
    }
};
// @lc code=end
