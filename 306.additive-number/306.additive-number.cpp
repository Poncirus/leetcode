/*
 * @lc app=leetcode id=306 lang=cpp
 *
 * [306] Additive Number
 *
 * https://leetcode.com/problems/additive-number/description/
 *
 * algorithms
 * Medium (28.99%)
 * Likes:    333
 * Dislikes: 393
 * Total Accepted:    49.9K
 * Total Submissions: 171.2K
 * Testcase Example:  '"112358"'
 *
 * Additive number is a string whose digits can form additive sequence.
 * 
 * A valid additive sequence should contain at least three numbers. Except for
 * the first two numbers, each subsequent number in the sequence must be the
 * sum of the preceding two.
 * 
 * Given a string containing only digits '0'-'9', write a function to determine
 * if it's an additive number.
 * 
 * Note: Numbers in the additive sequence cannot have leading zeros, so
 * sequence 1, 2, 03 or 1, 02, 3 is invalid.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "112358"
 * Output: true
 * Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5,
 * 8. 
 * 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "199100199"
 * Output: true
 * Explanation: The additive sequence is: 1, 99, 100, 199. 
 * 1 + 99 = 100, 99 + 100 = 199
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * num consists only of digits '0'-'9'.
 * 1 <= num.length <= 35
 * 
 * 
 * Follow up:
 * How would you handle overflow for very large input integers?
 * 
 */

// @lc code=start
class Solution
{
public:
    bool isAdditiveNumber(string num)
    {
        if (num.size() < 3)
            return false;

        for (int i = 1; i <= num.size() * 2 / 3; i++)
        {
            if (i > 1 && num[0] == '0')
                return false;

            for (int j = i + 1; j <= num.size() * 2 / 3; j++)
            {
                if (j - i > 1 && num[i] == '0')
                    break;

                long a = atol(num.substr(0, i).c_str());
                long b = atol(num.substr(i, j - i).c_str());
                if (rec(a, b, num.substr(j)))
                    return true;
            }
        }

        return false;
    }

private:
    bool rec(long a, long b, string num)
    {
        long c = a + b;
        string cs = to_string(c);

        if (cs.size() > num.size())
            return false;
        else if (cs.size() == num.size())
        {
            if (cs == num)
                return true;
            return false;
        }
        else
        {
            if (cs != num.substr(0, cs.size()))
                return false;
            return rec(b, c, num.substr(cs.size()));
        }
    }
};
// @lc code=end
