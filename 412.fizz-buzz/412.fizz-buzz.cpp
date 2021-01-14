/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 *
 * https://leetcode.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (61.22%)
 * Likes:    862
 * Dislikes: 1160
 * Total Accepted:    329.9K
 * Total Submissions: 532.3K
 * Testcase Example:  '1'
 *
 * Write a program that outputs the string representation of numbers from 1 to
 * n.
 * 
 * But for multiples of three it should output “Fizz” instead of the number and
 * for the multiples of five output “Buzz”. For numbers which are multiples of
 * both three and five output “FizzBuzz”.
 * 
 * Example:
 * 
 * n = 15,
 * 
 * Return:
 * [
 * ⁠   "1",
 * ⁠   "2",
 * ⁠   "Fizz",
 * ⁠   "4",
 * ⁠   "Buzz",
 * ⁠   "Fizz",
 * ⁠   "7",
 * ⁠   "8",
 * ⁠   "Fizz",
 * ⁠   "Buzz",
 * ⁠   "11",
 * ⁠   "Fizz",
 * ⁠   "13",
 * ⁠   "14",
 * ⁠   "FizzBuzz"
 * ]
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> res(n, "");
        for (int i = 0; i < n; i++)
        {
            if ((i + 1) % 3 == 0)
            {
                res[i] += "Fizz";
            }

            if ((i + 1) % 5 == 0)
            {
                res[i] += "Buzz";
            }

            if (res[i] == "")
            {
                int t = i + 1;
                while (t > 0)
                {
                    res[i] = (char)(t % 10 + '0') + res[i];
                    t /= 10;
                }
            }
        }

        return res;
    }
};
// @lc code=end
